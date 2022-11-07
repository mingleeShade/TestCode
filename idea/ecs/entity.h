/**
 * @file        entity.h
 * @date        Oct 14, 2022
 * @author      lihaiming
 * @maintainer  lihaiming
 * @brief       entity 基类，entity 是 component 的集合
*/
#pragma once

#include "component.h"

#include <cstdint>
#include <unordered_map>
#include <string>

class Entity {
public:
    Entity() = default;
    virtual ~Entity() = default;

protected:
    uint64_t id_ = 0;
    std::unordered_map<std::string, Component*> components_;
};
