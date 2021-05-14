#ifndef CLAP_TRAP_HPP
#define CLAP_TRAP_HPP

#include <string>
#include <iostream>

class ClapTrap {
 public:
  ClapTrap(std::string const& name);
  ~ClapTrap(void);

  void rangedAttack(std::string const& target);
  void meleeAttack(std::string const& target);
  void takeDamage(unsigned int amount);
  void beRepaired(unsigned int amount);
  std::string& getName(void);

 protected:
  std::ostream& speak(void);
  void giveUp(void);

  static long long myMax(long long v1, long long v2);
  static long long myMin(long long v1, long long v2);

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
  std::string type;
  std::string msgBorn;
  std::string msgDestroy;
  std::string msgRangedAttack;
  std::string msgMeleeAttack;
  std::string msgTakeDamage;
  std::string msgDied;
  std::string msgPain;
  std::string msgFullPower;
  std::string msgRepaired;
  std::string msgNoEnerge;
  std::string msgGiveUp;
};

#endif
