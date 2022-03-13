// main.cpp
// Tyler Chase
// Solomon Himelbloom
// 2022-03-12
//
// For CS 321 Spring 2022
// Final Project: Octoshell

#include <cassert>
#include <cstdlib>
#include <iostream>
#include <string>
#include <utility>

// userPause
// Wait for user to press ENTER: read all chars through first newline.
void userPause() {
    std::cout.flush();
    while (std::cin.get() != '\n') ;
}

// Main program
int main() {
    std::cout << "Hello, world." << std::endl;

    // Wait for user
    std::cout << "Press ENTER to quit ";
    userPause();
}
