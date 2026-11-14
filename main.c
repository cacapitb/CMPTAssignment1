/* main.c
 *
 * Test your implementation here
 *
 * Author: Ben.C
 * ID: 3172656
 * Lab instructor: Hanan S.
 * Lecture instructor: Hanan S.
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
	Header * p4 = myMalloc(900);
	Header * p5 = myMalloc(3560);
	Header * p6 = myMalloc(52);

	myFree(p3);
	myFree(p5);

	mallocInfo(0);
	mallocInfo(1);
/*
	printf("\nP1 Header Len = %d",p1->len);
	Footer * p1foot = get_footer_pos(p1);
	printf("\nP1 Footer Len = %d",p1foot->len);

	printf("\nP2 Header Len = %d", p2->len);
	Footer * p2foot = get_footer_pos(p2);
	printf("\nP2 Footer Len = %d",p2foot->len);

	Header * newHead = get_next_header(p2);
	printf("\nFree Header Len = %d",newHead->len);
	printf("\nFree Footer Len = %d\n",foot->len);
*/
  return 0;
	
}
