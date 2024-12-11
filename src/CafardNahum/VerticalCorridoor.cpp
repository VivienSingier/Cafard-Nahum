#include "pch.h"
#include "VerticalCorridoor.h"

VerticalCorridoor::VerticalCorridoor(float x, float y) : Corridoor::Corridoor(x, y)
{
	Init();
}

void VerticalCorridoor::Init()
{
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (j == 0 || j == 4)
			{
				AddWall(j, i);
			}
			else
			{
				AddFloor(j, i);
			}
		}
	}
}
