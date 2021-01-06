#ifndef backend_reactor_hpp_main
#define backend_reactor_hpp_main

#include <backend/processors/dummy/hpp/dummy.hpp>

namespace reactor{

class Reactor{
    private:
        processors::DummyProc proc;
    public:
        bool update();
};

}
#endif //backend_reactor_hpp_main