#include "FragTrap.hpp"

unsigned int FragTrap::defaultHitPoints = 100;
unsigned int FragTrap::defaultMaxHitPoints = 100;
unsigned int FragTrap::defaultEnergePoints = 100;
unsigned int FragTrap::defaultMaxEnergePoints = 100;
unsigned int FragTrap::defaultLevel = 1;
unsigned int FragTrap::defaultMeleeAttackDamage = 30;
unsigned int FragTrap::defaultRangedAttackDamage = 20;
unsigned int FragTrap::defaultArmorDamageReduction = 5;
bool defaultDead = false;
std::string type = "Frag";
std::string msgBorn = "system run. ready complete";
std::string msgDestroy = "system off. bye";
std::string msgRangedAttack = "launch rocket punch";
std::string msgMeleeAttack = "upper cut";
std::string msgDied = "i'am dead, good bye";
std::string msgPain = "pain. stop attacking";
std::string msgFullPower = "full power!";
std::string msgRepaired = "self-repair complete";
std::string msgNoEnerge = "not enough energe, need repair";
std::string msgGiveUp = "i can't do anything because I'm dead";

FragTrap::FragTrap(std::string const& name) : ClapTrap(name) {
  speak() << msgBorn << "\n";
}

FragTrap::~FragTrap(void) {
  speak() << msgDestroy << "\n";
}

void FragTrap::vaulthunter_dot_exe(std::string const& target) {
  if (dead) return giveUp();
  if (energePoints < 25) {
    speak() << "Not enough energe, need repair\n";
    return ;
  }
  energePoints = myMax(0, (long long)energePoints - 25);
  static const std::string skills[] = {
    "Super Ultra NeClear Punch",
    "Launch oil",
    "Electric shock",
    "Super Ultra Noise Sound",
    "Throwing it out of the earth"};
  int index = std::rand() % 5;
  speak() << skills[index] << " to " << target << '\n';
}
