//
//  update_keywords.cpp
//  aces-ansatz
//
//  Created by Jason Byrd on 4/2/15.
//  Copyright (c) 2015 Jason Byrd. All rights reserved.
//
/******************************************************************************/

#include "input_reader.h"
#include "molecule_data.h"
#include "asv.h"
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

namespace input {
    void keyword_handler(input_block ib) {
        std::cout << "Starting on keywords" << std::endl;
        
        asv::ioppar_flags f_flags;
        f_flags.ioppar = new int[asv::GlobalKeywords::get_max_ioppar()];
        
        // init in parser
        //f_flags = asv::init_keyword_flags();
        
        f_flags = asv::parse_keyword_flags(ib);
        
        //asv::asv_dump(f_flags);
        
    }
}