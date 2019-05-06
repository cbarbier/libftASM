/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilib_part2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <cbarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 17:50:48 by matirell          #+#    #+#             */
/*   Updated: 2019/05/03 12:59:22 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libtester.h>

void	my_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		my_putchar(str[i]);
		i++;
	}
}

char	*my_strdup(const char *str)
{
	char	*str_dup;
	int		i;

	i = -1;
	str_dup = NULL;
	if (str)
	{
		str_dup = my_memalloc((my_strlen(str) + 1) * sizeof(char));
		if (str_dup == NULL)
			return (NULL);
		while (str[++i])
			str_dup[i] = str[i];
		str_dup[i] = '\0';
	}
	return (str_dup);
}

size_t	my_strlen(const char *str)
{
	size_t i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}
