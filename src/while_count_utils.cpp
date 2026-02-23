#include <iostream>
#include "while_count_utils.h"

namespace while_count_utils {

void runWhileCount() {
  int num;
  std::cout << "Enter a number to count to:" << std::endl;
  std::cin >> num;
  while (num > 10) {
    std::cout << "I'm programmed to only count up to 10!" << std::endl;
    std::cout << "Enter a number to count to:" << std::endl;
    std::cin >> num;
  }
  int i = 1;

  while (i <= num) {
    if (i != 5) {
      std::cout << i << std::endl;
    }
    ++i;
  }
}

}
