// command.cpp

#include "command.hpp"
#include <utility>

Command::Command(std::string command, std::vector<std::string> args,
                 std::vector<std::string> flags) {
  this->command = std::move(command);
  this->arguments = std::move(args);
  this->flags = std::move(flags);
  this->semicolon_continuation = false;
}

// TODO: Wait for a command to finish... [sleep]

std::string Command::get_command() { return this->command; }

std::vector<std::string> Command::get_arguments() { return this->arguments; }

std::vector<std::string> Command::get_flags() { return this->flags; }
