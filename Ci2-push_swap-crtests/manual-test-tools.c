/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manual-test-tools.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 14:11:56 by reciak            #+#    #+#             */
/*   Updated: 2025/07/29 17:55:45 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "manual-test.h"
#include "push_swap.h"

void	print__single_stack(t_dl_node	*one_stack);

void	print_stacks(t_dl_node	**stack)
{

	printf("****** A ******\n");
	printf("n        goal\n");
	printf("=====    =====\n");
	print__single_stack(stack[A]);
	printf("*** STACK B ***\n");
	print__single_stack(stack[B]);
	printf("--------------------------------------------------------------");
}

void	print__single_stack(t_dl_node	*one_stack)
{
	t_dl_node	*node;
	t_ps_obj	*obj;

	node = one_stack;
	while (node != NULL)
	{
		obj = ((t_ps_obj*)node->obj);
		printf("%d \t %d\n", obj->n, obj->goal);
		node = node->next;
	}
	printf("\n");

}
/*

void	hprint_stack(t_stacknd *stack, char* msg)
{
	t_stacknd *iter;

	iter = stack;
	printf("%s\n", msg);
	printf("stack->number: ");
	while (iter != NULL)
	{
		printf("%d \t", iter->number);
		iter = iter->next;
	}
	// iter = stack;
	// printf("\n");
	// printf("stack->index : ");
	// while (iter != NULL)
	// {
	// 	printf("%d \t",  iter->index);
	// 	iter = iter->next;
	// }
}
*/