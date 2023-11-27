#pragma once
#include "IRace.h"

class Halfling : public IRace
{

public:
	Halfling() : IRace(5, 3, 7)
	{
	}
    virtual ~Halfling() {}
};