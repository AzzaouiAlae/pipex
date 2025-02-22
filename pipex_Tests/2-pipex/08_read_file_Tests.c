#include "../Tests.h"

void read_file_simple_test1()
{
    //arrange    
    char *fileName = "file333.txt";
    char *exp = "this is a file5555";

    //act
    char *result = read_file(fileName);

    //asert   
    TEST_ASSERT_CHAR_ARRAY_WITHIN(0, exp, result, 19);
}

void read_file_simple_test2()
{
    //arrange    
    char *fileName = "file33.txt";
    char *exp = "this is a file5555";

    //act
    char *result = read_file(fileName);

    //asert
    TEST_ASSERT_EQUAL_INT64(0, result);
}

void read_file_Tests()
{
    RUN_TEST(read_file_simple_test1);
    RUN_TEST(read_file_simple_test2);
}
