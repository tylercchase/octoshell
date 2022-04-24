// terminal.hpp

#include "command.hpp"
#include "parser.hpp"
#include <iostream>
#include <string>
#include <vector>

#ifndef TERMINAL_H
#define TERMINAL_H

// * FIXME: What does a terminal do?
// 0. Start command (begin process -> loop management)
// 1. Take input from a user.
// 2. Parse input into commands.
// 3. Execute commands.
// 4. Print output.
// 5. Repeat.
class Terminal {
public:
  Terminal();
  void start();
  static std::string execute(Command &command);

  //? Link to function (internal vs. external).
  std::vector<std::string> commands = {"exit", "print", "help"};
  std::vector<std::string> flags = {"--help", "--version"};

  // Table of Internal Commands:
  // (SWITCH --> exit, print, or help).
  // search path for executables not built-in.
private:
};

// TODO: Loop Management (Similar to games in C++).

#endif //#ifndef TERMINAL_H
