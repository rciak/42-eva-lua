/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 17:47:50 by reciak            #+#    #+#             */
/*   Updated: 2025/06/04 11:07:42 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ci1-ft_printf-crtests.h"

Test(ft_printf, without_args)
{
	cr_redirect_stdout();
	ft_printf();
	fflush(stdout);
	cr_assert_stdout_eq_str("Dummy");
}
