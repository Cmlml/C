#pragma once
#include"main.h"
#include<stdlib.h>

constexpr auto OK = 1;
constexpr auto ERROR = 0;
constexpr auto TRUE = 1;

typedef struct StackNode//�����ڵ�
{
	int up;//����
	int down;//��ĸ
	struct StackNode* next;
}node1;

typedef int ElemType;
typedef struct LStack//����ջ
{
	node1* top;
	int length;
} LStack;

typedef int Status;
Status InitStack_LS(LStack& S);
Status Push_LS(LStack& S, int up,int down);
node1 Pop_LS(LStack& S);

typedef struct LSCNode//�ַ�ջ
{
	char data;
	struct LSCNode* next;
}LSCNode, * LCStack;
bool InitStack_LCS(LCStack& S);
bool Push_LCS(LCStack& S, char e);
bool Pop_LCS(LCStack& S, char& e);
bool StackEmpty_LCS(LCStack S);
char GetTop_LCS(LCStack& S);

node1 answer(node1 num1, node1 num2, char op);//�����
void answerprintf(node1 ans,int check);//�򻯴𰸲���ӡ
int gcd(int a, int b);//������Լ��
