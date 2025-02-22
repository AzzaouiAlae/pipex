/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazzaoui <aazzaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 16:42:53 by aazzaoui          #+#    #+#             */
/*   Updated: 2025/02/02 12:36:56 by aazzaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*exe_file_name(char *file_name)
{
	static char	*name;
	size_t		len;

	if (file_name)
	{
		len = ft_strlen(file_name) - 1;
		while (file_name[len] != '/')
			len--;
		len++;
		name = &(file_name[len]);
	}
	return (name);
}

void	pipex(int argc, char *argv[], char *envp[])
{
	int	i;

	i = 2;
	read_input_file(argv[1]);
	start_run_commands(i, argc, argv, envp);
	ft_free_all();
}

int	is_valid_args(int arg_c, char *arg_v[])
{
	int	i;

	i = 0;
	while (arg_v && ((arg_v[i] && arg_v[i][0] != '\0') || (arg_c == i)))
	{
		if (arg_c == i)
			return (1);
		i++;
	}
	return (0);
}

int	main(int arg_c, char *arg_v[], char *envp[])
{
	if (arg_c == 5 && is_valid_args(arg_c, arg_v))
	{
		save_std_input();
		save_std_output();
		exe_file_name(arg_v[0]);
		pipex(arg_c, arg_v, envp);
	}
	else
	{
		ft_putstr_fd("Error invalid argument\n", 2);
		ft_exit(1);
	}
	return (ft_error(0, 0));
}
