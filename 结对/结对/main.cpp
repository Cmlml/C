#include"main.h"

int main()
{
	for(;;)
	{
		char selectNumber;
		cout << "��ѡ���ܣ�1.���������ʽ  2.�˶Դ�  3.�˳�" << endl;
		cin >> selectNumber;
		switch (selectNumber)
		{
		case '1':
			printf("��������:\n");
			cin >> n;
			printf("�����С:\n");
			cin >> r;
			if (n > 0 && r > 0)
			{
				while (n != 0)
				{
					make();
					cout << "�Ѿ�ȫ������" << endl;
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
			cout << "�������������ԣ�" << endl;
			break;
		}

			system("pause");
			return 0;
	}
}