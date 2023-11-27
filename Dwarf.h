#pragma once
#include "IRace.h"

class Dwarf : public IRace
{

public:
	Dwarf() : IRace(7, 8, 2)
	{
	}
    virtual ~Dwarf() {}
};
