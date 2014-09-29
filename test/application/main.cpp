// main.cpp

#include <stdio.h>

#include <iostream>
#include <boost/filesystem.hpp>
using namespace boost::filesystem;

// to test boost lib link and usage
int validateBoost(int argc, char* argv[]);

int main(int argc, char* argv[]) {

    validateBoost(argc, argv);
    return 0;
}

int validateBoost(int argc, char* argv[]) {

  if (argc < 2)
  {
    std::cout << "Usage: application path\n";
    return 1;
  }
  std::cout << argv[1] << " " << file_size(argv[1]) << '\n';
}