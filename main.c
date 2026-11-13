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
	printf("Header len = %d", ((Header *)&mem[0])->len);
	
  return 0;
	
}
