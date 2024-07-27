#ifndef GAME_HPP
#define GAME_HPP
#include "player.hpp"
#include "type.hpp"
#include "input.hpp"
#include "output.hpp"
#include "account.hpp"
void Game(player &p, std::vector<Bank*> bks) {
	// 询问用户下一步操作：存钱、取钱、转账、查询余额
	int oper;
	input("Please input your operation: 1-Deposit, 2-Withdraw, 3-Transfer, 4-Query balance",oper);
	float money;
	int bank_num;
	switch(oper) {
		case 1:
			// 存钱
			input("Please input the amount of money you want to deposit:",money);
			//输入银行编号
			input("Please input the bank number:",bank_num);
			p.Deposit(money,bks[bank_num]);
			output("Deposit successful!");
			break;
		case 2:
			// 取钱
			input("Please input the amount of money you want to withdraw:",money);
			input("Please input the account number of the bank:",bank_num);
			p.Withdraw(money,bks[bank_num]);
			output("Withdraw successful!");
			break;
		case 3:
			// 转账
			input("Please input the amount of money you want to transfer:",money);
			int account_num;
			input("Please input the account number of the recipient:",account_num);
			p.Transfer(money,account_num);
			output("Transfer successful!");
			break;
		case 4:
			// 查询余额
			output("Your balance is: ");
			output(p.money);
			break;
		default:
			output("Invalid operation!");
			break;
	}
}
#endif