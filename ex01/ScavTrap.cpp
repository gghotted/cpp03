#include "ScavTrap.hpp"

static long long myMax(long long v1, long long v2) {
  if (v1 > v2) return v1;
  return v2;
}

static long long myMin(long long v1, long long v2) {
  if (v1 > v2) return v2;
  return v1;
}

// constructor

ScavTrap::ScavTrap(std::string const& name)
    : name(name),
      hitPoints(100),
      maxHitPoints(100),
      energePoints(50),
      maxEnergePoints(50),
      level(1),
      meleeAttackDamage(20),
      rangedAttackDamage(15),
      armorDamageReduction(3),
      dead(false) {
  speak() << "hahahahaha. i am born.\n";
}

ScavTrap::~ScavTrap(void) {
  speak() << "hahahahaha. i am died, bye.\n";
}

// public method

void ScavTrap::rangedAttack(std::string const& target) {
  if (dead) return giveUp();
  speak() << "hahahahaha. Grenade Throwing to " << target
          << "(-" << rangedAttackDamage << ").\n";
}

void ScavTrap::meleeAttack(std::string const& target) {
  if (dead) return giveUp();
  speak() << "hahahahaha. Head breaking to " << target
          << "(-" << meleeAttackDamage << ").\n";
}

void ScavTrap::takeDamage(unsigned int amount) {
  if (dead) return giveUp();
  amount = myMax(0, (long long)amount - armorDamageReduction);
  hitPoints = myMax(0, (long long)hitPoints - amount);
  if (hitPoints == 0) {
    dead = true;
    speak() << "hahahahaha. i'am dead, good bye.\n";
  } else {
    speak() << "hahahahaha. pain. stop attacking.\n";
  }
}

void ScavTrap::beRepaired(unsigned int amount) {
  if (dead) return giveUp();
  hitPoints = myMin(maxHitPoints, (long long)hitPoints + amount);
  energePoints = myMin(maxEnergePoints, (long long)energePoints + amount);
  if (hitPoints == maxHitPoints && energePoints == maxEnergePoints)
    speak() << "hahahahaha. full power!\n";
  else
    speak() << "hahahahaha. self-repair complete.\n";
}

void ScavTrap::challengeNewcomer(std::string const& target) {
  if (dead) return giveUp();
  if (energePoints < 25) {
    speak() << "Not enough energe, need repair\n";
    return ;
  }
  energePoints = myMax(0, (long long)energePoints - 25);
  static const std::string challenges[] = {
    "Slap down with hammer",
    "Throwing in boiling water",
    "Pulling out all the hair",
    "Set fire to the head",
    "Pulling out nails"};
  int index = std::rand() % 5;
  speak() << challenges[index] << " to " << target << '\n';
}

// private method

std::ostream& ScavTrap::speak(void) {
  std::cout << "LEVEL: " << level
            << ", HP: [" << hitPoints << " / " << maxHitPoints << "]"
            << ", MP: [" << energePoints << " / " << maxEnergePoints << "]\n"
            << name << " (SCAV-TP)" << ": ";
  return std::cout;
}

void ScavTrap::giveUp(void) {
  speak() << "hahahahaha. i can't do anything because I'm dead.\n";
}
