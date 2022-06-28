


#define __module_name__		"signal"

#include "include/proc.h"
#include "include/signal.h"


#include "include/types.h"
#include "include/param.h"
#include "include/memlayout.h"
#include "include/riscv.h"
#include "include/spinlock.h"






void sighandle(void)
{

	struct proc *p = myproc();
	if(p->signum==SIGALARM)
	{
		p->flag=1;
  		p->alarm_tick=0;
	}
}