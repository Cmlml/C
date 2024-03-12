#include "pch.h"
#include "CppUnitTest.h"
#include"../论文查重/main.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		Hanshu person;
		TEST_METHOD(TestMethod1)
		{

			std::wstring origin = L"今天是星期天，天气晴，今天晚上我要去看电影";
			std::wstring test = L"今天是周天，天气晴朗，我晚上要去看电影";

			Assert::AreEqual(15, person.lcp(origin, test));
		}
		TEST_METHOD(TestMethod2)//输入错误地址检测check函数
		{
			char addr1[] = "C:\\Users\\陈家谦\\Djk\\测试文本\\orig.txt";
			char addr2[] = "C:\\Users\\陈家谦\\Desktop\\测试文本\\orig_0.8_add.txt";
			char addr3[] = "C:\\Users\\陈家谦\\Desktop\\测试文本\\answer.txt";
			char* argv[] = { "", addr1, addr2, addr3 };
			Assert::AreEqual(false, person.check(4, argv));

		}
		TEST_METHOD(TestMethod3)
		{
			std::wstring origin = L"";
			std::wstring test = L"";
			Assert::AreEqual(0, person.checkfileopen());

		}
	};
}
