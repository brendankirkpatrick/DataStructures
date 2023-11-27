#pragma once
#include "IRace.h"

class Elf : public IRace
{

public:
	Elf() : IRace(4, 3, 8)
	{
	}
    virtual ~Elf() {}
};
