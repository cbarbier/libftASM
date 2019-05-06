/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_putchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <cbarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 16:32:41 by cbarbier          #+#    #+#             */
/*   Updated: 2019/05/06 18:25:01 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tests.h>

static int				test1()
{
	int		c;

	c = 'C';
	if (ft_putchar(c) != putchar(c))
			return (1);
	return (0);
}

static int				test2()
{
		int		c;

	c = 42;
	if (ft_putchar(c) != putchar(c))
			return (1);
	return (0);
}

int             test_putchar(int *tot)
{
    t_unit      tests;

    tests.head = NULL;
	tests.cur = NULL;
	*tot += 2;
	my_putendl("\n### FT_PUTCHAR TESTS");
    load_test(&tests, " 1/2 [EASY] - same return values ??\t\t\t",\
			test1);
    load_test(&tests, " 2/2 [EASY] - COMPARE the outputs ??\t\t\t",\
			test2);
	tests.returnval = ft_execute_tests(&tests);
	return (tests.returnval);
}