// Octoshell Integration Testing
#include "../src/terminal.hpp"
#include <catch2/catch.hpp>

TEST_CASE("Internal Commands", "[terminal][!mayfail]") {
    Terminal t;

    SECTION("print") {
        auto c = Command("print");
        auto output = t.execute(c);
        REQUIRE( output == "print");
    }

    SECTION("exit") {
        auto c = Command("exit");
        auto output = t.execute(c);
        REQUIRE( output == "exit");
    }

    SECTION("help") {
        auto c = Command("help");
        auto output = t.execute(c);
        REQUIRE( output == "help");
    }

    SECTION("cd") {
        auto pwd = Command("pwd");
        auto cd = Command("cd", {".."});
        auto start = t.execute(pwd);
        t.execute(cd);
        auto end = t.execute(pwd);
        REQUIRE( start != end );
    }
}

TEST_CASE("External Commands", "[terminal][!mayfail]") {
    Terminal t;

    SECTION("ls") {
        auto c = Command("/bin/ls");
        auto output = t.execute(c);
        // REQUIRE( output == "ls");
    }
}
