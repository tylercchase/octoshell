// parser.cpp

#include <sstream>
#include "parser.hpp"

// 1. Individual Command Sequences: split on semi-colons.
// 2. Concurrently: split on ampersand (& connecter).
// 3. Pieces of Commands: split on spaces.

// TODO:
// - Initialize the parser class.
// - Format for the commands.
// - Validation checking (regular expressions).

std::vector<Command> parse(std::string input) {
    std::stringstream ss(input);
    std::string line;
    std::vector<Command> commands;
    while (std::getline(ss, line, ';')) {
        std::string command;
        std::stringstream ss2(input);
        std::string line2;
        std::vector<std::string> output;
        std::vector<std::string> args;
        while(std::getline(ss2, line2, ' ')) {
            output.push_back(line2);
        }
        command = output[0];
        output.erase(output.begin());
        // find the command

        // find the flags
        std::vector<std::string> flags;

        for(std::string x : output) {
            if(x.find("-") != std::string::npos) {
                for(char y : x) {
                    if(y != '-') {
                        flags.push_back(std::string(1,y));
                    }
                }
            } else {
                args.push_back(x);
            }
        }

        commands.push_back(Command(command, args, flags));
    }
    
    return commands;
}
