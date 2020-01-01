#ifndef __SOURCE_SOURCE_HPP__
#define __SOURCE_SOURCE_HPP__

namespace source {

    constexpr char END_OF_TEXT = '\3'; 

    class Source {
    public:
        virtual const char curr() const = 0;
        virtual const char peek() const = 0;
        virtual void bump() = 0;
    };
   
}

#endif