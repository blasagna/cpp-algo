#include <string>
#include <iostream>

int main(int argc, char** argv) {
  std::cout << "Which version of the C++ standard is being used?" << std::endl;
  #if defined(__cplusplus)
    std::cout << "C++ standard version is " << std::to_string(__cplusplus) << std::endl;
  #else
  std::cout << "Unknown, C++ standard is not defined" << std::endl;
  #endif
  std::cout << std::endl;
  
  std::cout << "When was this compiled?" << std::endl;
  #if defined(__DATE__)
    std::cout << "Date: " << __DATE__ << std::endl;
  #else
  std::cout << "Unknown, compilation date is not defined" << std::endl;
  #endif
  #if defined(__TIME__)
    std::cout << "Time: " << __TIME__ << std::endl;
  #else
  std::cout << "Unknown, compilation time is not defined" << std::endl;
  #endif
  std::cout << std::endl;

  return 0;
}