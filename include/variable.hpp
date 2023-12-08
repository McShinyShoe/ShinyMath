#pragma once
#include <string>
#include <unordered_map>
#include <cstddef>
#include "variable_list.hpp"
#include "variable_list.hpp"
#include <memory>

namespace shiny {
    template<typename return_type, typename key_type = std::string>
    class Variable : public Term<return_type, key_type> {
    private:
        key_type variable_m;

    public:
        using Term<return_type, key_type>::calculate;
        inline return_type calculate(const VariableList<return_type, key_type>& variableList) {
            return variableList.at(variable_m);
        };
        inline void set(const key_type variable) {
            variable_m = variable;
        }
        inline key_type get() const {
            return variable_m;
        }
        inline std::shared_ptr<Term<return_type, key_type>> copy() const {;
            return std::static_pointer_cast<Term<return_type, key_type>>(std::make_shared<Variable>(*this));
        }

        Variable() : variable_m("") {};
        Variable(const Variable& variable) : variable_m(variable.variable_m) {};
        Variable(const key_type& key) : variable_m(key) {};
    };
};