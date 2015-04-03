//
//  core.h
//  aces-ansatz
//
//  Created by Jason Byrd on 3/19/15.
//  Copyright (c) 2015 Jason Byrd. All rights reserved.
//

#ifndef aces_ansatz_core_h
#define aces_ansatz_core_h


namespace aces{
    
    class GlobalSettings {
    public:
        
        static int get_max_column() { return max_col; }
        
        static int get_max_dump_length() { return max_dump_length; }
        
        static int get_starting_atom_count() { return starting_atom_count; }
        
        static void set_max_column(int s) { max_col = s; }
        
        static void set_max_dump_length(int s) { max_dump_length = s; }
        
        static void set_starting_atom_count(int s) { starting_atom_count = s; }
        
    private:
        static int max_col;
        static int max_dump_length;
        static int starting_atom_count;
    };
    
    extern char *aces_verno;

}
#endif
