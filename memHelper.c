#include <stdio.h>
#include <stdlib.h>

#include "memManager.h"

Footer * get_footer_pos(Header *header)
{
	return (Footer *)((char *)header + sizeof(Header) + header->len);
}

Header * get_next_header(Header * header)
{
	return(Header *)((char *)header + sizeof(Header) + sizeof(Footer) +header->len);
}

int alignment(unsigned int sz)
{
	unsigned int remainder = sz % 4;
	if(remainder == 0)
	{
		return sz;
	}
	return sz + (4-remainder);
}

Footer * get_prev_footer(Header * header)
{
	return (Footer *)((char *)header - sizeof(Footer));
}

Header * get_prev_header(Header * header)
{
	Footer * foot = get_prev_footer(header);
	return (Header *)((char *)header - sizeof(Footer) - foot->len - sizeof(Header));
}

void print_break_line()
{
	printf("---------------------------------------------------------\n");
	return;
}

void print_title()
{
	print_break_line();
	printf("|Status    |Start          |Block Size    |End           |\n");
	print_break_line();
}

void print_info_line(int i,unsigned int status, Header * start,unsigned int size, Footer * end)
{
	char * initial = mem;

	printf("|");
	
	if(status == 0)
	{
		printf("Free      |");
	}
	else
	{
		printf("Occupied  |");
	}

	if(i == 0)
	{
		printf("%-15p|", (void *)start + 4);
	}
	else
	{
		int pos = (int*)(((char*)start + 4) - initial);
		printf("%-15d|", pos);
	}

	printf("%-14u|",size);

	if(i == 0)
	{
		printf("%-14p|\n", (void *) end);
	}
	else
	{
		int pos = (int*)((char*)end - initial);
		printf("%-14d|\n", pos);
	}

	print_break_line();
}
