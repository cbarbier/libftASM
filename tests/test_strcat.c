/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strcat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <cbarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 16:32:41 by cbarbier          #+#    #+#             */
/*   Updated: 2019/05/03 15:03:08 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tests.h>


static int				test1()
{
	char mine[100];
	char his[100];

	bzero(mine, 100);
	bzero(his, 100);
	memmove(mine, "abc", 3);
	memmove(his, "abc", 3);
	ft_strcat(mine, "def");
	strcat(his, "def");
	if (strcmp(mine, his))
		return (1);
	return (0);
}

static int				test2()
{
	char mine[100];
	char his[100];

	bzero(mine, 100);
	bzero(his, 100);
	memmove(mine, "abc", 3);
	memmove(his, "abc", 3);
	ft_strcat(mine, "");
	strcat(his, "");
	if (strcmp(mine, his))
		return (1);
	return (0);
}

static int				test3()
{
	char mine[100];
	char his[100];

	bzero(mine, 100);
	bzero(his, 100);
	ft_strcat(mine, "blabla");
	strcat(his, "blabla");
	if (strcmp(mine, his))
		return (1);
	return (0);
}

static int				test4()
{
	char mine[100];
	char his[100];

	bzero(mine, 100);
	bzero(his, 100);
	ft_strcat(mine, "");
	strcat(his, "");
	if (strcmp(mine, his))
		return (1);
	return (0);
}

static int				test5()
{
	char mine[100];
	char his[100];

	bzero(mine, 100);
	bzero(his, 100);
	memmove(mine, "abcdef", 6);
	memmove(his, "abcdef", 6);
	mine[12] = 42;
	ft_strcat(mine, "blabla");
	strcat(his, "blabla");
	if (strcmp(mine, his))
		return (1);
	return (0);
}

int             test_strcat(int *tot)
{
    t_unit      tests;

    tests.head = NULL;
	tests.cur = NULL;
	*tot += 5;
	my_putendl("\n### FT_STRCAT TESTS");
    load_test(&tests, " 1/5 [EASY] - abc << def, too easy ?\t\t\t",\
			test1);
	load_test(&tests, " 2/5 [EASY] - what if s2 is empty \t\t\t",\
			test2);
	load_test(&tests, " 3/5 [EASY] - what if s1 is empty \t\t\t",\
			test3);
	load_test(&tests, " 4/5 [HARD] - what if they're both null \t\t",\
			test4);
	load_test(&tests, " 5/5 [HARD] - what about that final zero \t\t",\
			test5);
	tests.returnval = ft_execute_tests(&tests);
	return (tests.returnval);
}