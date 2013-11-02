#include <iostream>
#include <string>
#include <chrono>
#include <thread>
using namespace std::chrono;

int timer(seconds); 
int stopwatch();
int showclock(bool repeat=false);
std::string humanreadabletime(double); 

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
  std::cout << humanreadabletime((duration_cast<duration<double>>(t2-t1)).count())<< std::endl;
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
std::string humanreadabletime(double seconds){
  //First, get the integer part. The decimal in this is ms. 
  const int sec = (int) seconds; 
  //now, create a timearray to hold the possible values.
  // We have years, days, hours, minutes, and seconds.
  // Doing weeks can cause loss of precision.  
  //Find if conversion is needed, and if so, how many steps: 
  std::string time = "";
  if( sec > 60 ) {
    //same algorighm for sec --> min, min --> hour 
    int var = sec; 
    for( int i = 0; i < 2; i ++){
      //insert var%60 value into the string 
      time.std::string::insert(0, ":"+ std::to_string(var%60) );
      //make var the normal value again  
      var = (var - (var %60)) / 60; 
    }
    //now for days 
    if(var > 24){
      time.std::string::insert(0, std::to_string(var%24)); 
      var = (var - (var % 24) ) / 24; 
    }
    else{
      time.std::string::insert(0,std:: to_string(var));
    }
    // Its weird putting days in the : format, so they get to be special. 
    if( var > 365 ){ 
      time.std::string::insert(0, std::to_string(var%365) + " Days, " );
      var = (var - (var % 365) ) / 365; 
      time.std::string::insert(0,std::to_string(var) + " Years, ");  
    }
    else{
      time.std::string::insert(0,std::to_string(var) + "Days, "); 
    } 
  }
  //If its less than 60 seconds, 
  else{
    return std::to_string(seconds);
  } 
  time.std::string::append(std::to_string(seconds-sec));
  return time;    
}
  
