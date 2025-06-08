/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf-tests.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 17:47:50 by reciak            #+#    #+#             */
/*   Updated: 2025/06/08 10:46:51 by reciak           ###   ########.fr       */
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
// 1. A raw strings, and one additional argument 
////////////////////////////////////////////////////////////////////////////////
//
// The tests for regular input are grouped by the type of the argument /
// the character that follows the % character:
//
// Group 1: c (char)
// Group 2: s 
// Group 3: p
// Group 4: d, i (int)
// Group 5: u, x, X (unsigned int)

//
// Irregular Input 
// Group 6: Examples of feasible in printf, but not in ft_printf: a, e
//          --> different behaviour of ft_printf and printf is expected!
// Group 7: nonsense stuff after '%' : '\0', '\t', '\n', '\a', '\b', 'xFF'
//

////////////////////////////////////////////////////////////////////////////////
// 1.1(c)  a) Testcases
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
// 1.1(c)  b) same return values?
//
ParameterizedTestParameters(ft_printf, c_one_arg_same_reval_expected)
{
	t11c_param *param;
	size_t nb_param;

	st11c_get_params(&param, &nb_param);
	return (cr_make_param_array(t11c_param, param, nb_param));
}
ParameterizedTest(t11c_param *param, ft_printf, c_one_arg_same_reval_expected)
{
	int reval_ori = printf(param->str, param->arg1);
	int reval_ft = ft_printf(param->str, param->arg1);
	cr_assert(reval_ori == reval_ft);
}
//
// 1.1(c)  c) same output?
//
ParameterizedTestParameters(ft_printf, c_one_arg_ori_behav_expected)
{
	t0_param *param;
	size_t nb_param;

	st0_get_params(&param, &nb_param);
	return (cr_make_param_array(t0_param, param, nb_param));
}
ParameterizedTest(t11c_param *param, ft_printf, c_one_arg_ori_behav_expected)
{
	char expected[1024];

	cr_redirect_stdout();
	ft_printf(param->str, param->arg1);
	fflush(stdout);
	sprintf(expected, param->str, param->arg1);
	cr_assert_stdout_eq_str(expected);
}

////////////////////////////////////////////////////////////////////////////////
// 1.2(s)  a) Testcases
//
typedef struct s12s_param
{
	const char	*str;
	char		*arg1;
}	t12s_param;

static void st12s_get_params(t12s_param **pparam, size_t *nb_param)
{
	static t12s_param param[] =
	{
		{"%sA", NULL},
		{"%sA", "Servus & Ahoi!"}, {"brave %s", "B"}, 
		  {"camel |%s|danced ", "(◕‿◕)"},
		{"s%space", "      \n"},
		{"%s", ""},
		{"%s\n", "Dodelido"}, {"\t%s", "~~~"}, {"%s\r", "<#>"}, {"%s\b", ">-("}, 
		  {"%s\t", "*df"}, {"%s\a", "%"}, {"\b%s", "%"},
		{"\n%s", "%%"}, {"%s\0", "%%"}, {"\0%s", "%%"}, 
		{"%s\xFF", "\0Abrakadabra"}, {"\xFF%s", "\0"},
		{"%scba%%", "$USER"}, {"%%s", "001232"}, {"%s%", "%}"}, {"%%s", "-~~-"},
		  {"%sc%", "!?!"}, {"c%%s", "?öä"},
		{"%s%%", "+++"}, {"%%%s","#123"}
	};
	*pparam = param;
	*nb_param = sizeof(param) / sizeof(t12s_param);
}
//
// 1.2(s)  b) same return values?
//
ParameterizedTestParameters(ft_printf, s_one_arg_same_reval_expected)
{
	t12s_param *param;
	size_t nb_param;

	st12s_get_params(&param, &nb_param);
	return (cr_make_param_array(t12s_param, param, nb_param));
}
ParameterizedTest(t12s_param *param, ft_printf, s_one_arg_same_reval_expected)
{
	int reval_ori = printf(param->str, param->arg1);
	int reval_ft = ft_printf(param->str, param->arg1);
	cr_assert(reval_ori == reval_ft);
}
//
// 1.2(s) c) same output?
//
ParameterizedTestParameters(ft_printf, s_one_arg_ori_behav_expected)
{
	t0_param *param;
	size_t nb_param;

	st0_get_params(&param, &nb_param);
	return (cr_make_param_array(t0_param, param, nb_param));
}
ParameterizedTest(t12s_param *param, ft_printf, s_one_arg_ori_behav_expected)
{
	char expected[1024];

	cr_redirect_stdout();
	ft_printf(param->str, param->arg1);
	fflush(stdout);
	sprintf(expected, param->str, param->arg1);
	cr_assert_stdout_eq_str(expected);
}

