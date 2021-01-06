#include <hpp/dummy.hpp>

int processors::DummyProc::workMyNum(int inputNum)
{
    return inputNum + inputNum;
}

std::string processors::DummyProc::workMyString(std::string inputString)
{
    printf("[DummyProc] input string '%s'\n", inputString);
    return inputString.append(" ADJUSTED");
}