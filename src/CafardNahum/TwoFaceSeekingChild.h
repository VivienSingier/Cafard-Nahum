#pragma once
#include "TwoFaceCross2.h"

class TwoFaceSeekingChild :
    public TwoFaceCross2
{
public:
    TwoFaceSeekingChild(float x, float y);
    void Update(float deltatime) override;
};

