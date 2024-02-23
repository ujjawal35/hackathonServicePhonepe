//
// Created by ujjawalmishra on 14/12/23.
//

#ifndef PHONEPE_MCT_GREATERTHAN_H
#define PHONEPE_MCT_GREATERTHAN_H


#include <functional>
#include "FunctionalFilter.h"

template<typename T, typename V>
class GreaterThan : public FunctionalFilter<T> {
public:
    GreaterThan(V(*valueExtractor)(const T &element), const V &value) : FunctionalFilter<T>(
            [value, valueExtractor](const T &element) { return valueExtractor(element) > value; }) {};
};


#endif //PHONEPE_MCT_GREATERTHAN_H
