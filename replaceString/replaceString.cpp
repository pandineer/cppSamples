#include <iostream> // cout, endl

std::string stringReplace(const std::string target,
			  const std::string from,
			  const std::string to);

// First command line argment is target string to replace
// Second command line argument is replaced to Third command line argument
int main(int argc, char *argv[]) {
  if (argc != 4) {
    std::cout << "Please specify 3 strings!" << std::endl;
    return -1;
  }
  std::string target = std::string(argv[1]);
  std::string from   = std::string(argv[2]);
  std::string to     = std::string(argv[3]);
  std::cout << stringReplace(target, from, to) << std::endl;
  return 0;
}

/**
 * @brief Replace substring of string
 *
 * @param[in] target Target string, substring of this is replaced
 * @param[in] from "from" is changed to "to".
 * @param[in] to "from" is changed to "to".
 * @return Replaced string
 */
std::string stringReplace(const std::string target,
			  const std::string from,
			  const std::string to) {
  std::string result = target;
  std::string::size_type pos = 0;
  while(pos = result.find(from, pos), pos != std::string::npos) {
    result.replace(pos, from.length(), to);
    pos += to.length();
  }
  return result;
}
