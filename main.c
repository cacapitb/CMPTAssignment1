/* main.c
 *
 * Test your implementation here
 *
 * Author:
 * ID:
 * Lab instructor:
 * Lecture instructor:
 */

#include <stdio.h>
#include <stdbool.h>

#include "memManager.h"
#include "memHelper.h"


int main(int argc, char *argv[]){

	initializeMemory();
	Header * head = (Header *)mem;
	printf("Header len = %d", head->len);
	Footer * foot = get_footer_pos((Header*)&mem[0]);
	printf("\nFooter len = %d\n", foot->len);

	Header * p1 = myMalloc(3);
	Header * p2 = myMalloc(100);
	Header * p3 = myMalloc(35);

	myFree(p2);

	myFree(p3);


	printf("\nP1 Header Len = %d",p1->len);
	Footer * p1foot = get_footer_pos(p1);
	printf("\nP1 Footer Len = %d",p1foot->len);
/*
	printf("\nP2 Header Len = %d", p2->len);
	Footer * p2foot = get_footer_pos(p2);
	printf("\nP2 Footer Len = %d",p2foot->len);
*/
	Header * newHead = get_next_header(p2);
	printf("\nFree Header Len = %d",newHead->len);
	printf("\nFree Footer Len = %d\n",foot->len);

  return 0;
	
}
