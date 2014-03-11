#include <iostream>   // cout, endl
#include <sys/stat.h> // stat

int main(void) {
  struct stat statFile;
  struct stat statDirectory;
  struct stat statNothing;

  // if file/directory exists, stat() returns 0
  // if file/directory does not exist, stat() returns -1
  std::cout << stat("file", &statFile) << std::endl;
  std::cout << stat("directory", &statDirectory) << std::endl;
  std::cout << stat("nothing", &statNothing) << std::endl;

  return 0;
}
