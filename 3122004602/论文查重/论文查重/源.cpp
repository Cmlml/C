#include"main.h"
int main(int argc, char* argv[])
{

	setlocale(LC_ALL, "");
	Hanshu person;

	//string orig_adress = "C:\\Users\\陈家谦\\Desktop\\测试文本\\orig.txt";//原文地址
	//string test_adress = "C:\\Users\\陈家谦\\Desktop\\测试文本\\orig_0.8_add.txt";//改篇地址
	//string ans_adress = "C:\\Users\\陈家谦\\Desktop\\测试文本\\answer.txt";
	string orig_adress = argv[1];//原文地址
	string test_adress = argv[2];//改篇地址
	string ans_adress = argv[3];
	if (person.check(argc, argv) == false)    //如果地址错误或者参数错误会直接报错退出
	{
		return 0;
	}
	printf("%s\n", argv[1]);


	person.origFile.open(orig_adress, ios::in);	//打开文件


	person.testFile.open(test_adress, ios::in);	//打开文件


	person.ansFile.open(ans_adress, ios::out | ios::app);

	if (!person.origFile.is_open() && !person.testFile.is_open() && !person.ansFile.is_open())
		cout << "文件打开失败，请查看文件路径。" << endl;

	//将文本存入暂存字符串中分析是否出现溢出

	if (person.checkfileopen() == 0)
		return 0;


	int ans = person.lcp(person.origin, person.test);

	double rate = (double)ans / (double)person.test.size(); //查重率

	cout << "文本查重率=" << setprecision(4) << rate * 100 << "%" << endl;
	cout << "已经打印" << endl;
	person.ansFile << "查重率：" << setprecision(4) << rate * 100 << "%" << endl;
	person.ansFile.close();
	system("pause");
	return 0;
}



