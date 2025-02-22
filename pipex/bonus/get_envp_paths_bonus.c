/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_envp_paths_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazzaoui <aazzaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 16:42:34 by aazzaoui          #+#    #+#             */
/*   Updated: 2025/02/01 12:49:30 by aazzaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	str_start_with(char *str, char *start)
{
	if (!str || !start)
		return (0);
	while (str && start && *str == *start)
	{
		str++;
		start++;
		if (!(*start))
			return (1);
	}
	return (0);
}

char	*find_str_start_with(char **strs, char *to_find)
{
	if (!strs || !to_find || !(*strs))
		return (NULL);
	while (*strs)
	{
		if (str_start_with(*strs, to_find))
			return (*strs);
		strs++;
	}
	return (NULL);
}

char	**get_envp_paths(char *envp[])
{
	char	*pts;
	char	**paths;

	pts = find_str_start_with(envp, "PATH=");
	if (!pts)
		pts = "/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin";
	paths = ft_super_split(&(pts[5]), ":", "");
	if (!paths)
	{
		perror("The PATH environment variable is missing or undefined");
		ft_exit(errno);
		return (NULL);
	}
	return (paths);
}
