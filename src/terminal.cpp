// terminal.cpp

#include "terminal.hpp"
#include <unistd.h>
#include <stdio.h>
#include <linux/limits.h>

Terminal::Terminal() {};

void execute_internal(Command &command) {
    // call execvp
    // char* a = "";
    // char* b[2];
    // b[0] = "";
    // b[1] = NULL;
    // auto a = execvp(command.get_command().c_str(), b);
    
    FILE *fp;
    int status;
    char path[4096];

    fp = popen(command.get_command().c_str(), "r");
    if (fp == NULL) {
      // TODO: Handle error conditions.
    }
    std::vector<std::string> output;
    while (fgets(path, 4096, fp) != NULL) {
      // printf("%s", path);
      output.push_back(path);
    }
    
    status = pclose(fp);
}

std::string Terminal::execute(Command &command) {
  if (command.get_command() == "help")
    return "help";
  else if (command.get_command() == "exit")
    return "exit";
  else if (command.get_command() == "print")
    return "print";
  else {
    execute_internal(command);
    return "";
  }
};

