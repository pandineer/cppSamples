#include <iostream> // cout, endl
#include <cstdlib>  // atoi

// Convert string (char array) to integer
int main() {
  std::string string123("123"); // This is string

  // Convert string (char array) to integer using atoi
  if (std::atoi(string123.c_str()) == 123) {
    std::cout << "std::atoi(string123.c_str()) is 123(int)" << std::endl;
  } else {
    std::cout << "std::atoi(string123.c_str()) is not 123(int)" << std::endl;
  }

  // If string variable has no numeric value
  std::string str("str");
  std::cout << "atoi(str) = " << std::atoi(str.c_str()) << std::endl;
  return 0;
}
