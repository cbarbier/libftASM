/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <cbarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 16:32:41 by cbarbier          #+#    #+#             */
/*   Updated: 2019/04/30 16:51:49 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <libfts.h>

static int      test_fbzero()
{
    return (0);
}


int             main(void)
{
    char        buf[] = "is bzero working ? NO or YES";
    char        *page = malloc(4096);

    ft_bzero(page, 4098);
    free(page);
    ft_bzero(buf + 17, 6);
    printf("buf : %s %s\n", buf, buf + 24);
    return (0);
}