#include <unistd.h>
#include <string.h>
#include <pthread.h>
/* Only for the debug printf */
#include <stdio.h>

typedef char ALIGN[16];

union header {
	struct {
		size_t size;
		unsigned is_free;
		union header *next;
	} s;
	/* force the header to be aligned to 16 bytes */
	ALIGN stub;
};
typedef union header header_t;

header_t *head = NULL, *tail = NULL;
pthread_mutex_t global_malloc_lock;

header_t *get_free_block(size_t size)
{
	header_t *curr = head;
	while(curr) {
		/* see if there's a free block that can accomodate requested size */
		if (curr->s.is_free && curr->s.size >= size)
			return curr;
		curr = curr->s.next;
	}
	return NULL;
}