#include "NinjaTrap.hpp"

// constructor

NinjaTrap::NinjaTrap(std::string const& name) : ClapTrap(name) {
  hitPoints = 60;
  maxHitPoints = 60;
  energePoints = 120;
  maxEnergePoints = 120;
  level = 1;
  meleeAttackDamage = 60;
  rangedAttackDamage = 5;
  armorDamageReduction = 0;
  dead = false;
  type = "Ninja";
  msgBorn = "ninjaTrap run. ready complete";
  msgDestroy = "ninjaTrap off. bye";
  msgRangedAttack = "Dagger Throw";
  msgMeleeAttack = "Two-stage dagger cutting";
  msgDied = "i'am dead, good bye";
  msgPain = "pain. stop attacking";
  msgFullPower = "full power!";
  msgRepaired = "self-repair complete";
  msgNoEnerge = "not enough energe, need repair";
  msgGiveUp = "i can't do anything because I'm dead";
  speak() << msgBorn << "\n";
}

NinjaTrap::~NinjaTrap(void) {
  speak() << msgDestroy << "\n";
}

// public method

void NinjaTrap::ninjaShoebox(ClapTrap& clapTrap) {
  speak() << clapTrap.getName() << ": this object is not allowed"
                                   " because it is an inheritance-only class\n";
}

void NinjaTrap::ninjaShoebox(ScavTrap& scavTrap) {
  speak() << "hello my brother. i hate you\n";
  meleeAttack(scavTrap.getName());
  scavTrap.takeDamage(meleeAttackDamage);
}

void NinjaTrap::ninjaShoebox(FragTrap& fragTrap) {
  speak() << "hello my brother. i like you, i'm gonna fix you\n";
  fragTrap.beRepaired(50);
}

void NinjaTrap::ninjaShoebox(NinjaTrap& ninjaTrap) {
  speak() << "who are you..? oh my god!(Died of mental shock)\n";
  ninjaTrap.takeDamage(maxHitPoints);
  this->takeDamage(maxHitPoints + armorDamageReduction);
}
