#include "../Tests.h"

void get_cmd_path_simple_test1()
{
    //arrange
    char *paths[] = {"/home/aazzaoui/.local/bin", "/home/aazzaoui/bin", "/usr/share/Modules/bin", "/usr/local/bin", "/usr/local/sbin", "/usr/bin", "/usr/sbin", "/home/aazzaoui/.dotnet/tools"};
    char *e_paths = "/usr/bin/ls";
    char *r_paths;

    //act
    r_paths = get_cmd_path(paths, "ls");

    //asert  
    if(!r_paths)
            TEST_FAIL();    
    TEST_ASSERT_CHAR_ARRAY_WITHIN(0, e_paths, r_paths, ft_strlen(e_paths) + 1);    
}

void get_cmd_path_Tests()
{
    RUN_TEST(get_cmd_path_simple_test1);
}