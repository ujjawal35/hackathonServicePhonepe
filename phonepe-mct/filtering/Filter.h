//
// Created by ujjawalmishra on 14/12/23.
//

#ifndef PHONEPE_MCT_FILTER_H
#define PHONEPE_MCT_FILTER_H

#include <vector>
#include <functional>

// Composite design pattern used
template<typename T>
class Filter {
public:
    virtual ~Filter() = default;

    virtual bool matches(const T &element) const = 0;

    virtual void filter(std::vector<T> &elements) const {
        elements.erase(std::remove_if(elements.begin(), elements.end(), [this](const T &element) { return !this->matches(element); }), elements.end());
    }
};

#endif //PHONEPE_MCT_FILTER_H
