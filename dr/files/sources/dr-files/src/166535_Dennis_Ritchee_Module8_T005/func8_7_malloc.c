/* REQUIRED HEADERS */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdint.h>
#include"main.h"
#include <ctype.h>

#include <fcntl.h>
#include <unistd.h>

#include <stddef.h>
#include <dirent.h>


/* REQUIRED MACROS */

#define NALLOC 1024                  /* Minimum number of units to request */
#define MAX_ALLOC (1024 *1024 *100) /* Max allowed allocation (100MB) */

typedef long Align; /* For alignment to long boundary */

union header {
        struct {
                union header *ptr;
                size_t size;
        } s;
        Align x;
};

typedef union header Header;

static Header base; /* empty list to get started */
static Header *freep = NULL; /* start of free list */
static Header *morecore(unsigned);
void my_free(void *ap);
/* malloc: general-purpose storage allocator */
void *my_malloc(size_t nbytes)
{
        Header *p, *prevp;
        size_t nunits;
        if (nbytes == 0 || nbytes > MAX_ALLOC) {
                fprintf(stderr, "my_malloc: invalid request size %zu\n", nbytes);
                return NULL;
        }
	
	/* prevent integer overflow */
	if (nbytes > (SIZE_MAX - sizeof(Header))){
		fprintf(stderr,"malloc: size overflow\n");
		return NULL;
	}


	/*Number header units required*/
        nunits = (nbytes+sizeof(Header)-1)/sizeof(Header) + 1;
        
	if ((prevp = freep) == NULL) { /* no free list yet */
                 base.s.ptr = &base;
                base.s.size = 0;
                freep = &base;
                prevp = freep;
        }
        for (p = prevp->s.ptr; ; prevp = p, p = p->s.ptr) {
                if (p->s.size >= nunits) { /* big enough */
                        if (p->s.size == nunits) /* exactly */
                                prevp->s.ptr = p->s.ptr;
                        else { /* allocate tail end */
                                p->s.size -= nunits;
                                p += p->s.size;
                                p->s.size = nunits;
                        }
                        freep = prevp;
                        return (void *)(p+1);
                }
                if (p == freep){ /* wrapped around free list */
                        if ((p = morecore(nunits)) == NULL)
                                return NULL; /* none left */
                }
        }
}
/* morecore: ask system for more memory */
static Header *morecore(unsigned nu)
{
        char *cp;
        void *sbrk(intptr_t);
        Header *up;
        if (nu < NALLOC)
                nu = NALLOC;
        cp = sbrk(nu * sizeof(Header));
        if (cp == (char *) -1) /* no space at all */
                return NULL;

        up = (Header *) cp;
        up->s.size = nu;
        my_free((void *)(up+1));
        return freep;
}
void my_free(void *ap)
{
        Header *bp, *p;
        bp = (Header *)ap - 1; /* point to block header */
       	if (ap == NULL){
		fprintf(stderr,"Error:can not free NULL pointer\n");
		return;
	} 
	if (bp->s.size == 0 || bp->s.size > MAX_ALLOC ){
		fprintf(stderr,"free: can't free %lu units\n",bp->s.size);
	}

	for (p = freep; !(bp > p && bp < p->s.ptr); p = p->s.ptr)
                if (p >= p->s.ptr && (bp > p || bp < p->s.ptr))
                        break; /* freed block at start or end of arena */
        if (bp + bp->s.size == p->s.ptr) { /* join to upper nbr */
                bp->s.size += p->s.ptr->s.size;
                bp->s.ptr = p->s.ptr->s.ptr;
        } else
                bp->s.ptr = p->s.ptr;
        if (p + p->s.size == bp) { /* join to lower nbr */
                p->s.size += bp->s.size;
                p->s.ptr = bp->s.ptr;
        } else
                p->s.ptr = bp;
        freep = p;

}

void  bfree(void *p, size_t n){
	if (n < sizeof(Header)){
		fprintf(stderr,"bfree: block too small to free\n");
		return;
	}

	Header *hp = (Header *)p;
	hp->s.size = n / sizeof(Header);

	my_free((void *) (hp + 1) );

	
}


void call_bfree(){
	char static_men[NALLOC];
	base.s.ptr = freep = &base;
	base.s.size  = 0;

	bfree(static_men,NALLOC);

	void *block = my_malloc(100);

	if(block){
		printf("allocated\n");
		my_free(block);
	}
}


int custom_malloc() {
        printf("Allocating memory with custom malloc...\n");

        int *arr = (int *)my_malloc(11000 * sizeof(int));
        if (!arr) {
                printf("Allocation failed.\n");
                return 1;
        }

        for (int i = 0; i < 10; ++i) arr[i] = i;
        for (int i = 0; i < 10; ++i) printf("arr[%d] = %d\n", i, arr[i]);

        printf("Freeing memory...\n");
        my_free(arr);
	arr=NULL;
	my_free(arr);
        return 0;
}


