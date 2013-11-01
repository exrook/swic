#include <iostream>
#include <string>
#include <chrono>
using namespace std::chrono;

int stopwatch();
int timer(milliseconds); 
int main(int argc, char **argv) {
  //parse options
  for(int i=1; i<argc; i++) {
    if (argv[i] ==( std::string("-t"))){
      //parse their time input. They should have strings. 
      //first check and make sure its a valid string!!! 
      if(std::string(argv[i+1]).std::string::length()%2  != 0){
        std::cout << "Improper time given. Try again" << std::endl; 
        return 1; 
      } 
      //create a variable to keep track of stuff
      hours h ( std::stoi(std::string(argv[i+1]).substr(0,2), nullptr, 10));
      minutes m( std::stoi(std::string(argv[i+1]).substr(4,5), nullptr, 10)); 
      seconds s( std::stoi(std::string(argv[i+1]).substr(7,8), nullptr, 10)); 
      milliseconds ms(std::stoi(std::string(argv[i+1]).substr(10,11), nullptr,10));
      //The max a millisecond can hold is 45 bits, which is a lot more than we need. 
      milliseconds total; 
      //The nice thing is that you can do implicit conversions. 
      total = total + h + m + ms; 
      return timer(total);

    } else /*if (argv[i] == std::string("-h"))*/ {
      std::cout << "Usage:" << std::endl;
      std::cout << argv[0] << "           - act as a stopwatch, stoping when input is recieved" << std::endl;
  }
      std::cout << argv[0] << " -t <time> - wait until time, then exit" << std::endl;
      std::cout << argv[0] << " <time> should be in format HHH:MM:SS:MS. Include 0's even if you aren't using it, so 1 second will be: 000:00:01:00" << std::endl;  }
  return stopwatch();
}

int stopwatch() {
  auto t1 = high_resolution_clock::now();
  std::cin.ignore();
  auto t2 = high_resolution_clock::now();
  std::cout <<  (duration_cast<duration<double>>(t2-t1)).count() << std::endl;
  return 0;
}

  
int timer(milliseconds count) {
  return 0;
}
