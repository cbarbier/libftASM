/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_memset.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <cbarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 16:32:41 by cbarbier          #+#    #+#             */
/*   Updated: 2019/05/04 16:51:09 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tests.h>

static int				test1()
{
	char		mine[] = "test";
	char		his[] = "test";

	ft_memset(mine, 42, 4);
	memset(his, 42, 4);
	if (strcmp(mine, his))
			return (1);
	return (0);
}

static int				test2()
{
	char		mine[] = "test____harder______";
	char		his[] = "test____harder______";
	
	if (strcmp(ft_memset(mine + 3, 32, 7), memset(his + 3, 32, 7)))
			return (1);
	return (0);
}

static int				test3()
{
	char		mine[] = "test";
	char		his[] = "test";

	ft_memset(mine, 42, 0);
	memset(his, 42, 0);
	if (strcmp(mine, his))
			return (1);
	return (0);
}

int             test_memset(int *tot)
{
    t_unit      tests;

    tests.head = NULL;
	tests.cur = NULL;
	*tot += 3;
	my_putendl("\n### FT_MEMCPY TESTS");
    load_test(&tests, " 1/3 [EASY] - all char of simple string are set to * ??\t",\
			test1);
    load_test(&tests, " 2/3 [EASY] - only part of a ling string ??\t\t",\
			test2);
    load_test(&tests, " 3/3 [EASY] - what if len == 0 ????\t\t\t",\
			test3);
	tests.returnval = ft_execute_tests(&tests);
	return (tests.returnval);
}