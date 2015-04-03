//
//  molecule_data.h
//  aces-ansatz
//
//  Created by Jason Byrd on 3/19/15.
//  Copyright (c) 2015 Jason Byrd. All rights reserved.
//

#ifndef aces_ansatz_molecule_data_h
#define aces_ansatz_molecule_data_h

#include <string>

namespace molecule {
    
    class GlobalMolecule {
        public:
        
        static int get_atom_count() { return atom_count; }
        
        static void set_atom_count(int s) { atom_count = s; }
        
        private:
        static int atom_count;
    };
    
    
    struct molecule_data {
//        std::string* atom_type = new std::string[molecule::atom_count];
//        double** xyz = new double*[molecule::atom_count];
//        int* fragment_index = new int[molecule::atom_count];
//        std::string* atom_basis_set_name = new std::string[molecule::atom_count];
        std::string* atom_type;
        double** xyz;
        int* fragment_index;
        std::string* atom_basis_set_name;
    };
    
}

#endif
