/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <cbarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 16:32:41 by cbarbier          #+#    #+#             */
/*   Updated: 2019/05/03 15:46:29 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libtester.h>
#include <tests.h>

static int          quicktest(void)
{
    int             i = -51321312;

    printf("%d %d, %d\n",i, isalpha(i), ft_isalpha(i));
    return (0);
}


int             main(void)
{
    int         tot;
    int         ok;

    tot = 0;
    ok = 0;
    my_putendl("\033[43m-------------------------------\033[0m");
	my_putendl("\033[43m-       LIB ASM TESTER         \033[0m");
	my_putendl("\033[43m-------------------------------\033[0m");
    my_putstr("\n - PART 1 -\n");
    ok += test_bzero(&tot);
    ok += test_strcat(&tot);
    ok += test_isalpha(&tot);
    ok += test_isdigit(&tot);
    my_putendl("\n\n\033[43m-------------------------------\033[0m");
	my_putstr("\033[43mTOTAL\t\033[0m");
    my_putnbr(ok);
	my_putstr(" / ");
    my_putnbr(tot);
	my_putendl(" PASSED");
	my_putendl("\033[43m-------------------------------\033[0m");
    quicktest();
    return (0);
}