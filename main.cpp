#include "File.h"

//��ʽ��
/*
void format()
{
    int i, j, k;

    super_block.n = 50;

    for (i = 0; i < 50; i++) //�������ʼ��
    {
        super_block.free[i] = i; //��Ž���ջ�еĿ��п�
        //super_block.stack[i]=50+i; //�����һ����̿�
    }

    for (i = 0; i < 640; i++) //i�����Ϣ��ʼ��
    {
        for (j = 0; j < 100; j++) {
            i_node[i].file_address[j] = -1; //�ļ���ַ
        }

        i_node[i].limit = -1;
        i_node[i].file_length = -1; //�ļ�����
        i_node[i].file_style = -1; //�ļ�����
        i_node[i].file_UserId = -1; //�û�ID
    }

    for (i = 0; i < 640; i++) //Ŀ¼����Ϣ��ʼ��
    {
        strcpy(root[i].file_name, "");
        root[i].i_numl = -1;
        strcpy(root[i].dir_name, "");
    }

    for (i = 0; i < 20449; i++) //�洢�ռ��ʼ��
    {
        memory[i].number = 0; //���������
        memory[i].is_use = 0;
        for (j = 0; j < 50; j++) {
            memory[i].free[j] = -1;
        }
        for (int c = 0; c < 1000; c++) {
            memory[i].content[c] = '\0';
        }
    }

    for (i = 0; i < 20449; i++) //�����п����Ϣ�ó������ӵķ���д��ÿ������һ������
    {
        //�洢�ռ��ʼ��
        if ((i + 1) % 50 == 0) {
            k = i + 1;
            for (j = 0; j < 50; j++) {
                if (k < 20450) {
                    memory[i].free[j] = k; //��һ����е�ַ
                    memory[i].number++; //��һ����и��� ע����memory[i].n++֮ǰҪ���丳��ֵ
                    k++;
                } else {
                    memory[i].free[j] = -1;
                }
            }

            memory[i].is_use = 0; //���Ϊû��ʹ��
            continue; //���������ڴ洢��һ���̿���Ϣ�������̿����������ѭ��
        }

        for (j = 0; j < 50; j++) {
            memory[i].free[j] = -1;
        }

        memory[i].number = 0;
    }

    for (int l = 0; l < 8; l++) {

        filearray[l] = -1;
    }

    file_array_head = 0;

    for (int u = 0; u < 100; u++) {

        physic[u] = -1;
    }

    printf("�Ѿ���ʼ�����\n");

    printf("����UNIX�ļ�ģ��............\n\n");
}
*/
void format() {
    int i, j, k;
    super_block.n = 50;
    for (i = 0; i < 50; i++) {
        super_block.free[i] = i;
        //super_block.empty_block[i] = 50 + i;//�����һ����̿�
    }
    for (i = 0; i < 640; i++) {
        for (j = 0; j < 100; j++) {
            i_node[i].file_address[j] = -1;
        }
        i_node[i].limit = -1;
        i_node[i].file_style = -1;
        i_node[i].file_UserId = -1;
    }
    for (i = 0; i < 640; i++) {
        strcpy(root[i].file_name, "");
        root[i].i_numl = -1;
        strcpy(root[i].dir_name, "");
    }
    for (i = 0; i < 20449; i++) {
        memory[i].number = 0;
        memory[i].is_use = 0;
        for (j = 0; j < 50; j++)
            memory[i].free[j] = -1;
        for (int c = 0; c < 1000; c++)
            memory[i].content[c] = '\0';
    }
    for (i = 0; i < 20449; i++) {
        if ((i + 1) % 50 == 0) {  //�������ӷ��������ʼ��
            k = i + 1;
            for (j = 0; j < 50; j++) {
                if (k < 20450) {
                    memory[i].free[j] = k;
                    memory[i].number++;
                    k++;
                }
                else {
                    memory[i].free[j] = -1;
                }
            }
            memory[i].is_use = 0;
            continue;
        }
        for (j = 0; j < 50; j++) {
            memory[i].free[j] = -1;
        }
        memory[i].number = 0;
    }
    extern int filearray[8];
    for (int l = 0; l < 8; l++) {
        filearray[l] = -1;
    }
    extern int file_array_head;
    file_array_head = 0;
    extern int physic[100];
    for (int u = 0; u < 100; u++)
        physic[u] = -1;
    cout << "��ʼ�������" << endl;
    cout << "��ӭ�����ļ�ϵͳ" << endl << endl;
}
void callback(int length);

