#include <catch2/catch.hpp>
#include "../src/parser.hpp"

TEST_CASE( "Parser Test", "[parser]" ) {
    SECTION("Single command sequence") {
        std::string input("ls");
        std::vector<Command> commands = parse(input);
        REQUIRE(commands.size() == 1);
        REQUIRE(commands[0].get_command() == "ls");
    }
}
