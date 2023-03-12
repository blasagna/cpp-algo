#include <string>
#include <iostream>
#include <version>
#include <bit>

#if defined(__cpp_lib_source_location)
#include <source_location>
#endif

int main(int argc, char **argv)
{
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

#if defined(__cpp_lib_source_location)
  auto location = std::source_location::current();
  std::cout < < < < "file: " << location.file_name() << ", line: " << location.line() << ", function: " << location.function_name() << std::endl;
#else
  std::cout << "source location is not defined" << std::endl;
#endif
  std::cout << std::endl;

#if defined(__cpp_lib_endian)
  std::cout << "endianness of scalar types: ";
  if constexpr (std::endian::native == std::endian::big) {
        std::cout << "big-endian";
  } else if constexpr (std::endian::native == std::endian::little) {
        std::cout << "little-endian";
  } else {
    std::cout << "mixed-endian";
  }
#else
  std::cout << "endianness is not defined" << std::endl;
#endif
  std::cout << std::endl;

  return 0;
}