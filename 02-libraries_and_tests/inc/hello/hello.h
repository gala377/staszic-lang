#ifndef __HELLO_HELLO_H__
#define __HELLO_HELLO_H__

#include <string>

namespace hello {

    static const char* EMPTY_NAME_MSG = "Who are you?";

    void greet(std::string const& name);
    std::string make_greeting(std::string const& name);

}

#endif