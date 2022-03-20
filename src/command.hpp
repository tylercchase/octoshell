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
      std::string get_command();
      std::vector<std::string> get_arguments();
      std::vector<std::string> get_flags();
    private:
        std::string command;
        std::vector<std::string> arguments;
        std::vector<std::string> flags;

};

#endif
