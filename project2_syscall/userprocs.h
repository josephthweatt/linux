#include <stdio.h>
#include <stdlib.h>

// data for a user's process
struct user_proc {
	int pid;
	char *tty;
	int time_in_seconds;
	char *comm;

	struct user_proc *next;
};
void return_procs(char *uname, struct user_proc **taskptr);
