#include "kernel/include/types.h"
#include "kernel/include/stat.h"
#include "kernel/include/sysinfo.h"
#include "xv6-user/user.h"
#include "kernel/include/signal.h"
void test_getmem()
{
  struct sysinfo info;
    if (sysinfo(&info) < 0) {
        printf("sysinfo fail!\n");
    } else {
        printf("memory left: %d KB\n", info.freemem >> 10);
        printf("process amount: %d\n", info.nproc);
    }
}

int test_alarm()
{
  printf("Alarm testing!\n");
    
  alarm(5);         // send SIGALARM to calling process after 5 seconds, which means terminating it
  while(1)
  {   // process suspended, waiting for signals to wake up
//    printf("unreachable!");
  }
}


int test_signal()
{

  printf("Alarm testing!\n");

  alarm (5);
  
  printf("Waiting for alarm to go off\n");
  (void) signal ( SIGALARM, SIG_IGN );
 
  pause();      //process suspended, waiting for signals to wake up
  //while(1);
  printf("now reachable!\n");

  exit(0);
}

//simulates an alarm clock
void ding ( int sig )
{
  printf("GGGGGG\n");
  printf("Alarm has gone off\n");
}

int test_signal2()
{


  printf("Alarm testing!\n");

  alarm (5);

  printf("Waiting for alarm to go off\n");
  (void) signal ( SIGALARM, ding );

  pause();      //process suspended, waiting for signals to wake up
  printf("Done!\n");

  exit(0);
}

int main() {
  test_signal2();
  exit(0);
}
