/*  
 *  hello−1.c − The simplest kernel module.
 */
#include <linux/module.h>       /* Needed by all modules */
#include <linux/kernel.h>       /* Needed for KERN_INFO */

void my_name(void);

int init_module (void) {

	my_name();
        
        /* 
         * A non 0 return means init_module failed; module can't be loaded.
         */
        return 0;
}

void cleanup_module(void) {

}

void my_name(void) {
	printk(KERN_INFO "Kernel Developers:\n\tJason Price\n\tJoseph Thweatt");
}
