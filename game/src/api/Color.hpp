
#pragma once

#include <optional>

namespace API {

    struct Color {
std::string toString() const;
void fromString(const std::string &str);
        std::optional<double> hue;
        std::optional<double> sat;
    };
}
