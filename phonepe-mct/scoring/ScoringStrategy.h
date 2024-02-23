//
// Created by ujjawalmishra on 18/12/23.
//

#ifndef PHONEPE_MCT_SCORINGSTRATEGY_H
#define PHONEPE_MCT_SCORINGSTRATEGY_H


#include "../model/Problem.h"

class ScoringStrategy {
public:
    virtual ~ScoringStrategy() = default;

    virtual void scoreSubmission(const Problem& problem, Submission& submission) = 0;
};


#endif //PHONEPE_MCT_SCORINGSTRATEGY_H
