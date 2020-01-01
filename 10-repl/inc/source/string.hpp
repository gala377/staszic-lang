#ifndef __SOURCE_FILE_HPP__
#define __SOURCE_FILE_HPP__

#include <iostream>

#include <source/source.hpp>

namespace source {

    class String: public Source {
    public:
        String(std::string raw);

        const char curr() const override;
        const char peek() const override;
        
        void bump() override;

    protected:
        std::uint32_t curr_index = 0;
        std::string raw;
    };
}

#endif