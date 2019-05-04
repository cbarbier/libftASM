/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_memcpy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <cbarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 16:32:41 by cbarbier          #+#    #+#             */
/*   Updated: 2019/05/04 17:04:59 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tests.h>

static int				test1()
{
	char		mine_src[] = "test";
	char		mine_dst[] = "____";
	char		his_src[] = "test";
	char		his_dst[] = "____";

	ft_memcpy(mine_dst, mine_src, 4);
	memcpy(his_dst, his_src, 4);
	if (strcmp(mine_dst, his_dst))
			return (1);
	return (0);
}


static int				test2()
{
	char		mine_src[] = "test___DATACOPY__";
	char		mine_dst[] = "________";
	char		his_src[] = "test___DATACOPY__";
	char		his_dst[] = "________";

	ft_memcpy(mine_dst, mine_src + 8, 8);
	memcpy(his_dst, his_src + 8, 8);
	if (strcmp(mine_dst, his_dst))
			return (1);
	return (0);
}

static int				test3()
{
	char		mine_src[] = "test";
	char		mine_dst[] = "____";
	char		his_src[] = "test";
	char		his_dst[] = "____";

	ft_memcpy(mine_dst, mine_src, 0);
	memcpy(his_dst, his_src, 0);
	if (strcmp(mine_dst, his_dst))
			return (1);
	return (0);
}

int             test_memcpy(int *tot)
{
    t_unit      tests;

    tests.head = NULL;
	tests.cur = NULL;
	*tot += 3;
	my_putendl("\n### FT_MEMCPY TESTS");
    load_test(&tests, " 1/3 [EASY] - all char of simple string are cpy to * ??\t",\
			test1);
    load_test(&tests, " 2/3 [EASY] - only part of a ling string ??\t\t",\
			test2);
    load_test(&tests, " 3/3 [EASY] - what if len == 0 ????\t\t\t",\
			test3);
	tests.returnval = ft_execute_tests(&tests);
	return (tests.returnval);
}