#include "FragTrap.hpp"

static long long myMax(long long v1, long long v2) {
  if (v1 > v2)
    return v1;
  return v2;
}

static long long myMin(long long v1, long long v2) {
  if (v1 > v2)
    return v2;
  return v1;
}

// constructor

FlagTrap::FlagTrap(std::string const& name)
    : name(name),
      hitPoints(100),
      maxHitPoints(100),
      energePoints(100),
      maxEnergePoints(100),
      level(1),
      meleeAttackDamage(30),
      rangedAttackDamage(20),
      armorDamageReduction(5),
      dead(false) {
  msg << "system run. ready complete.";
  speak();
}

// public method

void FlagTrap::rangedAttack(std::string const& target) {
  if (dead) return giveUp();
  msg << "rocket punch launch to " << target
            << "(-" << rangedAttackDamage << ").";
  speak();
}

void FlagTrap::meleeAttack(std::string const& target) {
  if (dead) return giveUp();
  msg << "upper cut to " << target
            << "(-" << meleeAttackDamage << ").";
  speak();
}

void FlagTrap::takeDamage(unsigned int amount) {
  if (dead) return giveUp();
  hitPoints = myMax(0, (int)hitPoints - amount);
  if (hitPoints == 0) dead = true;
  speakHp();
}

void FlagTrap::beRepaired(unsigned int amount) {
  if (dead) return giveUp();
  hitPoints = myMin(maxHitPoints, hitPoints + amount);
  speakHp();
}

// private method

void FlagTrap::speak(void) {
  std::cout << name << "(FR4G-TP)" << ": "
            << msg.str() << std::endl;
  msg.clear();
}

void FlagTrap::speakHp(void) {
  msg << "HP: " << '[' << hitPoints << " / " << maxHitPoints << ']';
  if (hitPoints == 0)   msg << ", died.";
  if (hitPoints == 100) msg << ", I`am happy^^.";
  speak();
}

void FlagTrap::giveUp(void) {
  msg << "i can't do anything because I'm dead.";
  speak();
}
