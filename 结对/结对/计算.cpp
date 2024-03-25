#include"main.h"
#include"LStack.h"
Status InitStack_LS(LStack& S)//��ͷ������ջ��ʼ��
{
	S.top = NULL;
	S.length = 0;
	return OK;
}
Status Push_LS(LStack& S, int  up,int down)//��ջ
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
node1 Pop_LS(LStack& S) {  //�ǵ������� node1 
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
char GetTop_LCS(LCStack& S)//ȡջ������
{
	if (S != NULL)
		return S->data;
	else
		return ERROR;
}

int calculate(char formula1[])//�����
{

	//cout << "���ڼ���" << endl;
	LStack s1;//����ջ
	InitStack_LS(s1);	
	LCStack s2;//������ջ
	InitStack_LCS(s2);
	
	int i = 0; int num = 0;
	node1 num1 ; node1 num2 ;node1 num3 ;//���������ڵ��������ջ�ķ����ڵ�
	char op=0;
	//cout <<"ʽ�ӵ�һ����"<< formula1[0] << endl;
	while (formula1[i] != '=')
	{
		//cout << "����ʽ�Ӵ���ѭ��" << endl;
		if (formula1[i] >= '1' && formula1[i] <= '9')
		{
			//cout << "���ڴ�������" << endl;
			num = (int)formula1[i] - 48;
			Push_LS(s1, num, 1);
			
		}
		if (formula1[i] == '+' || formula1[i] == '-')
		{
			//cout << "���ڴ���Ӽ���" << endl;
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
		//*/ 1.ջ�ա�ջ��'('����'+-'ֱ����ջ�������ջ���м���ֱ������
		if (formula1[i] == '/' || formula1[i] == '*')
		{
			//cout << "���ڴ���˳���" << endl;
		
			Push_LCS(s2, formula1[i]);
			
		}
		if (formula1[i] == '(')//����������ʱֱ�ӽ�ջ
		{
			Push_LCS(s2, formula1[i]);
			
		}
		if (formula1[i] == ')')//����������ʱ���ַ�ջ�ڵķ��ų�ջ���浽������ֱ������������
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
		// cout << "�ӷ�" << d.up<<"/" << d.down << endl;
	 }
	 if (op == '-')
	 {
		 d.up = num1.up * num2.down - num2.up * num1.down;
		 d.down = num1.down * num2.down;
		// cout << "����" << d.up <<"/"<< d.down << endl;
	 }
	 if (op == '*')
	 {
		 d.up = num1.up * num2.up ;
		 d.down = num1.down * num2.down;
		// cout << "�˷�" << d.up <<"/"<< d.down << endl;
	 }
	 if (op == '/')
	 {
		 d.up = num1.up*num2.down;
		 d.down = num1.down * num2.up;
		//	 cout << "����" << d.up <<"/"<< d.down << endl;
		
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
	int a = p.up;//����
	int b = p.down;//��ĸ
	char answer[20] = {};//�����
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

int gcd(int x, int y)//շת����� ,�����������Լ�� 
{
	if (y == 0) return x;
	return gcd(y, x % y);
}
void answercheck()
{
	check = 1;
	cout << "��ӭʹ�ô𰸺˶Թ���" << endl;
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
	cout << "��������Ŀ�ļ���ַ��" << endl;
	cin >> questionsTxt;
	cout << "��������ļ���ַ��" << endl;
	cin >> answersTxt;
	std::ifstream questionsFile(questionsTxt);
	std::ifstream answersFile(answersTxt);
	if (!questionsFile.is_open() || !answersFile.is_open())
	{
		cout << "���ļ�ʧ�ܣ�" << endl;
		return;
	}
	else
		cout << "�򿪳ɹ���" << endl;
	answersFile.close();
	while (questionsFile.getline(questions, 30))
	{
		std::ifstream answersFile(answersTxt);
		//questionsNumber = questions[0];//���

		//����������Ŀ�𰸣���һ������Ϊquesstions[2]���𰸴���ĳһ����
		char temp1[30] = {};
		char temp2[5] = {};
		char temp3[30] = {};
		char answer2[20] = {};
		for (int i = 0; i < 28; i++)
		{
			temp1[i] = questions[i + 2];//������ʽ����
		}
		int j = 0;
		while (questions[j] != '.')
		{
			//cout << "���." << endl;
			temp2[j] = questions[j];                 //�����������
			j++;
		}
		j = 0;
		char string[30] = {};
		
		if (calculate(temp1) == 1)
		{
			strcat_s(string, answerchecks);//�𰸴���string

			//cout << "�𰸣�" << string << endl;
			while (answersFile.getline(answers, 20))
			{


				while (answers[j] != '.')
				{
					temp3[j] = answers[j];//��������
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
					if (strcmp(string, answer2))//�ȶԴ�,�󴢴���Ž�����ȷ�����
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
		cout << "�򿪼�����ļ�ʧ�ܣ�" << endl;
		return;
	}
	else
	{
		cout << "�򿪼�����ļ��ɹ���" << endl;
		cout << correct << wrongNumber << wrongList << endl;
		cout << wrong << correctNumber << correctList << endl;
		gradeFile << correct << wrongNumber << wrongList << endl;
		gradeFile << wrong << correctNumber << correctList << endl;
	}
	gradeFile.close();
	system("pause");
}