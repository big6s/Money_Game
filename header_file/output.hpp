#ifndef OUTPUT_HPP
#define OUTPUT_HPP
#include <cstdio>
#include "type.hpp"
#define Endl '\n'
int output(char *x,char ch=0) { //输出函数模板
	printf("%s",x);
	if(ch) putchar(ch);
	return 0;
}
int output(const char *x,char ch=0) { //输出函数模板
	printf("%s",x);
	if(ch) putchar(ch);
	return 0;
}
int output(int &x,char ch=0) { //输出函数模板
	printf("%d",x);
	if(ch) putchar(ch);
	return 0;
}
int output(lli &x,char ch=0) { //输出函数模板
	printf("%lld",x);
	if(ch) putchar(ch);
	return 0;
}
int output(float &x,char ch=0) { //输出函数模板
	printf("%f",x);
	if(ch) putchar(ch);
	return 0;
}
int Tips(const char *s) { //提示函数模板
	output("Tips: ");
	output(s,Endl);
	return 0;
}
int error(const char *s) { //提示函数模板
	output("Error: ");
	output(s,'!');
	output("\n");
	return 0;
}
#undef Endl
#endif