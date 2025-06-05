/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf-tests.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 17:47:50 by reciak            #+#    #+#             */
/*   Updated: 2025/06/05 11:51:28 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ci1-ft_printf-crtests.h"

// -1. Reaction to NULL
Test(ft_printf, NULL_instead_string)
{
	ft_printf(NULL);
}

//
// 0. Only raw strings, no further arguments after that mandatory one
//

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
ParameterizedTestParameters(ft_printf, only_string_ori_behav_expected)
{
	static t_params0 params[] = 
	{
		{"A "}, {"brave "}, {"camel "}, {"danced "}, {"energetic. "}, 
		{""},
		{"\n"}, {"\t"}, {"\r"}, {"%%"}, {"\b"} , {"cba%%"}, {"%"}, {"c%"},
		{"\0"}, {"\t"}, {"\n"}, {"\a"}, {"\b"}, {"xFF"}
	};
	size_t nb_params = sizeof (params) / sizeof (t_params0);
	return cr_make_param_array(t_params0, params, nb_params);
}

ParameterizedTest(t_params0 *param, ft_printf, only_string_ori_behav_expected)
{
	char expected[1024];

	st_pre0(param);
	sprintf(expected, param->str);
	cr_assert_stdout_eq_str(expected);
}
////
ParameterizedTestParameters(ft_printf, only_string_diff_behav_expected)
{
	static t_params0 params[] = 
	{
		{"%a"}, {"%e"}
	};
	size_t nb_params = sizeof (params) / sizeof (t_params0);
	return cr_make_param_array(t_params0, params, nb_params);
}

ParameterizedTest(t_params0 *param, ft_printf, only_string_diff_behav_expected)
{
	char ori_out[1024];

	st_pre0(param);
	sprintf(ori_out, param->str);
	cr_assert_stdout_neq_str(ori_out);
}

//
// 1. A raw strings, and one optional argument 
//
// The tests for regular input are grouped by the type of arguments /
// the character that follows the % character:
//
// Group 1: c (char)
// Group 2: s, p (after casting: char *)
// Group 3: d, i (int)
// Group 4: u, x, X (unsigned int)
// Group 5: %
//
// Tests for irregular input, but no 
// Group 6: a, e
//          --> different behaviour of ft_printf and printf is expected!
// Group 7: nonsense stuff after '%' : '\0', '\t', '\n', '\a', '\b', 'xFF'
//
// The tests for i


// typedef struct s_params1
// {
// 	const char	*str;
// 	const char
// }	t_params0;

// static void st_pre0(t_params0 *param)
// {
// 	ft_printf(param->str);
// 	cr_redirect_stdout();
// 	ft_printf(param->str);
// 	fflush(stdout);
// }
// ParameterizedTestParameters(ft_printf, only_string)
// {
// 	static t_params0 params[] = 
// 	{
// 		{"A "}, {"bra "}, {"ka "}, {"da "}, {"bra! "}, 
// 		{"\n"}, {""}, {"cba%%"}, {"c%"}
// 	};
// 	size_t nb_params = sizeof (params) / sizeof (t_params0);
// 	return cr_make_param_array(t_params0, params, nb_params);
// }
// ParameterizedTest(t_params0 *param, ft_printf, only_string)
// {
// 	char expected[1024];

// 	st_pre0(param);
// 	sprintf(expected, param->str);
// 	cr_expect_stdout_eq_str(expected);
// }
