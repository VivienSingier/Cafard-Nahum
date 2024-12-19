#include "pch.h"
#include "HorizontalCorridoor.h"

HorizontalCorridoor::HorizontalCorridoor(float x, float y) : Corridoor::Corridoor(x, y)
{
	Init();
	width = 15 * 32;
	height = 18 * 32;
}

void HorizontalCorridoor::Init()
{
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			if (j == 0 || j == 6)
			{
				AddWall(i, j);
			}
			else
			{
				AddFloor(i, j);
			}
		}
	}
}