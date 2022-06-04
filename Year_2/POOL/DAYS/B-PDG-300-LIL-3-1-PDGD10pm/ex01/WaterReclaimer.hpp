#pragma once

#include <cstddef>
#include "BaseComponent.hpp"

class WaterReclaimer : public BaseComponent
{
public:
    WaterReclaimer();
    virtual ~WaterReclaimer() {}

    void start(void);
    void generateWater(void);
    void useWater(int water);
    int getWater(void);
    bool getStarted(void);

private:
    int _water;
    bool _started;
};
