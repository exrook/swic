swic
====
StopWatch Including Clock (and a timer)

Synopsis:  
        swic [OPTION]

Description:
	By default, swic acts as a stopwatch.
        
        [OPTIONS] are:
        
    	-h
        	Display help
        -t ```[[[[[YEARS:]WEEKS:]DAYS:]HOURS:]MINUTES:]<SECONDS>```
        	Specify the duration for the timer. Exits on completion.
        -c <loop>
		        Display the current time, optionally in a loop. Loop can be anything. 
	        	As of this version, it CAN NOT be used to continously display the stopwatch or timer values.

Exit Status:
	0 if OK
	1 if error occured during parsing -t
	2 if value of input is wayy too high or 0, or doesn't exist. 
AUTHOR
	Written by Raj Shrimali and Jacob Hughes

REPORTING BUGS
	Report a bug to rajshrimali@gmail.com or jhughes@distanthills.org

COPYRIGHT
	This software is licensed under a GPLv3 lisence.
	This is free software; you are free to change and redistribute it.
