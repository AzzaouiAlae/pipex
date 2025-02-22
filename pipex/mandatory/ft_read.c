/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazzaoui <aazzaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 16:41:40 by aazzaoui          #+#    #+#             */
/*   Updated: 2025/01/27 20:00:12 by aazzaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_read(int fd, char *buf, size_t size)
{
	int	n;

	n = read(fd, buf, size);
	if (n == -1)
	{
		perror("Error read file");
		return (-1);
	}
	return (n);
}
