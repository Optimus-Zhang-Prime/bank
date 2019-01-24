from 卡 import 卡
class 用户(object):
    def __init__(self,姓名,电话,身份证,卡,密码):
        self.name=姓名
        self.id=身份证
        self.tel=电话
        self.pwd=密码
        self.card=卡
    def __str__(self):
        return self.pwd

