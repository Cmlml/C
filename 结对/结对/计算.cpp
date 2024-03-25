#include"main.h"
#include"LStack.h"
Status InitStack_LS(LStack& S)//无头结点空链栈初始化
{
	S.top = NULL;
	S.length = 0;
	return OK;
}
Status Push_LS(LStack& S, int  up,int down)//入栈
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

int calculate(char formula1[])//计算答案
{

	//cout << "正在计算" << endl;
	LStack s1;//数字栈
	InitStack_LS(s1);	
	LCStack s2;//操作符栈
	InitStack_LCS(s2);
	
	int i = 0; int num = 0;
	node1 num1 ; node1 num2 ;node1 num3 ;//创建三个节点来储存出栈的分数节点
	char op=0;
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
			while ('/'==GetTop_LCS(s2) || '*' == GetTop_LCS(s2))
			{
			num2=Pop_LS(s1); //cout << "num2:" <<num2.up/num2.down  << endl;
			num1=Pop_LS(s1);// cout << "num1:" << num1.up/num1.down << endl;
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
				num2=Pop_LS(s1);// cout << "num2:" << num2.up / num2.down << endl;
				num1=Pop_LS(s1); //cout << "num1:" << num1.up / num1.down << endl;
				num3 = answer(num1, num2, op);
				Push_LS(s1,num3.up,num3.down);
				
				
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

	if (ans.up >0 && ans.down >0)
	{
		answerprintf(ans,check);
		return 1;
	}
	else
	{
		return -1;
	}
		
}
node1 answer(node1 num1,node1 num2,char op)
{
	
	node1 d{};
	 if (op == '+')
	 {
		d.up = num1.up *num2.down+ num2.up*num1.down;
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
		 d.up = num1.up * num2.up ;
		 d.down = num1.down * num2.down;
		// cout << "乘法" << d.up <<"/"<< d.down << endl;
	 }
	 if (op == '/')
	 {
		 d.up = num1.up*num2.down;
		 d.down = num1.down * num2.up;
		//	 cout << "除法" << d.up <<"/"<< d.down << endl;
		
	 }
	
	 return d;
}

void answerprintf(node1 ans,int check)
{
	//cout << "qweerrrsaaa" << endl;
	fstream cd;
    cd.open("answerfile.txt", ios::out | ios::app);
	node1 p = ans;
	int temp1 = 0,temp2=0;
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
	
	else if(a < b)
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
		num3 = a /b;
		a = num1 - num2 * num3;
		_itoa_s(num3, answer, 10);
		strcat_s(answer, "\'");
		sprintf_s(c, "%d", a);
		strcat_s(answer, c);
		strcat_s(answer,"/" );
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
	cin >> questionsTxt;
	cout << "请输入答案文件地址：" << endl;
	cin >> answersTxt;
	std::ifstream questionsFile(questionsTxt);
	std::ifstream answersFile(answersTxt);
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
		std::ifstream answersFile(answersTxt);
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

			//cout << "答案：" << string << endl;
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
					//cout << "temp2:"<< temp2 << endl;
					//cout << "temp3:" << temp3 << endl;
					//cout << "string:" << string << endl;
					//cout << "answer2:" << answer2<< endl;
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
	std::ofstream gradeFile("Grades.txt");
	if (!gradeFile.precision())
	{
		cout << "打开检查结果文件失败！" << endl;
		return;
	}
	else
	{
		cout << "打开检查结果文件成功！" << endl;
		cout << correct << wrongNumber << wrongList << endl;
		cout << wrong << correctNumber << correctList << endl;
		gradeFile << correct << wrongNumber << wrongList << endl;
		gradeFile << wrong << correctNumber << correctList << endl;
	}
	gradeFile.close();
	system("pause");
}