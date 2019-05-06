/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tests.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <cbarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 01:55:02 by matirell          #+#    #+#             */
/*   Updated: 2019/05/03 17:22:58 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libtester.h>

void		load_test(t_unit *tests, char *testname, int (*ft)())
{
	ft_init(&tests->head, &tests->cur);
	if (tests->cur)
	{
		tests->cur->name = my_strdup(testname);
		tests->cur->ft = ft;
	}
}

int			ft_test_process(t_unit_test *test, int (*ft)())
{
	pid_t	pid;
	int		result;
	int		status;

	pid = fork();
	if (pid >= 0)
	{
		if (pid == 0)
		{
			alarm(2);
			result = (*ft)();
			exit(result);
		}
		else
		{
			wait(&status);
			test->ret = -1;
			if (WIFSIGNALED(status))
				test->signal = WTERMSIG(status);
			else
				test->ret = (WEXITSTATUS(status)) ? -1 : 0;
		}
	}
	return (0);
}

int			ft_execute_tests(t_unit *tests)
{
	t_unit_test	*tmp;

	tmp = tests->head;
	while (tmp)
	{
		ft_test_process(tmp, tmp->ft);
		my_putchar('\t');
		my_putstr(tmp->name);
		free(tmp->name);
		ft_putsignal(tmp);
		tmp = tmp->next;
	}
	return (ft_display_resume(tests, 1));
}

static void	ft_free_testlist(t_unit_test *l)
{
	t_unit_test		*t;

	while (l)
	{
		t = l->next;
		free(l);
		l = t;
	}
}

int			ft_display_resume(t_unit *tests, int verbose)
{
	int			total;
	int			ok;
	t_unit_test	*tmp;

	total = 0;
	ok = 0;
	tmp = tests->head;
	while (tmp && ++total)
	{
		ok += (!tmp->ret) ? 1 : 0;
		tmp = tmp->next;
	}
	if (total && verbose)
	{
		my_putnbr(ok);
		my_putchar('/');
		my_putnbr(total);
		my_putstr(" TESTS PASSED -> ");
		if (ok == total)
			my_putendl("\033[0;32m- All good - \033[0m");
		else
			my_putendl("\033[0;31m- WORK MORE!! - \033[0m");
		ft_free_testlist(tests->head);
	}
	return (ok);
}
