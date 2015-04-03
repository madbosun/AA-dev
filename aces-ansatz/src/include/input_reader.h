//
//  input_reader.h
//  aces-ansatz
//
//  Created by Jason Byrd on 3/19/15.
//  Copyright (c) 2015 Jason Byrd. All rights reserved.
//

#include "molecule_data.h"
#include <string>
#include <vector>

#ifndef __aces_ansatz__input_reader__
#define __aces_ansatz__input_reader__

namespace input {
    
    struct input_block {
        std::vector<std::string> all_coordinate_vector;
        std::vector<std::string> all_keyword_string_vector;
    };

    void reader(std::string, std::string);
    
    input_block parse_file(std::string);
    
    void count_atom(std::string);
    
    std::string comment_removed_line(std::string);

    void dump_file_string(int, std::string);
    
    molecule::molecule_data store_cartesian_data(input_block);
    
    void keyword_handler(input_block);

}

#endif /* defined(__aces_ansatz__input_reader__) */
