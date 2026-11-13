/* memManager.h
 *
 * Interface to your memory manager
 *
 * Please do not modify any code in this file!  We will be testing your code
 * under the assumption that the public interface matches this interface.
 *
 * Hanan S.
 */

#ifndef MEMMANAGER_H
#define MEMMANAGER_H

#define HEAP_SIZE 65536   // Total Memory Size (64kB)

typedef struct{
  unsigned int len;
  char data[];
}Header;

typedef struct{
  unsigned int len;
}Footer;


/*
 *Declare your heap variable here
 *This variable can be static or dynamic of size HEAP_SIZE
 */
extern char mem[HEAP_SIZE];


/*
 * initializeMemory()
 *
 * Initialize your heap vairable to size HEAP_SIZE
 * This initalization will differ depending on whether your
 * heap variable is static or dynamic
 *
 * Parameters: None
 * Return: None
 *
 * PRE: A valid heap variable exists
 * POST: Header and footer information are written to your initial
 *       heap chunk
 */
void initializeMemory();


/*
 * myMalloc(unsigned int size)
 *
 * Allocates the requested bytes, size, and returns a pointer to the beginning
 * of the allocated memory. If the space cannot be allocated, then NULL is returned.
 *
 * Parameters: size - number of bytes to allocate
 * Return: a pointer to a newly allocated memory region of the desired size
 *         or NULL if allocation fails
 *
 * PRE: 0 < size < HEAP_SIZE
 * POST: region is allocated, and valid pointer is returned
 *       OR region is not allocated, and NULL is returned
 */
void *myMalloc(unsigned int sz);



/*
 * myFree(void *ptr)
 *
 * Frees the memory region at the given pointer that was previously allocated using myMalloc.
 * It gives the chunk of memory containing region back to the allocator, and allows for it to
 * be reused in the future.
 *
 * Parameters: region - a pointer to an allocated memory region
 * Return: void
 *
 * PRE: Heap start <= ptr < Heap start + HEAP_SIZE
 * POST: the chunk containing region is added to the available memory
 */
void myFree(void *ptr);

/*
 * mallocInfo(int i)
 *
 * Print heap memory information to stdout
 *
 * Parameters: i indicating print format. If i=0 print addresses for start
 *             and end. if i=1 print number of bytes relative to the beginning
 *             of the heap
 * Return: void
 *
 * PRE: heap memory variable is initialized
 * POST: prints heap information to stdout in the format:
 *
 * +---------+-------+------------+-------+
 * |  Status | Start | Block Size | End   |
 * +---------+-------+------------+-------+
 */
void mallocInfo(int i);

#endif // !MEMMANAGER_H
