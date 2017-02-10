#include "userprocs.h"
#include <string.h>

void return_procs(char *uname, struct user_proc **taskptr) {

	// create two programs (task->task2->NULL) and give to taskptr
	
	struct user_proc *task = (struct user_proc*) malloc(sizeof(struct user_proc));
	task->tty = malloc(sizeof(char) * 100);
	task->comm = malloc(sizeof(char) * 500);
	
	task->pid = 12;
	strcpy(task->tty, "term 1");
	task->time_in_seconds = 34;
	strcpy(task->comm, "proc1");

	
	struct user_proc *task2 = (struct user_proc*) malloc(sizeof(struct user_proc));
	task2->tty = malloc(sizeof(char) * 100);
	task2->comm = malloc(sizeof(char) * 500);

	task2->pid = 24;
	strcpy(task2->tty, "term 2");
	task2->time_in_seconds = 65;
	strcpy(task2->comm, "proc2");

	task->next = task2;
	*taskptr = task;
}
