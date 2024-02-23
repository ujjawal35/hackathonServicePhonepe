//
// Created by ujjawalmishra on 14/12/23.
//

#ifndef PHONEPE_MCT_USERREPOSITORY_H
#define PHONEPE_MCT_USERREPOSITORY_H


#include <map>
#include "../model/User.h"
#include "Repository.h"

class UserRepository : public Repository<UserID, User> {
public:
    std::string entityName() const override {
        return "User";
    }
};


#endif //PHONEPE_MCT_USERREPOSITORY_H
