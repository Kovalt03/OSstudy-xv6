#include "types.h"
#include "riscv.h"
#include "defs.h"

int myfunction(char *str){
	printf("%s\n", str);
	return 0xABCDABCD;
}


int
sys_myfunction(void)
{
	char str[100];
	//Decode argument using argstr
	if (argstr(0,str,100) < 0)
		return -1;
	return myfunction(str);
}
