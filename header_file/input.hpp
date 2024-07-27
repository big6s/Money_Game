#ifndef INPUT_HPP
#define INPUT_HPP
#include <cstdio>
#include "type.hpp"
#include "output.hpp"
int input(const char* s,int &x) { //输入函数模板
	output(s);
	scanf("%d",&x);
	return 0;
}
int input(const char* s,float &x) { //输入函数模板
	output(s);
	scanf("%f",&x);
	return 0;
}
int input(const char* s,lli &x) { //输入函数模板
	output(s);
	scanf("%lld",&x);
	return 0;
}
int input(const char* s,char* x) { //输入函数模板
	output(s);
	scanf("%s",x);
	return 0;
}
#endif