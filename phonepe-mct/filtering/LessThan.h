//
// Created by ujjawalmishra on 14/12/23.
//

#ifndef PHONEPE_MCT_LESSTHAN_H
#define PHONEPE_MCT_LESSTHAN_H

#include "FunctionalFilter.h"

template<typename T, typename V>
class LessThan : public FunctionalFilter<T> {
public:
    LessThan(V(*valueExtractor)(const T &element), const V &value) : FunctionalFilter<T>(
            [value, valueExtractor](const T &element) { return valueExtractor(element) < value; }) {};
};


#endif //PHONEPE_MCT_LESSTHAN_H
