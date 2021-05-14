#include "ScavTrap.hpp"

// constructor

ScavTrap::ScavTrap(std::string const& name) : ClapTrap(name) {
  hitPoints = 100;
  maxHitPoints = 100;
  energePoints = 50;
  maxEnergePoints = 50;
  level = 1;
  meleeAttackDamage = 20;
  rangedAttackDamage = 15;
  armorDamageReduction = 3;
  dead = false;
  type = "Scav";
  msgRangedAttack = "haha. launch rocket punch";
  msgMeleeAttack = "haha. upper cut";
  msgDied = "haha. i'am dead, good bye";
  msgPain = "haha. pain. stop attacking";
  msgFullPower = "haha. full power!";
  msgRepaired = "haha. self-repair complete";
  msgNoEnerge = "haha. not enough energe, need repair";
  msgGiveUp = "haha. i can't do anything because I'm dead";
  std::cout << "scav created" << "\n";
}

ScavTrap::~ScavTrap(void) {
  std::cout << "scav deleted" << "\n";
}

// public method

void ScavTrap::challengeNewcomer(std::string const& target) {
  if (dead) return giveUp();
  if (energePoints < 25) {
    speak() << "haha. Not enough energe, need repair\n";
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

