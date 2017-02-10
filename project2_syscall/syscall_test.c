#include "userprocs.h"
#include <string.h>

void return_procs(char *uname, struct user_proc **taskptr) {
	
	struct user_proc *task = (struct user_proc*) malloc(sizeof(struct user_proc));
	task->tty = malloc(sizeof(char) * 100);
	task->comm = malloc(sizeof(char) * 500);
	
	task->pid = 12;
	strcpy(task->tty, "term 1");
	task->time_in_seconds = 34;
	strcpy(task->comm, "proc1");
	task->next = NULL;

	*taskptr = task;
}
