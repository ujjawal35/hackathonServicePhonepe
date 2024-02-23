//
// Created by ujjawalmishra on 14/12/23.
//

#ifndef PHONEPE_MCT_FUNCTIONALFILTER_H
#define PHONEPE_MCT_FUNCTIONALFILTER_H

#include "Filter.h"
#include <functional>

template<typename T>
class FunctionalFilter : public Filter<T>{
public:
    explicit FunctionalFilter(const std::function<bool(const T &)> &matcher) : matcher(matcher) {}

    bool matches(const T &element) const override {
        return matcher(element);
    };

private:
    std::function<bool(const T &element)> matcher;

};


#endif //PHONEPE_MCT_FUNCTIONALFILTER_H
