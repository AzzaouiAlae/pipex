#include "../Tests.h"

void cs_list_add_simple_test1()
{
    //arrange
    t_cs_list *list = cs_list_new(sizeof(int));
    int *r = ft_calloc(4, sizeof(int));
    r[0] = 10;
    r[1] = 15;
    r[2] = 20;
    r[3] = 25;

    //act
    for(int j = 10, k = 0; k < 4; k++, j+=5)
    {
        if( k == 3)
            k = 3;
        cs_list_add(list, j);
    }
        
    //asert
    for(int l = 0; l < list->count; l++)
    {
        if(r[l] != ((int *)(list->contate))[l])
            TEST_FAIL();
    }
}
void cs_list_add_simple_test2()
{
    //arrange
    t_cs_list *list = cs_list_new(sizeof(int));
    int *r = ft_calloc(4, sizeof(int));
    r[0] = 10;
    r[1] = 15;
    r[2] = 20;
    r[3] = 25;

    //act    
    cs_list_add_items(list, 4, r[0], r[1], r[2], r[3]);
        
    //asert
    for(int l = 0; l < list->count; l++)
    {
        if(r[l] != ((int *)(list->contate))[l])
            TEST_FAIL();
    }
}
void cs_list_add_simple_test3()
{
    //arrange
    t_cs_list *list = cs_list_new(sizeof(int));
    int *r = ft_calloc(4, sizeof(int));
    r[0] = 10;
    r[1] = 15;
    r[2] = 20;
    r[3] = 25;

    //act    
    cs_list_add_range(list, 4, r);
        
    //asert
    for(int l = 0; l < list->count; l++)
    {
        if(r[l] != ((int *)(list->contate))[l])
            TEST_FAIL();
    }
}
void cs_list_add_simple_test4()
{
    //arrange
    t_cs_list *list = cs_list_new(sizeof(int));
    int *r = ft_calloc(4, sizeof(int));
    r[0] = 10;
    r[1] = 15;
    r[2] = 20;
    r[3] = 25;

    //act    
    cs_list_add_ranges_count_arr(list, 1, 4, r);
        
    //asert
    for(int l = 0, k = 0; l < list->count; l++, k++)
    {
        if(r[k] != ((int *)(list->contate))[l])
            TEST_FAIL();
        if(k == 3)
            k = -1;
    }
}
void cs_list_add_Tests()
{
    RUN_TEST(cs_list_add_simple_test1);
    RUN_TEST(cs_list_add_simple_test2);
    RUN_TEST(cs_list_add_simple_test3);
    RUN_TEST(cs_list_add_simple_test4);
}
