// command.cpp
// TODO: exit, print, & help commands.

#include "command.hpp"

Command::Command(std::string command, std::vector<std::string> args,
                 std::vector<std::string> flags) {
  this->command = command;
  this->arguments = args;
  this->flags = flags;
}

const std::string Command::get_command() { return this->command; }
const std::vector<std::string> Command::get_arguments() {
    return this->arguments;
}
const std::vector<std::string> Command::get_flags() {
    return this->flags;
}