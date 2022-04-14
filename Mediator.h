#pragma once

#include "GameObject.h"


class GameObject;

class Mediator {
public:
	void AddGameObject(GameObject* pNewGO) {
		v.push_back(pNewGO);
	}

	void Notify(GameObject* pGO, std::string msg) {
		for (GameObject* pElem : v) {
			if (pElem != pGO)
			{
				pElem->BeNotified(msg);

			}
		}
	}

private:
	std::vector<GameObject*> v;
};