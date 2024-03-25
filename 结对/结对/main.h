#pragma once
#include<stdio.h>
#include<iostream>
#include<time.h>
#include<string.h>
#include<fstream>
using namespace std;

static int r;//控制式子中的数值
static int n;//控制式子数量
static int d1 = 1;//序号
static int d2= 1;//序号
static char num[100] = {};
static char operatorm[100] = {};
static char formula[100] = {};
static char answerchecks[100] = {};//储存计算答案
static int check = 0;
void make();//生成式子
void makeone();//生成一个操作符的式子
void maketwo();//生成两个操作符的式子
void makethree();//生成三个操作符的式子
void operatornum();//生成操作符的
void number();//生成操作数的
int calculate(char formula1[]);//整理式子进行计算函数调用准备
void answercheck();
