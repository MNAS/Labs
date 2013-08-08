
#include <iostream>
#include <chrono>
#include <thread>

/*
/n Launches a separate instance of Acrobat or Adobe Reader, even if one is currently open.
/s Opens Acrobat or Adobe Reader,suppressing the splash screen.
/o Opens Acrobat or Adobe Reader, suppressing the open file dialog.
/h Opens Acrobat or Adobe Reader in a minimized window.
*/

//AcroRd32.exe /t path "printername" "drivername" "portname"

/*
int main(int argc, char **argv)
{
    std::cout << "Hello waiter"; std::cout.flush();
    std::chrono::seconds dura( 1 );
    do
    {
        std::this_thread::sleep_for( dura );
        std::cout << "."; std::cout.flush();
    } while(true);
    return 0;
}
*/

/* system example : DIR */
#include <stdio.h>      /* printf */
#include <stdlib.h>     /* system, NULL, EXIT_FAILURE */

int main ()
{
  int i;
  printf ("Checking if processor is available...");
  if (system(NULL)) puts ("Ok");
    else exit (EXIT_FAILURE);
  printf ("Executing command DIR...\n");
  i=system ("dir");
  printf ("The value returned was: %d.\n",i);
  return 0;
}


/* 
#include <iostream>
#include <chrono>

using namespace std;
using namespace chrono;

int main()
{
    // the current time
    time_point<system_clock> now(system_clock::now());
    std::chrono::time_point<>

    // its value in seconds:
    cout << system_clock::to_time_t(now) << '\n';

    // now + two hours:
    cout << system_clock::to_time_t(now + hours(2)) << '\n';

    // define a time_point 1 hour after the epoch:
    time_point<system_clock> oneHrLater(hours(1));

    // show the epoch and the time in seconds of oneHrLater:
    cout << system_clock::to_time_t(time_point<system_clock>()) << ' ' <<
         system_clock::to_time_t(oneHrLater) << '\n';
}
*/
