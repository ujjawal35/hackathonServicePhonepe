//
// Created by ujjawalmishra on 14/12/23.
//

#ifndef PHONEPE_MCT_EQUALS_H
#define PHONEPE_MCT_EQUALS_H

#include "FunctionalFilter.h"

template<typename T, typename V>
class Equals : public FunctionalFilter<T> {
public:
    Equals(V(*valueExtractor)(const T &element), const V &value) : FunctionalFilter<T>(
            [value, valueExtractor](const T &element) {
                return valueExtractor(element) == value;
            }) {};
};


#endif //PHONEPE_MCT_EQUALS_H
