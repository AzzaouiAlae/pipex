/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd2_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazzaoui <aazzaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 16:41:11 by aazzaoui          #+#    #+#             */
/*   Updated: 2025/02/02 12:37:47 by aazzaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	error_running_cmd(char *cmd_path, char **args)
{
	int	i;

	i = 0;
	while (args[i])
		free(args[i++]);
	free(args[i++]);
	free(args);
	free(cmd_path);
	ft_exit(errno);
}

void	run_command(char *cmd_path, char **args, char *envp[])
{
	execve(cmd_path, args, envp);
	error_running_cmd(cmd_path, args);
}
