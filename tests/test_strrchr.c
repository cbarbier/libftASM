/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strrchr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <cbarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 16:32:41 by cbarbier          #+#    #+#             */
/*   Updated: 2019/05/06 18:12:29 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tests.h>


static int				test1()
{
	char		*mine;
	char		*his;
	char		str[]		= "cbarbier";

	mine = ft_strrchr(str, 'i');
	his = strrchr(str, 'i');
	if (mine != his)
		return (1);
	return (0);
}

static int				test2()
{
	char		*mine;
	char		*his;
	char		str[]		= "abcdefghijklmnopqrstuvwxyz";

	mine = ft_strrchr(str, 'z');
	his = strrchr(str, 'z');
	if (mine != his)
		return (1);
	return (0);
}

static int				test3()
{
	char		*mine;
	char		*his;
	char		str[]		= "blablaba";

	mine = ft_strrchr(str, 'G');
	his = strrchr(str, 'G');
	if (mine != his)
		return (1);
	return (0);
}

static int				test4()
{
	char		*mine;
	char		*his;
	char		str[]		= "abcdefghijklmnopqrstuvwxyz";

	mine = ft_strrchr(str, 0);
	his = strrchr(str, 0);
	if (mine != his)
		return (1);
	return (0);
}

int             test_strrchr(int *tot)
{
    t_unit      tests;

    tests.head = NULL;
	tests.cur = NULL;
	*tot += 4;
	my_putendl("\n### FT_STRRCHR TESTS");
    load_test(&tests, " 1/4 [EASY] - can u find i in cbarbier ?\t\t",\
			test1);
	load_test(&tests, " 2/4 [EASY] - can u find z in abcdefghijklmnopqrstuvwxyz",\
			test2);
	load_test(&tests, " 3/4 [EASY] - now find G in blablabla \t\t\t",\
			test3);
	load_test(&tests, " 4/4 [HARD] - now try to find zero \t\t\t",\
			test4);
	tests.returnval = ft_execute_tests(&tests);
	return (tests.returnval);
}