void allot(int length) //����ռ�

{

    int i, j, k, m, p;

    for (i = 0; i < length; i++) {

        k = 50 - super_block.n; //�������б�ʾ���п��ָ��

        m = super_block.free[k]; //ջ�е���Ӧ�̿�ĵ�ַ

        p = super_block.free[49]; //ջ�е����һ���̿�ָ��ĵ�ַ

        if (p == -1 /*||memory[p].a==1*/) //û��ʣ���̿�

        {

            printf("�ڴ治��,���ܹ�����ռ�\n");

            callback(i); //֮ǰ�ѷ����i���̿����;

            break;
        }

        if (super_block.n == 1) {

            memory[m].is_use = 1; //�����һ���̿�����

            physic[i] = m;

            super_block.free[49] = -1;

            super_block.n = 0;

            for (j = 50 - memory[m].number; j < 50; j++) //�����һ���̿���ȡ����һ���̿��д��ջ��

            {

                super_block.free[j] = memory[m].free[j];

                super_block.n++;
            }

            continue; //Ҫ�������ѭ��������������IF���Ѿ�ִ�й�
        }

        physic[i] = m; //���ջ�г���һ���̣�ջ�е���Ӧ�̿�ĵ�ַд�� �ļ���ַ������

        memory[m].is_use = 1;

        m = -1;

        super_block.n--;
    }
}

void callback(int length) //���մ��̿ռ�
{
    int i, j, k, m, q = 0;
    for (i = length - 1; i >= 0; i--) {
        k = physic[i];           //��Ҫ�ṩҪ���յ��ļ��ĵ�ַ
        m = 49 - super_block.n;  //���յ�ջ�е��ĸ�λ��
        if (super_block.n == 50) //ע�� ��super_block.n==50ʱ m=-1;��ֵ
        {                        //super_block.n==50��ʱ��ջ���ˣ�Ҫ�����ջ�е����е�ַ��Ϣд����һ����ַ��
            for (j = 0; j < 50; j++) {
                memory[k].free[j] = super_block.free[j];
            }
            int u;
            for (u = 0; u < 50; u++) {
                super_block.free[u] = -1;
                //super_block.stack[u]=memory[k].free[u];
            }
            super_block.n = 0;
            memory[k].number = 50;
        }
        memory[k].is_use = 0;
        if (m == -1) {
            m = 49; //����һ���ļ���ַ�е��̿�Ż��յ�ջ���У������ַ�д���Ÿղ���ջ�ĵ�ַ����Ϣ
        }
        super_block.free[m] = physic[i]; //����һ���ļ���ַ�е��̿�Ż��յ�ջ��
        super_block.n++;
    }
}

void create_file(char filename[], int length, int userid, int limit) //�����ļ�
{

    int i, j;

    for (i = 0; i < 640; i++) {
        if (strcmp(filename, root[i].file_name) == 0) {
            printf("�Ѿ�����ͬ���ļ������������������ļ�\n");
            return;
        }
    }

    for (i = 0; i < 640; i++) {
        if (root[i].i_numl == -1) {
            root[i].i_numl = i;
            strcpy(root[i].file_name, filename);
            strcpy(root[i].dir_name, cur_dir); //�ѵ�ǰĿ¼�� ���½������ļ�
            i_node[i].file_style = style; //style==0 ˵���ļ���Ŀ¼�ļ�
            i_node[i].file_length = length;
            i_node[i].limit = limit;
            i_node[i].file_UserId = userid; //printf("%s.%d\n",root[i].file_name,i_node[i].file_UserId);
            allot(length);

            for (j = 0; j < length; j++) {
                i_node[i].file_address[j] = physic[j];
            }

            int u;

            for (u = 0; u < 100; u++) //��������ջ�����
            {
                physic[u] = -1;
            }

            break;
        }
    }
}

