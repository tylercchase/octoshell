// parser.cpp

#include "parser.hpp"
#include <algorithm>
#include <regex>
#include <sstream>

std::vector<Command> parse(std::string input) {
  std::stringstream ss(input);
  std::string line;
  std::vector<Command> commands;

  // A–Z, a–z, 0–9, dash, dot, forward slash, and underscore.
  std::regex valid_command("^[A-Za-z0-9\\-\\.\\/\\_]+");

  while (std::getline(ss, line, ';')) {
    std::string command;

    std::stringstream ss2(line);
    std::string line2;
    std::vector<std::vector<std::string>> sequences;
    std::vector<std::string> args;

    while (std::getline(ss2, line2, '&')) {
      if (line2.length() > 100) {
        line2 = line2.substr(0, 100);
        std::cout << "(!) Line too long -- truncated." << std::endl;
      }
      std::stringstream ss3(line2);
      std::string line3;
      std::vector<std::string> tokens;
      while (std::getline(ss3, line3, ' ')) {
        if (line3.length() > 0) {
          tokens.push_back(line3);
        }
      }
      sequences.push_back(tokens);
    }

    for (auto output : sequences) {
      command = output[0];
      output.erase(output.begin());
      if (!std::regex_match(command, valid_command)) {
        std::cout << "(!) Invalid command: " << command << std::endl;
        continue;
      }
      std::vector<std::string> flags;

      for (std::string x : output) {
        if (x.find("-") != std::string::npos) {
          for (char y : x) {
            if (y != '-') {
              flags.push_back(std::string(1, y));
            }
          }
        } else {
          args.push_back(x);
        }
      }
      commands.push_back(Command(command, args, flags));
    }
    if (commands.size() == 0) {
      std::cout << "(!) No commands found." << std::endl;
    } else {
      Command latest = commands.back();
      latest.semicolon_continuation = true;
    }
  }

  return commands;
}
