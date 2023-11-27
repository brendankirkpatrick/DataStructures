#include "Factory.h"

#include "IRace.h"
#include "ICharacter.h"

#include "Elf.h"
#include "Human.h"
#include "Dwarf.h"
#include "Halfling.h"
#include "Wizard.h"
#include "Rogue.h"
#include "Fighter.h"
#include "Cleric.h"

#include <memory>

Factory & Factory::GetFactory()
{
	static Factory s;
	return s;
} // instance

std::shared_ptr<ICharacter> Factory::CreateCharacter(enumOfTypeCharacter enumOfTypeCharacterType, raceOfTypeCharacter race)
{
	std::shared_ptr<ICharacter> retVal = nullptr;
	if (enumOfTypeCharacterType == eWizard)
	{
		retVal = std::make_shared<Wizard>(m_raceMap[race]);
	}
    else if (enumOfTypeCharacterType == eRogue)
    {
        retVal = std::make_shared<Rogue>(m_raceMap[race]); 
    }
    else if(enumOfTypeCharacterType == eFighter)
    {
        retVal = std::make_shared<Fighter>(m_raceMap[race]); 
    }
	else if(enumOfTypeCharacterType == eCleric)
    {
        retVal = std::make_shared<Cleric>(m_raceMap[race]); 
    }
	return retVal;
}

Factory::Factory() 
{
	std::shared_ptr<IRace> t1 = std::make_shared<Elf>();
	std::shared_ptr<IRace> t2 = std::make_shared<Dwarf>();
    std::shared_ptr<IRace> t3 = std::make_shared<Human>();
	std::shared_ptr<IRace> t4 = std::make_shared<Halfling>();
	m_raceMap.insert(std::pair(eElf, t1));
    m_raceMap.insert(std::pair(eDwarf, t2));
	m_raceMap.insert(std::pair(eHuman, t3));
	m_raceMap[eHalfling] = t4;
}


Factory::~Factory() 
{
	m_raceMap.clear();
}