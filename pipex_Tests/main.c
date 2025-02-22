#include "Tests.h"

void setUp(void)
{
  
}
void tearDown(void)
{
    
}
void fexit(int status)
{
    is_pass_exit(1);
}
int is_pass_exit(int i)
{
    static int is_pass = 0;
    if(i != -10) 
        is_pass = i;
    return is_pass;
} 
int	main(void)
{
    current_working_mem_tests();
    ft_mem_list_tests();
    ft_free_all_Tests();
    ft_open_test();
    ft_check_input_files();
    str_start_with_tests();
    find_str_start_with_tests();
    get_envp_paths_tests();
    all_pipes_tests();
    bzero_tests();
    ft_exit_Tests();
    ft_free_Tests();
    cls_list_new_Tests();
    cs_list_add_Tests();
    check_input_output_files_Tests();
    str_end_with_Tests();
    write_str_in_new_pipe_Tests();
    //read_from_std_input_Tests();
    read_file_Tests();
    read_input_file_Tests();
    create_cmd_args_Tests();
    get_cmd_path_Tests();
    rederect_fd_to_pipe_Tests();
    create_new_arrgs_Tests();
    error_running_cmd_Tests();
    run_command_Tests();


    ft_free_all();    
    return (UnityEnd());
}