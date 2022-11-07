/**
 * @file        system.h
 * @date        Oct 14, 2022
 * @author      lihaiming
 * @maintainer  lihaiming
 * @brief       system 基类，管理组件，利用组件实现行为，只有行为，没有状态
*/
#pragma once

class System {
public:
    System() = default;
    virtual ~System() = default;

    virtual void Update();

private:
};
