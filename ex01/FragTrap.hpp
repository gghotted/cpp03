#ifndef FRAG_TRAP_HPP
#define FRAG_TRAP_HPP

#include <string>
#include <iostream>
#include <sstream>

class FragTrap {
 public:
  FragTrap(std::string const& name);
  ~FragTrap(void);

  void rangedAttack(std::string const& target);
  void meleeAttack(std::string const& target);
  void takeDamage(unsigned int amount);
  void beRepaired(unsigned int amount);
  void vaulthunter_dot_exe(std::string const& target);

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
