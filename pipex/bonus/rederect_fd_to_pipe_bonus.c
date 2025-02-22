/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rederect_fd_to_pipe_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazzaoui <aazzaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 16:43:43 by aazzaoui          #+#    #+#             */
/*   Updated: 2025/02/22 11:29:28 by aazzaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	rederect_fd_to_pipe(void)
{
	t_pipe	*cur_pipe;
	t_pipe	*n_pipe;
	int		result1;
	int		result2;

	cur_pipe = current_pipe();
	n_pipe = next_pipe();
	result1 = dup2(cur_pipe->fd_read, 0);
	result2 = dup2(n_pipe->fd_write, 1);
	if (result1 == -1 || result2 == -1)
	{
		ft_putstr_fd("error rederect file descriptor\n", 2);
		ft_exit(errno);
	}
}
