#include "sort.h"

/**
 * customSwap - swaps two nodes in a linked list
 * @head: pointer to the head of the list
 * @firstNode: first node to swap
 * @secondNode: second node to swap
 */
void customSwap(listint_t **head, listint_t *firstNode, listint_t *secondNode)
{
    listint_t *prevFirst = firstNode->prev;
    listint_t *nextSecond = secondNode->next;

    // Update pointers for first node
    if (prevFirst != NULL)
        prevFirst->next = secondNode;
    else
        *head = secondNode;

    firstNode->prev = secondNode;
    firstNode->next = nextSecond;

    // Update pointers for second node
    secondNode->prev = prevFirst;
    secondNode->next = firstNode;

    if (nextSecond != NULL)
        nextSecond->prev = firstNode;
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
