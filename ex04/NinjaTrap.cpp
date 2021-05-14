#include "NinjaTrap.hpp"

// constructor

NinjaTrap::NinjaTrap(std::string const& name) : ClapTrap(name) {
  speak() << msgBorn << "\n";
}

NinjaTrap::~NinjaTrap(void) {
  speak() << msgDestroy << "\n";
}

// public method

void NinjaTrap::ninjaShoebox(ClapTrap& clapTrap) {
  speak() << clapTrap.getName() << ": this object is not allowed"
                                   " because it is an inheritance-only class\n";
}

void NinjaTrap::ninjaShoebox(ScavTrap& scavTrap) {
  speak() << "hello my brother. i hate you\n";
  meleeAttack(scavTrap.getName());
  scavTrap.takeDamage(maxHitPoints);
}

void NinjaTrap::ninjaShoebox(FragTrap& fragTrap) {
  speak() << "hello my brother. i like you, i'm gonna fix you\n";
  fragTrap.beRepaired(50);
}

void NinjaTrap::ninjaShoebox(NinjaTrap& ninjaTrap) {
  speak() << "who are you..? oh my god!(Died of mental shock)\n";
  ninjaTrap.takeDamage(maxHitPoints);
  this->takeDamage(maxHitPoints);
}
