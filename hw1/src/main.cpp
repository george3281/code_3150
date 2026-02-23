#include <iostream>
#include "integer_utils.h"
#include "string_utils.h"
#include "grade_utils.h"
#include "while_count_utils.h"
#include "do_while_count_utils.h"

// g++ -o program.out src/*.cpp -I include

using std::cout, std::endl, std::cin;

int main() {
  int select;
  
  while (true) {
    cout << "1. Integer operations" << endl;
    cout << "2. Character arrays and C-style strings" << endl;
    cout << "3. Grade evaluation" << endl;
    cout << "4. While-loop counting" << endl;
    cout << "5. Do-while and range-based for counting" << endl;
    cout << "6. Quit" << endl;
    cin >> select;
    
    switch(select) {
      case 1: 
        integer_utils::runIntegerOption();
        break;
      case 2: 
        if (string_utils::runStringOption()) return 1;
        break;
      case 3: 
        if (grade_utils::calculateGrade() < 0) return 1;
        break;
      case 4: 
        while_count_utils::runWhileCount();
        break;
      case 5: 
        do_while_count_utils::runDoWhileCount();
        break;
      case 6:
        cout << "Goodbye!" << endl;
        return 0;
      default:
        break;  
    }
  }
}
