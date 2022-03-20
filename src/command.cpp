// command.cpp

#include "command.hpp"

Command::Command(std::string command, std::vector<std::string> args,
                 std::vector<std::string> flags) {
    this->command = command;
    this->arguments = args;
    this->flags = flags;
}

std::string Command::get_command() {
    return this->command;
}