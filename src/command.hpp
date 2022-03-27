// command.hpp

#include <iostream>
#include <string>
#include <vector>

#ifndef COMMAND_H
#define COMMAND_H

class Command {
public:
  Command(std::string, std::vector<std::string> = {},
          std::vector<std::string> = {});
  const std::string get_command();
  const std::vector<std::string> get_arguments();
  const std::vector<std::string> get_flags();

private:
  std::string command;
  std::vector<std::string> arguments;
  std::vector<std::string> flags;
};

#endif
