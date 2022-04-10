
#include <iostream>

#include "House.h"
#include "MyTools.h"

using namespace std;
using namespace MyTools;

bool House::isInside(double x1, double x2) const
{
	const double XBeg = x + 2;
	const double XEnd = x + width - 1;
	

	if (x1 < XBeg && x2 > XEnd)
	{
		return true;
	}

	if (x1 > XBeg && x1 < XEnd)
	{
		return true;
	}

	if (x2 > XBeg && x2 < XEnd)
	{
		return true;
	}

	return false;
}

void House::Draw() const
{
	MyTools::SetColor(CC_Yellow);
	GotoXY(x, y - 6);
	for (size_t i = 0; i < 13; i++)
	{
		cout << look[0][i];
	}
	GotoXY(x, y - 5);
	for (size_t i = 0; i < 13; i++)
	{
		cout << look[1][i];
	}
	GotoXY(x, y - 4);
	for (size_t i = 0; i < 13; i++)
	{
		cout << look[2][i];
	}
	GotoXY(x, y - 3);
	for (size_t i = 0; i < 13; i++)
	{
		cout << look[3][i];
	}
	GotoXY(x, y - 2);
	for (size_t i = 0; i < 13; i++)
	{
		cout << look[4][i];
	}
	GotoXY(x, y - 1);
	for (size_t i = 0; i < 13; i++)
	{
		cout << look[5][i];
	}
	GotoXY(x, y);
	for (size_t i = 0; i < 13; i++)
	{
		cout << look[6][i];
	}
	//MyTools::SetColor(CC_Yellow);
	//GotoXY(x, y - 5);
	//cout << "  ########  ";
	//GotoXY(x, y - 4);
	//cout << "##        ##";
	//GotoXY(x, y - 3);
	//cout << "############";
	//GotoXY(x, y - 2);
	//cout << "#          #";
	//GotoXY(x, y - 1);
	//cout << "#          #";
	//GotoXY(x, y);
	//cout << "############";
}