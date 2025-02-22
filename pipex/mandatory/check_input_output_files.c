/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input_output_files.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazzaoui <aazzaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 16:39:39 by aazzaoui          #+#    #+#             */
/*   Updated: 2025/02/01 12:44:12 by aazzaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0 || (!s1 && !s2))
		return (0);
	while (s1[i] && s2[i] && i < n - 1)
	{
		if (s1[i] != s2[i])
			return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
		i++;
	}
	return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
}

int	check_input_output_files(int argc, char *argv[])
{
	int	last_index;
	int	fd;

	if (!argv)
	{
		perror("Error argv is null");
		ft_exit(errno);
		return (-1);
	}
	last_index = argc - 1;
	if (ft_strncmp(argv[1], "here_doc", 9))
		fd = ft_open(argv[last_index], O_CREAT | O_TRUNC | O_RDWR, 0666);
	else
		fd = ft_open(argv[last_index], O_CREAT | O_RDWR, 0666);
	if (fd == -1)
		ft_error(errno, 1);
	return (fd);
}
