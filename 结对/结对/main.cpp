#include"main.h"

int main()
{
	for(;;)
	{
		char selectNumber;
		cout << "请选择功能：1.随机生成算式  2.核对答案  3.退出" << endl;
		cin >> selectNumber;
		switch (selectNumber)
		{
		case '1':
			printf("输入数量:\n");
			cin >> n;
			printf("输入大小:\n");
			cin >> r;
			if (n > 0 && r > 0)
			{
				while (n != 0)
				{
					make();
					cout << "已经全部算完" << endl;
					n--;
				}
			}
			break;
		case '2':
			answercheck();
			break;
		case '3':
			exit(1);
		default:
			cout << "输入有误，请重试！" << endl;
			break;
		}

			system("pause");
			return 0;
	}
}