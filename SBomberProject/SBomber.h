#pragma once

#include <vector>

#include "LevelGUI.h"
#include "Plane.h"
#include "Bomb.h"
#include "Ground.h"
#include "Tank.h"



class SBomber
{
public:

    SBomber();
    ~SBomber();
    
    inline bool GetExitFlag() const { return exitFlag; }

    void ProcessKBHit();
    void TimeStart();
    void TimeFinish();

    void DrawFrame();
    void MoveObjects();
    void CheckObjects();



private:

    void CheckPlaneAndLevelGUI();
    void CheckBombsAndGround();
    void __fastcall CheckDestoyableObjects(Bomb* pBomb);

    //void __fastcall DeleteDynamicObj(DynamicObject * pBomb);
    //void __fastcall DeleteStaticObj(GameObject* pObj);

    Ground * FindGround() const;
	Plane* FindPlane() const {
		for (size_t i = 0; i < vecDynamicObj.size(); i++)
		{
			Plane* p = dynamic_cast<Plane*>(vecDynamicObj[i]);
			if (p != nullptr)
			{
				return p;
			}
		}

		return nullptr;
	};
    LevelGUI * FindLevelGUI() const;
    std::vector<DestroyableGroundObject*> FindDestoyableGroundObjects() const;
    std::vector<Bomb*> FindAllBombs() const;

    //void DropBomb();

    std::vector<DynamicObject*> vecDynamicObj;
    std::vector<GameObject*> vecStaticObj;
    
    bool exitFlag;

    uint64_t startTime, finishTime, passedTime;
    uint16_t bombsNumber, deltaTime, fps;
    int16_t score;

public:

	class Command
	{
	public:
		Command() { }
		virtual ~Command() {}
		virtual void Execute() = 0;

	};

	template <class Object>
	class DeleteCommand : public Command
	{
	public:
		DeleteCommand(std::vector<Object*>& vecObj) : m_vecObj(vecObj), m_pObj(nullptr) {}
		void setObj(Object* pObj)
		{
			m_pObj = pObj;
		}
		void Execute()
		{
			if (!m_pObj)
			{
				return;
			}

			auto it = m_vecObj.begin();
			for (; it != m_vecObj.end(); it++)
			{
				if (*it == m_pObj)
				{
					m_vecObj.erase(it);
					break;
				}
			}
		}
	private:
		std::vector<Object*>& m_vecObj;
		Object* m_pObj;
	};

	class DropCommand : public Command
	{
	public:
		DropCommand(std::vector<DynamicObject*>& vecDynamicObj) :  m_vecDynamicObj(vecDynamicObj), m_pPlane(nullptr), m_bombsNumber(nullptr), m_score(nullptr) {}
		void setParams(Plane* pPlane, uint16_t* bombsNumber, int16_t* score)
		{
			m_pPlane = pPlane;
			m_bombsNumber = bombsNumber;
			m_score = score;
		}
		void Execute()
		{
			
			if (*m_bombsNumber > 0)
			{
				
				//Logger.WriteToLog(string(__FUNCTION__) + " was invoked");

				//const Plane* pPlane = this->FindPlane();
				double x = m_pPlane->GetX() + 4;
				double y = m_pPlane->GetY() + 2;

				Bomb* pBomb = new Bomb;
				pBomb->SetDirection(0.3, 1);
				pBomb->SetSpeed(2);
				pBomb->SetPos(x, y);
				pBomb->SetWidth(SMALL_CRATER_SIZE);

				m_vecDynamicObj.push_back(pBomb);
				m_bombsNumber--;
				m_score -= Bomb::BombCost;
			}
		}

	private:
		std::vector<DynamicObject*>& m_vecDynamicObj;
		Plane* m_pPlane;
		uint16_t* m_bombsNumber;
		int16_t* m_score;
	};




};