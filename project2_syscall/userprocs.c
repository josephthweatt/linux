#include "userprocs.h"
#include <linux/cred.h>
#include <linux/syscalls.h>
#include <linux/sched.h>
#include <linux/kernel.h>

#include <string.h>
#include <stdio.h>

// we need to see if and how we can pass a custom stucture to a syscall
asmlinkage long sys_userprocs (task_struct **taskptr) {

	struct task_struct *task = current;

	
	for_each_process(task) {

		if (current_uid() == task->cred->uid) {
			int time_in_seconds = task->utime / HZ;

//			printf("%s\t%d\t%s\t%d\t%s\n", 
//				uname, task->pid, task->signal->tty,
//				time_in_seconds, task->comm);
			// assign the values in task to the struct defined in userprocs.h
			// then add it to the linked list
			

		}
	}
	// we need to copy the task list to the userspace, I think this is the copy_to_user
	// function, but I'm fuzzy on the implementation 

	return 0;
}
