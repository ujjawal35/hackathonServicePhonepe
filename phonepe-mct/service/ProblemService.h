//
// Created by ujjawalmishra on 14/12/23.
//

#ifndef PHONEPE_MCT_PROBLEMSERVICE_H
#define PHONEPE_MCT_PROBLEMSERVICE_H


#include "../repository/ProblemRepository.h"

class ProblemService {
public:
    explicit ProblemService(ProblemRepository &problemRepository) : problemRepository(problemRepository) {}

    Problem addProblem(std::string description, const std::set<std::string> &tags, Problem::Difficulty difficulty, int score);

    template<typename Comparator>
    std::vector<Problem> fetchProblems(Filter<Problem> &filter, Comparator comparator) {
        return problemRepository.list(filter, comparator);
    }

private:
    ProblemID generateProblemID(std::string description);
    void validateCreateProblemParams();


    ProblemRepository &problemRepository;
};


#endif //PHONEPE_MCT_PROBLEMSERVICE_H
