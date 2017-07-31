#include <xinu.h>
#include <prodcons.h>
;

void consumer(int count)
{
	int32 i;
	for(i=1;i<=count;i++)
	{
		wait(produced);
		printf("\n consumed item is %d",n);
		signal(consumed);
 	}
}