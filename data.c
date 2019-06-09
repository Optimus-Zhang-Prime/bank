#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>

typedef struct user {//�û��ṹ�壬����Ľ��
    char userName[30];//����
    int id;//����
    long long int money;//���
    char userPwd[30];//����
    int flag;//���ڱ�ʶ�˻��Ƿ����
} User;

typedef struct Node {
    User data;//�û�����
    struct Node *next;//ָ��
} NODE;
NODE *ALL, *s, *end;//ALL���û���Ϣ��ͷָ��,sΪ����ָ�룬endָ��β�ڵ�


int last;//��Ϣ�ⳤ��

NODE *findUser(int ID) {//���ݿ����ҵ��û���Ϣ���
    NODE *s2;
    int i;
    if (ID > last) {
        printf("�ÿ�����δ����");
        return NULL;
    }
    s2 = ALL;//��ʼָ��ͷ�ڵ�
    for (i = 0; i <= ID; i++) {
        s2 = s2->next;
    }
    return s2;
}


int PwdLock(int inputID) {//������룬�����������δ��󶳽��˻�
    int i;//��������
    NODE *s4;//����ָ��
    char inputPwd[20];//���������
    s4 = findUser(inputID);
    if (s4 == NULL)return 0;
    for (i = 0; i < 3; i++) {//���δ����˻�
        printf("��������������");
        scanf("%s", inputPwd);
        if (strcmp(inputPwd, s4->data.userPwd) == 0) {//�Ƚ�������������ʵ
            return 1;//������ȷ�����ѭ��������1
        } else {
            printf("�������\n");
        }
    }
    printf("����������Σ����˻��ѱ�����\n");
    s4->data.flag = 0;//��־����0��ʾ����
    return 0;//������֤ʧ�ܷ���1
}

extern void startSystem() {//��ʼ��ϵͳ
    ALL = (NODE *) malloc(sizeof(NODE));
    last = -1;//ע�⣺˳���Ϊ��ʱlastΪ-1
    end = ALL;
}

extern void openAccount() {//����
    s = (NODE *) malloc(sizeof(NODE));
    end->next = s;//β�巨����
    end = s;

    last++;
    s->data.id = last;
    printf("��ӭ���뱾���У�����Ϊ������\n");
    printf("��������������:");
    scanf("%s", s->data.userName);
    printf("���������ĳ�ʼ����");
    scanf("%s", s->data.userPwd);
    printf("�����ɹ������Ŀ���Ϊ%d������Ϊ%s�������Ʊ���\n", last, s->data.userPwd);
    s->data.money = 0;//�������0
    s->data.flag = 1;//��ʾ�˻�����
    printf("��ǰ�������Ϊ0");
}

extern void withdraw() {//ȡ��
    int inputID;
    NODE *s3;
    long long int inputMoney;
    printf("����Ϊ��ȡ��\n");
    printf("���������Ŀ���:");
    scanf("%d", &inputID);
    s3 = findUser(inputID);
    if (s3 == NULL)return;
    if (s3->data.flag == 0) {
        printf("�ÿ����˻������ã����ڶ���״̬\n");
        return;
    }
    if (s3->data.flag == -1) {
        printf("�ÿ����˻��ѱ�����\n");
        return;
    }
    if (PwdLock(inputID)) {
        printf("��ǰ�������Ϊ%lld������������ȡ���", s3->data.money);
        scanf("%lld", &inputMoney);
        if (inputMoney > s3->data.money) {
            printf("���㣬ȡ��ʧ��");
        } else {
            s3->data.money -= inputMoney;
            printf("ȡ��%lldԪ�ɹ����������%lldԪ", inputMoney, s3->data.money);
        }
    }
}

