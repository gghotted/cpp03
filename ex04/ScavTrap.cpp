#include "ScavTrap.hpp"

// constructor

ScavTrap::ScavTrap(std::string const& name) : ClapTrap(name) {
  speak() << msgBorn << "\n";
}

ScavTrap::~ScavTrap(void) {
  speak() << msgDestroy << "\n";
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

