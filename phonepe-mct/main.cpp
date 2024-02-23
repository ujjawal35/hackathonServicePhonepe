#include <iostream>
#include <set>
#include "repository/UserRepository.h"
#include "service/UserService.h"
#include "repository/ProblemRepository.h"
#include "service/ProblemService.h"
#include "service/HackathonService.h"
#include "filtering/Equals.h"
#include "scoring/ConstantScoreStrategy.h"
#include "filtering/GreaterThan.h"
#include "filtering/AllOf.h"

template <class T>
std::ostream &operator<<(std::ostream &os, const std::vector<T> &v) {
    for (const auto &x : v) {
        os << '[' << x << "] ";
    }
    return os;
}

int main() {
    // ---------- Set Up ----------.
    UserRepository userRepo;
    UserService userService(userRepo);

    ProblemRepository problemRepo;
    ProblemService problemService(problemRepo);
    ConstantScoreStrategy scoringStrategy;

    HackathonService hackathonService(problemRepo, userRepo, scoringStrategy);


    // ---------- Seed initial data ----------.
    User u1 = userService.registerUser("ujjawal", "dep1");
    std::cout<<"Created User: "<<u1<<std::endl;
    User u2 = userService.registerUser("Heisenberg", "BreakingBad");
    std::cout<<"Created User: "<<u2<<std::endl;
    User u3 = userService.registerUser("Saul", "BreakingBad");
    std::cout<<"Created User: "<<u3<<std::endl;
    User u4 = userService.registerUser("AryaStark", "GOT");
    std::cout<<"Created User: "<<u4<<std::endl;
    //Creating the user again
//    User u5 = userService.registerUser("AryaStark", "GOT");
    // Created users, created problems.
    Problem p1 = problemService.addProblem("problem_1", {"dp"}, Problem::HARD, 100);
    std::cout<<"Created problem:"<<p1<<std::endl;
    Problem p2 = problemService.addProblem("problem_2", {"graph"}, Problem::EASY, 10);
    std::cout<<"Created problem:"<<p2<<std::endl;
    Problem p3 = problemService.addProblem("problem_3", {"list"}, Problem::EASY, 15);
    std::cout<<"Created problem:"<<p3<<std::endl;
    Problem p4 = problemService.addProblem("problem_4", {"array"}, Problem::MEDIUM, 50);
    Problem p6 = problemService.addProblem("problem_6", {"array"}, Problem::EASY, 50);
    std::cout<<"Created problem:"<<p4<<std::endl;
    Problem p5 = problemService.addProblem("problem_5", {"tree"}, Problem::HARD, 90);
    std::cout<<"Created problem:"<<p5<<std::endl;

    hackathonService.solveProblem(p4.getID(), u4.getID(), std::chrono::milliseconds(12091714));
    hackathonService.solveProblem(p4.getID(), u3.getID(), std::chrono::milliseconds(12091763));

    std::cout<<"fetchSolvedProblems:"<<hackathonService.fetchSolvedProblems(u4.getID())<<std::endl;

    // Given problem solved by and avg time taken to solve
//    std::cout<<std::endl<<std::endl<<"Problem solved by:"<<problemService.getProblem(p4.getID())<<std::endl;

    // ---------- Operations ----------.

    // Filtering example.
    auto f=Equals(User::getID, UserID("dep1/ujjawal"));
    std::cout<<userRepo.list(f)<<std::endl;

    auto f1=Equals(Problem::getID, p4.getID());
    std::cout<<std::endl<<"Hello"<<problemRepo.list(f1)<<std::endl;

    auto f2 = GreaterThan(Problem::getDifficulty, Problem::EASY);
    std::cout<<std::endl<<"Hello"<<problemService.fetchProblems(f2, Problem::Comparator::byDifficulty)<<std::endl;

    //Sorting by tag
    auto f3 = Equals(Problem::getTags, {"array"});
    std::cout<<std::endl<<"Hello"<<problemService.fetchProblems(f3, Problem::Comparator::byScore)<<std::endl;

    //AllOf filter example
    auto f4 = AllOf(f3, f2);
    std::cout<<std::endl<<"Hello"<<problemRepo.list(f4)<<std::endl;;

    // TODO: add documentation for all classes and functions.
    // TODO: document ideal world choices and tradeoffs made in this problem.
    // TODO: additional requirements coding, make return type of top solve() a struct whose field is recommended problems.
    // TODO: make top level functions' args part of a struct instead of sending around a long list of function args
    // TODO: Fill in validate functions in create user/problem flows.
}
