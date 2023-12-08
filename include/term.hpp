#pragma once
#include <string>
#include "variable_list.hpp"

namespace shiny {
    template<typename return_type, typename key_type = std::string>
    class Term {
    public:
        inline return_type calculate() {
            return this->calculate({});
        };
        inline virtual return_type calculate(const VariableList<return_type, key_type>& variableList) {
            return 0;
        };
    };
};