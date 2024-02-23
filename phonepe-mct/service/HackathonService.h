//
// Created by ujjawalmishra on 14/12/23.
//

#ifndef PHONEPE_MCT_HACKATHONSERVICE_H
#define PHONEPE_MCT_HACKATHONSERVICE_H


#include "../model/Leaderboard.h"
#include "../repository/ProblemRepository.h"
#include "../repository/UserRepository.h"
#include "../scoring/ScoringStrategy.h"
#include <chrono>


class HackathonService {
public:
    HackathonService(ProblemRepository &problemRepository, UserRepository &userRepository, ScoringStrategy &scoringStrategy): problemRepository(problemRepository), userRepository(userRepository), scoringStrategy(scoringStrategy) {}
    std::vector<Problem> fetchSolvedProblems(UserID userID);
    std::vector<Problem> solveProblem(ProblemID problemID, UserID userID, std::chrono::milliseconds timeTaken);
    User getLeader();


private:
    Leaderboard leaderboard;
    ProblemRepository &problemRepository;
    UserRepository &userRepository;
    ScoringStrategy &scoringStrategy;
};


#endif //PHONEPE_MCT_HACKATHONSERVICE_H
