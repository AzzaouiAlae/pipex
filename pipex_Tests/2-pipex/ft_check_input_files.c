#include "../Tests.h"

void ft_check_input_files_simple_test1()
{
    //arrange
    char *arg[] = {"", "", "", "file.txt"};
    int fd;
    char str2[15];
    int i = 0;
    is_pass_exit(0);

    //act
    fd = check_input_output_files(4, arg);
    if(fd != -1)
    {
        i = read(fd, str2, 15);
        str2[i] = '\0';
    }    
    
    //asert
    //TEST_ASSERT_EQUAL_CHAR_ARRAY("this is a file", str2, 15);
    TEST_ASSERT_EQUAL_INT64(1, is_pass_exit(-10));
}
void ft_check_input_files_simple_test2()
{
    //arrange
    char *arg[] = {"", "file0.txt", "", "file1.txt"};
    int fd;
    char str2[15];
    int i = 0;

    //act
    fd = check_input_output_files(4, arg);
    if(fd != -1)
        i = read(fd, str2, 15);
    str2[i] = '\0';
    
    //asert
    TEST_ASSERT_EQUAL_INT64(0, i);
}
void ft_check_input_files_simple_test3()
{
    //arrange
    char *arg[] = {"", "here_doc", "", "file2.txt"};
    int fd;
    char str2[15];
    int i = 0;

    //act
    fd = check_input_output_files(4, arg);
    
    if(fd != -1)
        i = read(fd, str2, 15);
    str2[i] = '\0';
    
    //asert
    TEST_ASSERT_EQUAL_CHAR_ARRAY("this is a file", str2, 15);
}
void ft_check_input_files()
{
    RUN_TEST(ft_check_input_files_simple_test1);
    RUN_TEST(ft_check_input_files_simple_test2);
    RUN_TEST(ft_check_input_files_simple_test3);
}
