#include "userprocs.h"

#include <asm/uaccess.h>
#include <linux/cred.h>
#include <linux/slab.h>
#include <linux/syscalls.h>
#include <linux/sched.h>
#include <linux/tty.h>
#include <linux/kernel.h>

// we need to see if and how we can pass a custom stucture to a syscall
asmlinkage long sys_userprocs (struct user_proc **taskptr) {

	unsigned int size = 0;
	unsigned int proc_size = sizeof(struct user_proc);
	struct task_struct *task = current;
	struct user_proc *procs_head = NULL;
	struct user_proc *proc = procs_head;
	
	for_each_process(task) {

		if (uid_eq(current_uid(), task->cred->uid)) {
			int time_in_seconds = task->utime / HZ;

			// assign the values in task to the struct defined in userprocs.h
			// then add it to the linked list
			proc = kmalloc(proc_size, GFP_KERNEL);
			proc->pid = task->pid;
			proc->tty = tty_name(task->signal->tty);
			proc->time_in_seconds = time_in_seconds;
			proc->comm = task->comm;

			printk("Pid of task is %d\n", task->pid);
			printk("Pid of my proc is %d\n", proc->pid);

			proc = proc->next;
			size += proc_size;
		}
	}
	// we need to copy the task list to the userspace, I think this is the copy_to_user
	// function, but I'm fuzzy on the implementation

	if (copy_to_user(*taskptr, procs_head, size)) {
		return -EFAULT;
	}

	return 0;
}
