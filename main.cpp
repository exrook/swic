#include <iostream>
#include <string>
#include <chrono>
using namespace std::chrono;

int stopwatch();
int timer(seconds); 
int main(int argc, char **argv) {
  //parse options
  for(int i=1; i<argc; i++) {
    if (argv[i] ==( std::string("-t"))){
      if (i+1 >= argc)
        return 1;
      std::string in(argv[i+1]);
      int colonc = 0;
      short colonp[in.length()];
      for(int j=0; j < in.length(); j++) {
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
      std::cout << argv[0] << " -t <time> - wait until time, then exit" << std::endl;
      std::cout << argv[0] << " <time> should be in format HHH:MM:SS:MS. Include 0's even if you aren't using it, so 1 second will be: 000:00:01:00" << std::endl;  }
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
  //Get the start loop
  auto endT = high_resolution_clock::now() + count;
  //std::cout <<  count.count() << std::endl
  //<< (<duration_cast<seconds>>endT).count() << std::endl;
  while( high_resolution_clock::now() != endT ){
    auto t = high_resolution_clock::now() - endT ;
    if( t < std::chrono::milliseconds(5) || t >-( std::chrono::milliseconds(5))) {
      std::cout << "Timer Complete" << std::endl; 
      return 0;
    }
  }
}
