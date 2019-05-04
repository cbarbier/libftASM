/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <cbarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 16:32:41 by cbarbier          #+#    #+#             */
/*   Updated: 2019/05/04 17:01:14 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libtester.h>
#include <tests.h>

static int          quicktest(void)
{
    int             i = 127;

    printf("quicktest\n");
    printf("strlen %lu\n", ft_strlen("mama"));
    return (0);
}


int             main(void)
{
    int         tot;
    int         ok;

    tot = 0;
    ok = 0;
    my_putendl("\033[32m-------------------------------\033[0m");
	my_putendl("\033[32m-       LIB ASM TESTER         \033[0m");
	my_putendl("\033[32m-------------------------------\033[0m");
    my_putstr("\n - PART 1 -\n");
    ok += test_bzero(&tot);
    ok += test_strcat(&tot);
    ok += test_isalpha(&tot);
    ok += test_isdigit(&tot);
    ok += test_isalnum(&tot);
    ok += test_isascii(&tot);
    ok += test_isprint(&tot);
    ok += test_islower(&tot);
    ok += test_isupper(&tot);
    ok += test_toupper(&tot);
    ok += test_tolower(&tot);
    ok += test_puts(&tot);
    ok += test_strlen(&tot);
    ok += test_memset(&tot);
    ok += test_memcpy(&tot);
    ok += test_strdup(&tot);
    my_putendl("\n\n\033[32m-------------------------------\033[0m");
	my_putstr("\033[32mTOTAL\t\033[0m");
    my_putnbr(ok);
	my_putstr(" / ");
    my_putnbr(tot);
	my_putendl(" PASSED");
	my_putendl("\033[32m-------------------------------\033[0m");
    quicktest();
    return (0);
}