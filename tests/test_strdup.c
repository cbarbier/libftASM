/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strdup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <cbarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 16:32:41 by cbarbier          #+#    #+#             */
/*   Updated: 2019/05/06 14:13:08 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tests.h>

static int				test1()
{
	char		test[] = "test";
	char		*mine;
	char		*his;

	mine = ft_strdup(test);
	his = strdup(test);
	if (strcmp(mine, his))
			return (1);
	return (0);
}

static int				test2()
{
	char		test[] = "test";
	char		*mine;
	char		*his;

	mine = ft_strdup(test);
	his = strdup(test);
	if (strcmp(mine, his))
			return (1);
	return (0);
}

static int				test3()
{
	char		test[] = "test";
	char		*mine;
	char		*his;

	mine = ft_strdup(test);
	his = strdup(test);
	if (strcmp(mine, his))
			return (1);
	return (0);
}

int             test_strdup(int *tot)
{
    t_unit      tests;

    tests.head = NULL;
	tests.cur = NULL;
	*tot += 3;
	my_putendl("\n### FT_strdup TESTS");
    load_test(&tests, " 1/3 [EASY] - all char of simple string are cpy to * ??\t",\
			test1);
    load_test(&tests, " 2/3 [EASY] - only part of a ling string ??\t\t",\
			test2);
    load_test(&tests, " 3/3 [EASY] - what if len == 0 ????\t\t\t",\
			test3);
	tests.returnval = ft_execute_tests(&tests);
	return (tests.returnval);
}