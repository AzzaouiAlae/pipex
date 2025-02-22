/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rederect_fd_to_pipe.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazzaoui <aazzaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 16:43:43 by aazzaoui          #+#    #+#             */
/*   Updated: 2025/01/29 18:27:13 by aazzaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	rederect_fd_to_pipe(void)
{
	t_pipe	*cur_pipe;
	t_pipe	*n_pipe;
	int		result1;
	int		result2;

	cur_pipe = current_pipe();
	n_pipe = next_pipe();
	close(n_pipe->fd_read);
	n_pipe->fd_read = -1;
	close(cur_pipe->fd_write);
	cur_pipe->fd_write = -1;
	result1 = dup2(cur_pipe->fd_read, 0);
	result2 = dup2(n_pipe->fd_write, 1);
	if (result1 == -1 || result2 == -1)
	{
		ft_putstr_fd("error rederect file descriptor\n", 2);
		ft_exit(errno);
	}
}
