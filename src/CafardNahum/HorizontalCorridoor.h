#pragma once
#include "Corridoor.h"

class HorizontalCorridoor : public Corridoor
{
public:
	HorizontalCorridoor(float x, float y);
	void Init() override;
};

