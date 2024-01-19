#include "sort.h"

/**
 * swap_nodes - swapps two nodes in a listint_t doubly linked list
 * @head: head pointer of doubly linked list
 * @node_a: a pointer to the first node to swap
 * @node_b: The second node to swap.
*/
void swap_nodes(listint_t **head, listint_t **node_a, listint_t *node_b)
{
	(*node_a)->next = node_b->next;
	if (node_b->next != NULL)
		node_b->next->prev = *node_a;
	node_b->prev = (*node_a)->prev;
	node_b->next = *node_a;
	if ((*node_a)->prev != NULL)
		(*node_a)->prev->next = node_b;
	else
		*head = node_b;
	(*node_a)->prev = node_b;
	*node_a = node_b->prev;
}

/**
 * insertion_sort_list - sorts a doubly linked list of integeers
 * using the insertation sort algorithm
 *
 * @list: A pointer to the head of doubly linked list of integers.
 *
 * Description: prints the list after each swap.
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *compare, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (current = (*list)->next; current != NULL; current = temp)
	{
		temp = current->next;
		compare = current->prev;

		while (compare != NULL && current->n < compare->n)
		{
			swap_nodes(list, &compare, current);
			print_list((const listint_t *)*list);
		}
	}
}
