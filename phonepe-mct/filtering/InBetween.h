//
// Created by ujjawalmishra on 14/12/23.
//

#ifndef PHONEPE_MCT_INBETWEEN_H
#define PHONEPE_MCT_INBETWEEN_H


#include <functional>
#include "AllOf.h"

template<typename T, typename V>
class InBetween : public AllOf<T> {
public:
    InBetween(V(*valueExtractor)(const T &element), const V &lo, const V &hi) : AllOf<T>(
            LessThan(valueExtractor, hi), GreaterThan(valueExtractor, lo)) {};
};


#endif //PHONEPE_MCT_INBETWEEN_H
