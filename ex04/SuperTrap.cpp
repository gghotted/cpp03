#include "SuperTrap.hpp"

SuperTrap::SuperTrap(std::string name) : ClapTrap(name),
                                         FragTrap(name),
                                         NinjaTrap(name) {
  hitPoints = 100;
  maxHitPoints = 100;
  energePoints = 120;
  maxEnergePoints = 120;
  level = 1;
  meleeAttackDamage = 60;
  rangedAttackDamage = 20;
  armorDamageReduction = 5;
  dead = false;
  type = "Super";
  msgRangedAttack = "launch rocket punch";
  msgMeleeAttack = "Two-stage dagger cutting";
  msgDied = "i'am dead, good bye";
  msgPain = "pain. stop attacking";
  msgFullPower = "full power!";
  msgRepaired = "self-repair complete";
  msgNoEnerge = "not enough energe, need repair";
  msgGiveUp = "i can't do anything because I'm dead";
  std::cout << "super created" << "\n";
}

SuperTrap::~SuperTrap(void) {
  std::cout << "super deleted" << "\n";
}
