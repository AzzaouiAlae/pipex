#include "../Tests.h"

void str_end_with_simple_test1()
{
    //arrange
    int result;

    //act
    result = str_end_with(NULL, NULL);

    //asert
    TEST_ASSERT_EQUAL_INT64(0, result);
}

void str_end_with_simple_test2()
{
    //arrange
    int result;
    t_cs_list *str = cs_list_new(sizeof(char));
    t_cs_list *to_find = cs_list_new(sizeof(char));
    cs_list_add_range(str, 27, "hello this is the test num2");
    cs_list_add_range(to_find, 4, "num2");    

    //act
    result = str_end_with(str, to_find);

    //asert
    TEST_ASSERT_EQUAL_INT64(1, result);
}

void str_end_with_simple_test3()
{
    //arrange
    int result;
    t_cs_list *str = cs_list_new(sizeof(char));
    t_cs_list *to_find = cs_list_new(sizeof(char));
    cs_list_add_range(str, 27, "hello this is the test num2");
    cs_list_add_range(to_find, 4, "num");    

    //act
    result = str_end_with(str, to_find);

    //asert
    TEST_ASSERT_EQUAL_INT64(0, result);
}

void str_end_with_Tests()
{
    RUN_TEST(str_end_with_simple_test1);
    RUN_TEST(str_end_with_simple_test2);
    RUN_TEST(str_end_with_simple_test3);
}
