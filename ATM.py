from 用户 import 用户
from 卡 import  卡
from random import randint
from getpass import getpass
class Atm(object):
    def __init__(self,allusers):
        self.allUsers=allusers
    def 开户(self):
        name=input("请输入姓名：")
        idcard=input("请输入身份证号：")
        tel=input("请输入电话：")
        money=int(input("请输入预存款金额："))
        if money<0:
            print("预存金额小于0元，开户失败")
            input()
        firstpwd=getpass("请输入初始密码：")
        #firstpwd=input("请输入初始密码：")
        if self.检查密码(firstpwd):#若两次密码相同
            卡号=self.randcard()#卡号为整形，注意类型转换
            card=卡(卡号,money)#创造对象
            user=用户(name,tel,idcard,card,firstpwd)#创造对象
            self.allUsers[卡号]=user#将该用户添加到字典中
            print("开户成功,您的卡号是：",卡号)
            print("————$欢迎加入虚拟银行$————")
            input()
        else :
            print("开户失败")
            input()
    def 存款(self):
        cardnum=int(input("请输入卡号："))
        user=self.allUsers.get(cardnum)
        if user:
            if self.检查密码(user.pwd):
                n=int(input("请输入存款金额："))
                if n>0:
                    self.改钱(n,user)
                    print("存款成功")
                    input()
                else:
                    print("存款失败，存款金额必须为正数")
                    input()
            else:
                print("密码输入错误三次，该卡已被锁定")
                self.锁定(cardnum)
                input()
        else:
            print("卡号不存在")
            input()
    def 取款(self):
        cardnum=int(input("请输入卡号："))
        user=self.allUsers.get(cardnum)
        if user:
            if self.检查密码(user.pwd)and self.检查锁定(cardnum):
                n=int(input("请输入取款金额："))
                if n>0:
                    q=-n
                    if self.改钱(q,user):
                        print("取款成功")
                        input()
                    else:
                        input()
                else:
                    print("取款失败，取款金额必须为正数")
                    input()
            else:
                print("取款失败，该卡已被锁定")
                self.锁定(cardnum)
                input()
        else:
            print("卡号不存在")
            input()
    def 查询(self):
        cardnum=int(input("请输入卡号："))
        user=self.allUsers.get(cardnum)
        if user:
            if self.检查密码(user.pwd)and self.检查锁定(cardnum):
                print("账户余额：%d"% (user.card.money))
                input()
            else :
                print("查询失败,该卡已被锁定")
                self.锁定(cardnum)
                input()
        else:
            print("抱歉，该卡号不存在")
            input()
    def 转账(self):
        cardnum=int(input("请输入卡号："))
        user=self.allUsers.get(cardnum)
        if user:
            if self.检查密码(user.pwd)and self.检查锁定(cardnum):
                elnum=int(input("请输入要转帐的卡号："))
                user2=self.allUsers.get(elnum)
                if user2:
                    money=int(input("请输入转账金额："))
                    if money>user.card.money:
                        print("余额不足，转账失败")
                        input()
                    else:
                        self.改钱(-money,user)
                        self.改钱(money,user2)
                        print("转账成功")
                        input()
                else:
                    print("该卡号不存在")
                    input()
            else :
                print("转账失败，该卡已被锁定")
                self.锁定(cardnum)
                input()
        else:
            print("抱歉，该卡号不存在")
            input()
    def 锁定(self,cardnum):
        user=self.allUsers.get(cardnum)
        user.card.lock=True
    def 解锁(self):
        print("注意，解锁需要银行管理员的协助")
        cardnum=int(input("请输入要解锁卡号"))
        user=self.allUsers.get(cardnum)
        if user:
            na=input("请输入管理员账户名：")
            pw=input("请输入管理员密码：")
            if na=="zhz" and pw=="123456":
                  if  检查密码(user.pwd):
                       user.card.lock=False
                       print("解锁成功")
                       input()
                  else:
                      print("解锁失败")
                      input()
            else :
                print("解锁失败")
                input()
        else:
            print("抱歉，该卡号不存在")
            input()
    def 销户(self):
        cardnum=int(input("请输入您要销户的卡号："))
        user=self.allUsers.get(cardnum)
        money=str(user.card.money)
        if user:
            if self.检查密码(user.pwd)and self.检查锁定(cardnum):
                print("请确认是否要销卡：是/否")
                ans=input()
                if ans=="是":
                    self.allUsers.pop(cardnum)
                    print("销卡成功,取出金额",money)
                    input()
                else:
                    print("已取消销卡")
                    input()
            else:
                print("销卡失败，该卡已被锁定")
                input()
        else:
            print("账号不存在")
            input()
    def 改密(self):
        cardnum=int(input("请输入您的卡号："))
        user=self.allUsers.get(cardnum)
        if user:
            if self.检查密码(user.pwd)and self.检查锁定(cardnum):
                newpwd=input("请输入新密码:")
                if self.检查密码(newpwd):
                    user.pwd=newpwd
                    print("密码修改成功")
                    input()
                else:
                    print("密码修改失败")
                    input()
            else :
                print("密码修改失败,该卡已被锁定")
                self.锁定(cardnum)
                input()
        else:
            print("抱歉，该卡号不存在")
            input()

    def 改钱(self,n,user):
        if user.card.lock==False:
            user.card.money+=n
        else:
            print("抱歉，该卡已被锁定，请解锁后再进行操作")
    def 检查密码(self,realpwd):
        for temp in range(3):
            temppwd=getpass("请输入密码：")
            #temppwd=input("请输入密码：")
            if temppwd == realpwd:
                return True
            else:
                print("密码错误")
                print("************************************************")
        return False
    def 检查信息(self,realpwd):
        for temp in range(3):
            temppwd=input("请输入身份证号码：")
            if temppwd == realpwd:
                return True
            else:
                print("信息错误")
                print("************************************************")
        return False
    def 检查电话(self,realpwd):
        for temp in range(3):
            temppwd=input("请输入电话号码：")
            if temppwd == realpwd:
                return True
            else:
                print("信息错误")
                print("************************************************")
        return False
    def 检查锁定(self,cardnum):
        user=self.allUsers.get(cardnum)
        if user.card.lock== True:
            print("很抱歉，该卡已被锁定，请解锁后再进行操作")
            return False
        else:
            return True
    def randcard(self):
        num=randint(10000,99999)
        if not self.allUsers.get(num):#卡号为整形，注意类型转换
            return num
        else:
            self.randcard()


