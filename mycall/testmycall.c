#include <linux/unistd.h>
#define __NR_my_syscall 329

int main() {
	syscall(__NR_my_syscall);
	return 0;
}
