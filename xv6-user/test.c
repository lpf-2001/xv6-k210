#include "kernel/include/types.h"
#include "kernel/include/stat.h"
#include "kernel/include/sysinfo.h"
#include "xv6-user/user.h"
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
    printf("unreachable!");
  }
}


int main() {
  test_alarm();
  exit(0);
}
