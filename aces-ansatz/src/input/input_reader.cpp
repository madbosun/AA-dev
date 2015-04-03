//
//  input_reader.cpp
//  aces-ansatz
//
//  Created by Jason Byrd on 3/19/15.
//  Copyright (c) 2015 Jason Byrd. All rights reserved.
//

#include "input_reader.h"
#include "molecule_data.h"
#include "core.h"
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
#include <fstream>
#include <cstdlib>
#include <iterator>     // back_inserter
#include <regex>        // regex, sregex_token_iterator
#include <locale>

namespace input{

    void reader(std::string input_string, std::string basis_string) {
        
        std::cout << std::endl << "Parsing input file" << std::endl;
        
        // parse input file and store in ib struct
        input::input_block ib;
        ib.all_coordinate_vector.reserve(aces::GlobalSettings::get_starting_atom_count());
        ib = input::parse_file(input_string);
        
        std::cout << "Found " << molecule::GlobalMolecule::get_atom_count() << " atoms" << std::endl;
        
        std::stringstream ss;
        std::string isline;
        ss << ib.all_coordinate_vector[1];
        
        int ncol=0;
        while (!ss.eof()) {
            ++ncol;
            ss >> isline;
        }
        if (ncol < 4) {
            std::cout << "Non-cartesian input coordinates not supported at this time" << std::endl;
            all_abort();
        }
        std::cout << "Identified " << ncol << " columns in first coordinate entry.  Assuming cartesian input." << std::endl;
        
        std::cout << "----" << std::endl;
        
        molecule::molecule_data MolD;
        MolD = input::store_cartesian_data(ib);
        //contemplate vector destructor here
        
        input::keyword_handler(ib);
    
        
        /*
        std::vector<std::string>::iterator it = ib.all_coordinate_vector.begin();
        std::vector<std::string>::iterator it_end = ib.all_coordinate_vector.end();
        for (; it != it_end; ++it) {
            std::string isline = *it;
            std::cout << isline <<std::endl;
        }
        
     */
        
    }


}