void del_file(char filename[]) //ɾ���ļ�
{
    int i, j, k;

    for (i = 0; i < 640; i++) {
        if ((strcmp(filename, root[i].file_name) == 0) && (strcmp(cur_dir, root[i].dir_name) == 0) &&
            (i_node[root[i].i_numl].file_UserId == login_userid)) {
            //printf("1get here\n");
            int add, c;

            for (add = 0; add < i_node[root[i].i_numl].file_length; add++) //�ļ��������
            {
                for (c = 0; memory[i_node[root[i].i_numl].file_address[add]].content[c] != '\0'; c++) {
                    memory[i_node[root[i].i_numl].file_address[add]].content[c] = '\0';
                }
            }

            k = root[i].i_numl; //printf("2get here\n");
            i_node[k].file_UserId = -1;
            i_node[k].limit = -1;
            for (j = 0; j < i_node[k].file_length; j++) {
                physic[j] = i_node[k].file_address[j];
            } // printf("get here\n");

            callback(i_node[k].file_length); //���� ���պ���

            //��������ջ�����
            for (int u = 0; u < 100; u++) {
                physic[u] = -1;
            }

            for (j = 0; j < 100; j++) //ɾ���ļ���Ҫ���ļ����Ժ�Ŀ¼��ĸ���ֵ�ָ���ֵ
            {
                i_node[k].file_address[j] = -1; //�ļ�ռ�õĿ�ŵ�ַ�ָ���ֵ
            }

            strcpy(root[i].file_name, ""); //�ļ����ָ���ֵ
            root[i].i_numl = -1; //Ŀ¼���I�����Ϣ�ָ���ֵ
            strcpy(root[i].dir_name, ""); //Ŀ¼����ļ�Ŀ¼��Ϣ�ָ���ֵ
            i_node[k].file_length = -1; //�ļ����Ȼָ�
            i_node[k].file_style = -1; //�ļ����ͻָ���ֵ
            break;
        }
    }

    if (i == 640) {
        printf("��¼�û��ĸ�Ŀ¼�²���������ļ�\n");
    }
}

void display_sys() //��ʾϵͳ��Ϣ(����ʹ�����)
{
    int i, m, k = 0;
    for (i = 0; i < 20449; i++) {
        if (memory[i].is_use == 0)
            k++;
    }

    m = 20449 - k;
    printf("���е��̿�����:\t");
    printf("%d\n", k);
    printf("ʹ�õ��̿�����:\t");
    printf("%d\n", m);
}

void show_file(char filename[]) //��ʾ�ļ���Ϣ
{
    int i, j, k;
    printf("\t\t�ļ����� �ļ����� �ļ����� ��ȡȨ�� ����Ŀ¼\t�����û�\n");
    for (i = 0; i < 640; i++) {
        k = root[i].i_numl;
        if (strcmp(filename, root[i].file_name) == 0 && (i_node[k].file_style == 1)) {
            printf("\t\t %s\t", root[i].file_name); //�ļ���
            printf("\t%d\t", i_node[k].file_style); //�ļ�������
            printf("%d\t", i_node[k].file_length); //�ļ��ĳ���
            printf("%d\t", i_node[k].limit);
            printf("%s\t", root[i].dir_name); //�ļ����ڵ�Ŀ¼
            printf("user%d\n", i_node[root[i].i_numl].file_UserId);
            printf("\t\t�ļ�ռ�õ������ַ\n");
            for (j = 0; j < i_node[k].file_length; j++) //��ʾ�����ַ
            {
                printf("%d ", i_node[k].file_address[j]); //�ļ�����ռ�õ��̿��
            }
            printf("\n");

            break;
        }
    }

    if (i == 640) {
        printf("û������ļ� ��������ļ����������ļ�\n");
    }
}
//shhch

void write_file(FILE *fp) //����Ϣд��ϵͳ�ļ���
{
    int i;
    fp = fopen("system", "wb");
    for (i = 0; i < 20449; i++) {
        fwrite(&memory[i], sizeof(struct block), 1, fp);
    }

    fwrite(&super_block, sizeof(struct block_super), 1, fp);

    for (i = 0; i < 640; i++) {
        fwrite(&i_node[i], sizeof(struct node), 1, fp);
    }

    for (i = 0; i < 640; i++) {
        fwrite(&root[i], sizeof(struct dir), 1, fp);
    }

    fclose(fp);
}

