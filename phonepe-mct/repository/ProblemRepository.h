//
// Created by ujjawalmishra on 17/12/23.
//

#ifndef PHONEPE_MCT_PROBLEMREPOSITORY_H
#define PHONEPE_MCT_PROBLEMREPOSITORY_H


#include "../model/ID.h"
#include "Repository.h"
#include "../model/Problem.h"

class ProblemRepository: public Repository<ProblemID, Problem> {
public:
    std::string entityName() const override {
        return "Problem";
    }
};


#endif //PHONEPE_MCT_PROBLEMREPOSITORY_H
