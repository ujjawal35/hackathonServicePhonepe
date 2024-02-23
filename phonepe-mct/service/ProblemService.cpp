//
// Created by ujjawalmishra on 14/12/23.
//

#include "ProblemService.h"

#include <utility>


ProblemID ProblemService::generateProblemID(std::string desc) {
    return ProblemID(std::move(desc));
}

void ProblemService::validateCreateProblemParams() {

}

Problem ProblemService::addProblem(std::string description, const std::set<std::string> &tags,
                                   Problem::Difficulty difficulty, int score) {
    auto problem = Problem(description, tags, difficulty, generateProblemID(description), score);
    problemRepository.add(problem);
    return problem;
}
