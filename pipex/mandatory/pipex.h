/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aazzaoui <aazzaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 16:43:00 by aazzaoui          #+#    #+#             */
/*   Updated: 2025/02/01 12:44:57 by aazzaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "cs_list/cs_list.h"
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_pipe
{
	int				fd_read;
	int				fd_write;
	struct s_pipe	*next;
}					t_pipe;

typedef struct s_command
{
	t_pipe			*pipe;
	char			*path;
	char			**args;
	char			**envp;
	int				pid;
	int				is_porc_complete;
}					t_command;

enum				e_pipe
{
	add,
	next,
	current,
	null
};

char				*exe_file_name(char *file_name);
void				start_run_commands(int i, int argc, char *argv[],
						char *envp[]);
void				start_run_commands(int i, int argc, char *argv[],
						char *envp[]);
int					wait_process(int pid);
char				**ft_super_split(const char *s, char *sep,
						char *special_sep);
char				*ft_strchr(const char *s, int c);
int					ft_open(char *file, int flags, int permissions);
int					check_input_output_files(int argc, char *argv[]);
char				**get_envp_paths(char *envp[]);
size_t				ft_strlen(const char *s);
char				**ft_split(const char *s, char c);
char				*ft_strdup(const char *s1);
char				*ft_substr(const char *s, unsigned int start, size_t len);
int					str_start_with(char *str, char *start);
char				*find_str_start_with(char **strs, char *to_find);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
void				add_pipe(t_pipe *p);
t_pipe				*next_pipe(void);
t_pipe				*current_pipe(void);
t_pipe				*all_pipes(enum e_pipe action, t_pipe *n_p);
t_pipe				*create_pipe(void);
void				ft_putstr_fd(char *s, int fd);
void				read_from_std_input(char *limiter);
int					str_end_with(t_cs_list *cs_str, t_cs_list *cs_end);
void				read_input_file(char *file);
void				rederect_fd_to_pipe(void);
char				*ft_strdup_without_save_mem(const char *s1);
void				run_command(char *cmd_path, char **args, char *envp[]);
void				exec_cmd(t_command *cmd);
t_command			*proccess_commad(char *str, char **paths, char *envp[],
						int final_fd);
char				*read_result_from_pipe(void);
int					ft_read(int fd, char *buf, size_t size);
void				save_std_input(void);
int					std_input(int fd);
void				save_std_output(void);
void				write_str_in_new_pipe(char *s);
void				read_input_file(char *file);
char				**create_cmd_args(char *str);
char				*get_cmd_path(char **paths, char *cmd, int print_cmd);
int					std_output(int fd);
int					std_input(int fd);
void				create_new_arrgs(char *cmd_path, char **args,
						char **cmd_path_, char ***args_);
void				error_running_cmd(char *cmd_path, char **args);
int					ft_error(int exit_status, int is_input);

#endif