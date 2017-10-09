#pragma once

#include <istream>
#include <unordered_map>
#include <optional>
#include <vector>
#include <string>
#include <utility>

namespace fontobene {

struct Point {
    double x;
    double y;
};

struct Polyline {
    Point start;
    Point end;
};

struct Header {
    std::string name;
    std::string id;
    std::string author;
    std::string version;
    std::string license;
    std::vector<std::pair<std::string, std::string> > user;

    Header() = default;
};

struct Font {
    Header header;
    std::unordered_map<char32_t, std::vector<Polyline>> char_map;

    Font() = default;
};

struct Parser {
    enum class State {
        Start,
        HeaderFormat,
        //HeaderFont,
        //HeaderUser,
    };

    static auto parse(std::istream& input) -> std::optional<Font> {
        State state = State::Start;
        for (std::string line; std::getline(input, line);) {
            if (line.size() < 1 || line[0] == '#') {
                continue;
            }

            switch (state) {
                case State::Start:
                    if (line == "[format]") {
                        state = State::HeaderFormat;
                    } else {
                        return {};
                    }
                    break;
                case State::HeaderFormat:
                    break;
            }
        }
        return std::make_optional(Font{});
    }
};

};
