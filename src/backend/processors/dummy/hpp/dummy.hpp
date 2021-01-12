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