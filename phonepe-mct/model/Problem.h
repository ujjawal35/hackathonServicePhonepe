//
// Created by ujjawalmishra on 14/12/23.
//

#ifndef PHONEPE_MCT_PROBLEM_H
#define PHONEPE_MCT_PROBLEM_H


#include <set>
#include <string>
#include <utility>
#include <map>
#include <ostream>
#include "ID.h"
#include "Submission.h"
#include "../exception/AlreadyExistsException.h"

template <class T>
std::ostream &operator<<(std::ostream &os, const std::set<T> &v) {
    for (const auto &x : v) {
        os << '{' << x << ", ";
    }
    os<<'}';
    return os;
}

class Problem {
public:
    enum Difficulty {
        EASY, MEDIUM, HARD
    };

    class AggregateStats {
    public:
        int solvedBy = 0;
        std::chrono::milliseconds averageTimeToSolve{0};

        friend std::ostream &operator<<(std::ostream &os, const AggregateStats &stats) {
            os << "solvedBy: " << stats.solvedBy << " averageTimeToSolve: " << stats.averageTimeToSolve
               << " totalTimeToSolve: " << stats.totalTimeToSolve;
            return os;
        }

    private:
        std::chrono::milliseconds totalTimeToSolve{0};

        friend class Problem;
    };

    Problem(std::string description, const std::set<std::string> &tags, Difficulty difficulty, ProblemID id, int score)
            : description(std::move(description)), tags(tags), difficulty(difficulty), id(std::move(id)),
              score(score) {}

    std::string getDescription() const {
        return description;
    }

    const std::set<std::string> &getTags() const {
        return tags;
    }

    void addTag(const std::string &tag) {
        tags.insert(tag);
    }

    void ramoveTag(const std::string &tag) {
        tags.erase(tag);
    }

    Difficulty getDifficulty() const {
        return difficulty;
    }

    ProblemID getID() const {
        return id;
    }

    AggregateStats getAggregateStats() const {
        return aggregateStats;
    }

    int getScore() const {
        return score;
    }
//  because problem is domain object
    void addSubmission(const Submission &submission) {
        if (isSolvedBy(submission.getUserId())) {
            throw AlreadyExistsException(std::format("Problem {} has already been solved by user {}", std::string(id),
                                                     std::string(submission.getUserId())));
        }
        submissions.insert({submission.getUserId(), submission});
        aggregateStats.solvedBy++;
        aggregateStats.totalTimeToSolve += submission.getTimeTaken();
        aggregateStats.averageTimeToSolve = aggregateStats.totalTimeToSolve / aggregateStats.solvedBy;
    }

    bool isSolvedBy(UserID userID) const {
        return submissions.contains(userID);
    }

    static std::string getDescription(const Problem &p) {
        return p.getDescription();
    }

    static const std::set<std::string> &getTags(const Problem &p) {
        return p.getTags();
    }

    static Difficulty getDifficulty(const Problem &p) {
        return p.difficulty;
    }

    static ProblemID getID(const Problem &p) {
        return p.getID();
    }

    static AggregateStats getAggregateStats(const Problem &p) {
        return p.getAggregateStats();
    }

    static int getScore(const Problem &p) {
        return p.getScore();
    }

    class Comparator {
    public:
        static bool byScore(const Problem &p1, const Problem &p2) {
            return p1.score < p2.score;
        }

        static bool byDifficulty(const Problem &p1, const Problem &p2) {
            return p1.difficulty < p2.difficulty;
        }
    };

    friend std::ostream &operator<<(std::ostream &os, const Problem &problem) {
        os << "description: " << problem.description << " tags: " << problem.tags << " difficulty: "
           << problem.difficulty << " score: " << problem.score << " id: " << problem.id << " aggregateStats: "
           << problem.aggregateStats;
        return os;
    }

private:
    std::string description;
    std::set<std::string> tags;
    Difficulty difficulty;
    int score;
    ProblemID id;
    AggregateStats aggregateStats;
    std::map<UserID, Submission> submissions;
};


#endif //PHONEPE_MCT_PROBLEM_H
