#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP
#include <stdio.h>
#include <stdlib.h>
#include "input.hpp"
#include "output.hpp"
#include "player.hpp"
void Save(player& p) {
	FILE* fp=fopen("save/player.txt","w");
	if(fp==nullptr) { //如果存档文件创建失败
		output("Failed to create save file.\n"); //提示玩家存档文件创建失败
		return;
	}
	fprintf(fp,"name:%s\n",p.name); //写入玩家的名字
	fprintf(fp,"money:%d\n",p.money); //写入玩家的钱数
	fprintf(fp,"lvl:%d\n",p.lvl); //写入玩家的等级
	fprintf(fp,"phone:%lld\n",p.phone); //写入玩家的手机号
	fprintf(fp,"email:%s\n",p.email); //写入玩家的邮箱
	fclose(fp); //关闭存档文件
}
void Read_save(player& p) { //读取存档文件
	FILE* fp=fopen("save/player.txt","r"); //打开存档文件
	if(fp==nullptr) { //如果存档文件创建失败
		output("Failed to create save file.\n"); //提示玩家存档文件创建失败
		return;
	}
	fscanf(fp,"name:%s\n",p.name); //读取玩家的名字
	fscanf(fp,"money:%d\n",&(p.money)); //读取玩家的钱数
	fscanf(fp,"lvl:%d\n",&(p.lvl)); //读取玩家的等级
	fscanf(fp,"phone:%lld\n",&(p.phone)); //读取玩家的手机号
	fscanf(fp,"email:%s\n",p.email); //读取玩家的邮箱
	fclose(fp); //关闭存档文件
}
void User_register(player &p) { //玩家注册
	input("Enter your name: ",p.name); //输入玩家的名字
	p.money = 50; //设置玩家的钱数
	p.lvl = 1; //设置玩家的等级
	//输入玩家的手机号
	input("Enter your phone number: ",p.phone);
	//输入玩家的邮箱
	input("Enter your email address: ",p.email);
	Save(p); //保存玩家信息
	output("Congratulations, you have registered successfully!\n"); //提示玩家注册成功
}
void User_login(player &p) { //玩家登录
	Read_save(p); //读取存档文件
	output("Login Accepted!\n");
	//欢迎玩家
	output("Welcome to the game, "),output(p.name),output("!\n");
	//显示玩家的钱数
	output("Your money is "),output(p.money),output("$.\n");
	output("Your level is "),output(p.lvl),output(".\n");
	//显示玩家的手机号和邮箱
	output("Your phone number is "),output(p.phone),output(".\n");
	output("Your email address is "),output(p.email),output(".\n");
	//提示用户如果登录信息错误，应该删除存档文件并重新注册
	Tips("If your login information is incorrect, please delete the save file and register again.");
}
void Welcome(player &p) { //开始游戏
	FILE *fp=fopen("save/player.txt","r"); //打开存档文件
	if(fp!=nullptr) { //如果存档文件存在
		User_login(p); //登录玩家
	}
	else { //如果存档文件不存在
		Tips("No save file found."); 
		//如果有存档文件，则提示用户将存档文件放入save文件夹中并重启游戏，随后游戏退出
		Tips("If you have a save file, please put it in the \"save\" folder and restart the game.");
		//或者玩家可以选择注册
		Tips("Or you can register a new account.");
		User_register(p); //注册玩家
	}
	fclose(fp); //关闭存档文件
}
#endif