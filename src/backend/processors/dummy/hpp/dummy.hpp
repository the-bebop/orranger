#include <string>

namespace processors 
{

class DummyProc {       // The class
    //Attributes
    private:             // Access specifier
        int myNum;        // Attribute (int variable)
    public:
        std::string myString;  // Attribute (string variable)

    //Methods
    public:
        std::string workMyString(std::string inputString);
        int workMyNum(int inputNum);
};

}