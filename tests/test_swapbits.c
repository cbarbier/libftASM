/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_swapbits.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <cbarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 16:32:41 by cbarbier          #+#    #+#             */
/*   Updated: 2019/05/06 19:31:21 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tests.h>

static int				test1()
{
	unsigned char c;

	c = 42;
	if (ft_swapbits(c) != (unsigned char)((c << 4) | (c >> 4)))
		return (1);
	return (0);
}

static int				test2()
{
	unsigned char c;

	c = 0xFD;
	if (ft_swapbits(c) != (unsigned char)((c << 4) | (c >> 4)))
		return (1);
	return (0);
}

int             test_swapbits(int *tot)
{
    t_unit      tests;

    tests.head = NULL;
	tests.cur = NULL;
	*tot += 2;
	my_putendl("\n### FT_SWAPBITS TESTS");
    load_test(&tests, " 1/2 [EASY] - easy value with 42\t\t\t",\
			test1);
    load_test(&tests, " 2/2 [EASY] - harder 0xFD ??\t\t\t\t",\
			test2);
	tests.returnval = ft_execute_tests(&tests);
	return (tests.returnval);
}