#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1000 // 定义最大行长度

int main(int argc, char *argv[]) {
    char *filename; // 文件名
    char *parameter; // 参数
    char line[MAX_LEN]; // 存储每行文本的字符数组
    int count = 0; // 统计字符数或单词数的变量
    int is_word = 0; // 标记是否在单词中

    // 解析命令行参数
    if (argc == 3) {
        parameter = argv[1];
        filename = argv[2];
    } else if (argc == 2) {
        parameter = argv[1];
        filename = "input.txt"; // 默认文件名
    } else {
        printf("Usage: %s -c/-w [filename]\n", argv[0]);
        return 1;
    }

    // 打开文件
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: cannot open file %s\n", filename);
        return 1;
    }

    // 逐行读取文件内容
    while (fgets(line, MAX_LEN, fp) != NULL) {
        int len = strlen(line);
        for (int i = 0; i < len; i++) {
            if (parameter[1] == 'c') {
                count++; // 统计字符数
            } else if (parameter[1] == 'w') {
                if (line[i] == ' ' || line[i] == ',' || line[i] == '\t' || line[i] == '\n') {
                    is_word = 0; // 标记单词结束
                } else if (is_word == 0) {
                    is_word = 1; // 标记单词开始
                    count++; // 统计单词数
                }
            }
        }
    }

    // 关闭文件
    fclose(fp);

    // 输出结果
    if (parameter[1] == 'c') {
        printf("字符数：%d\n", count);
    } else if (parameter[1] == 'w') {
        printf("单词数：%d\n", count);
    }

    return 0;
}