void read_file(FILE *fp) //����ϵͳ�ļ�����Ϣ
{
    int i;

    fp = fopen("system", "rb");

    for (i = 0; i < 20449; i++) {
        fread(&memory[i], sizeof(struct block), 1, fp);
    }

    fread(&super_block, sizeof(struct block_super), 1, fp);

    for (i = 0; i < 640; i++) {
        fread(&i_node[i], sizeof(struct node), 1, fp);
    }

    for (i = 0; i < 640; i++) {
        fread(&root[i], sizeof(struct dir), 1, fp);
    }

    fclose(fp);
}

int login() {
    system("title �û���¼���� ");
    printf("\n\n �û���:");
    string tempusername;
    cin >> tempusername;
    //cout<<tempusername!!;

    int i;
    for (i = 0; i < 8; i++) {
        if (tempusername == UserName[i]) {
            printf(" ����:");
            string temppassword;
            cin >> temppassword;

            if (temppassword == Password[i]) {

                login_userid = i;

                printf("��¼�ɹ������Ե�\n");

                for (int a = 0; a < 4; a++) {

                    Sleep(500);

                    printf(".");
                }

                return 0;
            } else {

                system("cls");

                printf("�������\n����y:���µ�¼\n����n:�˳�ϵͳ\n");

                getchar();

                char c = getchar();

                getchar();

                if (c == 'y' || c == 'Y') {

                    system("cls");

                    login();

                    return 0;
                }

                if (c == 'n' || c == 'N')

                    exit(0);
            }
        }
    }

    if (i == 8) {
        system("cls");
        printf("û�д��û�\n����y:���µ�¼\n����n:�˳�ϵͳ\n");
        getchar();
        char c = getchar();
        getchar();
        if (c == 'y' || c == 'Y') {
            system("cls");
            //i=0;
            login();
            return 0;
        }
        if (c == 'n' || c == 'N')
            exit(0);
    }
    return 0;
}

void logout() /*�˳�*/

{

    printf(" \n Logouting");

    for (int a = 0; a < 4; a++) {

        Sleep(500);

        printf(".");
    }

    system("cls");
}

int open(char filename[10]) {

    int i;

    for (i = 0; i < 640; i++) {

        if (strcmp(root[i].file_name, filename) == 0 && i_node[root[i].i_numl].file_style == 1 &&
            i_node[root[i].i_numl].file_UserId == login_userid) {

            if (file_array_head < 8) {

                filearray[file_array_head] = root[i].i_numl;

                file_array_head++;
            } else {

                printf("�򿪵��ļ��Ѵ����ޣ��޷��򿪱��ļ�\n");
            }

            return root[i].i_numl;
        }
    }

    if (i == 640) {

        printf("��Ҫ�򿪵��ļ������ڻ����ڸ��û�\n");
    }

    return 0;
}

void close(char filename[10]) {

    int i;

    for (i = 0; i < 640; i++) {

        if (strcmp(root[i].file_name, filename) == 0 && i_node[root[i].i_numl].file_style == 1 &&

            i_node[root[i].i_numl].file_UserId == login_userid) {

            int j;

            for (j = 0; j < file_array_head; j++) {

                if (root[i].i_numl == filearray[j]) {

                    int m;

                    for (m = j; m < file_array_head; m++) {

                        filearray[m] = filearray[m + 1];
                    }

                    file_array_head--;

                    return;
                }
            }

            if (j == file_array_head) {

                printf("��Ҫ�رյ��ļ�δ�򿪹���\n");
            }

            return;
        }
    }

    if (i == 640) {

        printf("��Ҫ�رյ��ļ������ڻ����ڸ��û�\n");
    }

    return;
}

//ft

void create_dir(char filename[]) //����Ŀ¼

{

    style = 0; //0�����ļ�������Ŀ¼�ļ�

    create_file(filename, 4, login_userid, -1);

    style = 1; //����ָ���ֵ����Ϊȫ�ֱ���������
}

