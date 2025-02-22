/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazzaoui <aazzaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 16:41:23 by aazzaoui          #+#    #+#             */
/*   Updated: 2025/01/27 20:02:14 by aazzaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_open(char *file, int flags, int permissions)
{
	int	fd;

	fd = open(file, flags, permissions);
	if (fd == -1)
	{
		ft_error(errno, 1);
		return (-1);
	}
	return (fd);
}
