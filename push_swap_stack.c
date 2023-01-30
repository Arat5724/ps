/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongble <jeongble@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 20:52:14 by jeongble          #+#    #+#             */
/*   Updated: 2022/07/22 09:43:18 by jeongble         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stack_init(void)
{
	t_stack	*result;

	result = (t_stack *)malloc(sizeof(t_stack));
	result->stack_a = 0;
	result->tail_a = 0;
	result->stack_b = 0;
	result->tail_a = 0;
	return (result);
}

void	stack_del(t_stack *stacks)
{
	node_clear(&(stacks->stack_a));
	node_clear(&(stacks->stack_b));
	free(stacks);
}

t_stack	*stack_dup(t_stack *stacks)
{
	t_stack	*result;

	result = (t_stack *)malloc(sizeof(t_stack));
	node_dup(&(result->stack_a), &(result->tail_a), stacks->stack_a);
	node_dup(&(result->stack_b), &(result->tail_b), stacks->stack_b);
	return (result);
}

void	stack_print(t_stack *stacks) {
	t_num *head;
	
	// printf("stack a\n");
	head = stacks->stack_a;
	while (head) {
		printf("%d ", head->n);
		head = head->next;
	}
	printf("\n");
	head = stacks->stack_b;
	while (head) {
		printf("%d ", head->n);
		head = head->next;
	}
	printf("\n");
}