/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libfts.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <cbarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 16:27:46 by cbarbier          #+#    #+#             */
/*   Updated: 2019/05/07 14:36:28 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTS_H
# define LIBFTS_H
# include <unistd.h>
void                ft_bzero(char *s, size_t n);
char                *ft_strcat(char *restrict s1, char *restrict s2);
int                 ft_isalpha(int c);
int                 ft_isdigit(int c);
int                 ft_isalnum(int c);
int                 ft_isascii(int c);
int                 ft_isprint(int c);
int                 ft_isupper(int c);
int                 ft_islower(int c);
int                 ft_toupper(int c);
int                 ft_tolower(int c);
int                 ft_puts(const char *s);
size_t              ft_strlen(const char *s);
void                *ft_memset(void *s, int c, size_t len);
void                *ft_memcpy(void *restrict dst, const void *restrict src, size_t n);
char                *ft_strdup(const char *s1);
char                *ft_strchr(const char *s1, int c);
int                 ft_putchar(int c);
void                ft_cat(int fd);
unsigned char       ft_swapbits(unsigned char c);
void                ft_putnbr(int n);
#endif