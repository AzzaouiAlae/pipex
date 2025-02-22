#include "../Tests.h"

void check_input_output_files_simple_test1()
{
    //arrange
    int argc = 6;
    char *argv[] = {"", "here_doc", "", "", "", "file1.txt"};
    char str[21];
    char *exp = "Hello this is a test";

    //act
    int fd = check_input_output_files(argc, argv);
    write(fd, "Hello this is a test", 20);
    close(fd);
    fd = open("file1.txt", O_RDWR, 0666);
    read(fd, str, 20);
    str[20] = '\0';
    open("file1.txt", O_TRUNC, 0666);

    //asert
    TEST_ASSERT_CHAR_ARRAY_WITHIN(0, exp, str, 21);
}
void check_input_output_files_simple_test2()
{
    //arrange
    int argc = 6;
    char *argv[] = {"", "fil.txt", "", "", "", "file1.txt"};
    char str[21];
    is_pass_exit(0);

    //act
    int fd = check_input_output_files(argc, argv);

    //asert
    TEST_ASSERT_EQUAL_INT64(-1, fd);
    TEST_ASSERT_EQUAL_INT64(1, is_pass_exit(-10));    
}
void check_input_output_files_simple_test3()
{
    //arrange
    int argc = 6;
    char *argv[] = {"", "file0.txt", "", "", "", "file1.txt"};
    char str[21];
    char *exp = "Hello this is a test";

    //act
    int fd = check_input_output_files(argc, argv);
    write(fd, "Hello this is a test", 20);
    close(fd);
    fd = open("file1.txt", O_RDWR, 0666);
    read(fd, str, 20);
    str[20] = '\0';
    open("file1.txt", O_TRUNC, 0666);

    //asert
    TEST_ASSERT_CHAR_ARRAY_WITHIN(0, exp, str, 21);
}
void check_input_output_files_simple_test4()
{
    //arrange
    int argc = 6;
    char str[21];
    is_pass_exit(0);

    //act
    int fd = check_input_output_files(argc, NULL);

    //asert
    TEST_ASSERT_EQUAL_INT64(-1, fd);
    TEST_ASSERT_EQUAL_INT64(1, is_pass_exit(-10));    
}
void check_input_output_files_Tests()
{
    RUN_TEST(check_input_output_files_simple_test1);
    RUN_TEST(check_input_output_files_simple_test2);
    RUN_TEST(check_input_output_files_simple_test3);
    RUN_TEST(check_input_output_files_simple_test4);
}
