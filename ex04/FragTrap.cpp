#include "FragTrap.hpp"

FragTrap::FragTrap(std::string const& name) : ClapTrap(name) {
  hitPoints = 100;
  maxHitPoints = 100;
  energePoints = 100;
  maxEnergePoints = 100;
  level = 1;
  meleeAttackDamage = 30;
  rangedAttackDamage = 20;
  armorDamageReduction = 5;
  dead = false;
  type = "Frag";
  msgRangedAttack = "launch rocket punch";
  msgMeleeAttack = "upper cut";
  msgDied = "i'am dead, good bye";
  msgPain = "pain. stop attacking";
  msgFullPower = "full power!";
  msgRepaired = "self-repair complete";
  msgNoEnerge = "not enough energe, need repair";
  msgGiveUp = "i can't do anything because I'm dead";
  std::cout << "frag created" << "\n";
}

FragTrap::~FragTrap(void) {
  std::cout << "frag deleted" << "\n";
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
