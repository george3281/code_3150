#include <iostream>
#include <string>

using std::cout, std::endl, std::string;

namespace stats_mode {
    void run(int argc, char* argv[]){
        if (argc < 3){
            cout << "Requires one additional argument" << endl;
            return;
        }
    
        string str(argv[2]);
    
        std::size_t len = str.size();
        cout << "Total length: " << len << endl;
    
        std::string seen;
        int count = 0;
        for (char c : str) {
            if (seen.find(c) == std::string::npos) {
                seen += c;
                count++;
            }
        }
    
        cout << "Unique: " << count << endl;
    
        bool alpha_only = true;
        for (char c : str){
            if (!std::isalnum(c))
                alpha_only = false;
        }
        cout << "Alphanumeric: " << (alpha_only ? "Yes" : "No") << endl;
    
        string reversed_str = str;
        size_t n = reversed_str.size();
        for (int i = 0; i < n / 2; i++){
            char temp = reversed_str[i];
            reversed_str[i] = reversed_str[n - 1 - i];
            reversed_str[n - 1 - i] = temp;
        }
        cout << "Reversed: " << reversed_str << endl;
    
        std::string no_spaces;
        for (char c : str) {
            if (c != ' ') {
                no_spaces += c;
            }
        }
        std::cout << "Without spaces: " << no_spaces << std::endl;
    
        std::string is_pal;
        for (char c : no_spaces) {
            is_pal += static_cast<char>(std::tolower(c));
        }
        bool palindrome = true;
        size_t plen = is_pal.size();
        for (size_t i = 0; i < plen / 2; i++) {
            if (is_pal[i] != is_pal[plen - 1 - i]) {
                palindrome = false;
                break;
            }
        }
        cout << "Palindrome: " << (palindrome ? "Yes" : "No") << std::endl;
    
    }
}
