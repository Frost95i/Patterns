#pragma once

#include <vector>
#include <iostream>
#include "LevelGUI.h"
#include "Plane.h"
#include "Bomb.h"
#include "Ground.h"
#include "Tank.h"
#include "MyTools.h"

class SBomber
{
public:

    SBomber(MyTools::ILogger& logger);
    ~SBomber();
    
    inline bool GetExitFlag() const { return exitFlag; }
    friend class BombIterator;

    void ProcessKBHit();
    void TimeStart();
    void TimeFinish();

    void DrawFrame();
    void MoveObjects();
    void CheckObjects();

    DynamicObject* begin() {
        return *vecDynamicObj.begin();
   }

    DynamicObject* end() {
        return *vecDynamicObj.end();
    }


    class BombIterator {
        const std::vector<DynamicObject*>& VecDynObj;
        Bomb* Current;
        int curIndex;
        int* ptr;

    public:
        BombIterator(const std::vector<DynamicObject*>& vec) : VecDynObj(vec), curIndex(-1), ptr(nullptr)
        {
            ++(*this);
        }

        void reset() { curIndex = -1; ptr = nullptr; }

        BombIterator& operator++ () {
            curIndex++;
            if (curIndex == -1)
                curIndex = 0;
            for (; curIndex < VecDynObj.size(); curIndex++)
            {
                if (typeid(VecDynObj[curIndex]) == typeid(Current))
                {
                    //ptr = &vecDynObj[curIndex];
                    break;
                }
            }
            if (curIndex == VecDynObj.size())
            {
                curIndex = -1;
                ptr = nullptr;
            }
            return *this;
        }

        BombIterator& operator-- () // префексный декремент
        {
            if (curIndex == -1)
                curIndex = VecDynObj.size() - 1;
            for (; curIndex >= 0; curIndex--)
            {
                if (typeid(VecDynObj[curIndex]) == typeid(Bomb*))
                {
                    // ptr = &vecDynObj[curIndex];
                    break;
                }
            }
            if (curIndex == -1)
            {
                ptr = nullptr;
            }
            return *this;
        }

        Bomb* operator*() // операция разыменования итератора
        {

            //return VecDynObj.at(curIndex);
            return (Bomb*)(VecDynObj[curIndex]);
        }


        bool operator==(BombIterator it) // проверка на лог. равенство итераторов
        {
            if (curIndex == it.curIndex &&
                ptr == it.ptr &&
                VecDynObj == it.VecDynObj)
            {
                return true;
            }
            return false;
        }
        bool operator!=(BombIterator it) // проверка на лог. неравенство
        {
            return !(*this == it);
        }


        void myReset() {
            curIndex++;
            if (curIndex == -1)
                curIndex = 0;
            for (; curIndex < VecDynObj.size(); curIndex++)
            {
                if (typeid(VecDynObj[curIndex]) == typeid(Current))
                {
                    //ptr = &vecDynObj[curIndex];
                    continue;
                }
            }

        }
    

        // получаем итератор настроенный на начало массива
        BombIterator begin() { BombIterator it(VecDynObj); return it; }
        // итератор в конечном состоянии
        BombIterator end() { 
            BombIterator it(VecDynObj);
             
            it.myReset();

            return it; }
    };



private:

    void CheckPlaneAndLevelGUI();
    void CheckBombsAndGround();
    void __fastcall CheckDestoyableObjects(Bomb* pBomb);

    void __fastcall DeleteDynamicObj(DynamicObject * pBomb);
    void __fastcall DeleteStaticObj(GameObject* pObj);

    Ground * FindGround() const;
    Plane * FindPlane() const;
    LevelGUI * FindLevelGUI() const;
    std::vector<DestroyableGroundObject*> FindDestoyableGroundObjects() const;
    std::vector<Bomb*> FindAllBombs() const;

    void DropBomb();

    std::vector<DynamicObject*> vecDynamicObj;
    std::vector<GameObject*> vecStaticObj;
    
    bool exitFlag;

    uint64_t startTime, finishTime, passedTime;
    uint16_t bombsNumber, deltaTime, fps;
    int16_t score;
    MyTools::ILogger& logger;
};

