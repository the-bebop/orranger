#include <hpp/reactor.hpp>

bool reactor::Reactor::update()
{
    printf("In Reactor's update\n");

    std::string proc_string = std::string("Working in Dummy Proc");
    printf("[Reactor] before processing '%s'\n", proc_string.c_str());
    printf(" %s\n", proc.workMyString(proc_string).c_str());

    return false;
}