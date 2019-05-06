/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_cat.c                                      :+:      :+:    :+:   */
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
	int		fd;

	fd = open("auteur", O_RDONLY);
	ft_cat(fd);
	close(fd);
	return (0);
}

static int				test2()
{
		int		fd;

	fd = open("Makefile", O_RDONLY);
	ft_cat(fd);
	close(fd);
	return (0);
}

static int				test3()
{
	ft_cat(-1);
	return (0);
}

static int				test4()
{
	ft_cat(0);
	return (0);
}

int             test_cat(int *tot)
{
    t_unit      tests;

    tests.head = NULL;
	tests.cur = NULL;
	*tot += 3;
	my_putendl("\n### FT_CAT TESTS");
    load_test(&tests, " 1/3 [EASY] - Can you print the auhtor file ??\t\t",\
			test1);
    load_test(&tests, " 2/3 [EASY] - What about the Makefile ??\t\t",\
			test2);
    load_test(&tests, " 3/3 [EASY] - what the file descriptor is -1????\t",\
			test3);
	tests.returnval = ft_execute_tests(&tests);
	return (tests.returnval);
}