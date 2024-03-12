#pragma once
#pragma once
#include <iostream>
#include <string>
#include <fstream>  
#include<io.h> 
#include <locale> 
#include <stdio.h>
#include <iomanip>
#include<algorithm>

using namespace std;
static const int Max = 100000000;
static int dp[2][Max];
class Hanshu
{
public:

	wstring origin = L" ";
	wstring test = L" ";

	wfstream origFile;//原文文件
	wfstream testFile;//改篇文件
	wfstream ansFile;//答案文件
	wstring buf;//暂存字符串


	int lcp(wstring origin, wstring test)
	{
		size_t originsize = origin.size();//得到原文长度

		size_t testsize = test.size();//得到改篇长度


		memset(dp, 0, sizeof(dp));
		unsigned int cur = 0, pre = 1;
		for (unsigned int i = 1; i < unsigned(originsize); i++)
		{
			cur = i & 1;
			pre = cur ^ 1;
			for (unsigned int j = 1; j < unsigned(testsize); j++)
			{
				if (origin[i] == test[j])
					dp[cur][j] = dp[pre][j - 1] + 1;
				else
					dp[cur][j] = max(dp[pre][j], dp[cur][j - 1]);
			}
		}
		return dp[cur][testsize - 1];
	}


	bool check(int argc, char* argv[])//判断命令行地址是否输少或输错
	{
		if (argc != 4)
		{
			cout << "ERROR：参数错误" << endl;
			return false;
		}
		if (_access(argv[1], 00) == -1)
		{
			cout << "Origin adress ERROR" << endl;
			return false;
		}

		if (_access(argv[2], 00) == -1)
		{
			cout << "Test adress ERROR" << endl;
			return false;
		}

		if (_access(argv[3], 00) == -1)
		{
			cout << "Ans adress ERROR" << endl;
			return false;
		}
		return true;
	}
	int checkfileopen()
	{
		while (origFile >> buf)   //通过字符串buf判断输入的字数是否储存溢出
		{
			if (buf.size() > Max)
			{
				printf("origin is too long!\n");
				origFile.close();
				return 0;
			}

			origin += buf;//将字符串放入origin字符串中
			if (origin.size() > Max)
			{
				printf("origin is too long!\n");
				origFile.close();
				return 0;
			}
		}
		origFile.close();
		if (origin.size() == 1)    //检测origin字符串中是否存在文本
		{
			printf("origin is empty\n");
			return 0;
		}
		while (testFile >> buf)
		{
			if (buf.size() > Max)
			{
				printf("test is too long!\n");
				testFile.close();
				return 0;
			}
			test += buf;
			if (test.size() > Max)
			{
				printf("test is too long!\n");
				testFile.close();
				return 0;
			}
		}
		testFile.close();
		if (test.size() == 1)
		{
			printf("add is empty\n");
			return 0;
		}
		return 1;
	}
};




