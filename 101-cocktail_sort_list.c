#include "sort.h"

/**
 * swap - swaps two nodes
 * @head: head of the list
 * @node1: first node to sort
 * @node2: second node to sort
 */
void swap(listint_t **head, listint_t *node1, listint_t *node2)
{
    if (node1 == node2) {
        return; // No need to swap if both nodes are the same
    }

    // Adjust previous and next pointers for node1
    if (node1->prev != NULL) {
        node1->prev->next = node2;
    } else {
        *head = node2;
    }

    if (node1->next != NULL) {
        node1->next->prev = node2;
    }

    // Adjust previous and next pointers for node2
    if (node2->prev != NULL) {
        node2->prev->next = node1;
    } else {
        *head = node1;
    }

    if (node2->next != NULL) {
        node2->next->prev = node1;
    }

    // Swap prev and next pointers for node1 and node2
    listint_t *temp = node1->prev;
    node1->prev = node2->prev;
    node2->prev = temp;

    temp = node1->next;
    node1->next = node2->next;
    node2->next = temp;
}

/**
 * cocktail_sort_list - sorts a list using the cocktail sort algorithm
 * @list: list to sort
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *head;
	int flag = 0;

	if (!list || !*list || !(*list)->next)
		return;

	do {
		for (head = *list; head->next != NULL; head = head->next)
		{
			if (head->n > head->next->n)
			{
				swap(list, head, head->next);
				print_list(*list);
				flag = 1;
				head = head->prev;
			}
		}
		if (flag == 0)
			break;
		flag = 0;
		for (; head->prev != NULL; head = head->prev)
		{
			if (head->n < head->prev->n)
			{
				swap(list, head->prev, head);
				print_list(*list);
				flag = 1;
				head = head->next;
			}
		}
	} while (flag == 1);
}
