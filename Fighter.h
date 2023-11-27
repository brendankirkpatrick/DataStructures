#include "ICharacter.h"
#include "IRace.h"
#include <memory>
#include <random>

class Fighter : public ICharacter
{
public:
	Fighter(std::shared_ptr<IRace> race) : ICharacter(race)
	{
        hp = 10;
        armor = 8;
        damage = 4;
	}

    int getArmor() override 
    {
        std::random_device rand;  
        std::mt19937 gen(rand());  
        std::uniform_int_distribution<>dis(1, 3); 

        int chance = dis(gen);

        if(chance == 1)
        {
            std::cout << "The Fighter found extra armor." << std::endl;
            return armor + m_race->getArmorClassMod() * 4;
        }
        else 
            return armor + m_race->getArmorClassMod();
    }

    ~Fighter() {}

    Fighter() = delete;

};