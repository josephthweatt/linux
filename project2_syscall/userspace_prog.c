#include "userprocs.h"
#include <stdio.h>
#include <linux/unistd.h>
#include <sys/syscall.h>

#define __NR_my_syscall 330

int main() {
	char *uname;
	struct user_proc *task;

	printf("Enter your username:\n");
	scanf("%s", uname);

	syscall(__NR_my_syscall, &task);

	printf("User\tPID\tTTY\tTime\tCommand\n");

	while (task) {

		if (task->pid) {
			printf("%d", task->pid);
		}

		printf("\n%s\t%d\t%s\t%d\t%s\n", 
					uname, task->pid, task->tty,
					task->time_in_seconds, task->comm);
		task = task->next;
	}

	return 0;
}
