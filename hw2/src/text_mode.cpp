#include <iostream>
#include <string>

using std::cout,std::endl;

namespace text_mode {
    void run(int argc, char* argv[]){
        if (argc < 3){
            cout << "Requires a third arguement" << endl;
            return;
        }
    
        std::string str(argv[2]);
        cout << "Original: " << str << endl;
        
        size_t len = str.size();
        cout << "Length: " << len << endl;
    
        int letter_count = 0;
        int digit_count = 0;
        int space_count = 0;
        int punct_count = 0;
    
        for (char c:str){
            if (std::isalpha(c))
                letter_count++;
            if (std::isdigit(c))
                digit_count++;
            if (std::isspace(c))
                space_count++;
            if (std::ispunct(c))
                punct_count++;
        }
    
        cout << "Letters: " << letter_count << endl;
        cout << "Digits: " << digit_count << endl;
        cout << "Spaces: " << space_count << endl;
        cout << "Punctuation: " << punct_count << endl;
    
        std::string upper_copy = str;
    
        for (size_t i = 0; i < str.size(); ++i) {
            upper_copy[i] = std::toupper(str[i]);
            str[i] = std::tolower(str[i]);
        }
    
        cout << "Uppercase: " << upper_copy << endl;
        cout << "Lowercase: " << str << endl;
    
        cout << "Contains \"test\": " << (str.find("test") ? "No" : "yes") << endl;
    
        size_t space_pos = str.find(' ');
        if (space_pos != std::string::npos) {
            std::string first_word = str.substr(0, space_pos);
            cout << "First word: " << first_word << endl;
        }
    }
}