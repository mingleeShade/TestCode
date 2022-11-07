/**
 * @file        component.h
 * @date        Oct 14, 2022
 * @author      lihaiming
 * @maintainer  lihaiming
 * @brief       component 基类，component 是属性和状态的集合，无行为
*/
#pragma once

#include <cstdint>
class Component {
public:
    Component() = default;
    virtual ~Component() = default;

protected:
    int64_t owner_id_ = 0;
};
