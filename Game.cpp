#include "Factory.h"

#include <iostream>
#include <string>
#include <random>
#include <cmath>
#include "Cleric.h"

int main(){
    //letting player create their own character
    //player chooses race
    std::cout << "Welcome to the tournament!" << std::endl;
    std::cout << "See if you can survive till the end!" std::endl;
    std::cout << "Choose your race!" << std::endl;
    std::cout << "(e for elf, d for dwarf, h for human, m for halfling)" << std::endl;
    std::string racetype;
    Factory::raceOfTypeCharacter playerRace;
    std::cin >> racetype;
    std::cout << std::endl;

    if (racetype == "e"){
        racetype = "Elf";
        playerRace = Factory::raceOfTypeCharacter::eElf;
    } else if (racetype == "d"){
        racetype = "Dwarf";
        playerRace = Factory::raceOfTypeCharacter::eDwarf;
    } else if (racetype == "h"){
        racetype = "Human";
        playerRace = Factory::raceOfTypeCharacter::eHuman;
    } else if (racetype == "m"){
        racetype = "Halfling";
        playerRace = Factory::raceOfTypeCharacter::eHalfling;
    } 
    else {
        std::cout << "wrong input, please try again";
        return -1;
    }

    //player chooses class
    std::cout << "Choose your class!" << std::endl;
    std::cout << "(w for wizard, r for rogue, f for fighter, c for cleric)" << std::endl;
    std::string classtype;
    Factory::enumOfTypeCharacter playerClass;
    std::cin >> classtype;
    std::cout << std::endl;

    if (classtype == "w"){
        classtype = "Wizard";
        playerClass = Factory::enumOfTypeCharacter::eWizard;
    } else if (classtype == "r"){
        classtype = "Rogue";
        playerClass = Factory::enumOfTypeCharacter::eRogue;
    } else if (classtype == "f"){
        classtype = "Fighter";
        playerClass = Factory::enumOfTypeCharacter::eFighter;
    } else if (classtype == "c"){
        classtype = "Cleric";
        playerClass = Factory::enumOfTypeCharacter::eCleric;
    }else {
        std::cout << "wrong input, please try again";
        return -1;
    }

    for(int i = 1; i < 4; i++)
    {
        auto mainCharacter = Factory::GetFactory().CreateCharacter(playerClass, playerRace);
        //randomly generated enemy to fight in game
        //randomly generate 2 numbers from 1 to 3 to determine race and class of enemy
        std::random_device rand;  
        std::mt19937 gen(rand());  
        std::uniform_int_distribution<>dis(1, 4);  
        int racenum = dis(gen); 
        int classnum = dis(gen); 
        Factory::enumOfTypeCharacter enemyClass;
        Factory::raceOfTypeCharacter enemyRace;

        //build enemy character based on randomly generated numbers
        if (racenum == 1){
            racetype = "Elf";
            enemyRace = Factory::raceOfTypeCharacter::eElf;
        } else if (racenum == 2){
            racetype = "Dwarf";
            enemyRace = Factory::raceOfTypeCharacter::eDwarf;
        } else if (racenum == 3){
            racetype = "Human";
            enemyRace = Factory::raceOfTypeCharacter::eHuman;
        }
        else if (racenum == 4){
            racetype = "Halfling";
            enemyRace = Factory::raceOfTypeCharacter::eHalfling;
        } 

        if (classnum == 1){
            classtype = "Wizard";
            enemyClass = Factory::enumOfTypeCharacter::eWizard;
        } else if (classnum == 2){
            classtype = "Rogue";
            enemyClass = Factory::enumOfTypeCharacter::eRogue;
        } else if (classnum == 3){
            classtype = "Fighter";
            enemyClass = Factory::enumOfTypeCharacter::eFighter;
        }
        else if (classtype == "c"){
            classtype = "Cleric";
            playerClass = Factory::enumOfTypeCharacter::eCleric;
        }

        std::cout << "In round " << i << " you will be fighting a " << racetype << " " << classtype << "!" << std::endl;
        
        auto enemy = Factory::GetFactory().CreateCharacter(enemyClass, enemyRace);
        // NOW FIGHT
        while(enemy->getHitPoints() > 0 && mainCharacter->getHitPoints() > 0)
        {
            std::cout << "You have " << mainCharacter->getHitPoints() 
            << " hp and your opponent appears to have " << enemy->getHitPoints() << " hp." << std::endl;
            std::cout << "Do you want to attack (a) or heal (h) 3 hp? ::: ";
            std::string response;
            std::cin >> response;

            if(response == "a")
                enemy->subtractHP(ceil(mainCharacter->getDamage() / (0.5 * enemy->getArmor())));
            else if(response == "h")
                mainCharacter->subtractHP(-3); // really a heal
            else
            {
                std::cout << "Your input is not valid, try again." << std::endl;
                continue;
            }
            mainCharacter->subtractHP(ceil(enemy->getDamage() / (0.5 * mainCharacter->getArmor())));
        }
        if(enemy->getHitPoints() <= 0)
        {
            std::cout << "You won round " << i << "!" << std::endl;
        }
        else
        {
            std::cout << "You lost the round. \nYour death was embarassing and shameful.\nBetter luck in your next life" << std::endl;
            return 0;
        }
        std::cout << std::endl;
    }
    std::cout << "You won the tournament!\nYou get 100 gold as prize money." << std::endl;
}
