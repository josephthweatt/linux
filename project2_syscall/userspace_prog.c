#include <linux/unistd.h>
#include <stdio.h>
#define __NR_my_syscall 330

int main() {
	char uname[256];

	printf("Enter your username:\n");
	scanf("%s", uname);

	syscall(__NR_my_syscall, uname);
	return 0;
}
