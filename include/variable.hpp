#pragma once
#include <string>
#include <unordered_map>
#include <cstddef>
#include "variable_list.hpp"
#include "variable_list.hpp"

namespace shiny {
    template<typename return_type, typename key_type = std::string>
    class Variable : public Term<return_type, key_type> {
    private:
        key_type variable_m;

    public:
        using Term<return_type, key_type>::calculate;
        inline return_type calculate(VariableList<return_type, key_type>& variableList) {
            return variableList[variable_m];
        };
        inline void set(const key_type variable) {
            variable_m = variable;
        }
        inline key_type& get() {
            return variable_m;
        }
        inline key_type get() const {
            return variable_m;
        }

        Variable() : variable_m("") {};
        Variable(const Variable& variable) : variable_m(variable.variable_m) {};
        Variable(const key_type& key) : variable_m(key) {};
    };
};