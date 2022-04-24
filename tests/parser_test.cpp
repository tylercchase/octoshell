#include "../src/parser.hpp"
#include <catch2/catch.hpp>

TEST_CASE("Parser Test", "[parser]") {
  SECTION("Single command") {
    std::string input("ls");
    std::vector<Command> commands = parse(input);
    REQUIRE(commands.size() == 1);
    REQUIRE(commands[0].get_command() == "ls");
  }
  SECTION("Single command with flags") {
    std::string input("ls -lh");
    std::vector<Command> commands = parse(input);
    REQUIRE(commands.size() == 1);
    REQUIRE(commands[0].get_command() == "ls");
    REQUIRE(commands[0].get_flags() == std::vector<std::string>{"l", "h"});
  }
  SECTION("Single command with arguments") {
    std::string input("ls /home/");
    std::vector<Command> commands = parse(input);
    REQUIRE(commands.size() == 1);
    REQUIRE(commands[0].get_command() == "ls");
    REQUIRE(commands[0].get_arguments() == std::vector<std::string>{"/home/"});
  }
  SECTION("Single command with flags and arguments") {
    std::string input("ls -lh /home/");
    std::vector<Command> commands = parse(input);
    REQUIRE(commands.size() == 1);
    REQUIRE(commands[0].get_command() == "ls");
    REQUIRE(commands[0].get_flags() == std::vector<std::string>{"l", "h"});
    REQUIRE(commands[0].get_arguments() == std::vector<std::string>{"/home/"});
  }
}
TEST_CASE("Parser multiple command") {
  SECTION("Multiple commands with ampersand") {
    std::string input("ls -lh & echo hello");
    std::vector<Command> commands = parse(input);
    REQUIRE(commands.size() == 2);
    REQUIRE(commands[0].get_command() == "ls");
    REQUIRE(commands[0].get_flags() == std::vector<std::string>{"l", "h"});
    REQUIRE(commands[1].get_command() == "echo");
    REQUIRE(commands[1].get_arguments() == std::vector<std::string>{"hello"});
  }
  SECTION("Multiple commands with semicolon") {
    std::string input("ls -lh; echo hello");
    std::vector<Command> commands = parse(input);
    REQUIRE(commands.size() == 2);
    REQUIRE(commands[0].get_command() == "ls");
    REQUIRE(commands[0].get_flags() == std::vector<std::string>{"l", "h"});
    REQUIRE(commands[1].get_command() == "echo");
    REQUIRE(commands[1].get_arguments() == std::vector<std::string>{"hello"});
  }
  SECTION("Multiple commands with ampersand and semicolon") {
    std::string input("ls -lh & echo hello; pwd");
    std::vector<Command> commands = parse(input);
    REQUIRE(commands.size() == 3);
    REQUIRE(commands[0].get_command() == "ls");
    REQUIRE(commands[0].get_flags() == std::vector<std::string>{"l", "h"});
    REQUIRE(commands[1].get_command() == "echo");
    REQUIRE(commands[1].get_arguments() == std::vector<std::string>{"hello"});
    REQUIRE(commands[2].get_command() == "pwd");
  }
}
