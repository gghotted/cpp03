#ifndef FLAG_TRAP_HPP
#define FLAG_TRAP_HPP

#include <string>

class FlagTrap {
 public:
  rangedAttack(std::string const& target);
  meleeAttack(std::string const& target);
  takeDamage(unsigned int amount);
  beRepaired(unsigned int amount);

 private:
  std::string name;
  unsigned int hitPoints;
  unsigned int maxHitPoints;
  unsigned int energePoints;
  unsigned int maxEnergePoints;
  unsigned int level;
  unsigned int meleeAttackDamage;
  unsigned int rangedAttackDamage;
  unsigned int armorDamageReduction;
};

#endif