void del_dir(char filename[]) //ɾ��Ŀ¼ ��Ҫ�ж�Ŀ¼��ʱ��Ϊ��,��Ϊ�վͲ�ɾ��
{
    int i, j, k;
    for (i = 0; i < 640; i++) //��Ҫ�������ж�Ҫɾ����Ŀ¼�ǲ��ǵ�ǰĿ¼
    {
        k = root[i].i_numl; //�ҵ�Ŀ¼����
        if (strcmp(root[i].file_name, filename) == 0 && strcmp(cur_dir, filename) != 0 && (i_node[k].file_style) == 0) {
            for (j = 0; j < 640; j++) {
                if (strcmp(filename, root[j].dir_name) == 0) {
                    printf("Ŀ¼��Ϊ�ղ���ֱ��ɾ��\n");
                    break;
                }
            }
            if (j == 640 || i_node[root[i].i_numl].file_UserId == login_userid) {
                del_file(filename);
                break;
            }
            break;
        }
    }
    if (i == 640) {
        printf("�������Ŀ¼�ļ� �����ѵ�¼�û����������Ŀ¼,������Ҫɾ�����ǵ�ǰĿ¼\n");
    }
}

void display_curdir() //��ʾ��ǰĿ¼�µ��ļ��б�
{

    int i, k;

    cout << "�û���:" << UserName[login_userid] << endl;

    printf("\t\t�ļ����� �ļ����� �ļ����� ����Ŀ¼\n");

    for (i = 0; i < 640; i++) {

        if (strcmp(cur_dir, root[i].dir_name) == 0 && i_node[root[i].i_numl].file_UserId == login_userid)

            //��ѯ�ļ��� ����Ŀ¼��Ϣ�͵�ǰĿ¼��Ϣ��ͬ������

        {

            k = root[i].i_numl;

            printf("\t\t %s\t", root[i].file_name); //�ļ���

            printf("\t%d\t", i_node[k].file_style); //�ļ�������

            printf("%d\t", i_node[k].file_length); //�ļ��ĳ���

            printf("%s\n", root[i].dir_name); //�ļ����ڵ�Ŀ¼
        }
    }
}

void display_dir(char filename[]) //����ָ����Ŀ¼

{

    int i, k;

    for (i = 0; i < 640; i++) {

        k = root[i].i_numl;

        //printf("i_node[%d].file_UserId %d,login_userid %d",k,i_node[k].file_UserId,login_userid) ; //�ж��ļ������ǲ���Ŀ¼����

        if ((strcmp(filename, root[i].file_name) == 0) && (i_node[k].file_style == 0) &&

            (i_node[k].file_UserId == login_userid)) {
            //printf("yes\n");

            strcpy(cur_dir, filename); //printf("cur_dir= %s\n",cur_dir); //��Ҫ�����ָ��Ŀ¼����Ϊ��ǰĿ¼ ��ֵ��Ҫ����strcpy(Ŀ�ģ�Դ)

            return;
        }
    }

    if (i == 640) {

        printf("��¼�û�û�����Ŀ¼\n");
    }
}

void back_dir() //������һ��Ŀ¼

{

    int i, k;

    for (i = 0; i < 640; i++) //��ѯ�͵�ǰĿ¼����ͬ��Ŀ¼�ļ���

    {

        k = root[i].i_numl;

        if (strcmp(cur_dir, root[i].file_name) == 0 && (i_node[k].file_style == 0)) {

            strcpy(cur_dir, root[i].dir_name); //����ѯ����Ŀ¼�ļ��� ���ڵ�Ŀ¼��ֵ����ǰĿ¼
        }
    }
}

int read(char filename[10]) {

    int i;

    for (i = 0; i < 640; i++) {

        if (strcmp(root[i].file_name, filename) == 0 && i_node[root[i].i_numl].file_style == 1) {

            int j;

            for (j = 0; j < 8; j++) {
                //int n; for (n=0;n<8;n++) printf("%d\n",filearray[n]);

                if (root[i].i_numl == filearray[j]) {

                    if (i_node[root[i].i_numl].limit == 0 || i_node[root[i].i_numl].limit == 1) {

                        int c, add;

                        printf("\n �ļ�����:");

                        for (add = 0; add < 100; add++)

                            for (c = 0; memory[i_node[root[i].i_numl].file_address[add]].content[c] != '\0'; c++)

                                printf("%c", memory[i_node[root[i].i_numl].file_address[add]].content[c]);

                        printf("\n ");
                    } else {

                        printf("��û��Ȩ�޶�ȡ�ļ����ݡ���\n");
                    }

                    return 0;
                }
            }

            if (j == 8) {

                printf("\n ���ļ�δ�򿪣����ȴ��ļ��ٽ��ж�д����!!\n");
            }

            return 0;
        }
    }

    if (i == 640) {

        printf("��Ҫ��ȡ���ļ�������\n");
    }

    return 0;
}

