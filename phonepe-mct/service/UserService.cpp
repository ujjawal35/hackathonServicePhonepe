//
// Created by ujjawalmishra on 14/12/23.
//

#include <format>
#include "UserService.h"

User UserService::registerUser(const std::string& name, const std::string& department) {
    validateCreateUserRequest(name, department);
    auto id = generateUserID(name, department);
    User user(name, department, id);
    userRepository.add(user);
    return user;
}

void UserService::validateCreateUserRequest(std::string name, std::string department) {
    // TODO: implement
}

UserID UserService::generateUserID(std::string name, std::string department) {
    return UserID(std::format("{}/{}", department, name));
}
