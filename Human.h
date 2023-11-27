#pragma once
#include "IRace.h"

class Human  : public IRace
{

public:
	Human() : IRace(5, 5, 5)
	{
	}
    virtual ~Human() {}
};
