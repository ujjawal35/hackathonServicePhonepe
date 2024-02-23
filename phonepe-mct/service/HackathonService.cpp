//
// Created by ujjawalmishra on 14/12/23.
//

#include "HackathonService.h"
#include "../filtering/FunctionalFilter.h"
#include <chrono>

std::vector<Problem> HackathonService::fetchSolvedProblems(UserID userID) {
    std::function<bool(const Problem& problem)> f = [&userID](const Problem& problem){
        return problem.isSolvedBy(userID);
    };
    auto filter = FunctionalFilter(f);
    return problemRepository.list(filter);
}

std::vector<Problem> HackathonService::solveProblem(ProblemID problemID, UserID userID, std::chrono::milliseconds timeTaken) {
    Problem problem = problemRepository.get(problemID);
    User user = userRepository.get(userID);
    Submission submission(userID, problemID, timeTaken);
    scoringStrategy.scoreSubmission(problem, submission);

    problem.addSubmission(submission);
    problemRepository.update(problem);
    leaderboard.incorporateSubmission(submission);

    return std::vector<Problem>();
}

User HackathonService::getLeader() {
    return userRepository.get(leaderboard.getLeader());
}
