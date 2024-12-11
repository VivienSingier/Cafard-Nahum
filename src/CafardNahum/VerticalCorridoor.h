#pragma once
#include "Corridoor.h"

class VerticalCorridoor : public Corridoor
{
public:
	VerticalCorridoor(float x, float y);
	void Init() override;
};