void write(char filename[10], char writec) {

    int i;

    for (i = 0; i < 640; i++) {

        if (strcmp(root[i].file_name, filename) == 0 && i_node[root[i].i_numl].file_style == 1) {

            int j; //for(j=0;j<8;j++) printf("%d",filearray[j]);

            for (j = 0; j < 8; j++) {

                if (root[i].i_numl == filearray[j]) {

                    if (i_node[root[i].i_numl].limit == 0 || i_node[root[i].i_numl].limit == 2) {

                        int c, add;

                        for (add = 0; add < 100; add++) {

                            for (c = 0; c < 1000; c++) {
                                //memory[i_node[root[i].i_numl].file_address[add]].content[c]='b';printf("\ns %c %d %d",memory[i_node[root[i].i_numl].file_address[add]].content[c],c);

                                if (memory[i_node[root[i].i_numl].file_address[add]].content[c] == '\0') {

                                    //printf("\n%d %d\n",add,c);

                                    memory[i_node[root[i].i_numl].file_address[add]].content[c] = writec;

                                    // memory[i_node[root[i].i_numl].file_address[add]].content[c]='b';

                                    printf("\n %c ��д���ļ�ĩβ��\n",
                                           memory[i_node[root[i].i_numl].file_address[add]].content[c]);

                                    return;
                                }
                            }
                        }

                        if (add == 100) {

                            printf("\n�ļ��ռ�������д��ʧ�ܡ���\n");
                        }

                        return;
                    } else {

                        printf("��û��Ȩ�޽�����д���ļ�����\n");

                        return;
                    }

                    return;
                }
            }

            if (j == 8) {

                printf("\n ���ļ�δ�򿪣����ȴ��ļ��ٽ��ж�д����!!\n");
            }

            return;
        }
    }

    if (i == 640) {

        printf("��Ҫд����ļ�������\n");
    }
    return;
}

// ��ʾ������Ϣ
void help() {
    printf("�û���:user%d\n", login_userid);

    printf("ע��:�������ļ����� < 100\n\n"); //˵���ļ�

    printf("0.��ʼ��-------------------------format\n");

    printf("1.�鿴��ǰĿ¼�ļ��б�-----------dir\n");

    printf("2.�鿴�ļ���Ϣ-----------------------cat-----(cat + �ո� + �ļ���) \n");

    printf("3.�鿴ϵͳ��Ϣ-------------------ls \n");

    printf("4.����Ŀ¼-----------------------md------(md + �ո� + Ŀ¼��) \n");

    printf("5.�����ļ�-----------------------vi-----(vi + �ļ��� + �ļ����� + Ȩ��)\n");

    printf("6.ɾ���ļ�----------------------del-----(del + �ո� + �ļ���) \n");

    printf("7.���ļ�----------------------open----(open + �ո� + �ļ���) \n");

    printf("8.�ر��ļ�----------------------close---(close + �ո� + �ļ���) \n");

    printf("9.��ȡ�ļ�----------------------read----(read + �ո� + �ļ���) \n");

    printf("10.д���ļ�---------------------write--(write + �ո� + �ļ���+ �ո� + д���ַ�)\n");

    printf("11.ɾ��Ŀ¼----------------------deldir--(deldir + �ո� + Ŀ¼��)\n");

    printf("12.���뵱ǰĿ¼�µ�ָ��Ŀ¼-------cd--------(cd + �ո� + Ŀ¼��)\n");

    printf("13.������һ��Ŀ¼-----------------cd.. \n");

    printf("14.��ʾ��������-----------------help \n");

    printf("15.�˳��ļ�ϵͳ------------------quit \n");

    printf("16.�˳���¼-------------------logout \n");
}

