// Timer Interrupt handler


#include "include/types.h"
#include "include/param.h"
#include "include/riscv.h"
#include "include/sbi.h"
#include "include/spinlock.h"
#include "include/timer.h"
#include "include/printf.h"
#include "include/proc.h"
#include "include/signal.h"

extern struct proc proc[NPROC];
struct spinlock tickslock;
uint ticks;

void timerinit() {
    initlock(&tickslock, "time");
    #ifdef DEBUG
    printf("timerinit\n");
    #endif
}

void
set_next_timeout() {
    // There is a very strange bug,
    // if comment the `printf` line below
    // the timer will not work.

    // this bug seems to disappear automatically
    printf("");
    sbi_set_timer(r_time() + INTERVAL);
}

void timer_tick() {
    //printf("timer_tick------\n");
    acquire(&tickslock);
    ticks++;
    //printf("timer_tick\n");
    struct proc *p;
    
    for(p = proc; p < &proc[NPROC]; p++) {

      if(p->alarm_tick>0)
      {
        p->alarm_tick--;
       // printf("alarm_timer_tick减减\n");
        if(p->alarm_tick==0)
        {
         //   printf("alarm_timer_tick time out    proc pid:%d\n",p->pid);
            if(p->sigaction.sig_flags==0)//没有被signal处理过
                kill(p->pid,SIGALARM);
            else
                kill(p->pid,p->sigaction.sig_type);

        }
      }
    }

    
    wakeup(&ticks);
    release(&tickslock);
    set_next_timeout();
}

