#include <source/string.hpp>


source::String::String(std::string raw): raw(std::move(raw)) {
    if(this->raw.size() == 0) {
        this->raw = {END_OF_TEXT};
    } else {
        this->raw += END_OF_TEXT;
    }
};

const char source::String::curr() const {
    return raw[curr_index];
}

const char source::String::peek() const {
    if(auto ch = curr(); ch == END_OF_TEXT) {
        return ch;
    }
    return raw[curr_index+1];
}

void source::String::bump() {
    if(curr_index == raw.size()-1) {
        return;
    }
    ++curr_index;
}