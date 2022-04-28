// command.hpp

#include <iostream>
#include <string>
#include <vector>

#ifndef COMMAND_H
#define COMMAND_H

class Command {
public:
  explicit Command(std::string, std::vector<std::string> = {},
                   std::vector<std::string> = {});
  std::string get_command();
  std::vector<std::string> get_arguments();
  std::vector<std::string> get_flags();
  bool semicolon_continuation;
private:
  std::string command;
  std::vector<std::string> arguments;
  std::vector<std::string> flags;
};

#endif //#ifndef COMMAND_H
