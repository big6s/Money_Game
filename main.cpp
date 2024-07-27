//赚钱游戏
#include "header_file/template.hpp"

int main() {
	player *p = new player();
	std::vector<Bank*> bks;
	bks.push_back(nullptr); // 第0个元素是 nullptr，表示没有银行
	bks.push_back(new Bank()); // 第1个元素是银行，因为编号从1开始
	Welcome(*p);
	Game(*p, bks);
	delete p;
	return 0;
}