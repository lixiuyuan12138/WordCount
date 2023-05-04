#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1000 // ��������г���

int main(int argc, char *argv[]) {
    char *filename; // �ļ���
    char *parameter; // ����
    char line[MAX_LEN]; // �洢ÿ���ı����ַ�����
    int count = 0; // ͳ���ַ����򵥴����ı���
    int is_word = 0; // ����Ƿ��ڵ�����

    // ���������в���
    if (argc == 3) {
        parameter = argv[1];
        filename = argv[2];
    } else if (argc == 2) {
        parameter = argv[1];
        filename = "input.txt"; // Ĭ���ļ���
    } else {
        printf("Usage: %s -c/-w [filename]\n", argv[0]);
        return 1;
    }

    // ���ļ�
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: cannot open file %s\n", filename);
        return 1;
    }

    // ���ж�ȡ�ļ�����
    while (fgets(line, MAX_LEN, fp) != NULL) {
        int len = strlen(line);
        for (int i = 0; i < len; i++) {
            if (parameter[1] == 'c') {
                count++; // ͳ���ַ���
            } else if (parameter[1] == 'w') {
                if (line[i] == ' ' || line[i] == ',' || line[i] == '\t' || line[i] == '\n') {
                    is_word = 0; // ��ǵ��ʽ���
                } else if (is_word == 0) {
                    is_word = 1; // ��ǵ��ʿ�ʼ
                    count++; // ͳ�Ƶ�����
                }
            }
        }
    }

    // �ر��ļ�
    fclose(fp);

    // ������
    if (parameter[1] == 'c') {
        printf("�ַ�����%d\n", count);
    } else if (parameter[1] == 'w') {
        printf("��������%d\n", count);
    }

    return 0;
}
