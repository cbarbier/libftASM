/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <cbarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 19:38:25 by cbarbier          #+#    #+#             */
/*   Updated: 2019/05/03 12:58:23 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libtester.h>

int		ft_putsignal(t_unit_test *tmp)
{
	my_putstr("\t: \t[");
	if (!tmp->ret)
		my_putstr("\033[0;32mOK\033[0m");
	else if (tmp->signal == SIGSEGV)
		my_putstr("\033[0;33mSEGV\033[0m");
	else if (tmp->signal == SIGBUS)
		my_putstr("\033[0;36mBUSE\033[0m");
	else if (tmp->signal == SIGALRM)
		my_putstr("\033[45mTIMEOUT\033[0m");
	else if (tmp->signal == SIGABRT)
		my_putstr("\033[43mABORT\033[0m");
	else
		my_putstr("\033[0;31mKO\033[0m");
	my_putendl("]");
	return (0);
}

void	ft_init(t_unit_test **head, t_unit_test **cur)
{
	if (!(*head))
	{
		if (!(*head = (t_unit_test *)my_memalloc(sizeof(t_unit_test))))
			return ;
		(*cur) = (*head);
		(*head)->next = NULL;
		return ;
	}
	if ((*cur)->next == NULL)
		if (!((*cur)->next = (t_unit_test *)my_memalloc(sizeof(t_unit_test))))
			return ;
	(*cur) = (*cur)->next;
	(*cur)->next = NULL;
}
