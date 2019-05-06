/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libtester.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <cbarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 01:01:05 by matirell          #+#    #+#             */
/*   Updated: 2019/05/03 12:58:07 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBTESTER_H
# define LIBTESTER_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <signal.h>
# include <sys/wait.h>

typedef struct			s_unit_test
{
	char				*name;
	int					signal;
	int					ret;
	int					(*ft)();
	struct s_unit_test	*next;
}						t_unit_test;

typedef	struct			s_unit
{
	struct s_unit_test	*head;
	struct s_unit_test	*cur;
	int					returnval;
}						t_unit;

void					ft_init(t_unit_test **head, t_unit_test **cur);
void					load_test(t_unit *tests, char *testname, int (*ft)());
int						ft_execute_tests(t_unit *tests);
int						ft_display_resume(t_unit *tests, int verbose);
int						ft_putsignal(t_unit_test *tmp);

void					*my_memset(void *str, int c, size_t n);
void					my_putstr(char *str);
void					my_putchar(char c);
void					my_putendl(char const *str);
void					*my_memalloc(size_t size);
char					*my_strdup(const char *str);
size_t					my_strlen(const char *str);
void					my_putnbr(int nbr);
#endif
