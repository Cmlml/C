#pragma once
#include<stdio.h>
#include<iostream>
#include<time.h>
#include<string.h>
#include<fstream>
using namespace std;
#include<stdlib.h>

constexpr auto OK = 1;
constexpr auto ERROR = 0;
constexpr auto TRUE = 1;

typedef struct StackNode//分数节点
{
	int up;//分子
	int down;//分母
	struct StackNode* next;
}node1;

typedef int ElemType;
typedef struct LStack//分数栈
{
	node1* top;
	int length;
} LStack;

typedef int Status;
Status InitStack_LS(LStack& S);
Status Push_LS(LStack& S, int up, int down);
node1 Pop_LS(LStack& S);

typedef struct LSCNode//字符栈
{
	char data;
	struct LSCNode* next;
}LSCNode, * LCStack;
bool InitStack_LCS(LCStack& S);
bool Push_LCS(LCStack& S, char e);
bool Pop_LCS(LCStack& S, char& e);
bool StackEmpty_LCS(LCStack S);
char GetTop_LCS(LCStack& S);

node1 answer(node1 num1, node1 num2, char op);//计算答案
void answerprintf(node1 ans, int check);//简化答案并打印
int gcd(int a, int b);//求出最大公约数
static int r;//控制式子中的数值
static int n;//控制式子数量
static int d1 = 1;//序号
static int d2 = 1;//序号
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
Status InitStack_LS(LStack& S)//无头结点空链栈初始化
{
	S.top = NULL;
	S.length = 0;
	return OK;
}
Status Push_LS(LStack& S, int  up, int down)//入栈
{
	node1* temp = (node1*)malloc(sizeof(node1));
	if (temp == NULL)
		return ERROR;
	temp->up = up;
	temp->down = down;
	temp->next = S.top;
	S.top = temp;
	S.length++;
	return OK;
}
node1 Pop_LS(LStack& S) {  //记得类型是 node1 
	node1 A;
	node1* p = S.top;
	A.down = p->down;
	A.up = p->up;
	S.top = p->next;
	free(p);
	S.length--;
	return A;
}

bool InitStack_LCS(LCStack& S)
{
	S = NULL;
	return OK;
}
bool Push_LCS(LCStack& S, char e)
{
	LSCNode* t;
	t = (LSCNode*)malloc(sizeof(LSCNode));
	if (NULL == t)
	{
		return ERROR;
	}
	t->next = NULL;
	t->data = e;
	if (S == NULL)
		S = t;
	else
	{
		t->next = S;
		S = t;
	}
	return OK;
}
bool Pop_LCS(LCStack& S, char& e)
{
	LSCNode* t;
	if (NULL == S)
		return ERROR;
	t = S;
	e = S->data;
	S = S->next;
	free(t);
	return OK;
}
bool StackEmpty_LCS(LCStack S)
{
	if (S == NULL)
		return TRUE;
	else
		return ERROR;
}
char GetTop_LCS(LCStack& S)//取栈顶符号
{
	if (S != NULL)
		return S->data;
	else
		return ERROR;
}
void make()
{
	int kind = 0;
	srand((unsigned int)time(NULL) + rand());

	char formulamake[200] = {};//通过字符数组存储计算式
	char* string = formulamake;
	//char* formula1 = formula;//通过数组指针将字符数组带出来
	kind = rand() % 3 + 1;//随机生成1~3的数来判断式子种类
	//cout <<"种类："<< kind << endl;
	fstream fs;
	fs.open("test.txt", ios::out | ios::app);
	switch (kind)
	{
	case 1:
		makeone();
		strcpy_s(formulamake, formula);//将组装好的式子复制给formula数组
		printf("%s\n", string);


		break;

	case 2:
		maketwo();
		strcpy_s(formulamake, formula);//将组装好的式子复制给formula数组
		printf("%s\n", formulamake);
		break;
	case 3:
		makethree();
		strcpy_s(formulamake, formula);//将组装好的式子复制给formula数组
		printf("%s\n", formulamake);
		break;

	default:break;
	}
	strcat_s(formulamake, "=");
	int temp = calculate(string);
#pragma region answercheck
	if (temp >= 0)
	{
		int i = 0;
		fs << d1 << ". ";
		d1++;
		while (formulamake[i] != '\0')
		{
			if (formulamake[i] == '/')
			{
				fs << "÷";
				i++;
			}
			if (formulamake[i] == '*')
			{
				fs << "×";
				i++;
			}

			fs << formulamake[i];
			i++;
		}
		fs << endl;
		fs.close();

	}
	else
	{
		n++;
	}

}
#pragma endregion//判断式子是否大于0


