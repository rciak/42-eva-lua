/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf-tests.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 17:47:50 by reciak            #+#    #+#             */
/*   Updated: 2025/06/04 16:38:00 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ci1-ft_printf-crtests.h"

// 1. Only strings /////////////////////////////////////////////////////////////

typedef struct s_params0
{
	const char	*str;
}	t_params0;

static void st_pre0(t_params0 *param)
{
	cr_redirect_stdout();
printf("%s", param->str);
	fflush(stdout);
}

ParameterizedTestParameters(ft_printf, only_string)
{
	static t_params0 params[] = 
	{
		{"A"}, {"bra"}, {"ka"}, {"da"}, {"bra!"}, 
		{""}, {"cba%%"}, {"c%"}
	};
	size_t nb_params = sizeof (params) / sizeof (t_params0);
	return cr_make_param_array(t_params0, params, nb_params);
}
//
ParameterizedTest(t_params0 *param, ft_printf, only_string)
{
	st_pre0(param);
	cr_expect_stdout_eq_str(param->str);
}







// Test(ft_printf, dummy_without_args)
// {
// 	cr_redirect_stdout();
// 	ft_printf();
// 	fflush(stdout);
// 	cr_assert_stdout_eq_str("Dummy\n");
// }
// Test(ft_printf, dummy_without_args2)
// {
// 	cr_redirect_stdout();
// 	ft_printf();
// 	fflush(stdout);	
// 	cr_assert_stdout_eq_str("Dummy");
// }