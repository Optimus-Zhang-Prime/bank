class 卡(object):
    money=0
    def __init__(self,卡号,钱):
        self.cardnum=卡号
        self.money=钱
        self.lock=False
