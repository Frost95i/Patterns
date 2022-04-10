#pragma once

#include <stdint.h>

#include "DestroyableGroundObject.h"

class House : public DestroyableGroundObject
{
public:

	bool __fastcall isInside(double x1, double x2) const override;

	inline uint16_t GetScore() const override { return score; }

	void Draw() const override;

	virtual void looker(char ch[7][14]) {
		for (size_t i = 0; i < 6; i++)
		{
			for (size_t j = 0; j < 13; j++)
			{
				look[i][j] = ch[i][j];
			}
		}
	}

protected:
	char look[7][14] ;
private:
	const uint16_t score = 40;
};

class HouseBuilder {
	
	char look[7][14] ;
	int mod;
public:
	HouseBuilder() {
	}
	//House* h = new House;
	virtual void buildHouseA() {	}
	virtual void buildHouseB() {}
	virtual House* buildHouse() { return h; }

};



class HouseBuilderA : public HouseBuilder {
	
public:
	House* h = new House;
	char look[7][14] = {
	 ' ',' ','=','=','=','=','=','=','=','=','=',' ',' ',' ',
	 ' ','=',' ',' ',' ',' ',' ',' ',' ',' ',' ','=',' ',' ',
	 '=','=','=','=','=','=','=','=','=','=','=','=','=',' ',
	 '=','=',' ',' ','=','=','=','=',' ',' ',' ','=','=',' ',
	 '=','=',' ',' ','|',' ',' ','|',' ',' ',' ','=','=',' ',
	 '=','=',' ',' ','=','=','=','=',' ',' ',' ','=','=',' ',
	 '=','=','=','=','=','=','=','=','=','=','=','=','=',' '
	};;
	HouseBuilderA() {	};
	void buildHouseA() {
		h->looker(look);
	}
	House* buildHouse() { return h; }
	~HouseBuilderA() {}
};

class HouseBuilderB : public HouseBuilder {

public:
	House pHouse;
	char look[7][14] = {
	 '0','0','=','=','=','=','=','=','=','=','=','0','0','0',
	 '0','=',' ',' ',' ',' ',' ',' ',' ',' ',' ','=',' ','0',
	 '=','=','=','=','=','=','=','=','=','=','=','=','=',' ',
	 '=','=',' ',' ','=','=','=','=',' ',' ',' ','=','=',' ',
	 '=','=',' ',' ','|','-','-','|',' ',' ',' ','=','=',' ',
	 '=','=',' ',' ','=','=','=','=',' ',' ',' ','=','=',' ',
	 '=','=','=','=','=','=','=','=','=','=','=','=','=',' '
	};;
	HouseBuilderB() {
		h->looker(look);
	};
	~HouseBuilderB() {}
};