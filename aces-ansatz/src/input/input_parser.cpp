//
//  input_parser.cpp
//  aces-ansatz
//
//  Created by Jason Byrd on 3/31/15.
//  Copyright (c) 2015 Jason Byrd. All rights reserved.
//

#include "input_reader.h"
#include "molecule_data.h"
#include "core.h"

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

namespace input {
    
    
    /* This routine takes as an argument the inputfilename.
     it returns:
     the coordinates in a struct vector of strings
     a string of comma separated keywords
     */
    input::input_block parse_file(std::string input_string){
        
        input::input_block tib;
        
        std::locale loc;
        
        std::ifstream input_stream(input_string);
        std::string isline;
        
        // no double commas
        std::regex redundant_comma(",\\s*,");
        // strip end of string comma
        std::regex endofline_comma(",$");
        // match *...( or )
        std::regex kw("((\\*.*\\()|(\\s)|(\\)))");
        
        std::cout << std::endl << "Echo of the first few input file lines:" << std::endl;
        // offset by 1 for header
        std::getline(input_stream,isline);
        std::cout << input::comment_removed_line(isline) << std::endl;
        
        // ---------------- parse coordinate section
        int icount = 1;
        int iscoordinates = 1;
        while (std::getline(input_stream,isline)) {
            std::string tmp;
            tmp = input::comment_removed_line(isline);
            
            if(isline.empty()){
                input::dump_file_string(icount," ");
                
                // blank lines signify breaks between coordinate and keyword sections.
                if(iscoordinates) {iscoordinates = 0;}
                break;
                
                // if we parse a comment line to empty, skip over
            } else if(!tmp.empty()) {
                tib.all_coordinate_vector.push_back(tmp);
                input::dump_file_string(icount,tmp);
            }
            icount++;
        }
        
        molecule::GlobalMolecule::set_atom_count(icount - 1);
        
        // ---------------- parse keyword section
        
        std::string store_keyword;
        
        int iskeywords = 0;
        while (std::getline(input_stream,isline) && !iscoordinates) {
            std::string tmp;
            tmp = comment_removed_line(isline);
            
            // blank lines are allowed
            if(isline.empty()){
                input::dump_file_string(icount," ");
                
                // find the first ( string element post coordinates and use that to start the keyword section
            } else if (tmp.find("(") != std::string::npos ) {
                iskeywords = 1;
                input::dump_file_string(icount,"*Aces(");
            }
            
            // this part will parse the keyword section between a ( and ) section in the input file
            if(iskeywords && !tmp.empty()) {
                std::string tmp2;
                tmp2 = std::regex_replace(tmp,kw,"");
                
                // since we regex strip ), for input file dumping we print it back out
                if (tmp.find(")") != std::string::npos ) {
                    iskeywords = 0;
                    input::dump_file_string(icount,")");
                }
                
                if(!tmp2.empty()) {
                    
                    input::dump_file_string(icount,std::regex_replace(tmp2,endofline_comma,""));
                    // append the keyword stream to a single stream with commas separating things
                    store_keyword.append(tmp2);
                    store_keyword.append(","); // extra comma gets stripped at end
                }
                
                // this is the effective EOF
                if (!iskeywords) {break;}
            }
            ++icount;
        }
        
        std::stringstream ss;
        
        ss << std::regex_replace(std::regex_replace(store_keyword,redundant_comma,","),endofline_comma,"");
        
        while (ss.good()) {
            std::string isline;
            std::getline(ss, isline, ',');
            tib.all_keyword_string_vector.push_back(isline);
        }
        // at this point we have stored the keywords in a vector
        
        std::cout << std::endl;
        
        return tib;
        
    }
    
// this routine will open the input file and count the number of atoms
    void count_atom(std::string input_string){
        
        std::ifstream input_stream(input_string);
        std::string isline;
        
        // offset by 1 for headerline
        std::getline(input_stream,isline);
        int icount = 0;
        
        while (std::getline(input_stream,isline)) {
            if(isline.empty()) {break;}
            // update atom_count
            icount++;
        }
        molecule::GlobalMolecule::set_atom_count(icount);
        std::cout << "Found " << molecule::GlobalMolecule::get_atom_count() << " atoms" << std::endl;
    }
    
    // when parsing input file, return the line without comment
    //  valid comment chars: #
    std::string comment_removed_line(std::string isline) {
        std::regex re("#.*");
        std::regex ms("\\s+");
        std::regex bs("^\\s\\s*");
        std::string tmp;
        tmp = std::regex_replace(std::regex_replace(std::regex_replace(isline,re,""),ms," "),bs,"");
        // work in all caps for legacy
        transform(tmp.begin(), tmp.end(), tmp.begin(), toupper);
        return tmp;
    }
    
    void dump_file_string(int icount, std::string tmp) {
        if(icount<aces::GlobalSettings::get_max_dump_length()) {
            std::cout << tmp << std::endl;
        }
    }
    
}