//
// Created by ujjawalmishra on 14/12/23.
//

#ifndef PHONEPE_MCT_ALLOF_H
#define PHONEPE_MCT_ALLOF_H


#include <vector>
#include "Filter.h"

template<typename T>
class AllOf : public Filter<T> {
public:
    AllOf(Filter<T> &f1,  Filter<T> &f2, std::vector<Filter<T>*> fs={}) {
        clauses=fs;
        clauses.push_back(&f1);
        clauses.push_back(&f2);
    }

    bool matches(const T& element) const override {
        for(const auto &f:clauses) {
            if(!f->matches(element))
                return false;
        }
        return true;
    }

private:
    std::vector<Filter<T>*> clauses;
};


#endif //PHONEPE_MCT_ALLOF_H