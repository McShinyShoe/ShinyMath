#pragma once
#include <string>
#include <unordered_map>
#include <cstddef>

namespace shiny {
    template<typename return_type, typename key_type = std::string>
    class VariableList : public std::unordered_map<key_type, return_type> {};
};