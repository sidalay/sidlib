#ifndef SIDLIB_FORMAT_HPP
#define SIDLIB_FORMAT_HPP

#include <string_view>
#include <string>
#include <sstream>

namespace sidlib 
{
    template <typename... args_t>
    std::string format(std::string_view string, args_t...args) {
        std::ostringstream oss;
        ([&string, &oss, &args] () {
            size_t open_bracket{string.find('{')};
            if (open_bracket == std::string::npos) {return;}
            size_t close_bracket{string.find('}', open_bracket + 1)};
            if (close_bracket == std::string::npos) {return;}
            oss << string.substr(0, open_bracket) << args;
            string = string.substr(close_bracket + 1);
        }(),...);
        oss << string;
        return oss.str();
    }
}

#endif // SIDLIB_FORMAT_HPP