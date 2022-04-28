// terminal.hpp

#include "command.hpp"
#include "parser.hpp"
#include <iostream>
#include <string>
#include <vector>

#ifndef TERMINAL_H
#define TERMINAL_H

class Terminal {
public:
  Terminal();
  void start();
  static std::string execute(Command &command);
private:
};

#endif //#ifndef TERMINAL_H
