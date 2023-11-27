#include "ICharacter.h"
#include "IRace.h"
#include <memory>
#include <random>
#include <iostream>

class Cleric : public ICharacter
{
public:
	Cleric(std::shared_ptr<IRace> race) : ICharacter(race)
	{
        hp = 15;
        armor = 4;
        damage = 2;
	}

    void subtractHP(int health) override
    {
        std::random_device rand;  
        std::mt19937 gen(rand());  
        std::uniform_int_distribution<>dis(1, 6); 

        int chance = dis(gen);

        if(chance == 1)
        {
            std::cout << "The Cleric healed." << std::endl;
            hp -= health;
            hp += 3;
        }
        else 
            hp -= health;
    }

    ~Cleric() {}

    Cleric() = delete;

};