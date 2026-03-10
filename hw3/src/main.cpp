#include <iostream>
#include <fstream>
#include <string>
#include "audit_mode.h"
#include "validation.h"

using std::cout, std::endl, std::string; 

int main(int argc, char* argv[]){
    if (argc == 3){        
        audit_mode::process_file(argv[1],argv[2]);
        return 0;
    }
    audit_mode::run_menu();
    return 0;
    
}