////////////////////////////////////////////////////////////////////////////////
// 1.3(p)  a) Testcases
//
typedef struct s12p_param
{
	const char	*str;
	void		*arg1;
}	t12p_param;

static void st12p_get_params(t12p_param **pparam, size_t *nb_param)
{
	static t12p_param param[] =
	{
		{"%pwas NULL", NULL},
		{"%pA", (void*) 0x00}, {"brave %p", (void*) 0x0000000000000000}, 
		  {"camel |%p|danced ", (void*)  0x00000000DEADBEEF},
		  {"s%ppace", (void*) 0xDEADBEEFDEADBEEF},
		{"%p", (void*)  0xFFFFFFFFFFFFFFFF},
		{"%p\n", (void*) 0x000000007FFFFFFF},
		  {"\t%p", (void*) 0x7FFFFFFFFFFFFFFF},
		  {"%p\r", (void*) 0x0000000020000000}, 
		  {"%p\b", (void*) 0x0000000000400000}, 
		  {"%p\t", (void*) 0x0000000000400001}, 
		  {"%p\a", (void*)  0x0000000000400002}, 
		  {"\b%p", (void*) 0x0000000000400003},
		{"\n%p", (void*) 0x000000000040000f},
		{"%p\0", (void*)  0x00000000004000FF}, 
		{"\0%p", (void*)  0x00000000004000ab}, 
		{"%p\xFF", (void*)  0xFFFFFFFFFFFFFFFF},
		{"\xFF%p", (void*)  0xFFFFFFFFFFFFFFFF},
		{"%pcba%%", (void*) 0x00000000}, 
		{"%%p", (void*) 0xDEADBEEF}, 
		{"%p%", (void*) 0x7FFFFFFF}, 
		  {"%%p", (void*) 0x20000000},
		  {"%pc%", (void*)  0x00400000}, {"c%%p", (void*) 0x00400abc},
		{"%p%%", (void*) 0x00400def}, {"%%%p",   (void*) 0x00400314}
	};
	*pparam = param;
	*nb_param = sizeof(param) / sizeof(t12p_param);
}
//
// 1.1(c)  b) same return values?
//
ParameterizedTestParameters(ft_printf, p_one_arg_same_reval_expected)
{
	t12p_param *param;
	size_t nb_param;

	st12p_get_params(&param, &nb_param);
	return (cr_make_param_array(t12p_param, param, nb_param));
}
ParameterizedTest(t12p_param *param, ft_printf, p_one_arg_same_reval_expected)
{
	int reval_ori = printf(param->str, param->arg1);
	int reval_ft = ft_printf(param->str, param->arg1);
	cr_assert(reval_ori == reval_ft);
}
//
// 1.1(c) c) same output?
//
ParameterizedTestParameters(ft_printf, p_one_arg_ori_behav_expected)
{
	t0_param *param;
	size_t nb_param;

	st0_get_params(&param, &nb_param);
	return (cr_make_param_array(t0_param, param, nb_param));
}
ParameterizedTest(t12p_param *param, ft_printf, p_one_arg_ori_behav_expected)
{
	char expected[1024];

	cr_redirect_stdout();
	ft_printf(param->str, param->arg1);
	fflush(stdout);
	sprintf(expected, param->str, param->arg1);
	cr_assert_stdout_eq_str(expected);
}

