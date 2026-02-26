#include <iostream>
#include <string>

using std::cout, std::endl, std::string;

namespace add_mode {
    int add(int a, int b){
        return a + b;
    }
    
    double add(double a, double b){
        return a + b;
    }
    
    string add(string a, string b){
        return a + b;
    }
    
    void run(int argc, char* argv[]){
        if (argc < 4){
            cout << "Requires two additional arguements" << endl;
            return;
        }
    
        string str1 = argv[2];
        string str2 = argv[3];
    
        bool all_digits1 = true;
        for (char c : str1) if (!std::isdigit(c)) { all_digits1 = false; break; }
        bool all_digits2 = true;
        for (char c : str2) if (!std::isdigit(c)) { all_digits2 = false; break; }
    
    
        string value;
    
        if (all_digits1 && all_digits2) {
            int result = add(std::stoi(str1), std::stoi(str2));
            value = std::to_string(result);
        }
        else if (str1.find('.') != std::string::npos || str2.find('.') != std::string::npos) {
            double result = add(std::stod(str1), std::stod(str2));
            value = std::to_string(result);
        }
        else {
            value = add(str1, str2);
        }
    
        std::cout << "Result: " << value << std::endl;
    }
}