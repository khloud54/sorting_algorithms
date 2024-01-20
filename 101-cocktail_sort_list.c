#include "sort.h"

/**
 * list_len - Returns list length
 * @myList: Linked list
 * Return: length of the list
*/
size_t list_len(listint_t *list)
{
	size_t custom_len = 0;

	while (list)
	{
		custom_len++;
		list = list->next;
	}

	return custom_len;
}

/**
 * switch_nodes - Swap/Return node
 * @list: List node
 * @p: pointer node
*/
void switch_nodes(listint_t **list, listint_t **p)
{
	listint_t *prev_one, *current_two, *next_three, *fourth_node;

	prev_one = (*p)->prev;
	current_two = *p;
	next_three = (*p)->next;
	fourth_node = (*p)->next->next;

	current_two->next = fourth_node;

	if (fourth_node)
		fourth_node->prev = current_two;

	next_three->next = current_two;
	next_three->prev = current_two->prev;

	if (prev_one)
		prev_one->prev = next_three;
	else
		*list = next_three;

	current_two->prev = next_three;

	*p = next_three;
}

/**
 * cocktail_sort_list - sort a doubly linked list
 * @list: list pointer
*/
void cocktail_sort_list(listint_t **list)
{
	listint_t *current_node;
	int is_sorted = 0;

	if (!list || !*list || list_len(*list) < 2)
		return;

	current_node = *list;

	while (!is_sorted)
	{
		is_sorted = 1;

		while (current_node->next)
		{
			if (current_node->n > current_node->next->n)
			{
				is_sorted = 0;
				switch_nodes(list, &current_node);
				print_list(*list);
			}
			else
				current_node = current_node->next;
		}

		if (is_sorted)
			break;

		current_node = current_node->prev;

		while (current_node->prev)
		{
			if (current_node->n < current_node->prev->n)
			{
				is_sorted = 0;
				current_node = current_node->prev;
				switch_nodes(list, &current_node);
				print_list(*list);
			}
			else
				current_node = current_node->prev;
		}
	}
}


