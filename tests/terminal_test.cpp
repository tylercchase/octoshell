// Octoshell Integration Testing
#include "../src/terminal.hpp"
#include <catch2/catch.hpp>
#include <sstream>
TEST_CASE("Internal Commands", "[terminal]") {
  Terminal t;

  SECTION("print") {
    auto c = Command("print");
    auto output = t.execute(c);
    auto match_expression = Catch::Matches("\\d+");
    REQUIRE_THAT(output, match_expression);
  }

  SECTION("help") {
    auto c = Command("help");
    auto output = t.execute(c);
    std::ostringstream help;
    help << "help - displays this menu\n"
         << "exit - closes the shell\n"
         << "print - shell's current process id\n"
         << "cd - navigate to another directory";
    REQUIRE(output == help.str());
  }

  SECTION("cd") {
    auto pwd = Command("pwd");
    auto cd = Command("cd", {".."});
    auto start = t.execute(pwd);
    t.execute(cd);
    auto end = t.execute(pwd);
    REQUIRE(start != end);
  }
}

TEST_CASE("External Commands", "[terminal]") {
  Terminal t;

  SECTION("ls") {
    auto c = Command("/bin/ls");
    auto output = t.execute(c);
    // TODO: REQUIRE( output == "ls");
  }
}
