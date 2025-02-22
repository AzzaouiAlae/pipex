/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input_file.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazzaoui <aazzaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 16:43:30 by aazzaoui          #+#    #+#             */
/*   Updated: 2025/01/29 21:24:43 by aazzaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	read_file(char *file)
{
	int	fd;

	fd = ft_open(file, O_RDONLY, 0666);
	if (fd == -1)
	{
		ft_putstr_fd("./", 2);
		ft_putstr_fd(exe_file_name(0), 2);
		perror(": input");
		ft_error(128, 1);
		return (fd);
	}
	return (fd);
}

void	read_input_file(char *file)
{
	t_pipe	*p;
	int		fd;

	fd = read_file(file);
	p = create_pipe();
	add_pipe(p);
	if (fd != -1)
	{
		dup2(fd, p->fd_read);
	}
	close(p->fd_write);
	p->fd_write = -1;
	close(fd);
}
