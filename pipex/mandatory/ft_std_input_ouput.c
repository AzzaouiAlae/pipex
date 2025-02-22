/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_std_input_ouput.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazzaoui <aazzaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 16:41:54 by aazzaoui          #+#    #+#             */
/*   Updated: 2025/01/28 19:13:52 by aazzaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	std_input(int fd)
{
	static int	fd_std_input;

	if (fd != -1)
		fd_std_input = fd;
	return (fd_std_input);
}

void	save_std_input(void)
{
	int	fd;

	fd = dup(0);
	std_input(fd);
}

int	std_output(int fd)
{
	static int	fd_std_output;

	if (fd != -1)
		fd_std_output = fd;
	return (fd_std_output);
}

void	save_std_output(void)
{
	int	fd;

	fd = dup(1);
	std_output(fd);
}
