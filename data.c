#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>

typedef struct user {//用户结构体，链表的结点
    char userName[30];//姓名
    int id;//卡号
    long long int money;//余额
    char userPwd[30];//密码
    int flag;//用于标识账户是否可用
} User;

typedef struct Node {
    User data;//用户数据
    struct Node *next;//指针
} NODE;
NODE *ALL, *s, *end;//ALL是用户信息库头指针,s为工作指针，end指向尾节点


int last;//信息库长度

NODE *findUser(int ID) {//根据卡号找到用户信息结点
    NODE *s2;
    int i;
    if (ID > last) {
        printf("该卡号尚未开户");
        return NULL;
    }
    s2 = ALL;//初始指向头节点
    for (i = 0; i <= ID; i++) {
        s2 = s2->next;
    }
    return s2;
}


int PwdLock(int inputID) {//检查密码，输入密码三次错误冻结账户
    int i;//迭代次数
    NODE *s4;//工作指针
    char inputPwd[20];//输入的密码
    s4 = findUser(inputID);
    if (s4 == NULL)return 0;
    for (i = 0; i < 3; i++) {//三次错冻结账户
        printf("请输入您的密码");
        scanf("%s", inputPwd);
        if (strcmp(inputPwd, s4->data.userPwd) == 0) {//比较输入密码与真实
            return 1;//密码正确则结束循环并返回1
        } else {
            printf("密码错误\n");
        }
    }
    printf("密码错误三次，该账户已被冻结\n");
    s4->data.flag = 0;//标志符置0表示冻结
    return 0;//密码验证失败返回1
}

extern void startSystem() {//初始化系统
    ALL = (NODE *) malloc(sizeof(NODE));
    last = -1;//注意：顺序表为空时last为-1
    end = ALL;
}

extern void openAccount() {//开户
    s = (NODE *) malloc(sizeof(NODE));
    end->next = s;//尾插法建表
    end = s;

    last++;
    s->data.id = last;
    printf("欢迎加入本银行，正在为您开户\n");
    printf("请输入您的姓名:");
    scanf("%s", s->data.userName);
    printf("请输入您的初始密码");
    scanf("%s", s->data.userPwd);
    printf("开卡成功，您的卡号为%d，密码为%s，请妥善保管\n", last, s->data.userPwd);
    s->data.money = 0;//将余额置0
    s->data.flag = 1;//表示账户可用
    printf("当前卡内余额为0");
}

extern void withdraw() {//取款
    int inputID;
    NODE *s3;
    long long int inputMoney;
    printf("正在为您取款\n");
    printf("请输入您的卡号:");
    scanf("%d", &inputID);
    s3 = findUser(inputID);
    if (s3 == NULL)return;
    if (s3->data.flag == 0) {
        printf("该卡号账户不可用，处于冻结状态\n");
        return;
    }
    if (s3->data.flag == -1) {
        printf("该卡号账户已被销户\n");
        return;
    }
    if (PwdLock(inputID)) {
        printf("当前卡内余额为%lld，请输入您的取款金额：", s3->data.money);
        scanf("%lld", &inputMoney);
        if (inputMoney > s3->data.money) {
            printf("余额不足，取款失败");
        } else {
            s3->data.money -= inputMoney;
            printf("取款%lld元成功，卡内余额%lld元", inputMoney, s3->data.money);
        }
    }
}

extern void unLock() {//解锁冻结的账户
    int inputID;
    char inputName[20];
    NODE *s5;
    printf("正在为您解锁账户\n");
    printf("请输入您的卡号:");
    scanf("%d", &inputID);
    s5 = findUser(inputID);
    if (s5 == NULL)return;
    if (s5->data.flag == -1) {
        printf("该卡号账户已被销户\n");
        return;
    }
    if (s5->data.flag != 0) {
        printf("该卡号账户并非处于冻结状态\n");
        return;
    } else {
        if (PwdLock(inputID)) {
            printf("请输入持卡人姓名：");
            scanf("%s", inputName);
            if (strcmp(inputName, s5->data.userName) == 0) {
                printf("解除冻结成功！");
                s5->data.flag = 1;
            }
        }
    }
}

extern void deleAccount() {//销户
    int inputID;
    char inputName[20];
    NODE *s6;
    printf("正在为您销户\n");
    printf("请输入您的卡号:");
    scanf("%d", &inputID);
    s6 = findUser(inputID);
    if (s6 == NULL)return;
    if (s6->data.flag == -1) {
        printf("该卡号账户已被销户\n");
        return;
    }
    if (s6->data.flag == 0) {
        printf("该卡号账户处于冻结状态\n");
        return;
    } else {
        if (PwdLock(inputID)) {
            printf("请输入持卡人姓名：");
            scanf("%s", inputName);
            if (strcmp(inputName, s6->data.userName) == 0) {
                printf("销户成功！取出余额%lld元", s6->data.money);
                s6->data.money = 0;
                s6->data.flag = -1;
            }
        }
    }
}

extern void help() {
    printf("欢迎来到帮助系统\n");
    printf("请选择需要帮助的内容：\n");
    printf("1.业务流程     2.账户冻结    3.账户销户   4.取消帮助\n");
    getchar();
    int order;
    scanf("%d", &order);
    if (order == 1) {
        printf("首先您需要开通一个账户\n");
        printf("向账户中存款，即可进行取款、转帐等业务\n");
    } else if (order == 2) {
        printf("输入密码连续三次错误账户会被冻结\n");
        printf("您可以使用“解锁”功能恢复账户使用\n");
    } else if (order == 3) {
        printf("销户会取出卡内余额\n");
        printf("销户后该账户不可被恢复\n");
    } else {
        return;
    }
    system("pause");
}

