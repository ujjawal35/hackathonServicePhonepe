//
// Created by ujjawalmishra on 14/12/23.
//

#ifndef PHONEPE_MCT_ANYOF_H
#define PHONEPE_MCT_ANYOF_H


#include <vector>
#include "Filter.h"

template<typename T>
class AnyOf : public Filter<T> {
public:
    AnyOf(const Filter<T>& f1, const Filter<T>& f2, std::vector<Filter<T>*> fs={}) {
        clauses=fs;
        clauses.push_back(&f1);
        clauses.push_back(&f2);
    }

    bool matches(const T& element) const override {
        for(const auto &f:clauses) {
            if(f(element))
                return true;
        }
        return false;
    }

private:
    std::vector<const Filter<T>&> clauses;
};


#endif //PHONEPE_MCT_ANYOF_H
