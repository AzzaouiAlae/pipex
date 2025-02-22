#include "../Tests.h"

void cls_list_new_simple_test1()
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

void cls_list_new_simple_test2()
{
    //arrange
    t_cs_list *list = cs_list_new(sizeof(int));
    int *r = ft_calloc(11, sizeof(int));
    r[0] = 10;
    r[1] = 15;
    r[2] = 20;
    r[3] = 25;
    r[4] = 30;
    r[5] = 35;
    r[6] = 40;
    r[7] = 45;
    r[8] = 50;
    r[9] = 55;
    r[10] = 60;

    //act
    for(int j = 10, k = 0; k < 10; k++, j+=5)
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

void cls_list_new_simple_test3()
{
    //arrange
    t_cs_list *list = cs_list_new_capacity(sizeof(int), 12);
    int *r = ft_calloc(11, sizeof(int));
    r[0] = 10;
    r[1] = 15;
    r[2] = 20;
    r[3] = 25;
    r[4] = 30;
    r[5] = 35;
    r[6] = 40;
    r[7] = 45;
    r[8] = 50;
    r[9] = 55;
    r[10] = 60;

    //act
    for(int j = 10, k = 0; k < 10; k++, j+=5)
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

void cls_list_new_Tests()
{
    RUN_TEST(cls_list_new_simple_test1);   
    RUN_TEST(cls_list_new_simple_test2);  
    RUN_TEST(cls_list_new_simple_test3); 
}
