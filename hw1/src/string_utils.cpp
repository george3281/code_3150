#include <iostream>
#include <string>
#include "string_utils.h"

namespace string_utils {

int runStringOption(){
    /*
    This is a multi-line comment
    that explains the function.
    */
    int length;
    std::cout << "Enter string length:" << std::endl;
    std::cin >> length;
    if (length >= 20){
        std::cout << "Error: string length must be less than 20" << std::endl;
        return 1;
    }
    std::cin.ignore();
    std::cout << "Enter string:" << std::endl;
    std::string input;
    std::getline(std::cin, input);
    char c_str[20];
    for (int i = 0; i < length; i++){
        c_str[i] = input[i];
    }
    c_str[length] = '\0';
    std::cout << "C-style string: " << c_str << std::endl;
    return 0;
}

}