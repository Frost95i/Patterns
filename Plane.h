#pragma once

#include "DynamicObject.h"

class Plane : public DynamicObject {
public:

    void Draw() const override;
    void BeNotified(std::string msg) const override { };
    inline void ChangePlaneY(double dy) { yDirection += dy; }

private:

};

