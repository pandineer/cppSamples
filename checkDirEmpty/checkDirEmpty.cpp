#include <iostream> // cout, endl
#include <dirent.h> // DIR, opendir, readdir, struct dirent
#include <string.h> // strcmp
#include <errno.h>  // errno
#include <stdlib.h> // exit

bool checkDirEmpty(std::string targetDir);

int main(void) {
  std::string emptyDirPath = "emptyDir";
  std::string noEmptyDirPath = "noEmptyDir";

  if (checkDirEmpty(emptyDirPath)) {
    std::cout << emptyDirPath << " is empty!" << std::endl;
  } else {
    std::cout << emptyDirPath << " is not empty." << std::endl;
  }

  if (checkDirEmpty(noEmptyDirPath)) {
    std::cout << noEmptyDirPath << " is empty!" << std::endl;
  } else {
    std::cout << noEmptyDirPath << " is not empty." << std::endl;
  }
  return 0;
}

/**
 * @brief Check a directory is empty or not
 * @param targetDir Directory path to be checked
 * @retval true targetDir is empty
 * @retval false targetDir is not empty
 */
bool checkDirEmpty(std::string targetDir) {
  // Open Directory
  DIR *pDir;
  pDir = opendir(targetDir.c_str());

  // Check opendir result
  if (NULL == pDir) {
    // opendir failed
    std::cout << "Can not open " << targetDir << std::endl;
    exit(-1);
  }

  // readdir
  struct dirent *pEnt;
  pEnt = readdir(pDir);

  // Check readdir result
  if (pEnt == NULL) {
    // readdir failed
    std::cout << "readdir failed, errno: " << errno << std::endl;
    exit(-1);
  }

  // Check directory content
  while(pEnt) {
    std::cout << "filename: " << pEnt->d_name << std::endl;
    // ignore "." and ".."
    if (strcmp(pEnt->d_name, ".") && strcmp(pEnt->d_name, "..")) {
      // if at least one file is found, return false
      closedir(pDir);
      return false;
    }
    // Read next content
    pEnt = readdir(pDir);
  }
  // if while loop is passed, the directory is empty
  closedir(pDir);
  return true;
}
