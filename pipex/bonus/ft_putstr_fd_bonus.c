/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazzaoui <aazzaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 16:41:35 by aazzaoui          #+#    #+#             */
/*   Updated: 2025/02/22 11:33:19 by aazzaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_putstr_fd(char *s, int fd)
{
	size_t	n;
	int		res;

	n = ft_strlen(s);
	res = write(fd, s++, n);
	if (res == -1)
	{
		perror("Error write");
		ft_exit(errno);
		return ;
	}
}
