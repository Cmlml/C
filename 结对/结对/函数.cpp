#include"main.h"
#include"LStack.h"
void make( )
{
	int kind = 0;
	srand((unsigned int)time(NULL)+rand());
	
	char formulamake[200] = {};//ͨ���ַ�����洢����ʽ
	char* string = formulamake;
	//char* formula1 = formula;//ͨ������ָ�뽫�ַ����������
	kind = rand()%3+1;//�������1~3�������ж�ʽ������
	//cout <<"���ࣺ"<< kind << endl;
	fstream fs;
	fs.open("test.txt", ios::out|ios::app);
	switch (kind)
	{
	case 1:
		makeone();
		strcpy_s(formulamake,formula);//����װ�õ�ʽ�Ӹ��Ƹ�formula����
		printf("%s\n", string);
		
		
		break;
	
	 case 2:
		maketwo();
		strcpy_s(formulamake, formula);//����װ�õ�ʽ�Ӹ��Ƹ�formula����
		printf("%s\n", formulamake);
		break;
	case 3:
		makethree();
		strcpy_s(formulamake, formula);//����װ�õ�ʽ�Ӹ��Ƹ�formula����
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
		fs << d1<< ". ";
		d1++;
		while (formulamake[i] != '\0')
		{
			if (formulamake[i] == '/')
			{
				fs << "��";
				i++;
			}
			if (formulamake[i] == '*')
			{
				fs << "��";
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
#pragma endregion//�ж�ʽ���Ƿ����0

	
#pragma region makeone
void makeone()//����һ����������ʽ��
{

	char temp[100] = {};//��temp������������Ͳ����������ʽ��


	char* temp2 = temp;//��ָ��ָ��temp��������
	number();
	strcpy_s(temp, num);//�����������Ƹ�temp����

	operatornum();

	strcat_s(temp, operatorm);

	number();

	strcat_s(temp, num);

	strcpy_s(formula, temp);


}
#pragma endregion//һ��������ʽ�����


#pragma region maketwo
void maketwo()//����������������ʽ��
{
	srand((unsigned int)time(NULL) + rand());
	int a = rand() % 2;//�ж��Ƿ���������
	cout << a << endl;
	int tag = 0;
	
	char temp[100] = {};//��temp������������Ͳ����������ʽ��
	
	number();
	strcpy_s(temp, num);//�����������Ƹ�temp����

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
#pragma endregion//����������ʽ�����

#pragma region makethree
void makethree()//����������������ʽ��
{
	srand((unsigned int)time(NULL) + rand());
	int a = rand() % 2;//�ж��Ƿ���������
	int tag = 0;
	char temp[100] = {};//��temp������������Ͳ����������ʽ��
	number();
	strcpy_s(temp, num);//�����������Ƹ�temp����

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

#pragma endregion//����������ʽ�����

#pragma region operatornum
void operatornum()
{
	//char c[100] = {};
	srand((unsigned int)time(NULL) + rand());
	int kind = rand() % 4;
	// char*operator1=c;//���������
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
#pragma endregion//���������

#pragma region number
void number()//���ɲ�������
{
	srand((unsigned int)time(NULL) + rand());
	
		int number1 = rand() % 5 + rand() % 3+1;
		char c[10] = {};

		if (0 < number1 && number1 < 10)//��������ת�����ַ����ʹ�����ַ�����
		{
			number1 = number1 + 48;

			char temp = (char)number1;
			c[0] = temp;
			strcpy_s(num, c);
			//printf("��������%s\n", num);
		}
}
#pragma endregion//����������


