#include <iostream>
#include <string>
#include <chrono>

using namespace std::chrono;

int stopwatch();

int main(int argc, char **argv) {
  //parse options
  for(int i=1; i<argc; i++) {
    if (argv[i] == std::string("-t")) {
      
    } else /*if (argv[i] == std::string("-h"))*/ {
      std::cout << "Usage:" << std::endl;
      std::cout << argv[0] << "           - act as a stopwatch, stoping when input is recieved" << std::endl;
      std::cout << argv[0] << " -t <time> - wait until time, then exit" << std::endl;
    }
  }
  return stopwatch();
}

int stopwatch() {
  auto t1 = high_resolution_clock::now();
  std::cin.ignore();
  auto t2 = high_resolution_clock::now();
  std::cout <<  (duration_cast<duration<double>>(t2-t1)).count() << std::endl;
  return 0;
}

double timer(duration<double> count) {
  return 0;
}
