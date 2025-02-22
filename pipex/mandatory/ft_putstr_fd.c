/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazzaoui <aazzaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 16:41:35 by aazzaoui          #+#    #+#             */
/*   Updated: 2025/01/27 17:51:14 by aazzaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