#pragma region makeone
void makeone()//生成一个操作符的式子
{

	char temp[100] = {};//用temp来储存操作数和操作符来组成式子


	char* temp2 = temp;//用指针指向temp的数组名
	number();
	strcpy_s(temp, num);//将操作数复制给temp数组

	operatornum();

	strcat_s(temp, operatorm);

	number();

	strcat_s(temp, num);

	strcpy_s(formula, temp);


}
#pragma endregion//一个操作符式子组成


#pragma region maketwo
void maketwo()//生成两个操作符的式子
{
	srand((unsigned int)time(NULL) + rand());
	int a = rand() % 2;//判断是否生成括号
	cout << a << endl;
	int tag = 0;

	char temp[100] = {};//用temp来储存操作数和操作符来组成式子

	number();
	strcpy_s(temp, num);//将操作数复制给temp数组

	operatornum();

	strcat_s(temp, operatorm);
	if (a <= 1)
	{
		tag++;
		strcat_s(temp, "(");
	}
	number();

	strcat_s(temp, num);
	operatornum();

	strcat_s(temp, operatorm);

	number();

	strcat_s(temp, num);
	if (tag == 1)
	{
		tag--;
		strcat_s(temp, ")");
	}
	strcpy_s(formula, temp);
}
#pragma endregion//两个操作符式子组成

#pragma region makethree
void makethree()//生成三个操作符的式子
{
	srand((unsigned int)time(NULL) + rand());
	int a = rand() % 2;//判断是否生成括号
	int tag = 0;
	char temp[100] = {};//用temp来储存操作数和操作符来组成式子
	number();
	strcpy_s(temp, num);//将操作数复制给temp数组

	operatornum();

	strcat_s(temp, operatorm);

	number();

	strcat_s(temp, num);
	operatornum();

	strcat_s(temp, operatorm);
	if (a <= 1)
	{
		tag++;
		strcat_s(temp, "(");
	}

	number();

	strcat_s(temp, num);
	operatornum();

	strcat_s(temp, operatorm);

	number();

	strcat_s(temp, num);
	if (tag == 1)
	{
		tag--;
		strcat_s(temp, ")");
	}
	strcpy_s(formula, temp);
}

#pragma endregion//三个操作符式子组成

#pragma region operatornum
void operatornum()
{
	//char c[100] = {};
	srand((unsigned int)time(NULL) + rand());
	int kind = rand() % 4;
	// char*operator1=c;//储存操作符
	switch (kind)
	{
	case 0:
		strcpy_s(operatorm, "+");
		break;
	case 1:
		strcpy_s(operatorm, "-");
		break;
	case 2:
		strcpy_s(operatorm, "*");
		break;
	case 3:
		strcpy_s(operatorm, "/");
		break;
	default:break;

	}


}
#pragma endregion//生成运算符

#pragma region number
void number()//生成操作数的
{
	srand((unsigned int)time(NULL) + rand());

	int number1 = rand() % 5 + rand() % 3 + 1;
	char c[10] = {};

	if (0 < number1 && number1 < 10)//将操作数转换成字符类型储存进字符数组
	{
		number1 = number1 + 48;

		char temp = (char)number1;
		c[0] = temp;
		strcpy_s(num, c);
		//printf("操作数：%s\n", num);
	}
}
#pragma endregion//生成运算数



