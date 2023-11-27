#pragma once

#include <memory>
#include <map>

// including these because we want this class to know about our character so we
// can call the methods attached to it?
#include "ICharacter.h"

class IRace;

class Factory
{
public:
	enum enumOfTypeCharacter { eWizard, eRogue, eFighter, eCleric };
	enum raceOfTypeCharacter { eElf, eDwarf, eHuman, eHalfling };


	std::shared_ptr<ICharacter> CreateCharacter(enumOfTypeCharacter characterType, raceOfTypeCharacter raceType);

	static Factory & GetFactory();

  	Factory(const Factory &) = delete;
  	Factory & operator = (const Factory &) = delete;

private:
	std::map<raceOfTypeCharacter,std::shared_ptr<IRace>> m_raceMap;

	Factory() ;
    ~Factory() ;

};