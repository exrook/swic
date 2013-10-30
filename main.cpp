#include <iostream>
#include <string>

int main(int argc, char **argv) {
  //parse options
  for(int i=1; i<argc; i++) {
    if (argv[i] == std::string("-h")) {
      std::cout << "Usage: swic [-h]" << std::endl;
    }
  }
  //put real code here
}
