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

	printf("Post initialize check\n");
	Header * head = (Header *)mem;
	printf("Header len = %d", head->len);
	Footer * foot = get_footer_pos((Header*)&mem[0]);
	printf("\nFooter len = %d\n", foot->len);

	int choice;
	scanf("%d", &choice);
	switch(choice)
	{
		case 1:
			printf("Test One\n");

			Header * p1 = myMalloc(100);
			Header * p2 = myMalloc(200);

			printf("\nPre-free\n");
			mallocInfo(1);

			myFree(p1);

			Header * p3 = myMalloc(300);
			printf("\nAfter free and new allocation\n");
			mallocInfo(1);

			break;
		case 2:
			printf("Test Two\n");

			Header * p4 = myMalloc(99);
			Header * p5 = myMalloc(198);

			printf("\nPre-free\n");
			mallocInfo(1);

			myFree(p4);

			Header * p6 = myMalloc(47);

			printf("\nPost-Free and new allocation\n");
			mallocInfo(1);

			break;
		case 3:
			printf("Test Three\n");

			Header * p7 = myMalloc(65520);
			printf("\nOccupy partition\n");
			mallocInfo(1);

			Header * p8 = myMalloc(100);

			printf("\nheap remains unchanged\n");
			mallocInfo(1);

			break;
		case 4:
			printf("Test Four\n");
			Header * p9 = myMalloc(100);
			Header * p10 = myMalloc(200);
			Header * p11 = myMalloc(300);
			Header * p12 = myMalloc(400);
			Header * p13 = myMalloc(500);
			Header * p14 = myMalloc(600);
			Header * p15 = myMalloc(700);
			Header * p16 = myMalloc(800);
			Header * p17 = myMalloc(900);
			Header * p18 = myMalloc(10000);

			printf("\nPre-free\n");
			mallocInfo(1);

			myFree(p10);
			myFree(p12);
			myFree(p16);
			
			printf("\nFirst free\n");
			mallocInfo(1);

			myFree(p9);
			myFree(p13);
			myFree(p15);
			myFree(p17);

			printf("\nSecond free\n");
			mallocInfo(1);

			break;
		case 5:
			printf("Test Five\n");

			Header * p19 = myMalloc(3);
			Header * p20 = myMalloc(100);
			Header * p21 = myMalloc(35);
			Header * p22 = myMalloc(900);
			Header * p23 = myMalloc(3560);
			Header * p24 = myMalloc(52);


			myFree(p21);
			myFree(p23);

			printf("Address\n");
			mallocInfo(0);
			printf("\nBytes\n");
			mallocInfo(1);

			break;
		default:
		printf("Error in test selection.");
	}
  return 0;
	
}
