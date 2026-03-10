#include <iostream>
#include <fstream>
#include <string>
#include "audit_mode.h"
#include "validation.h"

using std::cout, std::endl, std::cin, std::string;

namespace audit_mode{
   void process_file(string input_p, string output_p){
       std::ifstream input(input_p);
       if (!input.is_open()) {
           cout << "Error opening file" << endl;
           return;
       }

       // Open output in append mode so existing contents are preserved.
       std::ofstream output(output_p, std::ios::app);
       if (!output.is_open()) {
           cout << "Error opening file" << endl;
           return;
       }

       char input_delim;
       char output_delim;

       // Non-.csv extensions default to tab delimiter.
       if (input_p.size() >= 4 && input_p.compare(input_p.size() - 4, 4, ".csv") == 0)
           input_delim = ',';
       else
           input_delim = '\t';

       if (output_p.size() >= 4 && output_p.compare(output_p.size() - 4, 4, ".csv") == 0)
           output_delim = ',';
       else
           output_delim = '\t';

       string user, email, password;
       while (std::getline(input, user, input_delim)) {
           if (!std::getline(input, email, input_delim))
               break;
           if (!std::getline(input, password))
               break;

           if (!validation::is_valid(password)) {
               output << user << output_delim << email << output_delim << password << "\n";
           }
       }
   }
   
   void run_menu(){
       while (true) {
           cout << "1. Check a single password" << endl;
           cout << "2. Process a TSV/CSV file" << endl;
           cout << "3. Quit" << endl;
           int select;
           if (!(cin >> select)) {
               return;
           }

           switch (select) {
               case 1: {
                   cout << "Enter password:" << endl;
                   string password;
                   std::getline(cin >> std::ws, password);
                   cout << (validation::is_valid(password) ? "Valid" : "Invalid") << endl;
                   break;
               }
               case 2: {
                   cout << "Enter input file path:" << endl;
                   string input_file;
                   cin >> input_file;

                   cout << "Enter output file path:" << endl;
                   string output_file;
                   cin >> output_file;
   
                   process_file(input_file, output_file);
                   break;
               }
               case 3:
                   return;
               default:
                   continue;
           }
       }
   }
}
