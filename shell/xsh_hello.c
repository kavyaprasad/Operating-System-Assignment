/* xsh_hello.c - xsh_hello*/

#include <xinu.h>
#include <string.h>

#include<stdio.h>

/*------------------------------------------------------------------------
 * xsh_hello - Prints a hello message to a user and throws an error if the arguments are too few or more
 *------------------------------------------------------------------------
 */
shellcmd xsh_hello(int nargs, char *args[]){
	if(nargs==2){
		printf("Hello %s, Welcome to the world of Xinu!!\n", args[1]);
		return 0;
	}
	/* Checking for less nos of argument */
	else if(nargs <2) {
		printf("Too few arguments\n");
		return 1;
	}
	/* Checking for more than 1 no of argument */
	else if(nargs > 2) {
		printf("Too many arguments\n");
		return 1;
	}
	return 0;
}