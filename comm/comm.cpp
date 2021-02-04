// comm.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "stdio.h"
#pragma warning(disable:4996)

typedef struct
{
    unsigned int user_id;
    char file_dir[64];
    int comm_filg;

}user;





int chack_str(char *a,const char *b)
{
    while (*a != '\0')
    {
        if (*a != *b)
        {
            return 0;
        }
        a++;
        b++;
    }
    if (*b != '\0')
    {
        return 0;
    }
    else
    {
        return 1;
    }

}



int com_cut(char *com,char *com_a,char *com_b)
{
    char flag = 0;
    char* backup;
    backup = com_a;
    while (*backup != '\0')
    {
        *backup = '\0';
        backup++;
    }
    backup = com_b;
    while (*backup != '\0')
    {
        *backup = '\0';
        backup++;
    }
    while (*com != '0')
    {
        if (*com == ' '&&flag==0)
        {
            flag = 1;
            com++;
        }
        else
        {
            if (flag == 0)
            {
                *com_a = *com;
                com_a++;
                *com_a = '\0';
            }
            else
            {
                *com_b = *com;
                com_b++;
                *com_b = '\0';
            }
        }

        com++;
    }
}

const char fast[2][8] =
{
    "setting",
    "display"
};


int main()
{
    user i;

    sprintf(i.file_dir,"/");//初始化用户根目录

    char com[128];
    char com_a[28];
    char com_b[100];

    while (1)
    {
        printf("%s ", i.file_dir);

        scanf("%s", com);
        //printf("%s",com);
        if (chack_str(com, "exit"))
        {
            exit(0);
        }
        if (chack_str(com, "help"))
        {

        }
        com_cut(com,com_a,com_b);
        printf("%s\n%s\n%s\n",com,com_a,com_b);

        
    }

}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
