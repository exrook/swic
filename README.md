swic
====
StopWatch Including Clock (and a timer)



Usage
-----
By default, swic acts as a stopwatch.
	
The available parameters are listed here:

```
-h                 Display help
-t [[[[[YEARS:]WEEKS:]DAYS:]HOURS:]MINUTES:]<SECONDS>
                   Specify the duration for the timer. Exits on completion.
-c <loop>          Display the current time, optionally in a loop. Loop can be anything. As of this version,
                   it CAN NOT be used to continously display the stopwatch or timer values.
```

Exit Codes:
-----------
`0`: Terminated successfully.
`1`: Some Error Occured. See the output (to STDOUT). 

Authors
-------
Written by Raj Shrimali and Jacob Hughes, with help from Matthew Dean 

Reporting Bugs
--------------
Report bugs on the "[Issues](https://github.com/exrook/swic/issues)" tab on GitHub.

Copyright
---------
This software is licensed under a GPLv3 lisence.
This is free software; you are free to change and redistribute it.
