#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <string>
#include <cstring>
//�û�����
using namespace std;

string UserName[8] = {"user1", "user2", "user3", "user4",
                      "user5", "user6", "user7", "user8"};

string Password[8] = {"12345", "12345", "12345", "12345",
                      "12345", "12345", "12345", "12345"};

int login_userid = -1; //Ŀǰ��½�û����
int filearray[8] = {-1,-1,-1,-1,-1,-1,-1,-1};
int file_array_head;
int physic[100];                 //�ļ���ַ������     ?�Ҿ�������ط����Ըĸ�
int style = 1;                   //�ļ�����  ?�Ҿ�������ط����Ըĸ�
char cur_dir[11] = "filesystem"; //��ǰĿ¼

//�����ָ��
struct command
{
    char com[10];
} cmd[17];

//�ļ��� 1��1KB
struct block
{
    int number;         //��ſ����̿�ĸ���
    int free[50];       //��ſ����̿�ĵ�ַ
    int is_use;         //������Ƿ�ռ�ñ�־
    char content[1000]; //����ÿ��ÿ���ֽڴ�ŵķ���
} memory[20449];

//������
struct block_super
{
    int n;               //�����̿�ĸ���
    int free[50];        //��Ž���ջ�еĿ��п�
    //int empty_block[50]; //�����һ������̿�ĵ�ַ
} super_block;

//i�����Ϣ
struct node
{
    int file_style;
    int file_length;
    int file_address[100];
    int limit; //0��ʾ�ܴ򿪶�д��1��ʾ�ܴ򿪶���2��ʾ�ܴ�д��3��ʾֻ�ܴ�
    int file_UserId;
} i_node[640];

//Ŀ¼
struct dir
{
    char file_name[10];
    int i_numl; //�ļ�i�����
    char dir_name[10];
} root[640];
