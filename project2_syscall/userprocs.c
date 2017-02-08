#include <linux/cred.h>
#include <linux/syscalls.h>
#include <linux/sched.h>
#include <linux/kernel.h>

#include <string.h>
#include <stdio.h>

asmlinkage long sys_userprocs (char uname[256]) {

	struct task_struct *task = current;

	printf("User\tPID\tTTY\tTime\tCommand\n");
	for_each_process(task) {

		if (current_uid() == task->cred->uid) {
			int time_in_seconds = task->utime / HZ;

			printf("%s\t%d\t%s\t%d\t%s\n", 
				uname, task->pid, task->signal->tty,
				time_in_seconds, task->comm);
		}
	}

	return 0;
}
