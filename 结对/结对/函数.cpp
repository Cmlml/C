#include"main.h"
#include"LStack.h"
void make( )
{
	int kind = 0;
	srand((unsigned int)time(NULL)+rand());
	
	char formulamake[200] = {};//通过字符数组存储计算式
	char* string = formulamake;
	//char* formula1 = formula;//通过数组指针将字符数组带出来
	kind = rand()%3+1;//随机生成1~3的数来判断式子种类
	//cout <<"种类："<< kind << endl;
	fstream fs;
	fs.open("test.txt", ios::out|ios::app);
	switch (kind)
	{
	case 1:
		makeone();
		strcpy_s(formulamake,formula);//将组装好的式子复制给formula数组
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
		fs << d1<< ". ";
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
	
		int number1 = rand() % 5 + rand() % 3+1;
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


