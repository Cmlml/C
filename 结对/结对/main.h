#pragma once
#include<stdio.h>
#include<iostream>
#include<time.h>
#include<string.h>
#include<fstream>
using namespace std;

static int r;//����ʽ���е���ֵ
static int n;//����ʽ������
static int d1 = 1;//���
static int d2= 1;//���
static char num[100] = {};
static char operatorm[100] = {};
static char formula[100] = {};
static char answerchecks[100] = {};//��������
static int check = 0;
void make();//����ʽ��
void makeone();//����һ����������ʽ��
void maketwo();//����������������ʽ��
void makethree();//����������������ʽ��
void operatornum();//���ɲ�������
void number();//���ɲ�������
int calculate(char formula1[]);//����ʽ�ӽ��м��㺯������׼��
void answercheck();
