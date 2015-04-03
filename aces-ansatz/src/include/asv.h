//
//  asv.h
//  aces-ansatz
//
//  Created by Jason Byrd on 3/23/15.
//  Copyright (c) 2015 Jason Byrd. All rights reserved.
//

#ifndef aces_ansatz_asv_h
#define aces_ansatz_asv_h

#include "input_reader.h"
#include <string>

namespace asv {

    struct ASV_nl_t {
        std::string alias;  /* a plain string for whole key token matching */
        std::string oppar;  /* a key definition with a stub delimiter */
        int ichar;  /* a value type */
        int ideflt; /* the default value */
        std::string units;  /* value units (for printing) */
    };
    
    struct ioppar_flags {
        int* ioppar;
    };
    
    class GlobalKeywords {
    public:
        static int get_max_asv() { return 260; }
        static int get_max_ioppar() { return 600; }
    };

    asv::ioppar_flags init_keyword_flags();
    asv::ioppar_flags parse_keyword_flags(input::input_block);
    void asv_dump(asv::ioppar_flags);
    void asv_handle_proc(int, std::string, int);
    int asv_update_handle(int, std::string, const char*);
}


//

/* define type handles */

/*
#define h_ICHAR_handle		0
#define h_ICHAR_string		1
#define h_ICHAR_long		2
#define h_ICHAR_double		3
#define h_ICHAR_long_array	4
#define h_ICHAR_double_array	5



void init_flags();
void asv_dump();
*/

#endif
