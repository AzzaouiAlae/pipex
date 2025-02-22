/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_from_std_input.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazzaoui <aazzaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 16:43:21 by aazzaoui          #+#    #+#             */
/*   Updated: 2025/02/01 12:47:14 by aazzaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	str_end_with(t_cs_list *cs_str, t_cs_list *cs_end)
{
	char	*str;
	char	*end;
	int		l_end;
	int		l_str;

	if (!cs_str || !cs_end)
		return (0);
	str = cs_str->contate;
	end = cs_end->contate;
	l_end = cs_end->count - 1;
	l_str = cs_str->count - 1;
	if (!str || !end || l_end > l_str || l_end < 0 || l_str < 0)
		return (0);
	while (str[l_str] == end[l_end])
	{
		if (l_end == 0)
			return (1);
		l_end--;
		l_str--;
	}
	return (0);
}

void	write_str_in_new_pipe(char *s)
{
	t_pipe	*p;

	p = create_pipe();
	add_pipe(p);
	ft_putstr_fd(s, p->fd_write);
	close(p->fd_write);
	p->fd_write = -1;
}

char	*cut_str_end(char *s, size_t cut_len)
{
	size_t	len;

	len = ft_strlen(s) - 2 - cut_len;
	if (len > 0)
		s[len] = '\0';
	return (s);
}

void	read_from_std_input(char *limiter)
{
	t_cs_list	*str;
	t_cs_list	*lim;
	char		ch;

	ch = 0;
	str = cs_list_new(sizeof(char));
	lim = cs_list_new(sizeof(char));
	cs_list_add_ranges_count_arr(lim, 3, 1, "\n", ft_strlen(limiter), limiter,
		1, "\n");
	while (1)
	{
		while (ch != '\n')
		{
			ft_read(0, &ch, 1);
			cs_list_add(str, (long)ch);
		}
		ch = '\0';
		if (str_end_with(str, lim))
		{
			write_str_in_new_pipe(cut_str_end(str->contate,
					ft_strlen(limiter)));
			return ;
		}
	}
}
