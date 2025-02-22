/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_run_commands.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazzaoui <aazzaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 20:12:23 by aazzaoui          #+#    #+#             */
/*   Updated: 2025/02/02 12:37:41 by aazzaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	wait_proc(t_cs_list *cmds)
{
	t_command	*cmd;
	int			i;
	int			j;

	i = 0;
	while (i < cmds->count)
	{
		j = 0;
		ft_error(0, 1);
		cmd = ((t_command **)(cmds->contate))[i];
		while (j++ < 100000)
		{
			cmd->is_porc_complete = wait_process(cmd->pid);
			if (cmd->is_porc_complete)
				j = 100000;
		}
		i++;
	}
}

void	start_run_commands(int i, int argc, char *argv[], char *envp[])
{
	int			final_fd;
	char		**paths;
	t_cs_list	*cmds;
	t_command	*cmd;

	final_fd = check_input_output_files(argc, argv);
	paths = get_envp_paths(envp);
	cmds = cs_list_new_capacity(sizeof(t_command *), argc - i);
	while (i < argc - 1)
	{
		if (i == argc - 2)
			cmd = proccess_commad(argv[i], paths, envp, final_fd);
		else
			cmd = proccess_commad(argv[i], paths, envp, 0);
		cs_list_add(cmds, (long)cmd);
		i++;
	}
	wait_proc(cmds);
}
