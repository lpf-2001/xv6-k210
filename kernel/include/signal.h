#ifndef __SIGNAL_H
#define __SIGNAL_H

#include "types.h"
#include "trap.h"


#define SIGTERM 1
#define SIGALARM  2
#define SIGINT 3

#define SIG_IGN (func)4
#define SIG_FUNC (func)5
#define SIG_DFL (func)6


struct sigaction {
	int sig_flags;
	// void (*sa_restorer)(void);	// this field is not used on risc-v
	int sig_type;
	func sig_action;
	uint64 p;       //执行函数的地址
};

void sighandle(void);

#endif