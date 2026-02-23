#include <iostream>
#include "do_while_count_utils.h"

namespace do_while_count_utils {

void runDoWhileCount() {
  int val;
  do {
    std::cout << "Enter a number between 1 and 5:" << std::endl;
    std::cin >> val;
  } 
  while (val < 1 || val > 5);

  int vals[5] = {1,2,3,4,5};
  
  for (int num : vals) {
    std::cout << "Value: " << num << std::endl;
    if (num == val) {
      break;
    }
  }
}

}
