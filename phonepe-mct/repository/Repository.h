//
// Created by ujjawalmishra on 14/12/23.
//

#ifndef PHONEPE_MCT_REPOSITORY_H
#define PHONEPE_MCT_REPOSITORY_H

#include <map>
#include <vector>
#include <format>
#include "../filtering/Filter.h"
#include "../exception/AlreadyExistsException.h"
#include "../exception/NotFoundException.h"


template<typename K, typename V>
class Repository {
public:
    void add(const V &value) {
        const K& key = value.getID();
        if(this->entities.contains(key)) {
            throw AlreadyExistsException(std::format("{} with id \"{}\" already exists", this->entityName(), std::string(key)));
        }
        this->entities.insert({key, value});
    }

    void update(const V &value) {
        const K& key = value.getID();
        auto it = this->entities.find(key);
        if(it==this->entities.end()) {
            throw NotFoundException(std::format("{} with id \"{}\" not found", this->entityName(), std::string(key)));
        }
        it->second = value;
    }

    V get(const K &key) {
        const auto &it = entities.find(key);
        if(it==entities.end()) {
            throw NotFoundException(std::format("{} with id \"{}\" was not found", this->entityName(), std::string(key)));
        }
        return it->second;
    }

    std::vector<V> list() {
        std::vector<V> res;
        for(auto &it : this->entities)
            res.push_back(it.second);
        return res;
    }

    std::vector<V> list(Filter<V> &filter) {
        std::vector<V> elements = this->list();
        filter.filter(elements);
        return elements;
    }

    template<typename Compare>
    std::vector<V> list(Filter<V> &filter, Compare comparator) {
        std::vector<V> elements = this->list(filter);
        std::sort(elements.begin(), elements.end(), comparator);
        return elements;
    }

    virtual std::string entityName() const = 0;

    virtual ~Repository()= default;

private:
    std::map<K, V> entities;
};

#endif //PHONEPE_MCT_REPOSITORY_H
