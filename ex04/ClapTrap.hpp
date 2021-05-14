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
  const unsigned int defaultHitPoints;
  const unsigned int defaultMaxHitPoints;
  const unsigned int defaultEnergePoints;
  const unsigned int defaultMaxEnergePoints;
  const unsigned int defaultLevel;
  const unsigned int defaultMeleeAttackDamage;
  const unsigned int defaultRangedAttackDamage;
  const unsigned int defaultArmorDamageReduction;
  const unsigned int defaultDead;
  const std::string type;
  const std::string msgBorn;
  const std::string msgDestroy;
  const std::string msgRangedAttack;
  const std::string msgMeleeAttack;
  const std::string msgTakeDamage;
  const std::string msgDied;
  const std::string msgPain;
  const std::string msgFullPower;
  const std::string msgRepaired;
  const std::string msgNoEnerge;
  const std::string msgGiveUp;
};

#endif
