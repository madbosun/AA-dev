//
//  global_state.cpp
//  aces-ansatz
//
//  Created by Jason Byrd on 3/19/15.
//  Copyright (c) 2015 Jason Byrd. All rights reserved.
//

#include "global_state.h"

namespace aces {
    
    int GlobalState::prog_num = -1;
    std::string GlobalState::prog_name = "";
    std::size_t GlobalState::max_data_memory_usage = 536870912; // Default 0.5GB
    
}