extern void unLock() {//����������˻�
    int inputID;
    char inputName[20];
    NODE *s5;
    printf("����Ϊ�������˻�\n");
    printf("���������Ŀ���:");
    scanf("%d", &inputID);
    s5 = findUser(inputID);
    if (s5 == NULL)return;
    if (s5->data.flag == -1) {
        printf("�ÿ����˻��ѱ�����\n");
        return;
    }
    if (s5->data.flag != 0) {
        printf("�ÿ����˻����Ǵ��ڶ���״̬\n");
        return;
    } else {
        if (PwdLock(inputID)) {
            printf("������ֿ���������");
            scanf("%s", inputName);
            if (strcmp(inputName, s5->data.userName) == 0) {
                printf("�������ɹ���");
                s5->data.flag = 1;
            }
        }
    }
}

extern void deleAccount() {//����
    int inputID;
    char inputName[20];
    NODE *s6;
    printf("����Ϊ������\n");
    printf("���������Ŀ���:");
    scanf("%d", &inputID);
    s6 = findUser(inputID);
    if (s6 == NULL)return;
    if (s6->data.flag == -1) {
        printf("�ÿ����˻��ѱ�����\n");
        return;
    }
    if (s6->data.flag == 0) {
        printf("�ÿ����˻����ڶ���״̬\n");
        return;
    } else {
        if (PwdLock(inputID)) {
            printf("������ֿ���������");
            scanf("%s", inputName);
            if (strcmp(inputName, s6->data.userName) == 0) {
                printf("�����ɹ���ȡ�����%lldԪ", s6->data.money);
                s6->data.money = 0;
                s6->data.flag = -1;
            }
        }
    }
}

extern void help() {
    printf("��ӭ��������ϵͳ\n");
    printf("��ѡ����Ҫ���������ݣ�\n");
    printf("1.ҵ������     2.�˻�����    3.�˻�����   4.ȡ������\n");
    getchar();
    int order;
    scanf("%d", &order);
    if (order == 1) {
        printf("��������Ҫ��ͨһ���˻�\n");
        printf("���˻��д����ɽ���ȡ�ת�ʵ�ҵ��\n");
    } else if (order == 2) {
        printf("���������������δ����˻��ᱻ����\n");
        printf("������ʹ�á����������ָܻ��˻�ʹ��\n");
    } else if (order == 3) {
        printf("������ȡ���������\n");
        printf("��������˻����ɱ��ָ�\n");
    } else {
        return;
    }
    system("pause");
}

extern void askPwd() {
    int inputID;
    NODE *s3;
    long long int inputMoney;
    printf("����Ϊ��ѯ����\n");
    printf("�����뿨��:");
    scanf("%d", &inputID);
    s3 = findUser(inputID);
    if (s3 == NULL)return;
    if (s3->data.flag == -1) {
        printf("�ÿ����˻��ѱ�����\n");
        return;
    }
    printf("���˻�������Ϊ%s", s3->data.userPwd);

}

extern void deposit()//���
{
    NODE *p;
    int inputID;
    long long int inputMoney;
    printf("���ڽ�����ϵͳ\n");
    printf("���������Ŀ���:\n");
    scanf("%d", &inputID);
    p = findUser(inputID);  //finUser��ģ�黹û��
    if (p == NULL)
        return;
    if (p->data.flag == 0) {
        printf("���˻��ѱ�����\n");
        return;
    }
    if (p->data.flag == -1) {
        printf("���˻�������\n");
        return;
    }
    if (PwdLock(inputID)) {
        printf("���������");
        scanf("%lld", &inputMoney);
        p->data.money += inputMoney;
        printf("���%lldԪ�ɹ����������Ϊ%lldԪ", inputMoney, p->data.money);
    }
}

