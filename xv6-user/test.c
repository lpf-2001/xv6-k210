#include "kernel/include/types.h"
#include "kernel/include/time.h"
#include "xv6-user/user.h"

struct tms {
  uint64 utime;   // user time 
  uint64 stime;   // system time 
  uint64 cutime;    // user time of children 
  uint64 cstime;    // system time of children 
};

int test_times()
{
	struct tms t;
	int status;
	int pid = fork();
	if(pid > 0){
		wait(&status);
		uint64 ticks = times(&t);
		printf("parent process:\n");
		printf("the usertime of the process: %d\n",ticks);
		printf("utime:%d,stime:%d,cutime:%d,cstime:%d\n",t.utime,t.stime,t.cutime,t.cstime);
	}else if(pid == 0){
		printf("Hello from child process!\n");

		exit(0);
	}else{
		printf("fork error\n");
	}
	return 0;
}

int test_mem()
{
	return getmem();
}

int main(void) {
	printf("memory size:%d",test_mem());
	exit(0);
    return 0;
}


