/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <cbarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 16:32:41 by cbarbier          #+#    #+#             */
/*   Updated: 2019/05/04 16:36:10 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tests.h>

static int				test1()
{
	char		test[] = "test";

	printf("%lu %lu\n", ft_strlen(test), strlen(test));
	if (ft_strlen(test) != strlen(test))
			return (1);
	return (0);
}

static int				test2()
{
	char		test[] = "samesameButDifferente∆?!/:;'><{}()-_=+~πˆø¨¥†®®´´∑œåß∂ƒ©˙˙∆¬……æ≈ç∫˜∫µ≤≥÷÷æ";

	if (ft_strlen(test) != strlen(test))
			return (1);
	return (0);
}

static int				test3()
{
	char		test[] = "";

	if (ft_strlen(test) != strlen(test))
			return (1);
	return (0);
}

int             test_strlen(int *tot)
{
    t_unit      tests;

    tests.head = NULL;
	tests.cur = NULL;
	*tot += 3;
	my_putendl("\n### FT_STRLEN TESTS");
    load_test(&tests, " 1/3 [EASY] - short simple string  ??\t\t\t",\
			test1);
    load_test(&tests, " 2/3 [EASY] - long complex string ??\t\t\t",\
			test2);
    load_test(&tests, " 3/3 [HARD] - empty  string ????\t\t\t",\
			test3);
	tests.returnval = ft_execute_tests(&tests);
	return (tests.returnval);
}