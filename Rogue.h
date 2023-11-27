#include "ICharacter.h"
#include "IRace.h"
#include <memory>
#include <random>

class Rogue : public ICharacter
{
public:
	Rogue(std::shared_ptr<IRace> race) : ICharacter(race)
	{
        hp = 5;
        armor = 5;
        damage = 10;
	}

    int getDamage() override
    {
        std::random_device rand;  
        std::mt19937 gen(rand());  
        std::uniform_int_distribution<>dis(1, 4); 

        int chance = dis(gen);

        if(chance == 1)
        {
            std::cout << "The Rogue critically hit." << std::endl;
            return damage + m_race->getHitBonusMod() * 2;
        }
        else 
            return damage + m_race->getHitBonusMod();
    }

    ~Rogue() {}

    Rogue() = delete;

};