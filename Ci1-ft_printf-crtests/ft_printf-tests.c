/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf-tests.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 17:47:50 by reciak            #+#    #+#             */
/*   Updated: 2025/06/04 18:39:09 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ci1-ft_printf-crtests.h"

// -1. Reaction to NULL
Test(ft_printf, NULL_instead_string)
{
	ft_printf(NULL);
}

// 0. Only strings /////////////////////////////////////////////////////////////
typedef struct s_params0
{
	const char	*str;
}	t_params0;

static void st_pre0(t_params0 *param)
{
	ft_printf(param->str);
	cr_redirect_stdout();
	ft_printf(param->str);
	fflush(stdout);
}
ParameterizedTestParameters(ft_printf, only_string)
{
	static t_params0 params[] = 
	{
		{"A "}, {"bra "}, {"ka "}, {"da "}, {"bra! "}, 
		{"\n"}, {""}, {"cba%%"}, {"c%"}
	};
	size_t nb_params = sizeof (params) / sizeof (t_params0);
	return cr_make_param_array(t_params0, params, nb_params);
}
ParameterizedTest(t_params0 *param, ft_printf, only_string)
{
	char expected[1024];

	st_pre0(param);
	sprintf(expected, param->str);
	cr_expect_stdout_eq_str(expected);
}
