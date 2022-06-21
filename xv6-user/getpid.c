//#include "kernel/include/param.h"
//#include "kernel/include/types.h"
//#include "kernel/include/stat.h"
#include "xv6-user/user.h"
//#include "kernel/include/fcntl.h"
//#include "kernel/include/syscall.h"
//#include "kernel/include/memlayout.h"
//#include "kernel/include/riscv.h"

/*
理想结果：得到进程 pid，注意要关注 pid 是否符合内核逻辑，不要单纯以 Test OK! 作为判断。
*/

int test_getpid()
{
    //TEST_START(__func__);
    int pid = getpid();
    //assert(pid >= 0);
    printf("getpid success.\npid = %d\n", pid);
    //TEST_END(__func__);
    return 0;
}

int main(void) {
	test_getpid();
	exit(0);
    return 0;
}
