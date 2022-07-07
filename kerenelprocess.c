//kcode/kproc
#include <sys/thread.h>
#include <stdio.h>
static struct proc*buydaemonproc;
static struct kproc_desc buy_kp={
    "bydaemon",buy_daemon,*buydaemonproc
};
SYSINIT(buydaemon,SI_SUB_KTHREAD,SI_ORDER,FIRST,kproc_start,&buy_kp)
static void buy_daemon()
{
    kproc_start();
    kproc_suspend();
    EVENTHANDLER_REGISTER(shutdown_pre.sync,kproc_shutdown,buydaemonproc,SHUTDOWN_DRI_LAST)
    for (;;)
    {
        kproc_suspend_check(buydaemonproc);
    }
}