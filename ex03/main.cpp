#include <string>
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "NinjaTrap.hpp"
#include "Ui.hpp"

/*
0: melee attack
1: ranged attack
2: take damage
3: repair
4: vaulthunter_dot_exe
5: exit
ctrl + D: exit
*/

int main(void) {
  std::srand(time(0));
  Ui::setTextColor(Ui::green);

  Ui::readStr("ninja1 create");
  NinjaTrap ninja("ninja1");

  Ui::readStr("ninja2 create");
  NinjaTrap ninja2("ninja2");

  Ui::readStr("clap create");
  ClapTrap clap("clap");

  Ui::readStr("frag create");
  FragTrap frag("frag");

  Ui::readStr("scav create");
  ScavTrap scav("scav");

  Ui::readStr("shoebox to clap");
  ninja.ninjaShoebox(clap);

  Ui::readStr("shoebox to frag");
  ninja.ninjaShoebox(frag);

  Ui::readStr("shoebox to scav");
  ninja.ninjaShoebox(scav);

  Ui::readStr("shoebox to ninja2");
  ninja.ninjaShoebox(ninja2);

  Ui::readStr("destroy all");
  return 0;
}
