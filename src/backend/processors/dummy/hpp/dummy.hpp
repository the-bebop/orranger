#ifndef backend_processors_dummy_hpp
#define backend_processors_dummy_hpp

#include <string>

namespace processors {

class DummyProc {
private:
  int myNum;

public:
  std::string myString;

public:
  std::string workMyString(std::string inputString);
  int workMyNum(int inputNum);
};

} // namespace processors

#endif // backend_processors_dummy_hpp