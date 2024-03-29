/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_bzero.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <cbarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 16:32:41 by cbarbier          #+#    #+#             */
/*   Updated: 2019/05/07 14:38:55 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tests.h>


static int				test1()
{
	char mine[]		= "test bzero";
	char his[]		= "test bzero";

	ft_bzero(mine, 4);
	bzero(his, 4);
	if (strcmp(mine, his) || strcmp(mine + 5, his + 5))
		return (1);
	return (0);
}

static int				test2()
{
	char mine[]		= "test bzero";
	char his[]		= "test bzero";

	ft_bzero(mine, 0);
	bzero(his, 0);
	if (strcmp(mine, his) || strcmp(mine + 9, his + 9))
		return (1);
	return (0);
}

static int				test3()
{
	char mine[]		= "test bzero";
	char his[]		= "test bzero";

	ft_bzero(mine, 4);
	ft_bzero(mine + 6, 2);
	bzero(his, 4);
	bzero(his + 6, 2);
	if (strcmp(mine + 5, his + 5) || strcmp(mine + 9, his + 9))
		return (1);
	return (0);
}

int             test_bzero(int *tot)
{
    t_unit      tests;

    tests.head = NULL;
	tests.cur = NULL;
	*tot += 3;
	my_putendl("\n### FT_BZERO TESTS");
    load_test(&tests, " 1/3 [EASY] - too simple right ?\t\t\t",\
			test1);
	load_test(&tests, " 2/3 [EASY] - n is null \t\t\t\t",\
			test2);
	load_test(&tests, " 3/3 [HARD] - two bzero on one string \t\t\t",\
			test3);
	tests.returnval = ft_execute_tests(&tests);
	return (tests.returnval);
}