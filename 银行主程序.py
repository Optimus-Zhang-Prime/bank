from 界面 import View
from  ATM import Atm
from os import system
from pickle import load,dump
from getpass import getpass

def clear():
    system('cls')
def main():
    adname="zhz"
    adpwd="123456"
    view = View(adname,adpwd)#管理员密码
    filepath=r"C:\Users\14531\allUsers.txt"
    file=open(filepath,"rb")
    allUsers=load(file)
    atm=Atm(allUsers)
    file.close()
    view.hello()
    view.welcomeview()
    clear()
    view.functionview()


    while True:
        op = input("请输入操作：")
        if op == "开户":
            atm.开户()
            filepath=r"C:\Users\14531\allUsers.txt"
            f=open(filepath,"wb")
            dump(atm.allUsers,f)
            f.close()
        elif op == "存款":
            atm.存款()
            filepath=r"C:\Users\14531\allUsers.txt"
            f=open(filepath,"wb")
            dump(atm.allUsers,f)
            f.close()
        elif op == "取款":
            atm.取款()
            filepath=r"C:\Users\14531\allUsers.txt"
            f=open(filepath,"wb")
            dump(atm.allUsers,f)
            f.close()
        elif op == "查询":
            atm.查询()
            filepath=r"C:\Users\14531\allUsers.txt"
            f=open(filepath,"wb")
            dump(atm.allUsers,f)
            f.close()
        elif op == "改密":
            atm.改密()
            filepath=r"C:\Users\14531\allUsers.txt"
            f=open(filepath,"wb")
            dump(atm.allUsers,f)
            f.close()
        elif op == "解锁":
            atm.解锁()
            filepath=r"C:\Users\14531\allUsers.txt"
            f=open(filepath,"wb")
            dump(atm.allUsers,f)
            f.close()
        elif op == "帮助":
            print('''软件开发者QQ1453196338
软件开发于2019/1/24
暂不用于商业用途''')
            input()
        elif op == "销户":
            atm.销户()
            filepath=r"C:\Users\14531\allUsers.txt"
            f=open(filepath,"wb")
            dump(atm.allUsers,f)
            f.close()
        elif op == "转账":
            atm.转账()
            filepath=r"C:\Users\14531\allUsers.txt"
            f=open(filepath,"wb")
            dump(atm.allUsers,f)
            f.close()
        elif op == "安全退出":
            filepath=r"C:\Users\14531\allUsers.txt"
            f=open(filepath,"wb")
            dump(atm.allUsers,f)
            f.close()
        elif op == "关闭系统":
            view.byeview()
            filepath=r"C:\Users\14531\allUsers.txt"
            f=open(filepath,"wb")
            dump(atm.allUsers,f)
            f.close()
            clear()
            break
        elif op == "客户列表":
            inputadname=input("请输入管理员账户名：")
            inputadpwd=getpass("请输入密码：")
            #inputadpwd=input("请输入密码：")
            if inputadname!=adname or inputadpwd!=adpwd:
                print("账号密码有误, 查询客户列表失败")
                print("************************************************")
            else :
                print(allUsers)
                input()
        elif op=="查询密码":
            inputadname=input("请输入管理员账户名：")
            inputadpwd=getpass("请输入密码：")
            #inputadpwd=input("请输入密码：")
            if inputadname!=adname or inputadpwd!=adpwd:
                print("账号密码有误, 查询密码列表失败")
                print("************************************************")
                input()
            else :
                card=int(input("请输入要查询的卡号："))
                print(allUsers[card])
                input()
        else:
            print("暂不支持该功能")
            input()
        clear()
        view.functionview()
    main()



if __name__ == "__main__":
    main()





























