#ifndef NINJA_TRAP_HPP
#define NINJA_TRAP_HPP

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class NinjaTrap : public ClapTrap {
 public:
  NinjaTrap(std::string const& name);
  ~NinjaTrap(void);

  void ninjaShoebox(ClapTrap const& clapTrap);
  void ninjaShoebox(ScavTrap const& scavTrap);
  void ninjaShoebox(FragTrap const& fragTrap);
  void ninjaShoebox(NinjaTrap const& ninjaTrap);

 private:
  std::string msgNinjaShoebox;
};

#endif
