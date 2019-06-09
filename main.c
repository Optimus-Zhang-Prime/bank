#include <stdio.h>
#include <stdlib.h>

long int realpwd = 123456;//管理员初始密码，全局变量

int main() {
    int a;
    void save();
    void load();
    void userlist();//打印用户列表
    void inquire();//查询
    void deposit();//存款
    void transfer();//转帐
    void startSystem();//初始化系统
    void unLock();//解锁冻结的账户
    void menu();//菜单显示函数
    void askPwd();//管理员查询用户密码
    void deleAccount();//销户
    int adminPwd();//管理员密码验证函数
    void changePwd();//管理员密码修改函数
    void userChangePwd();//用户密码修改函数
    void openAccount();//开户
    void withdraw();//取款
    void help();//帮助
    startSystem();
    load();
    system("cls");//清屏
    int option;//指令
    while (1) {
        menu();
        printf("请输入操作：");
        scanf("%d", &option);
        if (option == 1) {
            openAccount();
        }//开户
        else if (option == 2) {
            deposit();
        }//存款
        else if (option == 3) {
            withdraw();
        }//取款
        else if (option == 4) {
            userChangePwd();
        }//改密
        else if (option == 5) {
            unLock();
        }//解锁

        else if (option == 6) {
            transfer();
        }//转帐
        else if (option == 7) {
            deleAccount();
        }//销户
        else if (option == 8) {
            inquire();
        }//查询
        else if (option == 9) {
            help();
        }//帮助
        else if (option == 10) {
            if (adminPwd())askPwd();
        }//查询密码
        else if (option == 11) {
            if (adminPwd())userlist();//打印用户列表
        }//用户列表
        else if (option == 12) {
            if (adminPwd())changePwd();
        }//修改管理员密码
        else if (option == 13) {
            if (adminPwd()) {
                save();
                break;
            }
        }//退出系统
        else {
            printf("指令无效");
        }
        system("pause");//任意键继续
        system("cls");//清屏
    }
    return 0;
}


int adminPwd() {
    //管理员密码验证函数
    //初始密码为123456
    long int inputpwd;//用户输入的密码
    printf("请输入管理员密码：");
    scanf("%ld", &inputpwd);
    if (inputpwd == realpwd)return 1;//验证成功则返回1
    else {
        printf("密码错误，操作失败");
        return 0;
    }
}

void changePwd() {
    printf("请输入您的新密码");
    scanf("%ld", &realpwd);
    printf("修改成功，您的新密码为%ld", realpwd);
}

