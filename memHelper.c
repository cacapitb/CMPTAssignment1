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