#include"main.h"
int main(int argc, char* argv[])
{

	setlocale(LC_ALL, "");
	Hanshu person;

	//string orig_adress = "C:\\Users\\�¼�ǫ\\Desktop\\�����ı�\\orig.txt";//ԭ�ĵ�ַ
	//string test_adress = "C:\\Users\\�¼�ǫ\\Desktop\\�����ı�\\orig_0.8_add.txt";//��ƪ��ַ
	//string ans_adress = "C:\\Users\\�¼�ǫ\\Desktop\\�����ı�\\answer.txt";
	string orig_adress = argv[1];//ԭ�ĵ�ַ
	string test_adress = argv[2];//��ƪ��ַ
	string ans_adress = argv[3];
	if (person.check(argc, argv) == false)    //�����ַ������߲��������ֱ�ӱ����˳�
	{
		return 0;
	}
	printf("%s\n", argv[1]);


	person.origFile.open(orig_adress, ios::in);	//���ļ�


	person.testFile.open(test_adress, ios::in);	//���ļ�


	person.ansFile.open(ans_adress, ios::out | ios::app);

	if (!person.origFile.is_open() && !person.testFile.is_open() && !person.ansFile.is_open())
		cout << "�ļ���ʧ�ܣ���鿴�ļ�·����" << endl;

	//���ı������ݴ��ַ����з����Ƿ�������

	if (person.checkfileopen() == 0)
		return 0;


	int ans = person.lcp(person.origin, person.test);

	double rate = (double)ans / (double)person.test.size(); //������

	cout << "�ı�������=" << setprecision(4) << rate * 100 << "%" << endl;
	cout << "�Ѿ���ӡ" << endl;
	person.ansFile << "�����ʣ�" << setprecision(4) << rate * 100 << "%" << endl;
	person.ansFile.close();
	system("pause");
	return 0;
}



