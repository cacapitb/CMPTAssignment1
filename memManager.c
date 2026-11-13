#include <stdio.h>
#include <stdlib.h>

#include  "memManager.h"
	char mem[HEAP_SIZE];
void initializeMemory()
{
	Header * head = (Header *) mem;
	head->len = 65228;
	/*int footpos = sizeof(Header) + head->len;
	Footer * foot = (Footer *)&mem[footpos];
	foot->len = 65228;
	*/
}
