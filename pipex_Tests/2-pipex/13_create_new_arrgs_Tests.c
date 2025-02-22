#include "../Tests.h"

void create_new_arrgs_simple_test1()
{
    //arrange
    //void create_new_arrgs(char *cmd_path, char **args, char **cmd_path_, char ***args_)
    char *cmd_path,  *cmd_path_, **args_;
    //create string and array of string and pass to create_new_arrgs(cmd_path, args, &cmd_path_, &args_)
    cmd_path = "this is a test";
    char *args[] = {"test1","test2", "test3","test4", 0};   


    //act 
    create_new_arrgs(cmd_path, args, &cmd_path_, &args_);

    //asert
    if(!cmd_path_ || !args_)
        TEST_FAIL();
    for(int i = 0; args[i]; i++)
    {
        TEST_ASSERT_CHAR_ARRAY_WITHIN(0, args[i], args_[i], ft_strlen(args[i]));
        free(args_[i]);
    }
    free(args_);
    TEST_ASSERT_CHAR_ARRAY_WITHIN(0, cmd_path, cmd_path_, ft_strlen(cmd_path));
    free(cmd_path_);

}

void create_new_arrgs_Tests()
{
    RUN_TEST(create_new_arrgs_simple_test1);
}
