//
// Created by ujjawalmishra on 17/12/23.
//

#ifndef PHONEPE_MCT_NOT_H
#define PHONEPE_MCT_NOT_H

#include "Filter.h"

template<typename T>
class Not : public Filter<T>{
public:
    explicit Not(const Filter<T>& f): f(f) {}

    bool matches(const T &element) const override {
        return !f.matches(element);
    }

private:
    const Filter<T>& f;
};


#endif //PHONEPE_MCT_NOT_H
