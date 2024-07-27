#ifndef BANK_HPP
#define BANK_HPP
#include "vector"
class Bank{
private:
	std::vector<double> balance; //每个玩家的余额
public:
	int id;
	int Deposit(player *p,double number); // 存钱
	int Withdraw(player *p,double number); // 取钱
	double Get_balance(); // 获取余额
	int Deposit(player *p,double number) { // 存钱
		balance[p->id] += number;
		return 0;
	}
};
#endif