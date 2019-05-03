/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_isalnum.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <cbarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 16:32:41 by cbarbier          #+#    #+#             */
/*   Updated: 2019/05/03 16:21:02 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tests.h>

static int				test1()
{
	int				i;

	i = INT16_MIN;
	while (i <= INT16_MAX)
	{
		if (ft_isalnum(i) != isalnum(i))
			return (1);
		i++;
	}
	return (0);
}

int             test_isalnum(int *tot)
{
    t_unit      tests;

    tests.head = NULL;
	tests.cur = NULL;
	*tot += 1;
	my_putendl("\n### FT_ISALNUM TESTS");
    load_test(&tests, " 1/1 [HARD] - passing throught every integer ?\t\t",\
			test1);
	tests.returnval = ft_execute_tests(&tests);
	return (tests.returnval);
}