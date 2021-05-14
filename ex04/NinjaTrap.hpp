#ifndef NINJA_TRAP_HPP
#define NINJA_TRAP_HPP

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class NinjaTrap : virtual public ClapTrap {
 public:
  NinjaTrap(std::string const& name);
  ~NinjaTrap(void);

  void ninjaShoebox(ClapTrap& clapTrap);
  void ninjaShoebox(ScavTrap& scavTrap);
  void ninjaShoebox(FragTrap& fragTrap);
  void ninjaShoebox(NinjaTrap& ninjaTrap);
};

#endif
