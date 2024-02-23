//
// Created by ujjawalmishra on 14/12/23.
//

#ifndef PHONEPE_MCT_NOTFOUNDEXCEPTION_H
#define PHONEPE_MCT_NOTFOUNDEXCEPTION_H


#include <utility>
#include <string>

class NotFoundException : public std::exception {
public:
    explicit NotFoundException(std::string  message) : message_(std::move(message)) {}

    const char* what() const noexcept override { return message_.c_str(); }

private:
    std::string message_;
};


#endif //PHONEPE_MCT_NOTFOUNDEXCEPTION_H
