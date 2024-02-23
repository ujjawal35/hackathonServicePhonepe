//
// Created by ujjawalmishra on 14/12/23.
//

#ifndef PHONEPE_MCT_LEADERBOARD_H
#define PHONEPE_MCT_LEADERBOARD_H


#include <map>
#include "ID.h"
#include "Submission.h"

class Leaderboard {
public:

    UserID getLeader() const {
        if(scores.empty()) {
            throw std::runtime_error("cannot compute rankings as no submissions have been made yet");
        }
        std::vector<std::pair<float, UserID>> res(scores.size());
        for(auto &it : scores)
            res.emplace_back(it.second, it.first);
        std::sort(res.begin(), res.end());
        return res.rbegin()->second;
    }

    void incorporateSubmission(const Submission &submission) {
        scores[submission.getUserId()]+=submission.getScore();
    }



private:
    std::map<UserID, float> scores;
};


#endif //PHONEPE_MCT_LEADERBOARD_H
