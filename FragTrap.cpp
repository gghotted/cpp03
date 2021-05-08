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
  this->msg << "system run. ready complete.";
  this->speak();
}

// public method

void FlagTrap::rangedAttack(std::string const& target) {
  if (this->dead) return this->giveUp();
  this->msg << "rocket punch launch to " << target
            << "(-" << this->rangedAttackDamage << ").";
  this->speak();
}

void FlagTrap::meleeAttack(std::string const& target) {
  if (this->dead) return this->giveUp();
  this->msg << "upper cut to " << target
            << "(-" << this->meleeAttackDamage << ").";
  this->speak();
}

void FlagTrap::takeDamage(unsigned int amount) {
  if (this->dead) return this->giveUp();
  this->hitPoints = myMax(0, (int)this->hitPoints - amount);
  if (this->hitPoints == 0) this->dead = true;
  this->speakHp();
}

void FlagTrap::beRepaired(unsigned int amount) {
  if (this->dead) return this->giveUp();
  this->hitPoints = myMin(this->maxHitPoints, this->hitPoints + amount);
  this->speakHp();
}

// private method

void FlagTrap::speak(void) {
  std::cout << this->name << "(FR4G-TP)" << ": "
            << this->msg.str() << std::endl;
  this->msg.clear();
}

void FlagTrap::speakHp(void) {
  this->msg << "HP: " << '[' << this->hitPoints << " / " << this->maxHitPoints << ']';
  if (this->hitPoints == 0)   this->msg << ", died.";
  if (this->hitPoints == 100) this->msg << ", I`am happy^^.";
  this->speak();
}

void FlagTrap::giveUp(void) {
  this->msg << "i can't do anything because I'm dead.";
  this->speak();
}