int main() //������
{
    char tmp[10], com[10], tmp1[10];
    struct command tmp2[10];
    int i, j = 0, p, len = 0;
    FILE *fp;
    login();
    //printf("loginid %d\n",login_userid);
    help();
    strcpy(cmd[0].com, "format"); //�����������������
    strcpy(cmd[1].com, "dir");
    strcpy(cmd[2].com, "cat");
    strcpy(cmd[3].com, "ls");
    strcpy(cmd[4].com, "md");
    strcpy(cmd[5].com, "vi");
    strcpy(cmd[6].com, "del");
    strcpy(cmd[7].com, "deldir");
    strcpy(cmd[8].com, "cd");
    strcpy(cmd[9].com, "cd..");
    strcpy(cmd[10].com, "help");
    strcpy(cmd[11].com, "quit");
    strcpy(cmd[12].com, "open");
    strcpy(cmd[13].com, "read");
    strcpy(cmd[14].com, "write");
    strcpy(cmd[15].com, "logout");
    strcpy(cmd[16].com, "close");

    if ((fp = fopen("system", "rb")) == NULL) //�ж�ϵͳ�ļ��Ƿ����
    {
        printf("can not open file\n");
        printf("format the disk \n");
        Sleep(500);
        format();
    } else {
        read_file(fp); //��ȡϵͳ�ļ�������
    }

    while (1) {
        j = 0; //�������¸��ָ�0�������
        strcpy(tmp, cur_dir);

        while (strcmp(tmp, "filesystem") != 0) {

            for (i = 0; i < 640; i++) {

                p = root[i].i_numl;

                if (strcmp(tmp, root[i].file_name) == 0 && (i_node[p].file_style == 0)) {

                    strcpy(tmp2[j].com, tmp);

                    j++;

                    strcpy(tmp, root[i].dir_name);
                }
            }
        }

        strcpy(tmp2[j].com, tmp);

        for (i = j; i >= 0; i--) {

            printf("%s/", tmp2[i].com);
        }

        scanf("%s", com); //��������Ҳ����������ز���

        for (i = 0; i < 17; i++) {

            if (strcmp(com, cmd[i].com) == 0) {

                p = i;

                break;
            }
        }
        if (i == 17) //���û���������Ժ����������͵�һ�������Ч��һ��
        {
            p = -1; //����һ��ֵ
        }
        switch (p) {
            case 0:
                format(); //��ʼ��
                break;
            case 1:
                display_curdir(); //�鿴��ǰĿ¼�µ��ļ��б�
                break;
            case 2:
                scanf("%s", tmp); //�鿴�ļ�
                show_file(tmp);
                break;
            case 3:
                display_sys(); //�鿴ϵͳ��Ϣ
                break;
            case 4:
                scanf("%s", tmp); //����Ŀ¼
                create_dir(tmp);
                break;
            case 5:
                scanf("%s", tmp); //�����ļ�
                scanf("%d", &len);
                int limit;
                scanf("%d", &limit);
                create_file(tmp, len, login_userid, limit);
                break;
            case 6:
                scanf("%s", tmp); //ɾ���ļ�
                for (i = 0; i < 640; i++) //�ж��ļ��ǲ��������ļ�
                {
                    j = root[i].i_numl;
                    if (strcmp(tmp, root[i].file_name) == 0 && (i_node[j].file_style) == 1) {
                        del_file(tmp);
                        break;
                    }
                }
                if (i == 640) {
                    printf("������������ļ��ļ�\n");
                }
                break;
            case 7:
                scanf("%s", tmp); //ɾ��Ŀ¼
                del_dir(tmp);
                break;
            case 8:
                scanf("%s", tmp1); //���뵱ǰĿ¼�µ�ָ��Ŀ¼ �൱�ڽ���Ŀ¼ cd +Ŀ¼��
                display_dir(tmp1);
                break;
            case 9:
                back_dir(); //������һ��Ŀ¼
                break;
            case 10:
                help();
                break;
            case 11:
                write_file(fp); //������������Ϣд��ϵͳ�ļ����˳�
                return 0;
            case 12:
                scanf("%s", tmp);
                open(tmp);
                break;

            case 13:
                scanf("%s", tmp);
                read(tmp);
                break;
            case 14:
                scanf("%s", tmp);
                char writec;
                getchar();
                scanf("%c", &writec);
                getchar();
                // printf("tmp=%s writec=%c\n",tmp,writec);
                write(tmp, writec);
                // printf("retuern here?");
                break;
            case 15:
                write_file(fp);

                logout();
                int l;
                for (l = 0; l < 8; l++) {
                    filearray[l] = -1;
                }
                file_array_head = 0;
                login();
                help();
                break;
            case 16:
                scanf("%s", tmp);
                close(tmp);
                break;
            default:
                printf("SORRY,û���������\n");
                break;
        }
    }
    return 0;
}
