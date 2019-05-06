/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilib_part1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <cbarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 17:14:13 by matirell          #+#    #+#             */
/*   Updated: 2019/05/03 12:59:13 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libtester.h>

void	*my_memalloc(size_t size)
{
	int		len;
	char	*ret;

	len = (sizeof(char) * size);
	ret = (char *)malloc(len);
	if (!ret)
		return (NULL);
	my_memset((void *)ret, '\0', size);
	return (ret);
}

void	*my_memset(void *str, int c, size_t n)
{
	char *new;

	if (n == 0)
		return (str);
	new = (char *)str;
	while (n--)
	{
		*new = (char)c;
		if (n)
			new++;
	}
	*(char *)str = (char)c;
	return (str);
}

void	my_putchar(char c)
{
	write(1, &c, 1);
}

void	my_putendl(char const *str)
{
	my_putstr((char*)str);
	my_putchar('\n');
}

void	my_putnbr(int nbr)
{
	unsigned int x;

	x = nbr;
	if (nbr < 0)
	{
		my_putchar('-');
		x = (unsigned int)nbr * -1;
	}
	if (x > 9)
	{
		my_putnbr(x / 10);
		my_putnbr(x % 10);
	}
	else
	{
		my_putchar('0' + x);
	}
}
