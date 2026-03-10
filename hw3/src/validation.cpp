#include <iostream>
#include <string>
#include <cctype>

using std::cout, std::endl, std::string;

namespace validation{
    bool is_valid(string password){
        if (password.size() < 8){
            return false;
        }
        bool non_alpha = false;
        bool has_upper = false;

        for (int i = 0; i < static_cast<int>(password.size()); i++){
            if (std::isupper(static_cast<unsigned char>(password[i])))
                has_upper = true;
            if (!std::isalnum(static_cast<unsigned char>(password[i])))
                non_alpha = true;
        }
        bool valid = (non_alpha && has_upper);
        return valid; 
    }
}
