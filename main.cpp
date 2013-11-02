#include <iostream>
#include <string>
#include <chrono>
#include <thread>
using namespace std::chrono;

int timer(seconds); 
int stopwatch();
int showclock(bool repeat=false);

int main(int argc, char **argv) {
  //parse options
  for(int i=1; i<argc; i++) {
    if (argv[i] == (std::string("-c"))) {
      if (argc > 2)
        return showclock(true);
      return showclock();
    } else if (argv[i] ==( std::string("-t"))){
      if (i+1 >= argc)
        return 1;
      std::string in(argv[i+1]);
      int colonc = 0;
      short colonp[in.length()];
      for(unsigned int j=0; j < in.length(); j++) {
        if (in[j] == ':') 
          colonp[colonc++] = j;
      }
      int times[colonc];
      times[0] = std::stoi(in.substr(0,colonp[0]));
      for(int j=0; j < colonc; j++) {
        times[j+1] = std::stoi(in.substr(colonp[j]+1, colonp[j+1]-colonp[j]-1));
      }
      int sum = times[colonc];
      for(int j=colonc-1; j >= 0; j--) {
        switch (colonc-j) {
          case 1: //minutes
            sum += times[j]*60;
            break;
          case 2: //hours
            sum += times[j]*60*60;
            break;
          case 3: //days
            sum += times[j]*60*60*24;
            break;
          case 4: //weeks
            sum += times[j]*60*60*24*7;
            break;
          case 5: //years
            sum += times[j]*60*60*24*365.25;
            break;
        }
      }
      return timer(seconds(sum));
    } else /*if (argv[i] == std::string("-h"))*/ {
      std::cout << "Usage:" << std::endl;
      std::cout << argv[0] << "           - act as a stopwatch, stoping when input is recieved" << std::endl;
      std::cout << argv[0] << " -c <loop> - displays the current date and time, optionally in a loop" << std::endl ;
      std::cout << argv[0] << " -t [[[[[years:]weeks:]days:]hours:]minutes:]<seconds> - wait for specified duration, then exit" << std::endl;
      return 0;
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

int timer(seconds count) {
  auto t1 = high_resolution_clock::now();
  auto t2 = t1+count;
  while ( t2 > high_resolution_clock::now()) {
    std::this_thread::sleep_for(milliseconds(100));
  }
  std::cout << "Finished" << std::endl;
  return 0;
}

int showclock(bool repeat) {
  auto t1 = system_clock::to_time_t(system_clock::now());
  if (!repeat) {
    std::cout << ctime(&t1);
    return 0;
  }
  while(true) {
    t1 = system_clock::to_time_t(system_clock::now());
    std::cout << ctime(&t1);
    std::this_thread::sleep_for(seconds(1));
  }
}
