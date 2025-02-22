/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_func.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazzaoui <aazzaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 16:42:42 by aazzaoui          #+#    #+#             */
/*   Updated: 2025/01/28 19:14:27 by aazzaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	add_new_pipe(t_pipe **l_pipes, t_pipe *n_p)
{
	t_pipe	*last_pipe;

	if (*l_pipes == NULL)
	{
		*l_pipes = n_p;
		return ;
	}
	last_pipe = *l_pipes;
	while (last_pipe->next)
		last_pipe = last_pipe->next;
	last_pipe->next = n_p;
}

t_pipe	*all_pipes(enum e_pipe action, t_pipe *n_p)
{
	static t_pipe	*p;

	if (action == add)
		add_new_pipe(&p, n_p);
	else if (action == next && p)
		p = p->next;
	else if (action == null)
		p = NULL;
	else
		return (p);
	return (p);
}

t_pipe	*create_pipe(void)
{
	int		pipe_fds[2];
	t_pipe	*p;

	p = ft_calloc(1, sizeof(t_pipe));
	if (pipe(pipe_fds))
	{
		perror("Error creating pipe");
		ft_exit(errno);
		return (0);
	}
	p->fd_read = pipe_fds[0];
	p->fd_write = pipe_fds[1];
	return (p);
}
