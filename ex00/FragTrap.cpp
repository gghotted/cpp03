#include "FragTrap.hpp"

static long long myMax(long long v1, long long v2) {
  if (v1 > v2) return v1;
  return v2;
}

static long long myMin(long long v1, long long v2) {
  if (v1 > v2) return v2;
  return v1;
}

// constructor

FragTrap::FragTrap(std::string const& name)
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
  speak() << "system run. ready complete.\n";
}

FragTrap::~FragTrap(void) {
  speak() << "system off. bye.\n";
}

// public method

void FragTrap::rangedAttack(std::string const& target) {
  if (dead) return giveUp();
  speak() << "launch rocket punch to " << target
          << "(-" << rangedAttackDamage << ").\n";
}

void FragTrap::meleeAttack(std::string const& target) {
  if (dead) return giveUp();
  speak() << "upper cut to " << target
          << "(-" << meleeAttackDamage << ").\n";
}

void FragTrap::takeDamage(unsigned int amount) {
  if (dead) return giveUp();
  amount = myMax(0, (long long)amount - armorDamageReduction);
  hitPoints = myMax(0, (long long)hitPoints - amount);
  if (hitPoints == 0) {
    dead = true;
    speak() << "i'am dead, good bye.\n";
  } else {
    speak() << "pain. stop attacking.\n";
  }
}

void FragTrap::beRepaired(unsigned int amount) {
  if (dead) return giveUp();
  hitPoints = myMin(maxHitPoints, (long long)hitPoints + amount);
  energePoints = myMin(maxEnergePoints, (long long)energePoints + amount);
  if (hitPoints == maxHitPoints && energePoints == maxEnergePoints)
    speak() << "full power!\n";
  else
    speak() << "self-repair complete.\n";
}

void FragTrap::vaulthunter_dot_exe(std::string const& target) {
  if (energePoints < 25) {
    speak() << "Not enough energe, need repair\n";
    return ;
  }
  energePoints = myMax(0, (long long)energePoints - 25);
  static const std::string skills[] = {
    "Super Ultra New Clear Punch",
    "Launch oil",
    "Electric shock",
    "Super Ultra Noise Sound",
    "Throwing it out of the earth"};
  int index = std::rand() % 5;
  speak() << skills[index] << " to " << target << '\n';
}

// private method

std::ostream& FragTrap::speak(void) {
  std::cout << "LEVEL: " << level
            << ", HP: [" << hitPoints << " / " << maxHitPoints << "]"
            << ", MP: [" << energePoints << " / " << maxEnergePoints << "]\n"
            << name << " (FR4G-TP)" << ": ";
  return std::cout;
}

void FragTrap::giveUp(void) {
  speak() << "i can't do anything because I'm dead.\n";
}
