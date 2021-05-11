#ifndef SCAV_TRAP_HPP
#define SCAV_TRAP_HPP

#include <string>
#include <iostream>
#include <sstream>

class ScavTrap {
 public:
  ScavTrap(std::string const& name);
  ~ScavTrap(void);

  void rangedAttack(std::string const& target);
  void meleeAttack(std::string const& target);
  void takeDamage(unsigned int amount);
  void beRepaired(unsigned int amount);
  void challengeNewcomer(std::string const& target);

 private:
  std::ostream& speak(void);
  void giveUp(void);

  std::string name;
  unsigned int hitPoints;
  unsigned int maxHitPoints;
  unsigned int energePoints;
  unsigned int maxEnergePoints;
  unsigned int level;
  unsigned int meleeAttackDamage;
  unsigned int rangedAttackDamage;
  unsigned int armorDamageReduction;
  bool dead;
};

#endif
