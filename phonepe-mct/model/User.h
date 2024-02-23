//
// Created by ujjawalmishra on 14/12/23.
//

#ifndef PHONEPE_MCT_USER_H
#define PHONEPE_MCT_USER_H


#include <string>
#include <utility>
#include <ostream>
#include "ID.h"

class User {
public:

    User(std::string name, std::string department, UserID id): name(std::move(name)), department(std::move(department)), id(std::move(id)) {};

    std::string getName() const {
        return name;
    }

    std::string getDepartment() const {
        return department;
    }

    UserID getID() const {
        return id;
    }

    static UserID getID(const User &u) {
        return u.getID();
    }

    friend std::ostream &operator<<(std::ostream &os, const User &user) {
        os << "id: " << user.id << " name: " << user.name << " department: " << user.department;
        return os;
    }

private:
    std::string name, department;
    UserID id;
};


#endif //PHONEPE_MCT_USER_H
