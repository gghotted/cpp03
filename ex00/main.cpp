#include <string>
#include "FragTrap.hpp"
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
  Ui::setTextColor(Ui::green);
  FragTrap robot(Ui::readStr("robot name"));
  while (1) {
    int cmd = Ui::readInt("cmd");
    if (cmd == 0)
      robot.meleeAttack(Ui::readStr("meleeAttack target"));
    else if (cmd == 1)
      robot.rangedAttack(Ui::readStr("rangedAttack target"));
    else if (cmd == 2)
      robot.takeDamage(Ui::readU("damage amount"));
    else if (cmd == 3)
      robot.beRepaired(Ui::readU("repair amount"));
    else if (cmd == 4)
      robot.vaulthunter_dot_exe(Ui::readStr("random attack target"));
    else if (cmd == 5)
      break ;
    else
      Ui::errorMsg() << cmd << ": invalid cmd. try again." << Ui::endMsg();
  }
}
