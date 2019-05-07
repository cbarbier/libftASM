/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_putnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <cbarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 16:32:41 by cbarbier          #+#    #+#             */
/*   Updated: 2019/05/07 14:14:55 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tests.h>

static int				test1()
{
	ft_putnbr(2147483647);
	return (0);
}

static int				test2()
{
	ft_putnbr(-2147483648);
	return (0);
}

static int				test3()
{
	ft_putnbr(0);
	return (0);
}

static int				test4()
{
	ft_putnbr(42);
	return (0);
}

int             test_putnbr(int *tot)
{
    t_unit      tests;

    tests.head = NULL;
	tests.cur = NULL;
	*tot += 4;
	my_putendl("\n### FT_PUTNBR TESTS");
    load_test(&tests, " 1/4 [EASY] - int max 2147483647??\t\t",\
			test1);
    load_test(&tests, " 2/4 [EASY] -  int min -2147483648??\t\t",\
			test2);
    load_test(&tests, "\t 3/4 [HARD] -  zero ??\t\t\t\t",\
			test3);
    load_test(&tests, "\t 4/4 [HARD] -  fortytwo ??\t\t\t",\
			test4);
	tests.returnval = ft_execute_tests(&tests);
	return (tests.returnval);
}