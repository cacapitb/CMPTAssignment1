#include <stdio.h>
#include <stdlib.h>
#include  "memHelper.h"
#include  "memManager.h"
char mem[HEAP_SIZE];

void initializeMemory()
{
	Header * head = (Header *) mem;
	head->len = HEAP_SIZE - 8;
	Footer * foot = get_footer_pos(head);
	foot->len = HEAP_SIZE - 8;
}

void *myMalloc(unsigned int sz)
{
	int reqSize = alignment(sz);
	Header * head = (Header *)mem;
	Footer * foot = get_footer_pos(head);

	char * limit = mem + HEAP_SIZE;

	while ((char *)head < limit)
	{
		if(foot->len %2 == 0 && head->len >= reqSize)
		{
			int remaining = head->len - reqSize;

			if(remaining > 12)
			{
				head->len = reqSize;
				Footer * newfoot = get_footer_pos(head);
				newfoot->len = reqSize + 1;

				Header * newhead = get_next_header(head);
				newhead->len = remaining -8;
				foot->len = remaining - 8;

			}
			else
			{
				foot->len += 1;
			}
			
			return head;
		}
		
		head = get_next_header(head);
		foot = get_footer_pos(head);
	}
	
	printf("\nAllocation Failed. Returning NULL\n");
	return NULL;
}

void myFree(void * ptr)
{
	Header * head = (Header *)ptr;
	Footer * foot = get_footer_pos(head);
	foot->len -= 1;

	Header * nexthead = get_next_header(head);

	char * limit = mem + HEAP_SIZE;

	if((char *)nexthead < limit)
	{
		Footer * nextfoot = get_footer_pos(nexthead);
		if(nextfoot->len % 2 == 0)
		{
			head->len = head->len + 8 + nexthead->len;
			nextfoot->len = head->len;
			foot = nextfoot;
		}
		
	}
	
	if ((char *)head > mem)
	{
		Footer * prevfoot = get_prev_footer(head);
		if (prevfoot->len % 2 == 0)
		{
			Header * prevhead = get_prev_header(head);
			prevhead->len = prevhead->len + 8 + head->len;
			foot->len = prevhead->len;
		}
		
	}
	
}
