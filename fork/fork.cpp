#include <iostream> // cout, endl
#include <unistd.h> // getpid()
#include <stdlib.h> // exit()

int main(void) {
  std::cout << "(First) Process ID is " << getpid() << std::endl;
  
  // Create child process
  int forkReturnValue = fork();

  if (forkReturnValue == 0) {
    // Child process receives 0 as a return value of fork()
    std::cout << "Created process ID is " << getpid() << std::endl;
    std::cout << "Parent process ID of created process is " << getppid() << std::endl;
    exit(0);
  }

  // Parent process receives child process ID as a return value of fork()
  std::cout << "Child process ID is " << forkReturnValue << std::endl;
  // Of course. process id is not changed from first getpid()
  std::cout << "(Second) Process ID is " << getpid() << std::endl;
  
  return 0;
}
