/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_command.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazzaoui <aazzaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 16:34:53 by aazzaoui          #+#    #+#             */
/*   Updated: 2025/02/02 12:55:28 by aazzaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**create_cmd_args(char *str)
{
	char	**args;

	args = ft_super_split(str, " \t\"'", "\"'");
	if (!args)
	{
		perror("Error creating args for command");
		ft_exit(errno);
		return (NULL);
	}
	return (args);
}

int	is_path(char *cmd)
{
	t_cs_list	*str;

	str = cs_list_new(sizeof(char));
	if (ft_strchr(cmd, '/'))
	{
		if (access(cmd, F_OK))
		{
			cs_list_add_ranges_count_arr(str, 5, 9, "./",
				ft_strlen(exe_file_name(0)), exe_file_name(0), 2, ": ",
				ft_strlen(cmd), cmd, 20, ": command not found\n");
			ft_putstr_fd(str->contate, 2);
		}
		return (1);
	}
	return (0);
}

char	*get_cmd_path(char **paths, char *cmd, int print_cmd)
{
	t_cs_list	*path;
	t_cs_list	*str;
	int			i;

	if (!cmd || !paths)
		return (NULL);
	if (is_path(cmd))
		return (cmd);
	i = -1;
	while (paths && paths[++i])
	{
		path = cs_list_new(sizeof(char));
		cs_list_add_ranges_count_arr(path, 3, ft_strlen(paths[i]), paths[i], 1,
			"/", ft_strlen(cmd), cmd);
		if (access(path->contate, X_OK) == 0)
			return (path->contate);
	}
	str = cs_list_new(sizeof(char));
	cs_list_add_ranges_count_arr(str, 5, 2, "./", ft_strlen(exe_file_name(0)),
		exe_file_name(0), 2, ": ", ft_strlen(cmd), cmd, 20,
		": command not found\n");
	if (print_cmd)
		ft_putstr_fd(str->contate, 2);
	ft_error(errno, 1);
	return (path->contate);
}

t_command	*proccess_commad(char *str, char **paths, char *envp[],
		int final_fd)
{
	char		**args;
	char		*cmd_path;
	t_pipe		*p;
	t_command	*cmd;

	cmd = ft_calloc(1, sizeof(t_command));
	args = create_cmd_args(str);
	cmd_path = get_cmd_path(paths, args[0], 1);
	if (cmd)
	{
		cmd->path = cmd_path;
		cmd->args = args;
		cmd->envp = envp;
		p = create_pipe();
		if (final_fd)
			p->fd_write = final_fd;
		add_pipe(p);
		cmd->pipe = current_pipe();
	}
	p = current_pipe();
	close(p->fd_write);
	p->fd_write = -1;
	exec_cmd(cmd);
	p = next_pipe();
	return (cmd);
}
