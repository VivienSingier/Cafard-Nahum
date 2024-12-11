#include "pch.h"
#include "HorizontalCorridoor.h"

HorizontalCorridoor::HorizontalCorridoor(float x, float y) : Corridoor::Corridoor(x, y)
{
	Init();
}

void HorizontalCorridoor::Init()
{
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (j == 0 || j == 4)
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