SRC =	mandatory/check_input_output_files.c	mandatory/exec_cmd2.c	mandatory/exec_cmd.c	mandatory/ft_error.c	mandatory/ft_open.c	\
		mandatory/ft_putstr_fd.c	mandatory/ft_read.c	mandatory/ft_std_input_ouput.c	mandatory/ft_strchr.c	mandatory/ft_strdup.c	\
		mandatory/ft_strlen.c	mandatory/ft_substr.c	mandatory/ft_super_split.c	mandatory/get_envp_paths.c	mandatory/pipe_func2.c	\
		mandatory/pipe_func.c	mandatory/pipex.c	mandatory/pipex_run_commands.c	mandatory/process_command.c	mandatory/read_from_std_input.c	\
		mandatory/read_input_file.c	mandatory/read_result_from_pipe.c	mandatory/rederect_fd_to_pipe.c
SRC_CS_LIST = mandatory/cs_list/cs_list_add.c	mandatory/cs_list/cs_list_new.c	mandatory/cs_list/cs_list_resize.c	mandatory/cs_list/ft_memcpy.c
SRC_GC =	mandatory/garbage_collector/ft_calloc.c	mandatory/garbage_collector/ft_exit.c	mandatory/garbage_collector/ft_free.c	\
			mandatory/garbage_collector/ft_save_mem.c	mandatory/garbage_collector/mem_list.c

SRC_GC_bonus = bonus/garbage_collector_bonus/ft_calloc_bonus.c	bonus/garbage_collector_bonus/ft_exit_bonus.c	bonus/garbage_collector_bonus/ft_free_bonus.c	\
			bonus/garbage_collector_bonus/ft_save_mem_bonus.c	bonus/garbage_collector_bonus/mem_list_bonus.c
SRC_CS_LIST_bonus = bonus/cs_list_bonus/cs_list_add_bonus.c	bonus/cs_list_bonus/cs_list_new_bonus.c	bonus/cs_list_bonus/cs_list_resize_bonus.c	\
					bonus/cs_list_bonus/ft_memcpy_bonus.c
SRC_bonus =	bonus/pipex_run_commands_bonus.c	bonus/ft_error_bonus.c	bonus/ft_strchr_bonus.c	bonus/ft_super_split_bonus.c	\
			bonus/check_input_output_files_bonus.c	bonus/exec_cmd2_bonus.c	bonus/exec_cmd_bonus.c	bonus/ft_open_bonus.c	bonus/ft_putstr_fd_bonus.c	\
			bonus/ft_read_bonus.c	bonus/ft_std_input_ouput_bonus.c	bonus/ft_strdup_bonus.c	bonus/ft_strlen_bonus.c	bonus/ft_substr_bonus.c	\
			bonus/get_envp_paths_bonus.c	bonus/pipe_func2_bonus.c	bonus/pipe_func_bonus.c	bonus/pipex_bonus.c	bonus/process_command_bonus.c	\
			bonus/read_from_std_input_bonus.c	bonus/read_input_file_bonus.c	bonus/read_result_from_pipe_bonus.c	bonus/rederect_fd_to_pipe_bonus.c

OBJS = 	mandatory/check_input_output_files.o	mandatory/exec_cmd2.o	mandatory/exec_cmd.o	mandatory/ft_error.o	\
		mandatory/ft_open.o	mandatory/ft_putstr_fd.o	mandatory/ft_read.o	mandatory/ft_std_input_ouput.o	mandatory/ft_strchr.o	\
		mandatory/ft_strdup.o	mandatory/ft_strlen.o	mandatory/ft_substr.o	mandatory/ft_super_split.o	mandatory/get_envp_paths.o	\
		mandatory/pipe_func2.o	mandatory/pipe_func.o	mandatory/pipex.o	mandatory/pipex_run_commands.o	mandatory/process_command.o	\
		mandatory/read_from_std_input.o	mandatory/read_input_file.o	mandatory/read_result_from_pipe.o	mandatory/rederect_fd_to_pipe.o

OBJS_CS_LIST =  mandatory/cs_list/cs_list_add.o	mandatory/cs_list/cs_list_new.o	mandatory/cs_list/cs_list_resize.o	mandatory/cs_list/ft_memcpy.o
OBJS_GC = mandatory/garbage_collector/ft_calloc.o	mandatory/garbage_collector/ft_exit.o	mandatory/garbage_collector/ft_free.o	\
		mandatory/garbage_collector/ft_save_mem.o	mandatory/garbage_collector/mem_list.o

OBJS_CS_LIST_bonus = bonus/cs_list_bonus/cs_list_add_bonus.o	bonus/cs_list_bonus/cs_list_new_bonus.o	bonus/cs_list_bonus/cs_list_resize_bonus.o	\
					bonus/cs_list_bonus/ft_memcpy_bonus.o
OBJS_GC_bonus = bonus/garbage_collector_bonus/ft_calloc_bonus.o	bonus/garbage_collector_bonus/ft_exit_bonus.o	bonus/garbage_collector_bonus/ft_free_bonus.o	\
				bonus/garbage_collector_bonus/ft_save_mem_bonus.o	bonus/garbage_collector_bonus/mem_list_bonus.o
OBJS_bonus  = bonus/pipex_run_commands_bonus.o	bonus/ft_error_bonus.o	bonus/ft_strchr_bonus.o	bonus/ft_super_split_bonus.o	\
			bonus/check_input_output_files_bonus.o	bonus/exec_cmd2_bonus.o	bonus/exec_cmd_bonus.o	bonus/ft_open_bonus.o	bonus/ft_putstr_fd_bonus.o	\
			bonus/ft_read_bonus.o	bonus/ft_std_input_ouput_bonus.o	bonus/ft_strdup_bonus.o	bonus/ft_strlen_bonus.o	bonus/ft_substr_bonus.o	\
			bonus/get_envp_paths_bonus.o	bonus/pipe_func2_bonus.o	bonus/pipe_func_bonus.o	bonus/pipex_bonus.o	bonus/process_command_bonus.o	\
			bonus/read_from_std_input_bonus.o	bonus/read_input_file_bonus.o	bonus/read_result_from_pipe_bonus.o	bonus/rederect_fd_to_pipe_bonus.o

FLAGS = -Wall -Wextra -Werror

CC = cc $(FLAGS)

NAME = pipex

all: $(NAME)

$(NAME): $(OBJS) $(OBJS_CS_LIST) $(OBJS_GC)
	$(CC) $(OBJS) $(OBJS_CS_LIST) $(OBJS_GC) -o $(NAME)

bonus: $(OBJS_bonus) $(OBJS_CS_LIST_bonus) $(OBJS_GC_bonus)
	$(CC) $(OBJS_bonus) $(OBJS_CS_LIST_bonus) $(OBJS_GC_bonus) -o $(NAME)

clean:
	rm -f $(OBJS) $(OBJS_CS_LIST) $(OBJS_GC) $(OBJS_bonus) $(OBJS_CS_LIST_bonus) $(OBJS_GC_bonus)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re bonus
