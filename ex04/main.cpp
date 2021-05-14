#include <string>
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "NinjaTrap.hpp"
#include "SuperTrap.hpp"
#include "Ui.hpp"

int main(void) {
  std::srand(time(0));
  Ui::setTextColor(Ui::green);

  Ui::readStr("super create");
  SuperTrap super("super");

  Ui::readStr("scav create");
  ScavTrap scav("scav");

  Ui::readStr("melee Attack as ninja");
  super.meleeAttack("enemy");

  Ui::readStr("melee Attack as frag");
  super.meleeAttack("enemy");

  Ui::readStr("shoebox to scav");
  super.ninjaShoebox(scav);

  Ui::readStr("destroy all");
  return 0;
}
