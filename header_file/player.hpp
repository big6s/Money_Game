#ifndef PLAYER_HPP
#define PLAYER_HPP
#include "bank.hpp"
#include "type.hpp"
struct player { //定义玩家结构体
	int id,lvl;
	float money; //余额
	lli phone; //手机号
	char name[20],email[50]; //名字，邮箱
	int Deposit(float number,Bank* bk); //存钱
	int Withdraw(float number,Bank* bk); //取钱
	int Transfer(float number,int account_number); //取钱
	int Withdraw(float number,Bank* bk) { //取钱
		bk->Withdraw(this,number);
		money += number;
	}
	int Deposit(float number,Bank* bk) { //存钱
		if(money >= number) {
			bk->Deposit(this,number);
			money -= number;
		} else {
			//余额不足
			error("Insufficient balance");
			return -1; //Insufficient balance
		}
	}
};
#endif