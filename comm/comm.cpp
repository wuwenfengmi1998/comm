// comm.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "stdio.h"
#pragma warning(disable:4996)

typedef struct
{
    unsigned int user_id;
    char file_dir[256];   //如果打开了文件或者路径 保存在这里
    char R_buff[128];     //用户占用一个接受器并且有接受缓存
    char com[64];         //分离出来的命令

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


//通过空格分离第一个命令  返回1分离成功 
int com_cut(char *r_buff,char *com)
{
    int i=0;
    if (*r_buff == ' ')
    {
        printf("error1\n");
        return 0;
        
    }

    while (*r_buff!=' ')
    {
        if (*r_buff == '\0')
        {
            printf("error2\n");
            return 0;
        }
        *com = *r_buff;
        com++;
        r_buff++;
        i++;
    }
    *com = '\0';

    return 1;
}

const char fast[2][8] =
{
    "setting",
    "display"
};


void GetString(char* p, int p_len)
{
    char c;
    int i = 0;
    while ((c = getchar()) != '\n') {
        if (i < p_len) {
            p[i] = c;
            i++;
        }
        else {
            break;
        }
    }
    p[i] = '\0';
}

int main()
{
    user i;

    sprintf(i.file_dir,"/");//初始化用户根目录

    


    while (1)
    {
        printf("%s ", i.file_dir);

        GetString(i.R_buff,128);
        if (chack_str(i.R_buff, "exit"))
        {
            exit(0);
        }
        if (chack_str(i.R_buff, "help"))
        {

        }
        if (com_cut(i.R_buff, i.com))
        {
            printf("%s\n%s\n", i.R_buff, i.com);
        }
       

        
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