int calculate(char formula1[])//计算答案
{

	//cout << "正在计算" << endl;
	LStack s1;//数字栈
	InitStack_LS(s1);
	LCStack s2;//操作符栈
	InitStack_LCS(s2);

	int i = 0; int num = 0;
	node1 num1; node1 num2; node1 num3;//创建三个节点来储存出栈的分数节点
	char op = 0;
	//cout <<"式子第一个数"<< formula1[0] << endl;
	while (formula1[i] != '=')
	{
		//cout << "进入式子处理循环" << endl;
		if (formula1[i] >= '1' && formula1[i] <= '9')
		{
			//cout << "正在处理数字" << endl;
			num = (int)formula1[i] - 48;
			Push_LS(s1, num, 1);

		}
		if (formula1[i] == '+' || formula1[i] == '-')
		{
			//cout << "正在处理加减法" << endl;
			while ('/' == GetTop_LCS(s2) || '*' == GetTop_LCS(s2))
			{
				num2 = Pop_LS(s1); //cout << "num2:" <<num2.up/num2.down  << endl;
				num1 = Pop_LS(s1);// cout << "num1:" << num1.up/num1.down << endl;
				Pop_LCS(s2, op);
				num3 = answer(num1, num2, op);
				Push_LS(s1, num3.up, num3.down);

			}
			Push_LCS(s2, formula1[i]);

		}
		//*/ 1.栈空、栈顶'('或者'+-'直接入栈，否则出栈进行计算直到这样
		if (formula1[i] == '/' || formula1[i] == '*')
		{
			//cout << "正在处理乘除法" << endl;

			Push_LCS(s2, formula1[i]);

		}
		if (formula1[i] == '(')//遇到左括号时直接进栈
		{
			Push_LCS(s2, formula1[i]);

		}
		if (formula1[i] == ')')//遇到右括号时将字符栈内的符号出栈并存到链表中直到遇见左括号
		{
			while (GetTop_LCS(s2) != '(')
			{
				Pop_LCS(s2, op);
				num2 = Pop_LS(s1);// cout << "num2:" << num2.up / num2.down << endl;
				num1 = Pop_LS(s1); //cout << "num1:" << num1.up / num1.down << endl;
				num3 = answer(num1, num2, op);
				Push_LS(s1, num3.up, num3.down);


			}
			Pop_LCS(s2, op);
		}
		i++;
	}
	while (!StackEmpty_LCS(s2))
	{
		Pop_LCS(s2, op);
		num2 = Pop_LS(s1); //cout << "num2:" << num2.up / num2.down << endl;
		num1 = Pop_LS(s1);// cout << "num1:" << num1.up / num1.down << endl;
		num3 = answer(num1, num2, op);
		Push_LS(s1, num3.up, num3.down);
	}
	node1 ans = Pop_LS(s1);
	//cout << "fz:"<<ans.up << endl;
	//cout << "fm:"<<ans.down << endl;

	if (ans.up > 0 && ans.down > 0)
	{
		answerprintf(ans, check);
		return 1;
	}
	else
	{
		return -1;
	}

}
node1 answer(node1 num1, node1 num2, char op)
{

	node1 d{};
	if (op == '+')
	{
		d.up = num1.up * num2.down + num2.up * num1.down;
		d.down = num1.down * num2.down;
		// cout << "加法" << d.up<<"/" << d.down << endl;
	}
	if (op == '-')
	{
		d.up = num1.up * num2.down - num2.up * num1.down;
		d.down = num1.down * num2.down;
		// cout << "减法" << d.up <<"/"<< d.down << endl;
	}
	if (op == '*')
	{
		d.up = num1.up * num2.up;
		d.down = num1.down * num2.down;
		// cout << "乘法" << d.up <<"/"<< d.down << endl;
	}
	if (op == '/')
	{
		d.up = num1.up * num2.down;
		d.down = num1.down * num2.up;
		//	 cout << "除法" << d.up <<"/"<< d.down << endl;

	}

	return d;
}

