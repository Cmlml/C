#include "pch.h"
#include "CppUnitTest.h"
#include"unittest1.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)//检测有无负数结果
		{
			char test[10] = { '1','-','5','=' };
			int a=calculate(test);
			Assert::AreEqual(-1, a);
		}
		TEST_METHOD(TestMethod2)
		{
			
		}
	};
}
