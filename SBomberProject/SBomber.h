#pragma once
#include <memory>
#include "MyTools.h"

class SBomberImp;

class SBomber
{
public:

    SBomber(MyTools::ILogger& logger);

    bool GetExitFlag() const;
    void ProcessKBHit();
    void TimeStart();
    void TimeFinish();

    void DrawFrame();
    void MoveObjects();
    void CheckObjects();

private:
    SBomberImp* impl;
    MyTools::ILogger& logger;
};