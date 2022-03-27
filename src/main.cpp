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

void octoASCII() {
  std::cout
      << "\n\n                    .---.         ,,\n            ,,        /    "
         " \       ;,,'\n        ;, ;      (  o  o )      ; ;\n            "
         ";,';,,,  \  \/ /      ,; ;\n        ,,,  ;,,,,;;,`   '-,;'''',,,'\n  "
         "      ;,, ;,, ,,,,   ,;  ,,,'';;,,;''';\n            ;,,,;    ~~'  "
         "'';,,''',,;''''  \n                            '''\n"
      << std::endl;
}

// Main program
int main() {
  octoASCII();
  std::cout << "----- Welcome to Octoshell! 🐙🐚 -----" << std::endl;
}
