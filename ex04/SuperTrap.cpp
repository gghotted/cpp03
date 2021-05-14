#include "SuperTrap.hpp"

unsigned int defaultHitPoints = FragTrap::defaultHitPoints;
unsigned int defaultMaxHitPoints = FragTrap::defaultMaxHitPoints;
unsigned int defaultEnergePoints = NinjaTrap::defaultEnergePoints;
unsigned int defaultMaxEnergePoints = NinjaTrap::defaultMaxEnergePoints;
unsigned int defaultLevel = 1;
unsigned int defaultMeleeAttackDamage = NinjaTrap::defaultMeleeAttackDamage;
unsigned int defaultRangedAttackDamage = FragTrap::defaultRangedAttackDamage;
unsigned int defaultArmorDamageReduction = FragTrap::defaultArmorDamageReduction;
bool defaultDead = false;
std::string type = "Super";
std::string msgBorn = "Super run. ready complete";
std::string msgDestroy = "Super off. bye";
std::string msgRangedAttack = FragTrap::msgRangedAttack;
std::string msgMeleeAttack = NinjaTrap::msgMeleeAttack;
std::string msgDied = "i'am dead, good bye";
std::string msgPain = "pain. stop attacking";
std::string msgFullPower = "full power!";
std::string msgRepaired = "self-repair complete";
std::string msgNoEnerge = "not enough energe, need repair";
std::string msgGiveUp = "i can't do anything because I'm dead";

SuperTrap::SuperTrap(std::string name) : ClapTrap(name),
                                         FragTrap(name),
                                         NinjaTrap(name) {
  speak() << msgBorn << "\n";
}


SuperTrap::~SuperTrap(void) {
  speak() << msgDestroy << "\n";
}
