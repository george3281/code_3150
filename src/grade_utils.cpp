#include <iostream>
#include "grade_utils.h"

namespace grade_utils {

double calculateGrade() {
    char type;
    double grade;
    std::cout << "Enter student type (u for undergrad, g for grad):" << std::endl;
    std::cin >> type;
    std::cout << "Enter numeric grade:" << std::endl;
    std::cin >> grade;
    //:::
    if (grade < 0 || grade > 100) {
        std::cout << "Invalid grade" << std::endl;
        return -1;
    }
    if (((type == 'u' || type == 'U') && grade >= 60) 
    || ((type == 'g' || type == 'G') && grade >= 70)) {
        std::cout << "Status: Pass" << std::endl;
    } else {
        std::cout << "Status: Fail" << std::endl;
    }
    
    return grade;
}

}