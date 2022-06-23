#include "kernel/include/types.h"
#include "kernel/include/stat.h"
#include "kernel/include/sysinfo.h"
#include "xv6-user/user.h"

struct tms {
  uint64 utime;   // user time 
  uint64 stime;   // system time 
  uint64 cutime;    // user time of children 
  uint64 cstime;    // system time of children 
};

int main()
{
    struct tms tm;
    printf("%d\n",times(&tm));
    printf("utime:%d\n",tm.utime);
    printf("stime:%d\n",tm.stime);
    printf("cutime:%d\n",tm.cutime);
    printf("cstime:%d\n",tm.cstime);
    exit(0);
}                                                    //2 times test