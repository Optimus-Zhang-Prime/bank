from getpass import getpass
from  time import sleep
class View(object):
    def __init__(self,adname,adpassword):
        self.adname=adname
        self.adpwd=adpassword
    def hello(self):
        print("************************************************")
        print("******************虚拟银行等待开启***************")
        print("************************************************")
    def welcomeview(self):
        inputadname=input("请输入管理员账户名：")
        inputadpwd=getpass("请输入密码")
        #inputadpwd=input("请输入密码：")
        if inputadname!=self.adname or inputadpwd!=self.adpwd:
            print("账号密码有误,请重新输入")
            print("************************************************")
            self.welcomeview()
        else :
            print("虚拟银行即将启动！ 欢迎",self.adname)
            print("$$$$$$$$$$$$$$$$$$虚拟银行启动$$$$$$$$$$$$$$$$$$$")
            sleep(1)
    def functionview(self):
        print("*************************************************")
        print("*****____________虚拟银行功能菜单___________*****")
        print("********____|开户|____|存款|____|取款|____*******")
        print("********____|改密|____|解锁|____|帮助|____*******")
        print("********____|销户|____|转账|____|查询|____*******")
        print("************————|安全退出|————************")
        print("****__|管理员选项:查询密码/关闭系统/客户列表|__***")
        print("*************************************************")

    def byeview(self):
        inputadname=input("请输入管理员账户名：")
        inputadpwd=getpass("请输入密码：")
        #inputadpwd=input("请输入密码：")
        if inputadname!=self.adname or inputadpwd!=self.adpwd:
            print("账号密码有误,请重新输入")
            print("************************************************")
            self.byeview()
        else :
            print("退出成功！ 再见",self.adname)








