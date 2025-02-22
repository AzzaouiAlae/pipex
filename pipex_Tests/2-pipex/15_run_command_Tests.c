#include "../Tests.h"

void run_command_simple_test1()
{
    //void run_command(char *cmd_path, char **args)
    //create cmd and args
    //create pipe
    //write input in pipe
    //rederect inpute output fd
    //crete new process with fork
    //run command with the new process
    //wait process in the parent process
    //read result from fd
    //assert result

    //arrange  
    t_cs_list *str = cs_list_new(sizeof(char));   
    char *cmd_path = "/usr/bin/grep";
    char *args[] = {"grep", "b", 0};
    char *input = "afs\nboot\ndev\nhome\nlib64\nmnt\nproc\nrun\nsrv\ntmp\nvar\nbin\ndata\netc\nlib\nmedia\nopt\nroot\nsbin\nsys\nusr";
    char *reslut = "boot\nlib64\nbin\nlib\nsbin\n";
    t_pipe *p  = create_pipe();    
    add_pipe(p);
    ft_putstr_fd(input, p->fd_write);
    close(p->fd_write);
    save_std_input();
    save_std_output();
    rederect_fd_to_pipe();
    pid_t pid = fork();
    int n = 1;
    char ch;

    //act
    if(!pid)    
        run_command(cmd_path, args);    
    else
    {
        waitpid(pid, 0, 0);
        p = next_pipe();
        close(p->fd_write);
        rederect_fd_to_pipe();
        while(n)
        {
            n = read(0, &ch, 1);
            if(n)
                cs_list_add(str, (long)ch);
        }   
    }
    dup2(std_input(-1), 0);
    dup2(std_output(-1), 1);

    //asert
    TEST_ASSERT_CHAR_ARRAY_WITHIN(0, reslut, str->contate, 25);
}

void run_command_Tests()
{
    RUN_TEST(run_command_simple_test1);
}
