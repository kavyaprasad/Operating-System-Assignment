#include <xinu.h>
#include <prodcons.h>
;
 
 	int32 n;                 //Definition for global variable 'n'
	/*Now global variable n will be on Heap so it is accessible all the processes i.e. consume and produce*/

	sid32 produced, consumed;

shellcmd xsh_prodcons(int nargs, char *args[])
{	
 	int32 count=0;
  	count = 2000;		//local varible to hold count
	if(nargs > 2)
	{
        	printf("Prodcons : Too many arguments, only one argument is allowed ");
         	printf("\noptions --help for more details");
		return 1;
	}
 	if(nargs==2)
	{
		if(strncmp(args[1], "--help", 7) == 0) 
        	{
			printf("Prodcons : Takes an optional integer parameter to display producer consumer synchronisation\n");
			printf("Syntax : prodcons <optional_parameter>");
			return 0;
		}
     		else
		{
			count=atoi(args[1]);
		}
	}
	
	produced = semcreate(0);
	consumed = semcreate(1);

	//create the process producer and consumer and put them in ready queue.
	//Look at the definations of function create and resume in exinu/system folder for reference.      
	resume( create(producer, 1024, 20, "producer", 1, count) );
	resume( create(consumer, 1024, 20, "consumer", 1, count) );
	return (0);
 }