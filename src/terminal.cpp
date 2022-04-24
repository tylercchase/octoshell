// terminal.cpp

#include "terminal.hpp"
#include <numeric>
#include <sstream>
#include <stdio.h>
#include <unistd.h>

Terminal::Terminal(){};

void Terminal::start() {
  while (true) {
    std::cout << "🐙🐚 octoshell » ";
    std::string input;
    std::getline(std::cin, input);
    std::vector<Command> commands = parse(input);
    for (Command command : commands) {
      if (command.semicolon_continuation) {
        std::cout << execute(command) << std::endl;
      } else {
        std::cout << execute(command) << std::endl;
      }
    }
  }
}

std::string execute_internal(Command &command) {
  FILE *fp;
  int status;
  char input[4096];
  char path[4096];
  std::string arguments;
  for (std::string argument : command.get_arguments()) {
    arguments += " " + argument;
  }
  sprintf(input, "%s %s", command.get_command().c_str(), arguments.c_str());
  fp = popen(input, "r");
  if (fp == NULL) {
    return "(!) Failed to run command";
  }
  std::ostringstream output;
  while (fgets(path, 4096, fp) != NULL) {
    output << path;
  }

  status = pclose(fp);
  return output.str();
}

std::string Terminal::execute(Command &command) {
  if (command.get_command() == "help") {
    std::ostringstream help;
    help << "help - displays this menu\n"
         << "exit - closes the shell\n"
         << "print - shell's current process id\n"
         << "cd - navigate to another directory";
    return help.str();
  } else if (command.get_command() == "exit") {
    exit(0);
  } else if (command.get_command() == "print") {
    return std::to_string(getpid());
  } else if (command.get_command() == "cd") {
    chdir(command.get_arguments()[0].c_str());
    return "";
  } else {
    auto output = execute_internal(command);
    return output;
  }
};
