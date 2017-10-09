#include "fontobene/fontobene.h"

#include <sstream>
#include <iostream>
#include <cassert>


int main() {
    // wrong input should return None
    {
        std::stringstream input{"foo"};
        auto font = fontobene::Parser::parse(input);
        assert(!font);
    }

    // correct input should return Some
    {
        std::stringstream input{"[format]"};
        auto font = fontobene::Parser::parse(input);
        assert(font);
    }
}

