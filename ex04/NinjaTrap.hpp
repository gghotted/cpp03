#ifndef NINJA_TRAP_HPP
#define NINJA_TRAP_HPP

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class NinjaTrap : virtual public ClapTrap {
 public:
  NinjaTrap(std::string const& name);
  ~NinjaTrap(void);

  void ninjaShoebox(ClapTrap& clapTrap);
  void ninjaShoebox(ScavTrap& scavTrap);
  void ninjaShoebox(FragTrap& fragTrap);
  void ninjaShoebox(NinjaTrap& ninjaTrap);

 protected:
  const unsigned int defaultHitPoints = 60;
  const unsigned int defaultMaxHitPoints = 60;
  const unsigned int defaultEnergePoints = 120;
  const unsigned int defaultMaxEnergePoints = 120;
  const unsigned int defaultLevel = 1;
  const unsigned int defaultMeleeAttackDamage = 60;
  const unsigned int defaultRangedAttackDamage = 5;
  const unsigned int defaultArmorDamageReduction = 0;
  const bool defaultDead = false;
  const std::string type = "Ninja";
  const std::string msgBorn = "ninjaTrap run. ready complete";
  const std::string msgDestroy = "ninjaTrap off. bye";
  const std::string msgRangedAttack = "Dagger Throw";
  const std::string msgMeleeAttack = "Two-stage dagger cutting";
  const std::string msgDied = "i'am dead, good bye";
  const std::string msgPain = "pain. stop attacking";
  const std::string msgFullPower = "full power!";
  const std::string msgRepaired = "self-repair complete";
  const std::string msgNoEnerge = "not enough energe, need repair";
  const std::string msgGiveUp = "i can't do anything because I'm dead";
};

#endif
