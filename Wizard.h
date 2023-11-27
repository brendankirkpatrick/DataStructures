#pragma once

#include "ICharacter.h"
#include "IRace.h"
#include <memory>
#include <random>

class Wizard : public ICharacter
{
public:
	Wizard(std::shared_ptr<IRace> race) : ICharacter(race)
	{
        hp = 7;
        armor = 2;
        damage = 10;
	}

    int getDamage() override
    {
        std::random_device rand;  
        std::mt19937 gen(rand());  
        std::uniform_int_distribution<>dis(1, 8); 

        int chance = dis(gen);

        if(chance == 1)
        {
            std::cout << "The Wizard attacked twice." << std::endl;
            return damage + m_race->getHitBonusMod() * 2;
        }
        else 
            return damage + m_race->getHitBonusMod();
    }

    int getArmor() override
    {
        std::random_device rand;  
        std::mt19937 gen(rand());  
        std::uniform_int_distribution<>dis(1, 8); 

        int chance = dis(gen);

        if(chance == 1)
        {
            std::cout << "The Wizard cast a defensive spell." << std::endl;
            return armor + m_race->getArmorClassMod() * 3;
        }
        else 
            return armor + m_race->getArmorClassMod();
    }

    ~Wizard() {}

    Wizard() = delete;

};