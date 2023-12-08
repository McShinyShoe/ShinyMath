#pragma once
#include <string>
#include <unordered_map>
#include <cstddef>
#include <memory>
#include "constanta.hpp"

namespace shiny {
    template<typename return_type, typename key_type = std::string>
    class Fraction : public Term<return_type, key_type> {
    private:
        std::shared_ptr<Term<return_type, key_type>> numerator_m;
        std::shared_ptr<Term<return_type, key_type>> denominator_m;

    public:
        using Term<return_type, key_type>::calculate;
        inline return_type calculate(const VariableList<return_type, key_type>& variableList) {
            return numerator_m->calculate(variableList) / denominator_m->calculate(variableList);
        };
        inline void setNumerator(const return_type& value) {
            numerator_m = std::static_pointer_cast<Term<return_type, key_type>>(std::make_shared<Constanta<return_type, key_type>>(Constanta<return_type, key_type>(value)));
        }
        inline void setDenominator(const return_type& value) {
            denominator_m = std::static_pointer_cast<Term<return_type, key_type>>(std::make_shared<Constanta<return_type, key_type>>(Constanta<return_type, key_type>(value)));
        }
        inline void setNumerator(Term<return_type, key_type>& value) {
            numerator_m = value.copy();
        }
        inline void setDenominator(Term<return_type, key_type>& value) {
            denominator_m = value.copy();
        }
        inline std::shared_ptr<Term<return_type, key_type>> getNumerator() const {
            return numerator_m->copy();
        }
        inline std::shared_ptr<Term<return_type, key_type>> getDenominator() const {
            return denominator_m->copy();
        }
        inline std::shared_ptr<Term<return_type, key_type>> copy() {;
            return std::static_pointer_cast<Term<return_type, key_type>>(std::make_shared<Fraction>(*this));
        }
    
        Fraction() : numerator_m(nullptr), denominator_m(nullptr) {};
        Fraction(const Fraction& fraction) : numerator_m(std::make_shared<Term<return_type, key_type>>(*fraction.numerator_m)), denominator_m(std::make_shared<Term<return_type, key_type>>(*fraction.denominator_m)) {};
    };
};