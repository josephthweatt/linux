#include <linux/syscalls.h>
#include <linux/kernel.h>

asmlinkage long sys_userprocs (char uname[256]) {



}


/**
 * Trying to keep this systemcall clean, we may need to add
 * more code here, because I have no idea how we are getting
 * the process info.
 */
void print_process (char uname[256], int pid, char tty[32],
			char time [12], char command[256]) {

	printf("%s\t%d\t%s\t%s\t%s\n", uname, pid, tty, time, command);
}
