//
// Created by ujjawalmishra on 14/12/23.
//

#ifndef PHONEPE_MCT_SUBMISSION_H
#define PHONEPE_MCT_SUBMISSION_H


#include "ID.h"
#include <chrono>
#include <utility>

class Submission {
public:
    Submission(UserID userId, ProblemID problemId, std::chrono::milliseconds timeTaken) : userID(std::move(userId)),
                                                                                                    problemID(std::move(
                                                                                                            problemId)),
                                                                                                    timeTaken(
                                                                                                            timeTaken),
                                                                                                    score(0) {}
    UserID getUserId() const {
        return userID;
    }

    ProblemID getProblemId() const {
        return problemID;
    }

    std::chrono::milliseconds getTimeTaken() const {
        return timeTaken;
    }

    float getScore() const {
        return score;
    }

    void setScore(float score) {
        this->score = score;
    }


private:
    UserID userID;
    ProblemID problemID;
    std::chrono::milliseconds timeTaken;
    float score;
};


#endif //PHONEPE_MCT_SUBMISSION_H
