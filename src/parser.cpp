// parser.cpp

#include <sstream>
#include <algorithm>

#include "parser.hpp"

// 1. Individual Command Sequences: split on semi-colons.
// 2. Concurrently: split on ampersand (& -> connecter).
// 3. Pieces of Commands: split on spaces.

// TODO (Command Continue Structure):
// - Initialize the parser class.
// - Format for the commands.
// - Validation checking (regular expressions).
// - Split the input into individual command sequences.
//      - Split on semicolon (;).
//      - Split on ampersand (&).
//      - Get the command [xyz] and arguments.

std::vector<Command> parse(std::string input) {
    std::stringstream ss(input);
    std::string line;
    std::vector<Command> commands;

    while (std::getline(ss, line, ';')) {
        std::string command;
        
        std::stringstream ss2(line);
        std::string line2;
        std::vector<std::vector<std::string>> sequences;
        std::vector<std::string> args;

        while (std::getline(ss2, line2, '&')) {
            std::stringstream ss3(line2);
            std::string line3;
            std::vector<std::string> things;
            while (std::getline(ss3, line3, ' ')) {
                if (line3.length() > 0) {
                    things.push_back(line3);
                }
            }
            sequences.push_back(things);
        }
        
        for(auto output : sequences) {
            command = output[0];
            output.erase(output.begin());

            std::vector<std::string> flags;

            for(std::string x : output) {
                if(x.find("-") != std::string::npos) {
                    for(char y : x) {
                        if(y != '-') {
                        flags.push_back(std::string(1, y));
                        }
                    }
                } else {
                    args.push_back(x);
                }
            }
            commands.push_back(Command(command, args, flags));
        }
    }
    
    return commands;
}
