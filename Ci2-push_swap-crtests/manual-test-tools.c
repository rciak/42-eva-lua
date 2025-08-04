/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manual-test-tools.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 14:11:56 by reciak            #+#    #+#             */
/*   Updated: 2025/08/04 19:57:26 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "manual-test.h"
#include "push_swap.h"

void	print__single_stack(t_dl_node	*one_stack);

void	print_stacks(t_dl_node	**stack)
{

	printf("************** A ************* A *************\n");
	print_single_stack(stack[A]);
	printf("************** B ************* B *************\n");
	print_single_stack(stack[B]);
	printf("--------------------------------------------------------------\n");
}

void	print_single_stack(t_dl_node	*one_stack)
{
	t_dl_node	*node;
	t_ps_obj	*obj;

	printf("n        goal    green   size    rank    start   end \n");
	printf("=====    =====   =====   =====   =====   =====   =====\n");
	node = one_stack;
	while (node != NULL)
	{
		obj = ((t_ps_obj*)node->obj);
		printf("%d \t %d \t %d \t %d \t %d \t %d \t %d \n", 
			obj->n, 
			obj->goal, 
			obj->is_green,
			obj->group.size,
			obj->group.rank,
			obj->group.starts,
			obj->group.ends);
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