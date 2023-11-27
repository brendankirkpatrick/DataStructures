#pragma once

#include "IRace.h"
#include <memory>
#include <random>
#include <iostream>

class ICharacter
{
public:

    ICharacter(std::shared_ptr<IRace> race) : 
    hp(race->getHitPointMod()), 
    armor(race->getArmorClassMod()), 
    damage(race->getHitBonusMod()), m_race(race)
    {
    }

    virtual void subtractHP(int health)
    {
        hp -= health;
    }

    virtual int getHitPoints() 
    {
        int retVal = hp + m_race->getHitPointMod();
        return retVal;
    }

    virtual int getArmor() 
    {
        int retVal = armor + m_race->getArmorClassMod();
        return retVal;
    }

    virtual int getDamage() 
    {
        int retVal = damage + m_race->getHitBonusMod();
        return retVal;
    }

    virtual ~ICharacter() {}

protected:
	int hp;
	int armor;
	int damage;
	std::shared_ptr<IRace> m_race;

};