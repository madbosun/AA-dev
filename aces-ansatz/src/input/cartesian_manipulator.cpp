//
//  cartesian_manipulator.cpp
//  aces-ansatz
//
//  Created by Jason Byrd on 4/1/15.
//  Copyright (c) 2015 Jason Byrd. All rights reserved.
//

#include "input_reader.h"
#include "molecule_data.h"
#include "asv.h"
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

namespace input{

    molecule::molecule_data store_cartesian_data(input::input_block ib) {
    
        molecule::molecule_data MolD;
        
        MolD.atom_type = new std::string[molecule::GlobalMolecule::get_atom_count()];
        MolD.xyz = new double*[molecule::GlobalMolecule::get_atom_count()];
        MolD.fragment_index = new int[molecule::GlobalMolecule::get_atom_count()];
        MolD.atom_basis_set_name = new std::string[molecule::GlobalMolecule::get_atom_count()];
        
        std::string isline;
        
        int maxcol = aces::GlobalSettings::get_max_column();
        int j = 0;
        std::vector<std::string>::iterator it = ib.all_coordinate_vector.begin();
        std::vector<std::string>::iterator it_end = ib.all_coordinate_vector.end();
        for (; it != it_end; ++it) {
            isline = *it;
            std::stringstream tmp;
            tmp << isline;
            
            MolD.xyz[j] = new double[3];
            for (int i=0; i< maxcol; i++) {
                std::string tmpstr;
                int tmpint;
                double tmpd;
                if(i==0) {
                    tmp >> tmpstr;
                    MolD.atom_type[j] = tmpstr;
                } else if(i>0 && i<4) {
                    tmp >> tmpd;
                    MolD.xyz[j][i-1] = tmpd;
                } else if(i==4) {
                    tmp >> tmpint;
                    MolD.fragment_index[j] = tmpint;
                } else if(i==5) {
                    tmp >> tmpstr;
                    MolD.atom_basis_set_name[j] = tmpstr;
                }
            }
            j++;
        }
        
        return MolD;
        
    }
}