// terminal.cpp

#include "terminal.hpp"

Terminal::Terminal() { std::cout << "Terminal::Terminal()" << std::endl; };

std::string Terminal::execute(Command &command) {
  std::cout << "Terminal::execute(std::string command)" << std::endl;
  std::cout << "command: " << command.get_command() << std::endl;

  if (command.get_command() == "help")
    return "help";
  if (command.get_command() == "exit")
    return "exit";
  if (command.get_command() == "print")
    return "print";

  return "";
};