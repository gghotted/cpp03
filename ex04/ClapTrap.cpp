#include "ClapTrap.hpp"

long long ClapTrap::myMax(long long v1, long long v2) {
  if (v1 > v2) return v1;
  return v2;
}

long long ClapTrap::myMin(long long v1, long long v2) {
  if (v1 > v2) return v2;
  return v1;
}

// constructor

const unsigned int ClapTrap::defaultHitPoints = 0;
const unsigned int ClapTrap::defaultMaxHitPoints = 0;
const unsigned int ClapTrap::defaultEnergePoints = 0;
const unsigned int ClapTrap::defaultMaxEnergePoints = 0;
const unsigned int ClapTrap::defaultLevel = 0;
const unsigned int ClapTrap::defaultMeleeAttackDamage = 0;
const unsigned int ClapTrap::defaultRangedAttackDamage = 0;
const unsigned int ClapTrap::defaultArmorDamageReduction = 0;
const unsigned int ClapTrap::defaultDead = true;
const std::string ClapTrap::msgDied = "This object is for inheritance only.\n"
                                      "Create objects after modifying properties";

ClapTrap::ClapTrap(std::string const& name) : name(name) {
  hitPoints = defaultHitPoints;
  maxHitPoints = defaultMaxHitPoints;
  energePoints = defaultEnergePoints;
  maxEnergePoints = defaultMaxEnergePoints;
  level = defaultLevel;
  meleeAttackDamage = defaultMeleeAttackDamage;
  rangedAttackDamage = defaultRangedAttackDamage;
  armorDamageReduction = defaultArmorDamageReduction;
  std::cout << "new ClapTrap\n";
}

ClapTrap::~ClapTrap(void) {
  std::cout << "del ClapTrap\n";
}

// public method

void ClapTrap::rangedAttack(std::string const& target) {
  if (dead) return giveUp();
  speak() << msgRangedAttack << " to " << target
          << "(-" << rangedAttackDamage << ").\n";
}

void ClapTrap::meleeAttack(std::string const& target) {
  if (dead) return giveUp();
  speak() << msgMeleeAttack << " to " << target
          << "(-" << meleeAttackDamage << ").\n";
}

void ClapTrap::takeDamage(unsigned int amount) {
  if (dead) return giveUp();
  amount = myMax(0, (long long)amount - armorDamageReduction);
  hitPoints = myMax(0, (long long)hitPoints - amount);
  if (hitPoints == 0) {
    dead = true;
    speak() << msgDied << "\n";
  } else {
    speak() << msgPain << "\n";
  }
}

void ClapTrap::beRepaired(unsigned int amount) {
  if (dead) return giveUp();
  hitPoints = myMin(maxHitPoints, (long long)hitPoints + amount);
  energePoints = myMin(maxEnergePoints, (long long)energePoints + amount);
  if (hitPoints == maxHitPoints && energePoints == maxEnergePoints)
    speak() << msgFullPower << "\n";
  else
    speak() << msgRepaired << "\n";
}

// private method

std::string& ClapTrap::getName(void) {
  return name;
}

std::ostream& ClapTrap::speak(void) {
  std::cout << "LEVEL: " << level
            << ", HP: [" << hitPoints << " / " << maxHitPoints << "]"
            << ", MP: [" << energePoints << " / " << maxEnergePoints << "]\n"
            << name << " " << type << ": ";
  return std::cout;
}

void ClapTrap::giveUp(void) {
  speak() << msgGiveUp << "\n";
}
