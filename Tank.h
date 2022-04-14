#pragma once

#include <stdint.h>

#include "DestroyableGroundObject.h"

class Tank : public DestroyableGroundObject
{
public:

	bool __fastcall isInside(double x1, double x2) const override;

	inline uint16_t GetScore() const override { return score; }

	void Draw() const override;
	void BeNotified(std::string msg) const override { };
	
	Mediator* pMed;

	void addMed(Mediator* medd) {
		pMed = medd;
	}

	void Send() {
		pMed->Notify(this, "Oh shit, it is the Plane");
	}
private:

	const uint16_t score = 30;
};

