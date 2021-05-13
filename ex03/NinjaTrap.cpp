#include "NinjaTrap.hpp"

// constructor

NinjaTrap::NinjaTrap(std::string const& name) : ClapTrap(name) {
  hitPoints = 100;
  maxHitPoints = 100;
  energePoints = 100;
  maxEnergePoints = 100;
  level = 1;
  meleeAttackDamage = 30;
  rangedAttackDamage = 20;
  armorDamageReduction = 5;
  dead = false;
  type = "Frag";
  msgBorn = "system run. ready complete";
  msgDestroy = "system off. bye";
  msgRangedAttack = "launch rocket punch";
  msgMeleeAttack = "upper cut";
  msgDied = "i'am dead, good bye";
  msgPain = "pain. stop attacking";
  msgFullPower = "full power!";
  msgRepaired = "self-repair complete";
  msgNoEnerge = "not enough energe, need repair";
  msgGiveUp = "i can't do anything because I'm dead";
  msgNinjaShoebox = "Throwing a shoe box!";
  speak() << msgBorn << "\n";
}

NinjaTrap::~NinjaTrap(void) {
  speak() << msgDestroy << "\n";
}

// public method

void NinjaTrap::ninjaShoebox(ClapTrap& clapTrap) {
  speak() << msgNinjaShoebox << "\n";
  clapTrap.takeDamage()
}

void NinjaTrap::ninjaShoebox(ScavTrap const& scavTrap) {
  speak() << msgNinjaShoebox << "\n";
}

void NinjaTrap::ninjaShoebox(FragTrap const& fragTrap) {
  speak() << msgNinjaShoebox << "\n";
}

void NinjaTrap::ninjaShoebox(NinjaTrap const& ninjaTrap) {
  speak() << msgNinjaShoebox << "\n";
}
