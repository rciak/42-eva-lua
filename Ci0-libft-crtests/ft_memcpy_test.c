/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 19:12:00 by reciak            #+#    #+#             */
/*   Updated: 2025/05/23 19:29:34 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "crtests.h"

Test(ft_memcopy, ori_only_NULL_NULL_three, .signal = SIGSEGV)
{
	memcpy(NULL, NULL, 3);
}

Test(ft_memcopy, ft_only_NULL_NULL_three, .signal = SIGSEGV)
{
	ft_memcpy(NULL, NULL, 3);
}