/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manual-test.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rene <rene@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 14:00:45 by reciak            #+#    #+#             */
/*   Updated: 2025/07/29 19:54:24 by rene             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MANUAL_TEST_H
# define MANUAL_TEST_H

/////////////////////////
# include "push_swap.h"
/////////////////////////
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <stdint.h>

void	print_stacks(t_dl_node	**stack);
void	print_single_stack(t_dl_node	*one_stack);

#endif