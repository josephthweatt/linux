#include "userprocs.h"

#include <asm/uaccess.h>
#include <linux/cred.h>
#include <linux/syscalls.h>
#include <linux/sched.h>
#include <linux/kernel.h>

#include <string.h>

// we need to see if and how we can pass a custom stucture to a syscall
asmlinkage long sys_userprocs (task_struct **taskptr) {

	unsigned int size = 0;
	unsigned int proc_size = sizeof(struct user_proc);
	struct user_proc *procs_head, *proc;
	struct task_struct *task = current;

	proc = procs_head;
	
	for_each_process(task) {

		if (current_uid() == task->cred->uid) {
			int time_in_seconds = task->utime / HZ;

			// assign the values in task to the struct defined in userprocs.h
			// then add it to the linked list
			proc = (struct user_proc*) malloc(proc_size);
			proc->pid = task->pid;
			proc->tty = task->signal->tty;
			proc->time_in_seconds = time_in_seconds;
			proc->comm = task->comm;

			proc = proc->next;
			size += proc_size;
		}
	}
	// we need to copy the task list to the userspace, I think this is the copy_to_user
	// function, but I'm fuzzy on the implementation

	if (copy_to_user(*taskptr, task, size)) {
		return -EFAULT;
	}

	return 0;
}
