//
// Created by ujjawalmishra on 14/12/23.
//

#ifndef PHONEPE_MCT_USERSERVICE_H
#define PHONEPE_MCT_USERSERVICE_H


#include "../repository/UserRepository.h"

class UserService {
public:
    explicit UserService(UserRepository &userRepository) : userRepository(userRepository) {}

    User registerUser(const std::string& name, const std::string& department);
private:

    void validateCreateUserRequest(std::string name, std::string department);
    UserID generateUserID(std::string name, std::string department);

    UserRepository &userRepository;

};


#endif //PHONEPE_MCT_USERSERVICE_H
