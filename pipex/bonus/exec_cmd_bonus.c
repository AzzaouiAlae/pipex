/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazzaoui <aazzaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 16:40:56 by aazzaoui          #+#    #+#             */
/*   Updated: 2025/02/01 12:45:08 by aazzaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	fork_error(void)
{
	perror("Failed to create a new process using fork");
	ft_exit(errno);
}

void	create_new_arrgs(char *cmd_path, char **args, char **cmd_path_,
		char ***args_)
{
	int	len;

	len = 0;
	*cmd_path_ = ft_strdup_without_save_mem(cmd_path);
	while (args[len])
		len++;
	*args_ = ft_calloc_without_save(len + 1, sizeof(char *));
	len = 0;
	while (args[len])
	{
		(*args_)[len] = ft_strdup_without_save_mem(args[len]);
		len++;
	}
}

int	wait_process(int pid)
{
	int			status;
	char		*ch;
	int			pid_;

	status = 0;
	pid_ = waitpid(pid, &status, WNOHANG);
	if (status)
	{
		ch = (char *)&status;
		if (!(ch[1]))
			ft_error(1, 1);
		else if (ch[1])
			ft_error(ch[1], 1);
		else
			ft_error(1, 1);
		return (1);
	}
	else if (pid == pid_)
		return (pid_);
	return (0);
}

void	exec_cmd(t_command *cmd)
{
	char	*cmd_path_;
	char	**args_;
	char	**envp;

	ft_error(0, 1);
	cmd->pid = fork();
	if (cmd->pid == -1)
		fork_error();
	else if (cmd->pid == 0)
	{
		create_new_arrgs(cmd->path, cmd->args, &cmd_path_, &args_);
		rederect_fd_to_pipe();
		envp = cmd->envp;
		ft_free_all();
		run_command(cmd_path_, args_, envp);
	}
}