extern void askPwd() {
    int inputID;
    NODE *s3;
    long long int inputMoney;
    printf("正在为查询密码\n");
    printf("请输入卡号:");
    scanf("%d", &inputID);
    s3 = findUser(inputID);
    if (s3 == NULL)return;
    if (s3->data.flag == -1) {
        printf("该卡号账户已被销户\n");
        return;
    }
    printf("该账户的密码为%s", s3->data.userPwd);

}

extern void deposit()//存款
{
    NODE *p;
    int inputID;
    long long int inputMoney;
    printf("正在进入存款系统\n");
    printf("请输入您的卡号:\n");
    scanf("%d", &inputID);
    p = findUser(inputID);  //finUser这模块还没建
    if (p == NULL)
        return;
    if (p->data.flag == 0) {
        printf("该账户已被冻结\n");
        return;
    }
    if (p->data.flag == -1) {
        printf("该账户不存在\n");
        return;
    }
    if (PwdLock(inputID)) {
        printf("请输入存款金额：");
        scanf("%lld", &inputMoney);
        p->data.money += inputMoney;
        printf("存款%lld元成功，卡内余额为%lld元", inputMoney, p->data.money);
    }
}

extern void transfer()//转账
{
    NODE *p, *q;
    int torID, peeID;
    long long int inputMoney;
    printf("正在进入转账系统\n");
    printf("请输入您的卡号：");
    scanf("%d", &torID);
    p = findUser(torID);  //finUser这模块还没建
    if (p == NULL)
        return;
    if (p->data.flag == 0) {
        printf("该账户已被冻结\n");
        return;
    }
    if (p->data.flag == -1) {
        printf("该账户不存在\n");
        return;
    }
    if (PwdLock(torID)) {
        printf("请输入你要转账的账户卡号：\n");
        scanf("%d", &peeID);
        q = findUser(peeID);
        if (q == NULL) return;
        if (q->data.flag == 0) {
            printf("该账户已被冻结\n");
            return;
        }
        if (q->data.flag == -1) {
            printf("该账户不存在\n");
            return;
        }

        printf("当前您的卡内余额为%lld，请输入你要转账的金额：\n", p->data.money);
        scanf("%lld", &inputMoney);
        if (inputMoney > p->data.money)
            printf("余额不足，转账失败");
        else {
            p->data.money -= inputMoney;
            q->data.money += inputMoney;
            printf("转账成功，卡内余额为%lld元", p->data.money);
        }
    }
}

extern void inquire()//账户查询
{
    int inputID;
    NODE *p;
    printf("请输入您要查询账户的卡号：\n");
    scanf("%d", &inputID);
    p = findUser(inputID);
    if (p == NULL)
        return;
    if (p->data.flag == 0) {
        printf("该账户已被冻结\n");
        return;
    }
    if (p->data.flag == -1) {
        printf("该账户不存在\n");
        return;
    }
    if (PwdLock(inputID)) {
        printf("您的余额为%lld元", p->data.money);
    }
}

extern void userlist()//打印用户列表
{
    NODE *p;
    p = ALL;

    while (p->next != NULL) {
        p = p->next;
        if (p->data.flag == 1||p->data.flag == 0) {

            printf("姓名：%s ", p->data.userName);    //姓名
            printf("卡号：%d ", p->data.id);     //卡号
            printf("余额：%lld ", p->data.money);    //余额
            printf("密码：%s ", p->data.userPwd);      //密码
            printf("flag：%d", p->data.flag);      //用户标识
            printf("\n");
        }

    }
}

extern void userChangePwd() {
    int inputID;
    NODE *s3;
    printf("正在为您改密\n");
    printf("请输入您的卡号:");
    scanf("%d", &inputID);
    s3 = findUser(inputID);
    if (s3 == NULL)return;
    if (s3->data.flag == 0) {
        printf("该卡号账户不可用，处于冻结状态\n");
        return;
    }
    if (s3->data.flag == -1) {
        printf("该卡号账户已被销户\n");
        return;
    }
    if (PwdLock(inputID)) {
        printf("请输入您的新密码");
        scanf("%s", s3->data.userPwd);
        printf("改密成功，请妥善保管您的密码\n");
    }

}

char path2[100];

extern void save() {
    FILE *f1;
    int i;
    NODE *s4 = ALL->next;
    f1 = fopen(path2, "wb");
    if (f1 == NULL)printf("路径错误");
    for (i = 0; i <= last; i++) {
        fwrite(&s4->data, sizeof(User), 1, f1);
        s4 = s4->next;
    }
    fclose(f1);
}

extern void load() {//char *path1
    printf("正在初始化系统，请输入存储用户信息的文件路径\n");
    printf("假如银行系统第一次被启动，您可以自行建立一个空白dat文件\n");
    printf("将文件路径在下方输入，例如：C:/Users/14531/Desktop/1.dat  请使用“/”作为分隔\n");
    scanf("%s", path2);
    FILE *f1;

    f1 = fopen(path2, "rb");
    NODE *s2, *s3;
    int ans = 0;
    s2 = (NODE *) malloc(sizeof(NODE));
    ALL->next = s2;

    if (f1 == NULL) {
        printf("路径错误\n");
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
