cmake_minimum_required(VERSION 3.27)
project(phonepe_mct)

set(CMAKE_CXX_STANDARD 23)

add_executable(phonepe_mct main.cpp
        model/ID.h
        repository/Repository.h
        model/Problem.h
        model/User.h
        repository/UserRepository.h
        service/HackathonService.cpp
        service/HackathonService.h
        exception/AlreadyExistsException.h
        service/UserService.cpp
        service/UserService.h
        service/ProblemService.cpp
        service/ProblemService.h
        filtering/Filter.h
        filtering/AllOf.h
        filtering/AnyOf.h
        filtering/FunctionalFilter.h
        filtering/LessThan.h
        filtering/GreaterThan.h
        filtering/Equals.h
        filtering/InBetween.h
        exception/NotFoundException.h
        model/Submission.h
        repository/ProblemRepository.h
        filtering/Not.h
        model/Leaderboard.h
        scoring/ScoringStrategy.h
        scoring/ConstantScoreStrategy.h)
