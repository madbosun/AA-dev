//
//  core.cpp
//  aces-ansatz
//
//  Created by Jason Byrd on 3/19/15.
//  Copyright (c) 2015 Jason Byrd. All rights reserved.
//

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

#include <execinfo.h>

void all_abort() {
    
    // Get backtrace
    
    std::cerr << "\nBacktrace:" << std::endl;
    void *array[10];
    size_t size;
    
    // get void*'s for all entries on the stack
    size = backtrace(array, 10);
    
    // print out all the frames to stderr
    backtrace_symbols_fd(array, size, STDERR_FILENO);

    //throw std::logic_error("logic error");
    exit(EXIT_FAILURE);

    fflush(stdout);
    fflush(stderr);
    
}