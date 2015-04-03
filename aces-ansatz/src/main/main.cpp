//
//  main.cpp
//  aces-ansatz
//
//  Created by Jason Byrd on 3/19/15.
//  Copyright (c) 2015 Jason Byrd. All rights reserved.
//

#include "core.h"
#include "global_state.h"
#include "io_utils.h"
#include "input_reader.h"
#include "abort.h"

#include <iostream>
#include <vector>
#include <sstream>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fenv.h>
#include <ctime>
#include <execinfo.h>
#include <signal.h>

void bt_sighandler(int signum) {
    std::cerr << "Interrupt signal (" << signum << ") received." << std::endl;
    all_abort();
}

int main(int argc, char * argv[]) {
    
    signal(SIGSEGV, bt_sighandler);
    signal(SIGFPE, bt_sighandler);
    signal(SIGTERM, bt_sighandler);
    signal(SIGINT, bt_sighandler);
    signal(SIGABRT, bt_sighandler);
    
    aces::aces_verno = "2015.A1";
    
    std::cout
    << std::endl
    << "This is the Advanced Concepts in Electronic Structure (ACES) data ansatz program version " << aces::aces_verno << std::endl
    << "From the Quantum Theory Project" << std::endl
    << "Jason N. Byrd" << std::endl << std::endl << std::endl;

    // default input file
    char *input_file = "ZMAT";
    // default basis file is ACESII format
    char *basis_file = "GENBAS";
    // default output binary file
    char *output_file = "data.dat";
    // 500 mb default
    std::size_t memory = 536870912;
    
    // setting some max and starting size guesses
    aces::GlobalSettings::set_max_column(6);
    aces::GlobalSettings::set_max_dump_length(200);
    aces::GlobalSettings::set_starting_atom_count(5000); // this is not a max, just an initial memory allocation starting point
    
    const char *optString = "f:b:o:m:h?";
    int c;
    while ((c = getopt(argc, argv, optString)) != -1){
        switch (c) {
            case 'f':{
                input_file = optarg;
            }
                break;
            case 'b':{
                basis_file = optarg;
            }
                break;
            case 'o':{
                output_file = optarg;
            }
                break;
            case 'm':{
                std::string memory_string(optarg);
                std::stringstream ss(memory_string);
                double memory_in_gb;
                ss >> memory_in_gb;
                memory = memory_in_gb * 1024 * 1024 * 1024;
            }
                break;
            case 'h':case '?':
            default:
                std::cerr << "Usage : "<< argv[0] <<" -f <input_file> -b <basis_file> -m <max_memory_in_gigabytes>" << std::endl;
                std::cerr << "\tDefaults: data file - \"data.dat\", sialx directory - \".\", Memory : 2GB" << std::endl;
                std::cerr << "\tm is the approximate memory to use. Actual usage will be more." << std::endl;
                std::cerr << "\t-? or -h to display this usage dialogue" << std::endl;
                return 1;
        }
    }
  
    aces::GlobalState::set_max_data_memory_usage(memory);
    

    std::string input_string(input_file);
    std::cout << "Initializing input file from " << input_string << std::endl;
    setup::ReadFileExists(input_string);
    
    std::string basis_string(basis_file);
    std::cout << "Initializing basis file from " << basis_string << std::endl;
    setup::ReadFileExists(basis_string);
    
    std::string output_string(output_file);
    std::cout << "Initializing binary output file " << output_file << std::endl;
    setup::BinaryOutputFile output_stream(output_string);
    
    input::reader(input_string,basis_string);
    
    return 0;
}
