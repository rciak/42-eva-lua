/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf-tests.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 17:47:50 by reciak            #+#    #+#             */
/*   Updated: 2025/06/06 16:34:56 by reciak           ###   ########.fr       */
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
typedef struct s0_param
{
	const char	*str;
}	t0_param;

static void st0_ft_printf_redush(t0_param *param)
{
	cr_redirect_stdout();
	ft_printf(param->str);
	fflush(stdout);
}
static void st0_get_params(t0_param **param, size_t *nb_param)
{
	static t0_param param0[] = 
	{
		{"A "}, {"brave "}, {"camel "}, {"danced "}, {"energetic. "}, 
		{""},
		{"\n"}, {"\t"}, {"\r"}, {"%%"}, {"\b"} , {"cba%%"}, {"%"}, {"c%"},
		{"\0"}, {"\t"}, {"\n"}, {"\a"}, {"\b"}, {"xFF"}
	};
	*param = param0;
	*nb_param = sizeof(param0) / sizeof(t0_param);
}
//--
ParameterizedTestParameters(ft_printf, only_string_same_reval_expected)
{
	t0_param *param;
	size_t nb_param;

	st0_get_params(&param, &nb_param);
	return (cr_make_param_array(t0_param, param, nb_param));
}
ParameterizedTest(t0_param *param, ft_printf, only_string_same_reval_expected)
{
	int reval_ori = printf(param->str);
	int reval_ft = ft_printf(param->str);
	cr_assert(reval_ori == reval_ft);
}
//--
ParameterizedTestParameters(ft_printf, only_string_ori_behav_expected)
{
	t0_param *param;
	size_t nb_param;

	st0_get_params(&param, &nb_param);
	return (cr_make_param_array(t0_param, param, nb_param));
}

ParameterizedTest(t0_param *param, ft_printf, only_string_ori_behav_expected)
{
	char expected[1024];

	st0_ft_printf_redush(param);
	sprintf(expected, param->str);
	cr_assert_stdout_eq_str(expected);
}
////
ParameterizedTestParameters(ft_printf, only_string_diff_behav_expected)
{
	static t0_param param[] = 
	{
		{"%a"}, {"%e"}
	};
	size_t nb_param = sizeof (param) / sizeof (t0_param);
	return cr_make_param_array(t0_param, param, nb_param);
}

ParameterizedTest(t0_param *param, ft_printf, only_string_diff_behav_expected)
{
	char ori_out[1024];

	st0_ft_printf_redush(param);
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


// typedef struct s_param1
// {
// 	const char	*str;
// 	const char
// }	t0_param;

// static void st0_ft_printf_redush(t0_param *param)
// {
// 	ft_printf(param->str);
// 	cr_redirect_stdout();
// 	ft_printf(param->str);
// 	fflush(stdout);
// }
// ParameterizedTestParameters(ft_printf, only_string)
// {
// 	static t0_param param[] = 
// 	{
// 		{"A "}, {"bra "}, {"ka "}, {"da "}, {"bra! "}, 
// 		{"\n"}, {""}, {"cba%%"}, {"c%"}
// 	};
// 	size_t nb_param = sizeof (param) / sizeof (t0_param);
// 	return cr_make_param_array(t0_param, param, nb_param);
// }
// ParameterizedTest(t0_param *param, ft_printf, only_string)
// {
// 	char expected[1024];

// 	st0_ft_printf_redush(param);
// 	sprintf(expected, param->str);
// 	cr_expect_stdout_eq_str(expected);
// }
