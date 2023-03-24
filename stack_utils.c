#include "push_swap.h"

t_list *new_element_stack(int value) // works
{
	t_list *new;
	
	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = value;
	new->next = NULL;
	return(new);
}

t_list *get_tail(t_list *stack)  // works
{
	while (stack && stack->next != NULL)
		stack = stack->next;
	return (stack);
}

void add_stack_back(t_list **stack, t_list *new)  // works
{
	t_list *tail;

	if(!new)
		return ;
	if (!*stack)
	{
		*stack = new;
		return ;
	}
	tail = get_tail(*stack);
	tail->next = new;
}

void add_stack_front(t_list **stack, t_list *new)
{
	t_list *head;

	head = *stack;
	if (!head)
		return ;
	new->next = *stack;

}

void print_stack (t_list **stack)
{
	t_list *tmp;
	tmp = *stack;
	if (!stack)
		printf("Wrong");
	else 
	{
		while (tmp)
		{
			// printf("content is %d\n", tmp->content);
			printf("index is %d\n", tmp->index); // to be removed
			// printf("position is %d\n", tmp->position); // to be removed
			tmp = tmp->next;
		}
	}
	printf("\n"); // to be deleted 
}