#pragma once
class IRace
{
public:
	IRace(int hitPointMod, int armorClassMod, int hitBonusMod) :
    hitPointMod(hitPointMod),
    armorClassMod(armorClassMod),
    hitBonusMod(hitBonusMod)
	{}

	virtual int getHitPointMod() { return hitPointMod; }
    virtual int getArmorClassMod() { return armorClassMod; }
    virtual int getHitBonusMod() { return hitBonusMod; }

    ~IRace() {}
protected:
	int hitPointMod;
    int armorClassMod;
    int hitBonusMod;
};