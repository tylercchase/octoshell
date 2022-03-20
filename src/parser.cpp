// parser.cpp

#include <sstream>
#include "parser.hpp"

// 1. Individual Command Sequences -- Split on semi-colons.
// 2. Concurrently -- Split on ampersand (& connecter).
// 3. Pieces of Commands -- Split on spaces.

// TODO:
// - Initialize the parser class
// - Format for the commands
// - Validation checking (regular expressions)

std::vector<Command> parse(std::string input) {
    std::stringstream ss(input);
    std::string line;
    std::vector<Command> commands;
    while (std::getline(ss, line, ';')) {
        std::cout << line << '\n';
    }

    // ls -lh
    // ls /home/ -lh
    // Command {
        // command: ls
        // arguments: std::vector<string> "l, h"
        // flags: std::vector<string> "-"
    // }

    // Vector commands prefixes?
    return commands;
}
