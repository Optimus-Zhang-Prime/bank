#include <stdio.h>
#include <stdlib.h>

long int realpwd = 123456;//����Ա��ʼ���룬ȫ�ֱ���

int main() {
    int a;
    void save();
    void load();
    void userlist();//��ӡ�û��б�
    void inquire();//��ѯ
    void deposit();//���
    void transfer();//ת��
    void startSystem();//��ʼ��ϵͳ
    void unLock();//����������˻�
    void menu();//�˵���ʾ����
    void askPwd();//����Ա��ѯ�û�����
    void deleAccount();//����
    int adminPwd();//����Ա������֤����
    void changePwd();//����Ա�����޸ĺ���
    void userChangePwd();//�û������޸ĺ���
    void openAccount();//����
    void withdraw();//ȡ��
    void help();//����
    startSystem();
    load();
    system("cls");//����
    int option;//ָ��
    while (1) {
        menu();
        printf("�����������");
        scanf("%d", &option);
        if (option == 1) {
            openAccount();
        }//����
        else if (option == 2) {
            deposit();
        }//���
        else if (option == 3) {
            withdraw();
        }//ȡ��
        else if (option == 4) {
            userChangePwd();
        }//����
        else if (option == 5) {
            unLock();
        }//����

        else if (option == 6) {
            transfer();
        }//ת��
        else if (option == 7) {
            deleAccount();
        }//����
        else if (option == 8) {
            inquire();
        }//��ѯ
        else if (option == 9) {
            help();
        }//����
        else if (option == 10) {
            if (adminPwd())askPwd();
        }//��ѯ����
        else if (option == 11) {
            if (adminPwd())userlist();//��ӡ�û��б�
        }//�û��б�
        else if (option == 12) {
            if (adminPwd())changePwd();
        }//�޸Ĺ���Ա����
        else if (option == 13) {
            if (adminPwd()) {
                save();
                break;
            }
        }//�˳�ϵͳ
        else {
            printf("ָ����Ч");
        }
        system("pause");//���������
        system("cls");//����
    }
    return 0;
}


int adminPwd() {
    //����Ա������֤����
    //��ʼ����Ϊ123456
    long int inputpwd;//�û����������
    printf("���������Ա���룺");
    scanf("%ld", &inputpwd);
    if (inputpwd == realpwd)return 1;//��֤�ɹ��򷵻�1
    else {
        printf("������󣬲���ʧ��");
        return 0;
    }
}

void changePwd() {
    printf("����������������");
    scanf("%ld", &realpwd);
    printf("�޸ĳɹ�������������Ϊ%ld", realpwd);
}

