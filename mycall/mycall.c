#include<linux/syscalls.h>
#include<linux/kernel.h>

asmlinkage long sys_mycall (void) {

	printk("This is the new systemcall Joseph Thweatt & Jason Price implemented");
	return 0;
}
