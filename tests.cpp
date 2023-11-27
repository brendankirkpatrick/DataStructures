#include <gtest/gtest.h>
#include "Factory.h"

TEST(Factory, CreateWizard1)
{
    auto race = Factory::raceOfTypeCharacter::eElf;
    auto charac = Factory::enumOfTypeCharacter::eWizard;
    auto character = Factory::GetFactory().CreateCharacter(charac, race);
    ASSERT_EQ(character->getHitPoints(), 11);
}

TEST(Factory, CreateWizard2)
{
    auto race = Factory::raceOfTypeCharacter::eHuman;
    auto charac = Factory::enumOfTypeCharacter::eWizard;
    auto character = Factory::GetFactory().CreateCharacter(charac, race);
    ASSERT_EQ(character->getHitPoints(), 12);
}

TEST(Factory, CreateRogue1)
{
    auto race = Factory::raceOfTypeCharacter::eElf;
    auto charac = Factory::enumOfTypeCharacter::eRogue;
    auto character = Factory::GetFactory().CreateCharacter(charac, race);
    ASSERT_EQ(character->getHitPoints(), 9);
    ASSERT_EQ(character->getArmor(), 8);
}

TEST(Factory, CreateRogue2)
{
    auto race = Factory::raceOfTypeCharacter::eHuman;
    auto charac = Factory::enumOfTypeCharacter::eRogue;
    auto character = Factory::GetFactory().CreateCharacter(charac, race);
    ASSERT_EQ(character->getHitPoints(), 10);
    ASSERT_EQ(character->getArmor(), 10);
}

TEST(Factory, CreateFighter1)
{
    auto race = Factory::raceOfTypeCharacter::eElf;
    auto charac = Factory::enumOfTypeCharacter::eFighter;
    auto character = Factory::GetFactory().CreateCharacter(charac, race);
    ASSERT_EQ(character->getHitPoints(), 14);
    ASSERT_EQ(character->getDamage(), 12);
}

TEST(Factory, CreateFighter2)
{
    auto race = Factory::raceOfTypeCharacter::eHuman;
    auto charac = Factory::enumOfTypeCharacter::eFighter;
    auto character = Factory::GetFactory().CreateCharacter(charac, race);
    ASSERT_EQ(character->getHitPoints(), 15);
    ASSERT_EQ(character->getDamage(), 9);
}

TEST(Factory, CreateCleric1)
{
    auto race = Factory::raceOfTypeCharacter::eElf;
    auto charac = Factory::enumOfTypeCharacter::eCleric;
    auto character = Factory::GetFactory().CreateCharacter(charac, race);
    ASSERT_EQ(character->getHitPoints(), 19);
    ASSERT_EQ(character->getArmor(), 7);
    ASSERT_EQ(character->getDamage(), 10);
}

TEST(Factory, CreateCleric2)
{
    auto race = Factory::raceOfTypeCharacter::eHuman;
    auto charac = Factory::enumOfTypeCharacter::eCleric;
    auto character = Factory::GetFactory().CreateCharacter(charac, race);
    ASSERT_EQ(character->getHitPoints(), 20);
    ASSERT_EQ(character->getArmor(), 9);
    ASSERT_EQ(character->getDamage(), 7);
}

TEST(Factory, Factory1)
{
    auto race = Factory::raceOfTypeCharacter::eHuman;
    auto charac = Factory::enumOfTypeCharacter::eCleric;
    auto character = Factory::GetFactory().CreateCharacter(charac, race);
    ASSERT_EQ(character->getHitPoints(), 20);
    ASSERT_EQ(character->getArmor(), 9);
    ASSERT_EQ(character->getDamage(), 7);
}

TEST(Factory, Factory2)
{
    auto race = Factory::raceOfTypeCharacter::eHuman;
    auto charac = Factory::enumOfTypeCharacter::eCleric;
    auto character = Factory::GetFactory().CreateCharacter(charac, race);
    ASSERT_EQ(character->getHitPoints(), 20);
    ASSERT_EQ(character->getArmor(), 9);
    ASSERT_EQ(character->getDamage(), 7);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}