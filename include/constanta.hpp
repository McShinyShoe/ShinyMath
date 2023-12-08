#pragma once
#include <string>
#include <unordered_map>
#include <cstddef>

namespace shiny {
    template<typename return_type, typename key_type = std::string>
    class Constanta : public Term<return_type, key_type> {
    private:
        return_type value_m;

    public:
        using Term<return_type, key_type>::calculate;
        inline return_type calculate(VariableList<return_type, key_type>& variableList) {
            return value_m;
        };
        inline void set(const return_type value) {
            value_m = value;
        }
        inline return_type& get() {
            return value_m;
        }
        inline return_type get() const {
            return value_m;
        }
    
        Constanta() : value_m(0) {};
        Constanta(const Constanta& constanta) : value_m(constanta.value_m) {};
        Constanta(const return_type& value) : value_m(value) {};
    };
};