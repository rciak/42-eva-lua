/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 17:47:50 by reciak            #+#    #+#             */
/*   Updated: 2025/05/23 18:57:05 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "crtests.h"

Test(ft_calloc, compare_to_ori)
{
	void	*pori;
	void	*pft;

	pft = ft_calloc(0,1);
	free (pft);
	pori = calloc(0,1);
	free (pori);
	printf("pft:  %p\n", pft);
	printf("pori: %p\n", pori);

	cr_assert(pft == pori);
}