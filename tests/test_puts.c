/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_puts.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <cbarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 16:32:41 by cbarbier          #+#    #+#             */
/*   Updated: 2019/05/03 16:59:22 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tests.h>

static int				test1()
{
	char		test[] = "test";

	if (ft_puts(test) != puts(test))
			return (1);
	return (0);
}

static int				test2()
{
	char		test[] = "samesameButDifferente∆?!/:;'><{}()-_=+~πˆø¨¥†®®´´∑œåß∂ƒ©˙˙∆¬……æ≈ç∫˜∫µ≤≥÷÷æ";

	if (ft_puts(test) != puts(test))
			return (1);
	return (0);
}

static int				test3()
{
	char		*test = 0;

	if (ft_puts(test) != puts(test))
			return (1);
	return (0);
}

int             test_puts(int *tot)
{
    t_unit      tests;

    tests.head = NULL;
	tests.cur = NULL;
	*tot += 3;
	my_putendl("\n### FT_PUTS TESTS");
    load_test(&tests, " 1/3 [EASY] - same return values ??\t\t\t",\
			test1);
    load_test(&tests, " 2/3 [EASY] - COMPARE the outputs ??\t\t\t",\
			test2);
    load_test(&tests, " 3/3 [HARD] - what if null pointer??\t\t\t",\
			test3);
	tests.returnval = ft_execute_tests(&tests);
	return (tests.returnval);
}