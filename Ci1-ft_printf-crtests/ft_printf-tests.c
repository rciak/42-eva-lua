/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf-tests.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 17:47:50 by reciak            #+#    #+#             */
/*   Updated: 2025/06/07 10:46:43 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ci1-ft_printf-crtests.h"

// W a r n i n g :  Since directly comparing the output of ft_printf 
// with the one of printf seems not possible with in Criterion framework 
// (or at least no straight forward way) the expected output is generated
// by the function sprintf instead.
// (But for comparison of the return value ft_printf is used.)


// -1. Reaction to NULL
Test(ft_printf, NULL_instead_string)
{
	ft_printf(NULL);
}

////////////////////////////////////////////////////////////////////////////////
// 0. Only raw strings, no further arguments after that mandatory one
////////////////////////////////////////////////////////////////////////////////

//
// 0. a) Testcases
//
typedef struct s0_param
{
	const char	*str;
}	t0_param;

static void st0_get_params(t0_param **pparam, size_t *nb_param)
{
	static t0_param param[] =
	{
		{"A "}, {"brave "}, {"camel "}, {"danced "}, {"energetic. "}, 
		{""},
		{"\n"}, {"\t"}, {"\r"}, {"%%"}, {"\b"} , {"cba%%"}, {"%"}, {"c%"},
		{"\0"}, {"\xFF"}
	};
	*pparam = param;
	*nb_param = sizeof(param) / sizeof(t0_param);
}

//
// 0. b) same return values?
//
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
//
// 0. c) same output?
//
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

	cr_redirect_stdout();
	ft_printf(param->str);
	fflush(stdout);
	sprintf(expected, param->str);
	cr_assert_stdout_eq_str(expected);
}
//
// 0. c') different output? 
//
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

	cr_redirect_stdout();
	ft_printf(param->str);
	fflush(stdout);
	sprintf(ori_out, param->str);
	cr_assert_stdout_neq_str(ori_out);
}

////////////////////////////////////////////////////////////////////////////////
// 1. A raw strings, and one optional argument 
////////////////////////////////////////////////////////////////////////////////
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
// Irregular Input 
// Group 6: Examples of feasible in printf, but not in ft_printf: a, e
//          --> different behaviour of ft_printf and printf is expected!
// Group 7: nonsense stuff after '%' : '\0', '\t', '\n', '\a', '\b', 'xFF'
//

//
// 1.1(c) a) Testcases
//
typedef struct s11c_param
{
	const char	*str;
	char		arg1;
}	t11c_param;

static void st11c_get_params(t11c_param **pparam, size_t *nb_param)
{
	static t11c_param param[] =
	{
		{"%cA", 'A'}, {"brave %c", 'B'}, {"camel |%c|danced ", 'C'},
		  {"s%cpace", ' '},
		{"%c", '/'},
		{"%c\n", 'D'}, {"\t%c", '~'}, {"%c\r", '<'}, {"%c\b", '>'}, 
		  {"%c\t", '*'}, {"%c\a", '%'}, {"\b%c", '%'},
		{"\n%c", '%'}, {"%c\0", '%'}, {"\0%c", '%'}, 
		{"%c\xFF", '\0'}, {"\xFF%c", '\0'},
		{"%ccba%%", '$'}, {"%%c", '2'}, {"%c%", '}'}, {"%%c", '-'},
		  {"%cc%", '!'}, {"c%%c", '?'},
		{"%c%%", '+'}, {"%%%c",'#'}
	};
	*pparam = param;
	*nb_param = sizeof(param) / sizeof(t11c_param);
}

//
// 1.1(c) b) same return values?
//
ParameterizedTestParameters(ft_printf, one_arg_same_reval_expected)
{
	t11c_param *param;
	size_t nb_param;

	st11c_get_params(&param, &nb_param);
	return (cr_make_param_array(t11c_param, param, nb_param));
}
ParameterizedTest(t11c_param *param, ft_printf, one_arg_same_reval_expected)
{
	int reval_ori = printf(param->str, param->arg1);
	int reval_ft = ft_printf(param->str, param->arg1);
	cr_assert(reval_ori == reval_ft);
}

//
// 1.1(c) c) same output?
//
ParameterizedTestParameters(ft_printf, one_arg_ori_behav_expected)
{
	t0_param *param;
	size_t nb_param;

	st0_get_params(&param, &nb_param);
	return (cr_make_param_array(t0_param, param, nb_param));
}
ParameterizedTest(t11c_param *param, ft_printf, one_arg_ori_behav_expected)
{
	char expected[1024];

	cr_redirect_stdout();
	ft_printf(param->str, param->arg1);
	fflush(stdout);
	sprintf(expected, param->str, param->arg1);
	cr_assert_stdout_eq_str(expected);
}

