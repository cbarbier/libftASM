/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libfts.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <cbarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 16:27:46 by cbarbier          #+#    #+#             */
/*   Updated: 2019/05/03 15:43:46 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTS_H
# define LIBFTS_H
# include <unistd.h>
void                ft_bzero(char *s, size_t n);
char                *ft_strcat(char *restrict s1, char *restrict s2);
int                 ft_isalpha(int c);
int                 ft_isdigit(int c);
#endif 