void answerprintf(node1 ans, int check)
{
	//cout << "qweerrrsaaa" << endl;
	fstream cd;
	cd.open("answer.txt", ios::out | ios::app);
	node1 p = ans;
	int temp1 = 0, temp2 = 0;
	int num1 = 0, num2 = 0, num3 = 0;
	char c[10] = {};
	int a = p.up;//分子
	int b = p.down;//分母
	char answer[20] = {};//储存答案
	if (a % b == 0)
	{
		temp1 = a / b;
		_itoa_s(temp1, answer, 10);

	}

	else if (a < b)
	{
		num3 = gcd(a, b);
		temp1 = a / num3;
		temp2 = b / num3;
		_itoa_s(temp1, answer, 10);
		strcat_s(answer, "/");
		sprintf_s(c, "%d", temp2);
		strcat_s(answer, c);
	}
	else if (a > b)
	{
		num3 = gcd(a, b);
		num1 = a / num3;
		num2 = b / num3;
		num3 = a / b;
		a = num1 - num2 * num3;
		_itoa_s(num3, answer, 10);
		strcat_s(answer, "\'");
		sprintf_s(c, "%d", a);
		strcat_s(answer, c);
		strcat_s(answer, "/");
		sprintf_s(c, "%d", num2);
		strcat_s(answer, c);
	}
	if (check == 0)
	{
		cd << d2 << ".";
		d2++;
		cd << answer << endl;

	}
	if (check == 1)
	{
		strcpy_s(answerchecks, answer);
	}

	cd.close();
}

int gcd(int x, int y)//辗转相除法 ,两整数的最大公约数 
{
	if (y == 0) return x;
	return gcd(y, x % y);
}
void answercheck()
{
	check = 1;
	cout << "欢迎使用答案核对功能" << endl;
	string questionsTxt;
	string answersTxt;
	string correct = "Correct:";
	string wrong = "Wrong:";
	string correctList = "(";
	string wrongList = "(";
	char questions[30] = {};
	char answers[20] = {};

	int correctNumber = 0;
	int wrongNumber = 0;
	cout << "请输入题目文件地址：" << endl;
	//cin >> questionsTxt;
	cout << "请输入答案文件地址：" << endl;
	//cin >> answersTxt;
	std::ifstream questionsFile("C:\\Users\\陈家谦\\Desktop\\C++\\结对\\questions.txt");
	std::ifstream answersFile("C:\\Users\\陈家谦\\Desktop\\C++\\结对\\answers.txt");
	//std::ifstream gradeFile("Grade.txt");
	if (!questionsFile.is_open() || !answersFile.is_open())
	{
		cout << "打开文件失败！" << endl;
		return;
	}
	else
		cout << "打开成功！" << endl;
	answersFile.close();
	while (questionsFile.getline(questions, 30))
	{
		std::ifstream answersFile("C:\\Users\\陈家谦\\Desktop\\C++\\结对\\answers.txt");
		//questionsNumber = questions[0];//题号

		//计算读入的题目答案，第一个数字为quesstions[2]，答案存入某一数组
		char temp1[30] = {};
		char temp2[5] = {};
		char temp3[30] = {};
		char answer2[20] = {};
		for (int i = 0; i < 28; i++)
		{
			temp1[i] = questions[i + 2];//将计算式存入
		}
		int j = 0;
		while (questions[j] != '.')
		{
			//cout << "检查." << endl;
			temp2[j] = questions[j];                 //储存问题序号
			j++;
		}
		j = 0;
		char string[30] = {};

		if (calculate(temp1) == 1)
		{
			strcat_s(string, answerchecks);//答案存在string

			cout << "答案：" << string << endl;
			while (answersFile.getline(answers, 20))
			{


				while (answers[j] != '.')
				{
					temp3[j] = answers[j];//储存答案序号
					j++;
				}
				j++;

				int i = 0;
				for (; j < 20; j++)
				{

					answer2[i++] = answers[j];
				}

				j = 0;
				if (!strcmp(temp2, temp3))
				{
					cout << "temp2:" << temp2 << endl;
					cout << "temp3:" << temp3 << endl;
					cout << "string:" << string << endl;
					cout << "answer2:" << answer2 << endl;
					if (strcmp(string, answer2))//比对答案,后储存题号进入正确或错误
					{
						correctNumber++;
						correctList += temp3;
						correctList += ',';
					}
					else
					{
						wrongNumber++;
						wrongList += temp3;
						wrongList += ',';
					}
				}
			}
		}
		answersFile.close();

	}
	correctList += ')';
	wrongList += ')';
	cout << correct << wrongNumber << wrongList << endl;
	cout << wrong << correctNumber << correctList << endl;
}