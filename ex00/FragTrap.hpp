#ifndef FLAG_TRAP_HPP
#define FLAG_TRAP_HPP

#include <string>
#include <iostream>
#include <sstream>

class FlagTrap {
 public:
  FlagTrap(std::string const& name);
  void rangedAttack(std::string const& target);
  void meleeAttack(std::string const& target);
  void takeDamage(unsigned int amount);
  void beRepaired(unsigned int amount);

 private:
  void speak(void);
  void speakHp(void);
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
  std::stringstream msg;
};

#endif
