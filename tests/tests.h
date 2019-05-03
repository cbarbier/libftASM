/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <cbarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 16:27:46 by cbarbier          #+#    #+#             */
/*   Updated: 2019/05/03 16:58:37 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_H
# define TESTS_H
# include <unistd.h>
# include <ctype.h>
# include <libfts.h>
# include <libtester.h>
# include <stdlib.h>
# include <strings.h>

int                test_bzero(int *total);
int                test_strcat(int *total);
int                test_isalpha(int *total);
int                test_isdigit(int *total);
int                test_isalnum(int *total);
int                test_isascii(int *total);
int                test_isprint(int *total);
int                test_isupper(int *total);
int                test_islower(int *total);
int                test_toupper(int *total);
int                test_tolower(int *total);
#endif 