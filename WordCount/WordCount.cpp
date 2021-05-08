// WordCount.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include<string.h>
int main(int argc, char* argv[])
{

    /*
        printf("main函数收到了%d个参数\n",argc);//第一个参数默认是可执行文件本身，第二个参数开始是接受到的参数
        int i;
        for( i = 0; i < argc; i++ ){
            printf("%s ",argv[i]);
        }
        printf("\n");
    */

    if (argc == 3) {

        //打印接受到的参数
        /*
            int i;
            printf("收到的外部参数：");
            for( i = 1; i < argc; i++ ){
                printf("%s ",argv[i]);
            }
            printf("\n");
        */

        //尝试读取文件的内容
        char data;
        FILE* fp = fopen(argv[2], "r");

        if (!fp) {
            printf("错误：文件读取失败\n");
            return -1;
        }

        //对参数进行判断


        if (!strcmp(argv[1], "-c")) {//字符数
            char temp;
            int num = 0;
            temp = fgetc(fp);
            while (temp != EOF) {
                //putchar(temp);
                temp = fgetc(fp);
                num++;
            }
            printf("该文本文件的字符数为：%d\n", num);

        }
        else if (!strcmp(argv[1], "-w")) {//单词数
            int w = 0;
            char a = fgetc(fp);
            while (a != EOF) {
                if ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z') || (a >= '0' && a <= '9')) {
                    while ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z') || (a >= '0' && a <= '9'))
                        a = fgetc(fp);
                    w++;
                    a = fgetc(fp);

                }
                else
                    a = fgetc(fp);
            }
            printf("该文本文件的单词数为：%d\n", w);

        }
        else if (!strcmp(argv[1], "-l")) {//行数
            char temp;
            int num = 1;
            temp = fgetc(fp);
            while (temp != EOF) {

                //putchar(temp);
                if (temp == '\n') {//字符需要用单引号扩住
                    num++;
                }
                temp = fgetc(fp);


            }
            printf("该文本文件的行数为：%d\n", num);

        }
        else {
            printf("错误：参数超出范围！\n");
            printf("允许参数：-c，-w，-l\n");
        }
        int n = fclose(fp);
    }
    else {
        printf("错误：运行参数必须要3个\n");
        printf("用法：wc.exe [parameter] [file_name]\n");
    }
    system("pause");
    return 0;
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