extern void transfer()//ת��
{
    NODE *p, *q;
    int torID, peeID;
    long long int inputMoney;
    printf("���ڽ���ת��ϵͳ\n");
    printf("���������Ŀ��ţ�");
    scanf("%d", &torID);
    p = findUser(torID);  //finUser��ģ�黹û��
    if (p == NULL)
        return;
    if (p->data.flag == 0) {
        printf("���˻��ѱ�����\n");
        return;
    }
    if (p->data.flag == -1) {
        printf("���˻�������\n");
        return;
    }
    if (PwdLock(torID)) {
        printf("��������Ҫת�˵��˻����ţ�\n");
        scanf("%d", &peeID);
        q = findUser(peeID);
        if (q == NULL) return;
        if (q->data.flag == 0) {
            printf("���˻��ѱ�����\n");
            return;
        }
        if (q->data.flag == -1) {
            printf("���˻�������\n");
            return;
        }

        printf("��ǰ���Ŀ������Ϊ%lld����������Ҫת�˵Ľ�\n", p->data.money);
        scanf("%lld", &inputMoney);
        if (inputMoney > p->data.money)
            printf("���㣬ת��ʧ��");
        else {
            p->data.money -= inputMoney;
            q->data.money += inputMoney;
            printf("ת�˳ɹ����������Ϊ%lldԪ", p->data.money);
        }
    }
}

extern void inquire()//�˻���ѯ
{
    int inputID;
    NODE *p;
    printf("��������Ҫ��ѯ�˻��Ŀ��ţ�\n");
    scanf("%d", &inputID);
    p = findUser(inputID);
    if (p == NULL)
        return;
    if (p->data.flag == 0) {
        printf("���˻��ѱ�����\n");
        return;
    }
    if (p->data.flag == -1) {
        printf("���˻�������\n");
        return;
    }
    if (PwdLock(inputID)) {
        printf("�������Ϊ%lldԪ", p->data.money);
    }
}

extern void userlist()//��ӡ�û��б�
{
    NODE *p;
    p = ALL;

    while (p->next != NULL) {
        p = p->next;
        if (p->data.flag == 1||p->data.flag == 0) {

            printf("������%s ", p->data.userName);    //����
            printf("���ţ�%d ", p->data.id);     //����
            printf("��%lld ", p->data.money);    //���
            printf("���룺%s ", p->data.userPwd);      //����
            printf("flag��%d", p->data.flag);      //�û���ʶ
            printf("\n");
        }

    }
}

extern void userChangePwd() {
    int inputID;
    NODE *s3;
    printf("����Ϊ������\n");
    printf("���������Ŀ���:");
    scanf("%d", &inputID);
    s3 = findUser(inputID);
    if (s3 == NULL)return;
    if (s3->data.flag == 0) {
        printf("�ÿ����˻������ã����ڶ���״̬\n");
        return;
    }
    if (s3->data.flag == -1) {
        printf("�ÿ����˻��ѱ�����\n");
        return;
    }
    if (PwdLock(inputID)) {
        printf("����������������");
        scanf("%s", s3->data.userPwd);
        printf("���ܳɹ��������Ʊ�����������\n");
    }

}

char path2[100];

extern void save() {
    FILE *f1;
    int i;
    NODE *s4 = ALL->next;
    f1 = fopen(path2, "wb");
    if (f1 == NULL)printf("·������");
    for (i = 0; i <= last; i++) {
        fwrite(&s4->data, sizeof(User), 1, f1);
        s4 = s4->next;
    }
    fclose(f1);
}

extern void load() {//char *path1
    printf("���ڳ�ʼ��ϵͳ��������洢�û���Ϣ���ļ�·��\n");
    printf("��������ϵͳ��һ�α����������������н���һ���հ�dat�ļ�\n");
    printf("���ļ�·�����·����룬���磺C:/Users/14531/Desktop/1.dat  ��ʹ�á�/����Ϊ�ָ�\n");
    scanf("%s", path2);
    FILE *f1;

    f1 = fopen(path2, "rb");
    NODE *s2, *s3;
    int ans = 0;
    s2 = (NODE *) malloc(sizeof(NODE));
    ALL->next = s2;

    if (f1 == NULL) {
        printf("·������\n");
        system("pause");
    }
    while (fread(&s2->data, sizeof(User), 1, f1) == 1) {
        s3 = (NODE *) malloc(sizeof(NODE));
        s2->next = s3;
        s2 = s3;
        last++;
        ans = 1;
    }
    if (ans == 0) {
        ALL->next = NULL;
    } else {
        end = findUser(last);
    }
    s2->next = NULL;
    fclose(f1);
}
