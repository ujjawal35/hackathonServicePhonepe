//
// Created by ujjawalmishra on 14/12/23.
//

#ifndef PHONEPE_MCT_ALREADYEXISTSEXCEPTION_H
#define PHONEPE_MCT_ALREADYEXISTSEXCEPTION_H


#include <exception>
#include <string>
#include <utility>

class AlreadyExistsException : public std::exception {
public:
    explicit AlreadyExistsException(std::string  message) : message_(std::move(message)) {}

    const char* what() const noexcept override { return message_.c_str(); }

private:
    std::string message_;
};



#endif //PHONEPE_MCT_ALREADYEXISTSEXCEPTION_H
