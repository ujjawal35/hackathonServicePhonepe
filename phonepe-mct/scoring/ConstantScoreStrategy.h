//
// Created by ujjawalmishra on 18/12/23.
//

#ifndef PHONEPE_MCT_CONSTANTSCORESTRATEGY_H
#define PHONEPE_MCT_CONSTANTSCORESTRATEGY_H


#include "../model/Submission.h"
#include "../model/Problem.h"
#include "ScoringStrategy.h"
//To add other strategies for scoring as per strategy design pattern
class ConstantScoreStrategy : public ScoringStrategy{
public:
    void scoreSubmission(const Problem& problem, Submission& submission) override {
        submission.setScore(problem.getScore());
    }
};


#endif //PHONEPE_MCT_CONSTANTSCORESTRATEGY_H
