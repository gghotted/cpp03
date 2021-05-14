#ifndef SCAV_TRAP_HPP
#define SCAV_TRAP_HPP

#include <string>
#include <iostream>
#include <sstream>
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
 public:
  ScavTrap(std::string const& name);
  ~ScavTrap(void);

  void challengeNewcomer(std::string const& target);

 protected:
  const unsigned int defaultHitPoints = 100;
  const unsigned int defaultMaxHitPoints = 100;
  const unsigned int defaultEnergePoints = 50;
  const unsigned int defaultMaxEnergePoints = 50;
  const unsigned int defaultLevel = 1;
  const unsigned int defaultMeleeAttackDamage = 20;
  const unsigned int defaultRangedAttackDamage = 15;
  const unsigned int defaultArmorDamageReduction = 3;
  const bool defaultDead = false;
  const std::string type = "Scav";
  const std::string msgBorn = "haha. system run. ready complete";
  const std::string msgDestroy = "haha. system off. bye";
  const std::string msgRangedAttack = "haha. launch rocket punch";
  const std::string msgMeleeAttack = "haha. upper cut";
  const std::string msgDied = "haha. i'am dead, good bye";
  const std::string msgPain = "haha. pain. stop attacking";
  const std::string msgFullPower = "haha. full power!";
  const std::string msgRepaired = "haha. self-repair complete";
  const std::string msgNoEnerge = "haha. not enough energe, need repair";
  const std::string msgGiveUp = "haha. i can't do anything because I'm dead";
};

#endif
