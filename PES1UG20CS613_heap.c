// Name: Vivian Rodriguez
// SRN: PES1UG20CS613
#include "heap.h"
#include <stdlib.h>

/*
 ** Do not use global variables.
 ** Mark any functions that you declare in this file that are not in the header
 *as static
 ** Do not use static variables
 ** All occurences of count_ptr indicate that the number of comparison
 ** operations need to be stored in the location pointed by it
 ** The implementation can assume it is initialized to 0.
 */

// Initialise heap
// Set heap size to 0
// Set heap max_size to paramter max_size
// Allocate memory of max_size to the array
void init_heap(heap_t *heap, int max_size) {
    heap -> arr = malloc(sizeof(heap));
    heap -> size = 0;
    heap -> max_size = max_size;
}

// Insert element "key" to heap "heap"
// and store the number of key comparisons made in the
// location pointed to by count_ptr.
void insert(heap_t *heap, int key, int *count_ptr) {
  if (heap -> size == 0)
  {
    heap -> arr[0] = key;
    heap->size += 1;
    (*count_ptr)++;	
  }
  else if (heap->size <= heap->max_size)
  {
    heap->arr[heap->size] = key;
    heap->size += 1;
    (*count_ptr)++;
  } 
}

void swap(int *a, int *b)
{
  int temp = *b;
  *b = *a;
  *a = temp;
}

static int heapify(int array[], int size, int i, int *c)
{

    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < size && array[l] > array[largest])
     { largest = l;
       (*c)++; 	
     }
    if (r < size && array[r] > array[largest])
     { largest = r;
       (*c)++; 	
     }
    if (largest != i)
    {
      swap(&array[i], &array[largest]);
      heapify(array, size, largest, c);
    }
return *c;
  
}

// *Removes and Returns* the maximum element in the heap
// and store the number of key comparisons made in the
// location pointed to by count_ptr.
int extract_max(heap_t *heap, int *count_ptr) {
    int c,h;

    for (int i = ((heap->size) / 2) - 1 ; i >= 0 ; i--)
    {
        
    h = heapify(heap->arr, heap->size, i, &c);
    
    }
    int max = heap->arr[0];
    int pos = 0;
    int num = sizeof(heap -> arr);   	
    // use for loop to delete the element and update the index  
    for (int j = pos - 1; j < num -1; j++)  
    {  
       heap->arr[j] = heap->arr[j+1]; // assign arr[i+1] to arr[i]  
    }     
     
    return max;
}

// Searches for the element key in the heap
// Returns the element if found, else -1
int search(const heap_t *heap, int key, int *count_ptr) {
	int flag = -1;	
	for (int i =0; i< heap->size; i++)
	{
		if (key == heap -> arr[i])
		{
			flag = heap->arr[i];
		}
		(*count_ptr)++;
	}
	return flag;
}

// Returns the maximum value of the element in the heap
// and store the number of key comparisons made in the
// location pointed to by count_ptr.
int find_max(const heap_t *heap, int *count_ptr) {
    int c,h;

    for (int i = ((heap->size) / 2) - 1 ; i >= 0 ; i--)
    {
        
    h = heapify(heap->arr, heap->size, i, &c);
    
    }

 
  return heap->arr[0];
}

// Returns the minimum value in the heap
int find_min(const heap_t *heap, int *count_ptr) {
    int c,h;

    for (int i = ((heap->size) / 2) - 1 ; i >= 0 ; i--)
    {
        
    h = heapify(heap->arr, heap->size, i, &c);
    
    }

 
  return heap->arr[(heap->size) - 1];
}

// Clears the heap for reuse
void clear_heap(heap_t *heap) {
  
  for (int i=0; i< heap->size; i++)
  {
    heap->arr[i] = 0;
  }
	
}

// Frees all resources acquired to initialize heap
void free_heap(heap_t *heap) {
	free(heap);
}
