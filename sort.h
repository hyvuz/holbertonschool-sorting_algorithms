#ifndef SORT_H
#define SORT_H

#include <stddef.h>

/**
 * struct listint_s - Doubly linked list node structure
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous node
 * @next: Pointer to the next node
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

/* Print helpers (provided) */
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);

/* Task 1: Insertion sort for doubly linked list */
void insertion_sort_list(listint_t **list);

/* Task 3: Quick sort for array */
void quick_sort(int *array, size_t size);

#endif /* SORT_H */
