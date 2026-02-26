#include <iostream>
#include <string>
#include "text_mode.h"
#include "add_mode.h"
#include "stats_mode.h"

using std::cout,std::endl,std::cin;

int main(int argc, char* argv[]){
    if (argc < 2){
        cout << "Usage: ./analyzer <mode> [arguments]" << endl;
        return 1;
    }

    std::string select = argv[1];
    int mode = 0;
    if (select == "text") mode = 1;
    else if (select == "add") mode = 2;
    else if (select == "stats") mode = 3;

    switch(mode) {
        case 1:
            text_mode::run(argc, argv);
            return 0;
        case 2:
            add_mode::run(argc, argv);
            return 0;
        case 3:
            stats_mode::run(argc, argv);
            return 0;
        default:
            cout << "Invalid mode" << endl;
            return 1;
    }
}