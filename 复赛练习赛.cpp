#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <fstream>
#include <thread>
#include <list>
#include <cstdio>
#include <cstdlib>
#include <time.h>
#include <unordered_map>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>
#include <bits/stdc++.h>
/*==============================================向量solve四线程---全数组*/

using namespace std;
//typedef unsigned long long ull;

#pragma warning(disable:4996)
//#define InAddress  "/data/test_data28W.txt"

//#define InAddress  "/data/test_data_38252_9153.txt"
//#define InAddress  "/data/CG_K16_3.txt"
//#define InAddress  "/data/test_data_19630345.txt"


#define InAddress "/data/test_data.txt"
#define OutAddress	"/projects/student/result.txt"

int cnt = 0;
char* buf;
int length = 0;
int test_data_size;

int user1[2000000] = { 0 };
int user2[2000000] = { 0 };
int tem[4000000] = { 0 };
unordered_map<int, int> idHash;
int nodeCnt = 0;

int vistC[4000000] = { 0 };
int vistR[4000000] = { 0 };
int account[2000000];
vector<vector<int>> GC;
vector<vector<int>> GR;
int first[4000000] = { -1 };
int next_i[4000000] = { -1 };

int length1;
int length2;
int length3;
int length4;
//---------------------------------第一个线程
int len3[6000000 * 3]; int len3Num = 0;
int len4[6000000 * 4]; int len4Num = 0;
int len5[8000000 * 5]; int len5Num = 0;
int len6[10000000 * 6]; int len6Num = 0;
int len7[20000000 * 7]; int len7Num = 0;  int ansNum = 0;

int vis[4000000] = { 0 };//记录节点是否被访问
int VistCut[4000000] = { 0 };//记录3邻域节点状态
int back1step[4000000] = { 0 };
int back2step[4000000] = { 0 };
int back3step[4000000] = { 0 };
int back1Account[4000000] = { 0 };

//----------------------------------第二个线程
int len31[6000000 * 3]; int len3Num1 = 0;
int len41[6000000 * 4]; int len4Num1 = 0;
int len51[8000000 * 5]; int len5Num1 = 0;
int len61[10000000 * 6]; int len6Num1 = 0;
int len71[20000000 * 7]; int len7Num1 = 0;
int ansNum1 = 0;

int		  vis1[4000000] = { 0 };//记录节点是否被访问
int   VistCut1[4000000] = { 0 };//记录3邻域节点状态
int back1step1[4000000] = { 0 };
int back2step1[4000000] = { 0 };
int back3step1[4000000] = { 0 };
int back1Account1[4000000] = { 0 };

//-----------------------------------第三个线程
int len32[6000000 * 3]; int len3Num2 = 0;
int len42[6000000 * 4]; int len4Num2 = 0;
int len52[8000000 * 5]; int len5Num2 = 0;
int len62[10000000 * 6]; int len6Num2 = 0;
int len72[20000000 * 7]; int len7Num2 = 0;
int ansNum2 = 0;

int		  vis2[4000000] = { 0 };//记录节点是否被访问
int   VistCut2[4000000] = { 0 };//记录3邻域节点状态
int back1step2[4000000] = { 0 };
int back2step2[4000000] = { 0 };
int back3step2[4000000] = { 0 };
int back1Account2[4000000] = { 0 };

//-----------------------------------第四个线程
int len33[6000000 * 3]; int len3Num3 = 0;
int len43[6000000 * 4]; int len4Num3 = 0;
int len53[8000000 * 5]; int len5Num3 = 0;
int len63[10000000 * 6]; int len6Num3 = 0;
int len73[20000000 * 7]; int len7Num3 = 0;
int ansNum3 = 0;

int		  vis3[4000000] = { 0 };//记录节点是否被访问
int   VistCut3[4000000] = { 0 };//记录3邻域节点状态
int back1step3[4000000] = { 0 };
int back2step3[4000000] = { 0 };
int back3step3[4000000] = { 0 };
int back1Account3[4000000] = { 0 };
//---------------------------------------------------

//vector<char> c;
char c[10000000 * 10 * 7 * sizeof(char)];//cun3-6的-----------------------------------------注意
int cntc = 0;

//-------------------------------------------------------------------------------------------注意
char char7f1[15000000 * 8 * 10 * sizeof(char)] = { 0 }; int char7fl1 = 0;  int len7fl1 = 0;
char char7f2[15000000 * 8 * 10 * sizeof(char)] = { 0 }; int char7fl2 = 0;  int len7fl2 = 0;
char char7f3[15000000 * 8 * 10 * sizeof(char)] = { 0 }; int char7fl3 = 0;  int len7fl3 = 0;
char char7s1[15000000 * 8 * 10 * sizeof(char)] = { 0 }; int char7sl1 = 0;  int len7sl1 = 0;
char char7s2[15000000 * 8 * 10 * sizeof(char)] = { 0 }; int char7sl2 = 0;  int len7sl2 = 0;
char  char7t[15000000 * 8 * 10 * sizeof(char)] = { 0 }; int char7tl = 0;  int len7tl = 0;
char  char7m[15000000 * 8 * 10 * sizeof(char)] = { 0 }; int char7ml = 0;  int len7ml = 0;

void write3_6();
void int2char(int a[], int len, int timelen);
//void int2char5(int a[], int len, int timelen);
//void int2char6(int a[], int len, int timelen);
void int2char7(int a[], int fir, int end, char res[], int charlen);

void mmwrite(char* ans, char* str, char* c);
void mmwrite1(char* ans, char* str, char* c, char* char7f1, char* char7f2);
void mmwrite2(char* ans, char* str, char* c, char* char7f1, char* char7f2, char* char7f3, char* char7s1);
void mmwrite3(char* ans, char* str, char* c, char* char7f1, char* char7f2, char* char7f3, char* char7s1, char* char7s2, char* char7t, char* char7m);

void forThread(int start, int end);
void forThread1(int start, int end);
void forThread2(int start, int end);
void forThread3(int start, int end);

void frontCut(int beg);
void frontCut1(int beg);
void frontCut2(int beg);
void frontCut3(int beg);

void backCut(int beg);
void backCut1(int beg);
void backCut2(int beg);
void backCut3(int beg);

void forNew(int head);
void forNew1(int head);
void forNew2(int head);
void forNew3(int head);

class Solution {
public:
	//=====================================char2int==========================================
	void char2int(char*& ch)
	{
		int num1[3] = { 0 };
		while (*ch != ',')
		{

			num1[0] = num1[0] * 10 + (int)(*ch - '0');
			ch++;
		}
		ch++;
		while (*ch != ',')
		{
			num1[1] = num1[1] * 10 + (int)(*ch - '0');
			ch++;
		}
		ch++;
		while (*ch != '\r' && *ch != '\n')
		{
			num1[2] = num1[2] * 10 + (int)(*ch - '0');
			ch++;
		}
		ch++;
		if (*ch == '\n') {
			ch++;
		}
		*(user1 + cnt) = num1[0];
		*(user2 + cnt) = num1[1];
		*(account + cnt) = num1[2];
		cnt++;
	}

	//======================================== = readFile========================================== =

	//void readFile()
	//{
	//	FILE* file = freopen(InAddress, "rb", stdin);
	//	//求得文件的大小  
	//	fseek(stdin, 0, SEEK_END);
	//	length = ftell(stdin);
	//	rewind(stdin);
	//	//申请一块能装下整个文件的空间  
	//	buf = (char*)malloc(sizeof(char) * length);
	//	//读文件  
	//	int len = fread(buf, 1, length, stdin);//每次读一个，共读size次  
	//	buf[len] = '\0';
	//	//cout << buf << endl;
	//	char* buffer = buf;
	//	cnt = 0;
	//	while (*buffer != '\0')
	//	{
	//		char2int(buffer);
	//	}
	//	fclose(file);
	//};

	void readFile()
	{
		char* buf = (char*)malloc(2000000 * 35 * sizeof(char));
		int fd = open(InAddress, O_RDONLY, 0666);
		test_data_size = lseek(fd, 0, SEEK_END);
		buf = (char*)mmap(NULL, test_data_size, PROT_WRITE, MAP_PRIVATE, fd, 0);
		//cout << test_data_size << endl;
		buf[test_data_size] = '\0';
		char* buffer = buf;
		while (*buffer != '\0')
		{
			char2int(buffer);
		}
		close(fd);
		//maxNum = (*max_element(user1, (user1 + cnt))) + 1;
	}

	void constructGraph() {
		int j = 0;
		for (int i = 0; i < cnt; i++) {
			tem[j] = user1[i];
			tem[j + 1] = user2[i];
			j += 2;
		}
		sort(tem, tem + j);
		nodeCnt = unique(tem, tem + j) - tem;
		/*sort(user1, user1 + cnt);
		sort(user2, user2 + cnt);*/
		//cout << nodeCnt << endl;
		int g = 0;
		for (int i = 0; i < nodeCnt; i++) {
			idHash[tem[i]] = g++;
		}
		GC = vector<vector<int>>(nodeCnt);
		GR = vector<vector<int>>(nodeCnt);

		int k = 0;
		int sizenum = 0;
		for (int i = 0; i < nodeCnt; i++)
			first[i] = -1;
		for (int i = 0; i < cnt; i++)
			next_i[i] = -1;
		for (int i = 0; i < cnt; i++)
		{
			next_i[i] = first[idHash[user1[i]]];
			first[idHash[user1[i]]] = i;
		}
		for (int i = 0; i < nodeCnt; i++)
		{
			sizenum = 0;
			k = first[i];
			if (k != -1)
			{
				GC[i].push_back(idHash[user2[k]]);
				GC[i].push_back(account[k]);
				sizenum++;
			}
			while (k != -1)
			{
				k = next_i[k];
				if (k >= 0)
				{
					GC[i].push_back(idHash[user2[k]]);
					GC[i].push_back(account[k]);
					sizenum++;
				}
			}
			//sort(GC[i].begin(), GC[i].end());
			//GC[i] = bubbleSort(GC[i], sizenum * 2);
			fastSort(GC[i], 0, sizenum * 2 - 2);
			vistC[i] = 2 * sizenum;
		}

		for (int i = 0; i < nodeCnt; i++)
			first[i] = -1;
		for (int i = 0; i < cnt; i++)
			next_i[i] = -1;
		for (int i = 0; i < cnt; i++)
		{
			next_i[i] = first[idHash[user2[i]]];
			first[idHash[user2[i]]] = i;
		}
		for (int i = 0; i < nodeCnt; i++)
		{
			sizenum = 0;
			k = first[i];
			if (k != -1)
			{
				GR[i].push_back(idHash[user1[k]]);
				GR[i].push_back(account[k]);
				sizenum++;
			}
			while (k != -1)
			{
				k = next_i[k];
				if (k >= 0)
				{
					GR[i].push_back(idHash[user1[k]]);
					GR[i].push_back(account[k]);
					sizenum++;
				}
			}
			//sort(GR[i].begin(), GR[i].end());
			//GR[i] = bubbleSort(GR[i], sizenum * 2);
			fastSort(GR[i], 0, sizenum * 2 - 2);
			vistR[i] = 2 * sizenum;
		}
	}

	//=========================================排序===============================================
	void fastSort(vector<int>& arr, int left, int right)
	{
		if (left >= right)
			return;
		int i, j, base, temp;
		i = left, j = right;
		base = arr[left];  //取最左边的数为基准数
		while (i < j)
		{
			while (arr[j] >= base && i < j)
				j -= 2;
			while (arr[i] <= base && i < j)
				i += 2;
			if (i < j)
			{
				temp = arr[j];
				arr[j] = arr[i];
				arr[i] = temp;
				temp = arr[j + 1];
				arr[j + 1] = arr[i + 1];
				arr[i + 1] = temp;
			}
		}
		//基准数归位
		arr[left] = arr[i];
		arr[i] = base;
		temp = arr[left + 1];
		arr[left + 1] = arr[i + 1];
		arr[i + 1] = temp;
		fastSort(arr, left, i - 2);//递归左边
		fastSort(arr, i + 2, right);//递归右边
	}

	void solve() {
		length1 = nodeCnt / 20;
		length2 = length1 * 3;
		length3 = length1 * 5;
		length4 = nodeCnt;
		//auto t11 = clock();
		thread forOne(forThread, 0, length1);
		//auto t21 = clock();
		thread forTwo(forThread1, length1, length2);
		//auto t31 = clock();
		thread forThree(forThread2, length2, length3);
		//auto t41 = clock();
		thread forFour(forThread3, length3, length4);
		forOne.join();
		//auto t12 = clock();
		forTwo.join();
		//auto t22 = clock();
		forThree.join();
		//auto t32 = clock();
		forFour.join();
		//auto t42 = clock();

		//cout << "T1：" << t12 - t11 << endl;
		//cout << "T2：" << t22 - t21 << endl;
		//cout << "T3：" << t32 - t31 << endl;
		//cout << "T4：" << t42 - t41 << endl;
	}

	//---------------------------多线程输出
	void int2charThread()
	{
		//write3_6();
		//thread theOne(write3_6);
		//thread theTwo(int2char7, len7, 0, len7Num, char7f, char7fl);
		//thread theThree(int2char7, len71, 0, len7Num1, char7s, char7sl);
		//thread theFour(int2char7, len72, 0, len7Num2, char7t, char7tl);
		//thread theFife(int2char7, len73, 0, len7Num3, char7m, char7ml);
		//theOne.join();
		//theTwo.join();
		//theThree.join();
		//theFour.join();
		//theFife.join();


		thread theOne(write3_6);

		thread theTwo(int2char7, len7, 0, len7Num / 3, char7f1, char7fl1);
		thread theThree(int2char7, len7, len7Num / 3, 2 * len7Num / 3, char7f2, char7fl2);
		thread theFour(int2char7, len7, 2 * len7Num / 3, len7Num, char7f3, char7fl3);

		thread theFife(int2char7, len71, 0, len7Num1 / 2, char7s1, char7sl1);
		thread theSix(int2char7, len71, len7Num1 / 2, len7Num1, char7s2, char7sl2);

		thread theSev(int2char7, len72, 0, len7Num2, char7t, char7tl);
		thread theEig(int2char7, len73, 0, len7Num3, char7m, char7ml);

		theOne.join();
		theTwo.join();
		theThree.join();
		theFour.join();
		theFife.join();
		theSix.join();
		theSev.join();
		theEig.join();

	}
	void save() {

		printf("Total Loops %d\n", (int)(ansNum + ansNum1 + ansNum2 + ansNum3));
		int i = 0;
		char str[200];
		FILE* fp = fopen(OutAddress, "w+");
		//写入总数
		sprintf(str, "%d\n", (int)(ansNum + ansNum1 + ansNum2 + ansNum3));
		fwrite(str, sizeof(char), strlen(str), fp);
		//cout << str << endl;
		int2charThread();
		cout << cntc << endl; //811139415
		//printf("Total Loops %d\n", (int)(ansNum + ansNum1 + ansNum2 + ansNum3));
		//cout << &c[0];
		//printf(&c[0]);
		fwrite(&c[0], sizeof(char), cntc, fp);
		//fwrite(&char7f[0], sizeof(char), char7f.size(), fp);
		/*fwrite(&char7s[0], sizeof(char), char7s.size(), fp);
		fwrite(&char7t[0], sizeof(char), char7t.size(), fp);
		fwrite(&char7m[0], sizeof(char), char7m.size(), fp);*/
		fclose(fp);

	}
	void mmapsave() {
		int2charThread();
		printf("Total Loops %d\n", (int)(ansNum + ansNum1 + ansNum2 + ansNum3));
		char str[20];
		sprintf(str, "%d\n", (int)(ansNum + ansNum1 + ansNum2 + ansNum3));
		int result_data_size = strlen(str) + cntc + strlen(char7f1) + strlen(char7f2) + strlen(char7f3) + strlen(char7s1) + strlen(char7s2) + strlen(char7t) + strlen(char7m);
		int fd2 = open(OutAddress, O_RDWR | O_CREAT | O_TRUNC, 0666);
		/* 增大文件大小，以用于映射 */
		off_t lengthh = lseek(fd2, result_data_size - 1, SEEK_END);
		write(fd2, "\0", 1);

		char* ans = (char*)mmap(NULL, lengthh, PROT_READ | PROT_WRITE, MAP_SHARED, fd2, 0);

		/* 写入数据 */
		thread wri(mmwrite, ans, str, c);
		thread wri1(mmwrite1, ans, str, c, char7f1, char7f2);
		thread wri2(mmwrite2, ans, str, c, char7f1, char7f2, char7f3, char7s1);
		thread wri3(mmwrite3, ans, str, c, char7f1, char7f2, char7f3, char7s1, char7s2, char7t, char7m);
		wri.join();
		wri1.join();
		wri2.join();
		wri3.join();


		//memcpy(ans, str, strlen(str));
		//memcpy(ans + strlen(str), &c[0], cntc);
		//memcpy(ans + strlen(str) + cntc, &char7f[0], strlen(char7f));
		//memcpy(ans + strlen(str) + cntc + strlen(char7f), &char7s[0],strlen(char7s));
		//memcpy(ans + strlen(str) + cntc + strlen(char7f) + strlen(char7s), &char7t[0], strlen(char7t));
		//memcpy(ans + strlen(str) + cntc + strlen(char7f) + strlen(char7s) + strlen(char7t), &char7m[0], strlen(char7m));

		close(fd2);
		munmap(ans, lengthh);
	}
};

void mmwrite(char* ans, char* str, char* c)
{
	memcpy(ans, str, strlen(str));
	memcpy(ans + strlen(str), c, strlen(c));
}
void mmwrite1(char* ans, char* str, char* c, char* char7f1, char* char7f2)
{
	memcpy(ans + strlen(str) + strlen(c), char7f1, strlen(char7f1));
	memcpy(ans + strlen(str) + strlen(c) + strlen(char7f1), char7f2, strlen(char7f2));
}
void mmwrite2(char* ans, char* str, char* c, char* char7f1, char* char7f2, char* char7f3, char* char7s1)
{
	memcpy(ans + strlen(str) + strlen(c) + strlen(char7f1) + strlen(char7f2), char7f3, strlen(char7f3));
	memcpy(ans + strlen(str) + strlen(c) + strlen(char7f1) + strlen(char7f2) + strlen(char7f3), char7s1, strlen(char7s1));
}
void mmwrite3(char* ans, char* str, char* c, char* char7f1, char* char7f2, char* char7f3, char* char7s1, char* char7s2, char* char7t, char* char7m)
{
	memcpy(ans + strlen(str) + strlen(c) + strlen(char7f1) + strlen(char7f2) + strlen(char7f3) + strlen(char7s1), char7s2, strlen(char7s2));
	memcpy(ans + strlen(str) + strlen(c) + strlen(char7f1) + strlen(char7f2) + strlen(char7f3) + strlen(char7s1) + strlen(char7s2), char7t, strlen(char7t));
	memcpy(ans + strlen(str) + strlen(c) + strlen(char7f1) + strlen(char7f2) + strlen(char7f3) + strlen(char7s1) + strlen(char7s2) + strlen(char7t), char7m, strlen(char7m));
}


//void mmwrite(char* ans, char* str, char* c, char* char7f)
//{
//	memcpy(ans, str, strlen(str));
//	memcpy(ans + strlen(str), c, cntc);
//	memcpy(ans + strlen(str) + cntc, char7f, strlen(char7f));
//}
//void mmwrite1(char* ans, char* str, char* c, char* char7f, char* char7s, char* char7t)
//{
//	memcpy(ans + strlen(str) + cntc + strlen(char7f), char7s, strlen(char7s));
//	memcpy(ans + strlen(str) + cntc + strlen(char7f) + strlen(char7s), char7t, strlen(char7t));
//}
//void mmwrite2(char* ans, char* str, char* c, char* char7f, char* char7s, char* char7t, char* char7m)
//{
//	memcpy(ans + strlen(str) + cntc + strlen(char7f) + strlen(char7s) + strlen(char7t), char7m, strlen(char7m));
//}

void int2char7(int a[], int fir, int end, char res[], int charlen)
{
	char b[11];
	int cntb = 0;
	int tem = 0;
	for (int i = fir; i < end; i++)
	{
		tem = a[i];
		if (tem == 0)
		{
			res[charlen++] = 0 + 48;
		}
		cntb = 0;
		while (tem != 0) {
			b[cntb] = (tem % 10) + 48;
			cntb++;
			tem = tem / 10;
		}
		for (int j = cntb - 1; j >= 0; j--) {
			res[charlen] = b[j];
			charlen++;

		}
		if ((i + 1) % 7 == 0)
			res[charlen] = '\n';
		else
			res[charlen] = ',';
		charlen++;
	}
	res[charlen] = '\0';
	//cout << &res[0] << endl;
}

void int2char(int a[], int len, int timelen) {
	char b[11];
	int cntb = 0;
	int tem = 0;
	for (int i = 0; i < len; i++) {

		tem = a[i];
		if (tem == 0)
		{
			c[cntc] = 0 + 48;
			cntc++;
		}
		cntb = 0;
		while (tem != 0) {
			b[cntb] = (tem % 10) + 48;
			cntb++;
			tem = tem / 10;
		}
		for (int j = cntb - 1; j >= 0; j--) {
			c[cntc] = b[j];
			cntc++;
		}
		if ((i + 1) % timelen == 0) {
			c[cntc] = '\n';
			cntc++;
		}
		else {
			c[cntc] = ',';
			cntc++;
		}
	}

}
/*
void int2char6(int a[], int len, int timelen) {
	char b[11];
	int cntb = 0;
	int tem = 0;
	for (int i = 0; i < len; i++) {

		tem = a[i];
		if (tem == 0)
		{
			c[cntc] = 0 + 48;
			cntc++;
		}
		cntb = 0;
		while (tem != 0) {
			b[cntb] = (tem % 10) + 48;
			cntb++;
			tem = tem / 10;
		}
		for (int j = cntb - 1; j >= 0; j--) {
			c[cntc] = b[j];
			cntc++;
		}
		if ((i + 1) % timelen == 0) {
			c[cntc] = '\n';
			cntc++;
		}
		else {
			c[cntc] = ',';
			cntc++;
		}
	}

}

void int2char5(int a[], int len, int timelen) {
	char b[11];
	int cntb = 0;
	int tem = 0;
	for (int i = 0; i < len; i++) {

		tem = a[i];
		if (tem == 0)
		{
			c[cntc] = 0 + 48;
			cntc++;
		}
		cntb = 0;
		while (tem != 0) {
			b[cntb] = (tem % 10) + 48;
			cntb++;
			tem = tem / 10;
		}
		for (int j = cntb - 1; j >= 0; j--) {
			c[cntc] = b[j];
			cntc++;
		}
		if ((i + 1) % timelen == 0) {
			c[cntc] = '\n';
			cntc++;
		}
		else {
			c[cntc] = ',';
			cntc++;
		}
	}

}
*/
void write3_6()
{
	int2char(len3, len3Num, 3);
	int2char(len31, len3Num1, 3);
	int2char(len32, len3Num2, 3);
	int2char(len33, len3Num3, 3);

	int2char(len4, len4Num, 4);
	int2char(len41, len4Num1, 4);
	int2char(len42, len4Num2, 4);
	int2char(len43, len4Num3, 4);

	int2char(len5, len5Num, 5);
	int2char(len51, len5Num1, 5);
	int2char(len52, len5Num2, 5);
	int2char(len53, len5Num3, 5);

	int2char(len6, len6Num, 6);
	int2char(len61, len6Num1, 6);
	int2char(len62, len6Num2, 6);
	int2char(len63, len6Num3, 6);

	//int2char(len7, len7Num, 7);
	//int2char(len71, len7Num1, 7);
	//int2char(len72, len7Num2, 7);
	//int2char(len73, len7Num3, 7);

	//c.push_back ('\0');

}

//=======================================线程1==========================
void forThread(int start, int end) {
	for (int i = start; i < end; i++)
	{
		if (!GC[i].empty() && !GR[i].empty()) {
			frontCut(i);
			backCut(i);
			int lin1 = -1;
			int lin2 = -1;
			int lin3 = -1;
			forNew(i);
			//恢复为初始值0的状态
			for (int j = 0; j < vistR[i]; j += 2)
			{
				lin1 = GR[i][j];
				back1step[GR[i][j]] = 0;
				for (int k = 0; k < vistR[lin1]; k += 2)
				{
					lin2 = GR[lin1][k];
					back2step[lin2] = 0;
					for (int q = 0; q < vistR[lin2]; q += 2)
					{
						lin3 = GR[lin2][q];
						back3step[lin3] = 0;
					}
				}
			}
		}
	}
}

//=========================================frontCut前向剪枝====================================
void frontCut(int beg)
{
	for (int i = 0; i < vistC[beg]; i += 2)
	{
		int firs = GC[beg][i];
		int acco1 = GC[beg][i + 1];//1->2 转账金额
	   // int acco1 = migic[(ull)beg << 32 | firs];//1->2 转账金额
		if (firs > beg && vis[firs] == 0)
		{
			VistCut[firs] = beg;
			vis[firs] = 1;
			for (int j = 0; j < vistC[firs]; j += 2)
			{
				int seco = GC[firs][j];
				int acco2 = GC[firs][j + 1];//2->3 转账金额
				//int acco2 = migic[(ull)firs << 32 | seco];//2->3 转账金额
				if (seco > beg && vis[seco] == 0 && 5ll * acco2 >= acco1 && acco2 <= 3ll * acco1)
				{
					VistCut[seco] = beg;
					vis[seco] = 1;
					for (int k = 0; k < vistC[seco]; k += 2)
					{
						int thir = GC[seco][k];
						int acco3 = GC[seco][k + 1];//3->4 转账金额
						//int acco3 = migic[(ull)seco << 32 | thir];//3->4 转账金额
						if (thir > beg && vis[thir] == 0 && 5ll * acco3 >= acco2 && acco3 <= 3ll * acco2)
						{
							VistCut[thir] = beg;
						}
					}
					vis[seco] = 0;
				}
			}
			vis[firs] = 0;
		}
	}
}

//=========================================backCut后向剪枝====================================
void backCut(int beg) {
	//备注：此时后向第一步与前向第一步的金额比较放在for循环中进行！！！
	for (int i = 0; i < vistR[beg]; i += 2)
	{
		int firs = GR[beg][i];
		int acco1 = GR[beg][i + 1];
		//int acco1 = migic[(ull)firs << 32 | beg];
		if (firs > beg && vis[firs] == 0)
		{
			VistCut[firs] = beg;
			back1step[firs] = -1;
			vis[firs] = 1;
			for (int j = 0; j < vistR[firs]; j += 2)
			{
				int seco = GR[firs][j];
				int acco2 = GR[firs][j + 1];
				//int acco2 = migic[(ull)seco << 32 | firs];
				if (seco > beg && vis[seco] == 0 && 5ll * acco1 >= acco2 && acco1 <= 3ll * acco2)
				{
					VistCut[seco] = beg;
					back2step[seco] = -2;
					vis[seco] = 1;
					for (int k = 0; k < vistR[seco]; k += 2)
					{
						int thir = GR[seco][k];
						int acco3 = GR[seco][k + 1];
						//int acco3 = migic[(ull)thir << 32 | seco];
						if (thir > beg && vis[thir] == 0 && 5ll * acco2 >= acco3 && acco2 <= 3ll * acco3)
						{
							VistCut[thir] = beg;
							back3step[thir] = -3;
						}
					}
					vis[seco] = 0;
				}
			}
			vis[firs] = 0;
		}
	}
}

//=============================================forNew循环找环=======================================
void forNew(int head) //第一层
{
	for (int ac = 0; ac < vistR[head]; ac += 2) //后向遍历头结点的邻接节点，为获得转账金额
	{
		int back1 = GR[head][ac];
		int back1acc = GR[head][ac + 1];
		//int back1acc = migic[(ull)back1 << 32 | head];
		back1Account[back1] = back1acc;
	}
	vis[head] = 1;
	int secNode = -1;
	int acco12 = -1;
	for (int sec = 0; sec < vistC[head]; sec += 2)//第二层
	{
		secNode = GC[head][sec];
		acco12 = GC[head][sec + 1];//1->2转账金额
		//acco12 = migic[(ull)head << 32 | secNode];//1->2转账金额
		if (secNode <= head || vis[secNode]) continue;
		vis[secNode] = 1;
		int thiNode = -1;
		int acco23 = -1;
		for (int thi = 0; thi < vistC[secNode]; thi += 2) //第三层
		{
			thiNode = GC[secNode][thi];
			acco23 = GC[secNode][thi + 1];//2->3转账金额
			//acco23 = migic[(ull)secNode << 32 | thiNode];//2->3转账金额
			if (thiNode > head && vis[thiNode] == 0 && VistCut[thiNode] == head && (5ll * acco23 >= acco12) && (acco23 <= 3ll * acco12))
			{
				if (back1step[thiNode] == -1) {//三个节点成环,然后判断金额是否满足条件
					int money31 = back1Account[thiNode];
					bool flag1 = (5ll * acco12 >= money31) && (acco12 <= 3ll * money31);
					bool flag2 = (5ll * money31 >= acco23) && (money31 <= 3ll * acco23);
					if (flag1 && flag2)
					{
						len3[len3Num] = tem[head];
						len3[len3Num + 1] = tem[secNode];
						len3[len3Num + 2] = tem[thiNode];
						len3Num += 3;
						ansNum++;
					}
				}
				vis[thiNode] = 1;
				int fouNode = -1;
				int acco34 = -1;
				for (int fou = 0; fou < vistC[thiNode]; fou += 2)//第四层
				{
					fouNode = GC[thiNode][fou];
					acco34 = GC[thiNode][fou + 1];//3->4转账金额
					//acco34 = migic[(ull)thiNode << 32 | fouNode];//3->4转账金额
					if (fouNode > head && vis[fouNode] == 0 && VistCut[fouNode] == head && (5ll * acco34 >= acco23) && (acco34 <= 3ll * acco23))
					{
						if (back1step[fouNode] == -1) {//四个节点成环
							int money41 = back1Account[fouNode];
							bool flag1 = (5ll * acco12 >= money41) && (acco12 <= 3ll * money41);
							bool flag2 = (5ll * money41 >= acco34) && (money41 <= 3ll * acco34);
							if (flag1 && flag2)
							{
								len4[len4Num] = tem[head];
								len4[len4Num + 1] = tem[secNode];
								len4[len4Num + 2] = tem[thiNode];
								len4[len4Num + 3] = tem[fouNode];
								len4Num += 4;
								ansNum++;
							}
						}
						vis[fouNode] = 1;
						int fifNode = -1;
						int acco45 = -1;
						for (int fif = 0; fif < vistC[fouNode]; fif += 2) //第五层
						{
							fifNode = GC[fouNode][fif];
							acco45 = GC[fouNode][fif + 1];//4->5转账金额
							//acco45 = migic[(ull)fouNode << 32 | fifNode];//4->5转账金额
							if (fifNode > head && vis[fifNode] == 0 && VistCut[fifNode] == head && (back1step[fifNode] == -1 || back2step[fifNode] == -2 || back3step[fifNode] == -3) && (5ll * acco45 >= acco34) && (acco45 <= 3ll * acco34))
							{
								if (back1step[fifNode] == -1) {//五个节点的环
									int money51 = back1Account[fifNode];
									bool flag1 = (5ll * acco12 >= money51) && (acco12 <= 3ll * money51);
									bool flag2 = (5ll * money51 >= acco45) && (money51 <= 3ll * acco45);
									if (flag1 && flag2)
									{
										len5[len5Num] = tem[head];
										len5[len5Num + 1] = tem[secNode];
										len5[len5Num + 2] = tem[thiNode];
										len5[len5Num + 3] = tem[fouNode];
										len5[len5Num + 4] = tem[fifNode];
										len5Num += 5;
										ansNum++;
									}
								}
								vis[fifNode] = 1;
								int sixNode = -1;
								int acco56 = -1;
								for (int six = 0; six < vistC[fifNode]; six += 2) //第六层
								{
									sixNode = GC[fifNode][six];
									acco56 = GC[fifNode][six + 1];//5->6转账金额
								   // acco56 = migic[(ull)fifNode << 32 | sixNode];//5->6转账金额
									if (sixNode > head && vis[sixNode] == 0 && VistCut[sixNode] == head && (back1step[sixNode] == -1 || back2step[sixNode] == -2) && (5ll * acco56 >= acco45) && (acco56 <= 3ll * acco45))
									{
										if (back1step[sixNode] == -1) {//六个节点的环
											int money61 = back1Account[sixNode];
											bool flag1 = (5ll * acco12 >= money61) && (acco12 <= 3ll * money61);
											bool flag2 = (5ll * money61 >= acco56) && (money61 <= 3ll * acco56);
											if (flag1 && flag2)
											{
												len6[len6Num] = tem[head];
												len6[len6Num + 1] = tem[secNode];
												len6[len6Num + 2] = tem[thiNode];
												len6[len6Num + 3] = tem[fouNode];
												len6[len6Num + 4] = tem[fifNode];
												len6[len6Num + 5] = tem[sixNode];
												len6Num += 6;
												ansNum++;
											}
										}
										vis[sixNode] = 1;
										int sevNode = -1;
										int acco67 = -1;
										for (int sev = 0; sev < vistC[sixNode]; sev += 2) //第七层
										{
											sevNode = GC[sixNode][sev];
											acco67 = GC[sixNode][sev + 1];//6->7转账金额
										  //  acco67 = migic[(ull)sixNode << 32 | sevNode];//6->7转账金额
											if (sevNode > head && vis[sevNode] == 0 && VistCut[sevNode] == head && (5ll * acco67 >= acco56) && (acco67 <= 3ll * acco56))
											{
												if (back1step[sevNode] == -1) {//七个节点的环
													int money71 = back1Account[sevNode];
													bool flag1 = (5ll * acco12 >= money71) && (acco12 <= 3ll * money71);
													bool flag2 = (5ll * money71 >= acco67) && (money71 <= 3ll * acco67);
													if (flag1 && flag2)
													{
														//len7.push_back(tem[head]);
														//len7.push_back(tem[secNode]);
														//len7.push_back(tem[thiNode]);
														//len7.push_back(tem[fouNode]);
														//len7.push_back(tem[fifNode]);
														//len7.push_back(tem[sixNode]);
														//len7.push_back(tem[sevNode]);
														len7[len7Num] = tem[head];
														len7[len7Num + 1] = tem[secNode];
														len7[len7Num + 2] = tem[thiNode];
														len7[len7Num + 3] = tem[fouNode];
														len7[len7Num + 4] = tem[fifNode];
														len7[len7Num + 5] = tem[sixNode];
														len7[len7Num + 6] = tem[sevNode];
														len7Num += 7;
														ansNum++;
													}
												}
											}
										}
										vis[sixNode] = false;
									}
								}
								vis[fifNode] = false;
							}
						}
						vis[fouNode] = false;
					}
				}
				vis[thiNode] = false;
			}
		}
		vis[secNode] = false;
	}
	vis[head] = false;
}
//=======================================线程2==========================
void forThread1(int start, int end) {
	for (int i = start; i < end; i++)
	{
		if (!GC[i].empty() && !GR[i].empty()) {
			frontCut1(i);
			backCut1(i);
			int lin1 = -1;
			int lin2 = -1;
			int lin3 = -1;
			forNew1(i);
			//恢复为初始值0的状态
			for (int j = 0; j < vistR[i]; j += 2)
			{
				lin1 = GR[i][j];
				back1step1[GR[i][j]] = 0;
				for (int k = 0; k < vistR[lin1]; k += 2)
				{
					lin2 = GR[lin1][k];
					back2step1[lin2] = 0;
					for (int q = 0; q < vistR[lin2]; q += 2)
					{
						lin3 = GR[lin2][q];
						back3step1[lin3] = 0;
					}
				}
			}
		}
	}
}

//=========================================frontCut前向剪枝====================================
void frontCut1(int beg)
{
	for (int i = 0; i < vistC[beg]; i += 2)
	{
		int firs = GC[beg][i];
		int acco1 = GC[beg][i + 1];//1->2 转账金额
	   // int acco1 = migic[(ull)beg << 32 | firs];//1->2 转账金额
		if (firs > beg && vis1[firs] == 0)
		{
			VistCut1[firs] = beg;
			vis1[firs] = 1;
			for (int j = 0; j < vistC[firs]; j += 2)
			{
				int seco = GC[firs][j];
				int acco2 = GC[firs][j + 1];//2->3 转账金额
				//int acco2 = migic[(ull)firs << 32 | seco];//2->3 转账金额
				if (seco > beg && vis1[seco] == 0 && 5ll * acco2 >= acco1 && acco2 <= 3ll * acco1)
				{
					VistCut1[seco] = beg;
					vis1[seco] = 1;
					for (int k = 0; k < vistC[seco]; k += 2)
					{
						int thir = GC[seco][k];
						int acco3 = GC[seco][k + 1];//3->4 转账金额
						//int acco3 = migic[(ull)seco << 32 | thir];//3->4 转账金额
						if (thir > beg && vis1[thir] == 0 && 5ll * acco3 >= acco2 && acco3 <= 3ll * acco2)
						{
							VistCut1[thir] = beg;
						}
					}
					vis1[seco] = 0;
				}
			}
			vis1[firs] = 0;
		}
	}
}

//=========================================backCut后向剪枝====================================
void backCut1(int beg) {
	//备注：此时后向第一步与前向第一步的金额比较放在for循环中进行！！！
	for (int i = 0; i < vistR[beg]; i += 2)
	{
		int firs = GR[beg][i];
		int acco1 = GR[beg][i + 1];
		//int acco1 = migic[(ull)firs << 32 | beg];
		if (firs > beg && vis1[firs] == 0)
		{
			VistCut1[firs] = beg;
			back1step1[firs] = -1;
			vis1[firs] = 1;
			for (int j = 0; j < vistR[firs]; j += 2)
			{
				int seco = GR[firs][j];
				int acco2 = GR[firs][j + 1];
				//int acco2 = migic[(ull)seco << 32 | firs];
				if (seco > beg && vis1[seco] == 0 && 5ll * acco1 >= acco2 && acco1 <= 3ll * acco2)
				{
					VistCut1[seco] = beg;
					back2step1[seco] = -2;
					vis1[seco] = 1;
					for (int k = 0; k < vistR[seco]; k += 2)
					{
						int thir = GR[seco][k];
						int acco3 = GR[seco][k + 1];
						//int acco3 = migic[(ull)thir << 32 | seco];
						if (thir > beg && vis1[thir] == 0 && 5ll * acco2 >= acco3 && acco2 <= 3ll * acco3)
						{
							VistCut1[thir] = beg;
							back3step1[thir] = -3;
						}
					}
					vis1[seco] = 0;
				}
			}
			vis1[firs] = 0;
		}
	}
}

//=============================================forNew循环找环=======================================
void forNew1(int head) //第一层
{
	for (int ac = 0; ac < vistR[head]; ac += 2) //后向遍历头结点的邻接节点，为获得转账金额
	{
		int back1 = GR[head][ac];
		int back1acc = GR[head][ac + 1];
		//int back1acc = migic[(ull)back1 << 32 | head];
		back1Account1[back1] = back1acc;
	}
	vis1[head] = 1;
	int secNode = -1;
	int acco12 = -1;
	for (int sec = 0; sec < vistC[head]; sec += 2)//第二层
	{
		secNode = GC[head][sec];
		acco12 = GC[head][sec + 1];//1->2转账金额
		//acco12 = migic[(ull)head << 32 | secNode];//1->2转账金额
		if (secNode <= head || vis1[secNode]) continue;
		vis1[secNode] = 1;
		int thiNode = -1;
		int acco23 = -1;
		for (int thi = 0; thi < vistC[secNode]; thi += 2) //第三层
		{
			thiNode = GC[secNode][thi];
			acco23 = GC[secNode][thi + 1];//2->3转账金额
			//acco23 = migic[(ull)secNode << 32 | thiNode];//2->3转账金额
			if (thiNode > head && vis1[thiNode] == 0 && VistCut1[thiNode] == head && (5ll * acco23 >= acco12) && (acco23 <= 3ll * acco12))
			{
				if (back1step1[thiNode] == -1) {//三个节点成环,然后判断金额是否满足条件
					int money31 = back1Account1[thiNode];
					bool flag1 = (5ll * acco12 >= money31) && (acco12 <= 3ll * money31);
					bool flag2 = (5ll * money31 >= acco23) && (money31 <= 3ll * acco23);
					if (flag1 && flag2)
					{
						len31[len3Num1] = tem[head];
						len31[len3Num1 + 1] = tem[secNode];
						len31[len3Num1 + 2] = tem[thiNode];
						len3Num1 += 3;
						ansNum1++;
					}
				}
				vis1[thiNode] = 1;
				int fouNode = -1;
				int acco34 = -1;
				for (int fou = 0; fou < vistC[thiNode]; fou += 2)//第四层
				{
					fouNode = GC[thiNode][fou];
					acco34 = GC[thiNode][fou + 1];//3->4转账金额
					//acco34 = migic[(ull)thiNode << 32 | fouNode];//3->4转账金额
					if (fouNode > head && vis1[fouNode] == 0 && VistCut1[fouNode] == head && (5ll * acco34 >= acco23) && (acco34 <= 3ll * acco23))
					{
						if (back1step1[fouNode] == -1) {//四个节点成环
							int money41 = back1Account1[fouNode];
							bool flag1 = (5ll * acco12 >= money41) && (acco12 <= 3ll * money41);
							bool flag2 = (5ll * money41 >= acco34) && (money41 <= 3ll * acco34);
							if (flag1 && flag2)
							{
								len41[len4Num1] = tem[head];
								len41[len4Num1 + 1] = tem[secNode];
								len41[len4Num1 + 2] = tem[thiNode];
								len41[len4Num1 + 3] = tem[fouNode];
								len4Num1 += 4;
								ansNum1++;
							}
						}
						vis1[fouNode] = 1;
						int fifNode = -1;
						int acco45 = -1;
						for (int fif = 0; fif < vistC[fouNode]; fif += 2) //第五层
						{
							fifNode = GC[fouNode][fif];
							acco45 = GC[fouNode][fif + 1];//4->5转账金额
							//acco45 = migic[(ull)fouNode << 32 | fifNode];//4->5转账金额
							if (fifNode > head && vis1[fifNode] == 0 && VistCut1[fifNode] == head && (back1step1[fifNode] == -1 || back2step1[fifNode] == -2 || back3step1[fifNode] == -3) && (5ll * acco45 >= acco34) && (acco45 <= 3ll * acco34))
							{
								if (back1step1[fifNode] == -1) {//五个节点的环
									int money51 = back1Account1[fifNode];
									bool flag1 = (5ll * acco12 >= money51) && (acco12 <= 3ll * money51);
									bool flag2 = (5ll * money51 >= acco45) && (money51 <= 3ll * acco45);
									if (flag1 && flag2)
									{
										len51[len5Num1] = tem[head];
										len51[len5Num1 + 1] = tem[secNode];
										len51[len5Num1 + 2] = tem[thiNode];
										len51[len5Num1 + 3] = tem[fouNode];
										len51[len5Num1 + 4] = tem[fifNode];
										len5Num1 += 5;
										ansNum1++;
									}
								}
								vis1[fifNode] = 1;
								int sixNode = -1;
								int acco56 = -1;
								for (int six = 0; six < vistC[fifNode]; six += 2) //第六层
								{
									sixNode = GC[fifNode][six];
									acco56 = GC[fifNode][six + 1];//5->6转账金额
								   // acco56 = migic[(ull)fifNode << 32 | sixNode];//5->6转账金额
									if (sixNode > head && vis1[sixNode] == 0 && VistCut1[sixNode] == head && (back1step1[sixNode] == -1 || back2step1[sixNode] == -2) && (5ll * acco56 >= acco45) && (acco56 <= 3ll * acco45))
									{
										if (back1step1[sixNode] == -1) {//六个节点的环
											int money61 = back1Account1[sixNode];
											bool flag1 = (5ll * acco12 >= money61) && (acco12 <= 3ll * money61);
											bool flag2 = (5ll * money61 >= acco56) && (money61 <= 3ll * acco56);
											if (flag1 && flag2)
											{
												len61[len6Num1] = tem[head];
												len61[len6Num1 + 1] = tem[secNode];
												len61[len6Num1 + 2] = tem[thiNode];
												len61[len6Num1 + 3] = tem[fouNode];
												len61[len6Num1 + 4] = tem[fifNode];
												len61[len6Num1 + 5] = tem[sixNode];
												len6Num1 += 6;
												ansNum1++;
											}
										}
										vis1[sixNode] = 1;
										int sevNode = -1;
										int acco67 = -1;
										for (int sev = 0; sev < vistC[sixNode]; sev += 2) //第七层
										{
											sevNode = GC[sixNode][sev];
											acco67 = GC[sixNode][sev + 1];//6->7转账金额
										  //  acco67 = migic[(ull)sixNode << 32 | sevNode];//6->7转账金额
											if (sevNode > head && vis1[sevNode] == 0 && VistCut1[sevNode] == head && (5ll * acco67 >= acco56) && (acco67 <= 3ll * acco56))
											{
												if (back1step1[sevNode] == -1) {//七个节点的环
													int money71 = back1Account1[sevNode];
													bool flag1 = (5ll * acco12 >= money71) && (acco12 <= 3ll * money71);
													bool flag2 = (5ll * money71 >= acco67) && (money71 <= 3ll * acco67);
													if (flag1 && flag2)
													{
														//len71.push_back(tem[head]);
														//len71.push_back(tem[secNode]);
														//len71.push_back(tem[thiNode]);
														//len71.push_back(tem[fouNode]);
														//len71.push_back(tem[fifNode]);
														//len71.push_back(tem[sixNode]);
														//len71.push_back(tem[sevNode]);
														len71[len7Num1] = tem[head];
														len71[len7Num1 + 1] = tem[secNode];
														len71[len7Num1 + 2] = tem[thiNode];
														len71[len7Num1 + 3] = tem[fouNode];
														len71[len7Num1 + 4] = tem[fifNode];
														len71[len7Num1 + 5] = tem[sixNode];
														len71[len7Num1 + 6] = tem[sevNode];
														len7Num1 += 7;
														ansNum1++;
													}
												}
											}
										}
										vis1[sixNode] = false;
									}
								}
								vis1[fifNode] = false;
							}
						}
						vis1[fouNode] = false;
					}
				}
				vis1[thiNode] = false;
			}
		}
		vis1[secNode] = false;
	}
	vis1[head] = false;
}

//=======================================线程3==========================
void forThread2(int start, int end) {
	for (int i = start; i < end; i++)
	{
		if (!GC[i].empty() && !GR[i].empty()) {
			frontCut2(i);
			backCut2(i);
			int lin1 = -1;
			int lin2 = -1;
			int lin3 = -1;
			forNew2(i);
			//恢复为初始值0的状态
			for (int j = 0; j < vistR[i]; j += 2)
			{
				lin1 = GR[i][j];
				back1step2[GR[i][j]] = 0;
				for (int k = 0; k < vistR[lin1]; k += 2)
				{
					lin2 = GR[lin1][k];
					back2step2[lin2] = 0;
					for (int q = 0; q < vistR[lin2]; q += 2)
					{
						lin3 = GR[lin2][q];
						back3step2[lin3] = 0;
					}
				}
			}
		}
	}
}

//=========================================frontCut前向剪枝====================================
void frontCut2(int beg)
{
	for (int i = 0; i < vistC[beg]; i += 2)
	{
		int firs = GC[beg][i];
		int acco1 = GC[beg][i + 1];//1->2 转账金额
	   // int acco1 = migic[(ull)beg << 32 | firs];//1->2 转账金额
		if (firs > beg && vis2[firs] == 0)
		{
			VistCut2[firs] = beg;
			vis2[firs] = 1;
			for (int j = 0; j < vistC[firs]; j += 2)
			{
				int seco = GC[firs][j];
				int acco2 = GC[firs][j + 1];//2->3 转账金额
				//int acco2 = migic[(ull)firs << 32 | seco];//2->3 转账金额
				if (seco > beg && vis2[seco] == 0 && 5ll * acco2 >= acco1 && acco2 <= 3ll * acco1)
				{
					VistCut2[seco] = beg;
					vis2[seco] = 1;
					for (int k = 0; k < vistC[seco]; k += 2)
					{
						int thir = GC[seco][k];
						int acco3 = GC[seco][k + 1];//3->4 转账金额
						//int acco3 = migic[(ull)seco << 32 | thir];//3->4 转账金额
						if (thir > beg && vis2[thir] == 0 && 5ll * acco3 >= acco2 && acco3 <= 3ll * acco2)
						{
							VistCut2[thir] = beg;
						}
					}
					vis2[seco] = 0;
				}
			}
			vis2[firs] = 0;
		}
	}
}

//=========================================backCut后向剪枝====================================
void backCut2(int beg) {
	//备注：此时后向第一步与前向第一步的金额比较放在for循环中进行！！！
	for (int i = 0; i < vistR[beg]; i += 2)
	{
		int firs = GR[beg][i];
		int acco1 = GR[beg][i + 1];
		//int acco1 = migic[(ull)firs << 32 | beg];
		if (firs > beg && vis2[firs] == 0)
		{
			VistCut2[firs] = beg;
			back1step2[firs] = -1;
			vis2[firs] = 1;
			for (int j = 0; j < vistR[firs]; j += 2)
			{
				int seco = GR[firs][j];
				int acco2 = GR[firs][j + 1];
				//int acco2 = migic[(ull)seco << 32 | firs];
				if (seco > beg && vis2[seco] == 0 && 5ll * acco1 >= acco2 && acco1 <= 3ll * acco2)
				{
					VistCut2[seco] = beg;
					back2step2[seco] = -2;
					vis2[seco] = 1;
					for (int k = 0; k < vistR[seco]; k += 2)
					{
						int thir = GR[seco][k];
						int acco3 = GR[seco][k + 1];
						//int acco3 = migic[(ull)thir << 32 | seco];
						if (thir > beg && vis2[thir] == 0 && 5ll * acco2 >= acco3 && acco2 <= 3ll * acco3)
						{
							VistCut2[thir] = beg;
							back3step2[thir] = -3;
						}
					}
					vis2[seco] = 0;
				}
			}
			vis2[firs] = 0;
		}
	}
}

//=============================================forNew循环找环=======================================
void forNew2(int head) //第一层
{
	for (int ac = 0; ac < vistR[head]; ac += 2) //后向遍历头结点的邻接节点，为获得转账金额
	{
		int back1 = GR[head][ac];
		int back1acc = GR[head][ac + 1];
		//int back1acc = migic[(ull)back1 << 32 | head];
		back1Account2[back1] = back1acc;
	}
	vis2[head] = 1;
	int secNode = -1;
	int acco12 = -1;
	for (int sec = 0; sec < vistC[head]; sec += 2)//第二层
	{
		secNode = GC[head][sec];
		acco12 = GC[head][sec + 1];//1->2转账金额
		//acco12 = migic[(ull)head << 32 | secNode];//1->2转账金额
		if (secNode <= head || vis2[secNode]) continue;
		vis2[secNode] = 1;
		int thiNode = -1;
		int acco23 = -1;
		for (int thi = 0; thi < vistC[secNode]; thi += 2) //第三层
		{
			thiNode = GC[secNode][thi];
			acco23 = GC[secNode][thi + 1];//2->3转账金额
			//acco23 = migic[(ull)secNode << 32 | thiNode];//2->3转账金额
			if (thiNode > head && vis2[thiNode] == 0 && VistCut2[thiNode] == head && (5ll * acco23 >= acco12) && (acco23 <= 3ll * acco12))
			{
				if (back1step2[thiNode] == -1) {//三个节点成环,然后判断金额是否满足条件
					int money31 = back1Account2[thiNode];
					bool flag1 = (5ll * acco12 >= money31) && (acco12 <= 3ll * money31);
					bool flag2 = (5ll * money31 >= acco23) && (money31 <= 3ll * acco23);
					if (flag1 && flag2)
					{
						len32[len3Num2] = tem[head];
						len32[len3Num2 + 1] = tem[secNode];
						len32[len3Num2 + 2] = tem[thiNode];
						len3Num2 += 3;
						ansNum2++;
					}
				}
				vis2[thiNode] = 1;
				int fouNode = -1;
				int acco34 = -1;
				for (int fou = 0; fou < vistC[thiNode]; fou += 2)//第四层
				{
					fouNode = GC[thiNode][fou];
					acco34 = GC[thiNode][fou + 1];//3->4转账金额
					//acco34 = migic[(ull)thiNode << 32 | fouNode];//3->4转账金额
					if (fouNode > head && vis2[fouNode] == 0 && VistCut2[fouNode] == head && (5ll * acco34 >= acco23) && (acco34 <= 3ll * acco23))
					{
						if (back1step2[fouNode] == -1) {//四个节点成环
							int money41 = back1Account2[fouNode];
							bool flag1 = (5ll * acco12 >= money41) && (acco12 <= 3ll * money41);
							bool flag2 = (5ll * money41 >= acco34) && (money41 <= 3ll * acco34);
							if (flag1 && flag2)
							{
								len42[len4Num2] = tem[head];
								len42[len4Num2 + 1] = tem[secNode];
								len42[len4Num2 + 2] = tem[thiNode];
								len42[len4Num2 + 3] = tem[fouNode];
								len4Num2 += 4;
								ansNum2++;
							}
						}
						vis2[fouNode] = 1;
						int fifNode = -1;
						int acco45 = -1;
						for (int fif = 0; fif < vistC[fouNode]; fif += 2) //第五层
						{
							fifNode = GC[fouNode][fif];
							acco45 = GC[fouNode][fif + 1];//4->5转账金额
							//acco45 = migic[(ull)fouNode << 32 | fifNode];//4->5转账金额
							if (fifNode > head && vis2[fifNode] == 0 && VistCut2[fifNode] == head && (back1step2[fifNode] == -1 || back2step2[fifNode] == -2 || back3step2[fifNode] == -3) && (5ll * acco45 >= acco34) && (acco45 <= 3ll * acco34))
							{
								if (back1step2[fifNode] == -1) {//五个节点的环
									int money51 = back1Account2[fifNode];
									bool flag1 = (5ll * acco12 >= money51) && (acco12 <= 3ll * money51);
									bool flag2 = (5ll * money51 >= acco45) && (money51 <= 3ll * acco45);
									if (flag1 && flag2)
									{
										len52[len5Num2] = tem[head];
										len52[len5Num2 + 1] = tem[secNode];
										len52[len5Num2 + 2] = tem[thiNode];
										len52[len5Num2 + 3] = tem[fouNode];
										len52[len5Num2 + 4] = tem[fifNode];
										len5Num2 += 5;
										ansNum2++;
									}
								}
								vis2[fifNode] = 1;
								int sixNode = -1;
								int acco56 = -1;
								for (int six = 0; six < vistC[fifNode]; six += 2) //第六层
								{
									sixNode = GC[fifNode][six];
									acco56 = GC[fifNode][six + 1];//5->6转账金额
								   // acco56 = migic[(ull)fifNode << 32 | sixNode];//5->6转账金额
									if (sixNode > head && vis2[sixNode] == 0 && VistCut2[sixNode] == head && (back1step2[sixNode] == -1 || back2step2[sixNode] == -2) && (5ll * acco56 >= acco45) && (acco56 <= 3ll * acco45))
									{
										if (back1step2[sixNode] == -1) {//六个节点的环
											int money61 = back1Account2[sixNode];
											bool flag1 = (5ll * acco12 >= money61) && (acco12 <= 3ll * money61);
											bool flag2 = (5ll * money61 >= acco56) && (money61 <= 3ll * acco56);
											if (flag1 && flag2)
											{
												len62[len6Num2] = tem[head];
												len62[len6Num2 + 1] = tem[secNode];
												len62[len6Num2 + 2] = tem[thiNode];
												len62[len6Num2 + 3] = tem[fouNode];
												len62[len6Num2 + 4] = tem[fifNode];
												len62[len6Num2 + 5] = tem[sixNode];
												len6Num2 += 6;
												ansNum2++;
											}
										}
										vis2[sixNode] = 1;
										int sevNode = -1;
										int acco67 = -1;
										for (int sev = 0; sev < vistC[sixNode]; sev += 2) //第七层
										{
											sevNode = GC[sixNode][sev];
											acco67 = GC[sixNode][sev + 1];//6->7转账金额
										  //  acco67 = migic[(ull)sixNode << 32 | sevNode];//6->7转账金额
											if (sevNode > head && vis2[sevNode] == 0 && VistCut2[sevNode] == head && (5ll * acco67 >= acco56) && (acco67 <= 3ll * acco56))
											{
												if (back1step2[sevNode] == -1) {//七个节点的环
													int money71 = back1Account2[sevNode];
													bool flag1 = (5ll * acco12 >= money71) && (acco12 <= 3ll * money71);
													bool flag2 = (5ll * money71 >= acco67) && (money71 <= 3ll * acco67);
													if (flag1 && flag2)
													{
														//len72.push_back(tem[head]);
														//len72.push_back(tem[secNode]);
														//len72.push_back(tem[thiNode]);
														//len72.push_back(tem[fouNode]);
														//len72.push_back(tem[fifNode]);
														//len72.push_back(tem[sixNode]);
														//len72.push_back(tem[sevNode]);
														len72[len7Num2] = tem[head];
														len72[len7Num2 + 1] = tem[secNode];
														len72[len7Num2 + 2] = tem[thiNode];
														len72[len7Num2 + 3] = tem[fouNode];
														len72[len7Num2 + 4] = tem[fifNode];
														len72[len7Num2 + 5] = tem[sixNode];
														len72[len7Num2 + 6] = tem[sevNode];
														len7Num2 += 7;
														ansNum2++;
													}
												}
											}
										}
										vis2[sixNode] = false;
									}
								}
								vis2[fifNode] = false;
							}
						}
						vis2[fouNode] = false;
					}
				}
				vis2[thiNode] = false;
			}
		}
		vis2[secNode] = false;
	}
	vis2[head] = false;
}

//=======================================线程4==========================
void forThread3(int start, int end) {
	for (int i = start; i < end; i++)
	{
		if (!GC[i].empty() && !GR[i].empty()) {
			frontCut3(i);
			backCut3(i);
			int lin1 = -1;
			int lin2 = -1;
			int lin3 = -1;
			forNew3(i);
			//恢复为初始值0的状态
			for (int j = 0; j < vistR[i]; j += 2)
			{
				lin1 = GR[i][j];
				back1step3[GR[i][j]] = 0;
				for (int k = 0; k < vistR[lin1]; k += 2)
				{
					lin2 = GR[lin1][k];
					back2step3[lin2] = 0;
					for (int q = 0; q < vistR[lin2]; q += 2)
					{
						lin3 = GR[lin2][q];
						back3step3[lin3] = 0;
					}
				}
			}
		}
	}
}

//=========================================frontCut前向剪枝====================================
void frontCut3(int beg)
{
	for (int i = 0; i < vistC[beg]; i += 2)
	{
		int firs = GC[beg][i];
		int acco1 = GC[beg][i + 1];//1->2 转账金额
	   // int acco1 = migic[(ull)beg << 32 | firs];//1->2 转账金额
		if (firs > beg && vis3[firs] == 0)
		{
			VistCut3[firs] = beg;
			vis3[firs] = 1;
			for (int j = 0; j < vistC[firs]; j += 2)
			{
				int seco = GC[firs][j];
				int acco2 = GC[firs][j + 1];//2->3 转账金额
				//int acco2 = migic[(ull)firs << 32 | seco];//2->3 转账金额
				if (seco > beg && vis3[seco] == 0 && 5ll * acco2 >= acco1 && acco2 <= 3ll * acco1)
				{
					VistCut3[seco] = beg;
					vis3[seco] = 1;
					for (int k = 0; k < vistC[seco]; k += 2)
					{
						int thir = GC[seco][k];
						int acco3 = GC[seco][k + 1];//3->4 转账金额
						//int acco3 = migic[(ull)seco << 32 | thir];//3->4 转账金额
						if (thir > beg && vis3[thir] == 0 && 5ll * acco3 >= acco2 && acco3 <= 3ll * acco2)
						{
							VistCut3[thir] = beg;
						}
					}
					vis3[seco] = 0;
				}
			}
			vis3[firs] = 0;
		}
	}
}

//=========================================backCut后向剪枝====================================
void backCut3(int beg) {
	//备注：此时后向第一步与前向第一步的金额比较放在for循环中进行！！！
	for (int i = 0; i < vistR[beg]; i += 2)
	{
		int firs = GR[beg][i];
		int acco1 = GR[beg][i + 1];
		//int acco1 = migic[(ull)firs << 32 | beg];
		if (firs > beg && vis3[firs] == 0)
		{
			VistCut3[firs] = beg;
			back1step3[firs] = -1;
			vis3[firs] = 1;
			for (int j = 0; j < vistR[firs]; j += 2)
			{
				int seco = GR[firs][j];
				int acco2 = GR[firs][j + 1];
				//int acco2 = migic[(ull)seco << 32 | firs];
				if (seco > beg && vis3[seco] == 0 && 5ll * acco1 >= acco2 && acco1 <= 3ll * acco2)
				{
					VistCut3[seco] = beg;
					back2step3[seco] = -2;
					vis3[seco] = 1;
					for (int k = 0; k < vistR[seco]; k += 2)
					{
						int thir = GR[seco][k];
						int acco3 = GR[seco][k + 1];
						//int acco3 = migic[(ull)thir << 32 | seco];
						if (thir > beg && vis3[thir] == 0 && 5ll * acco2 >= acco3 && acco2 <= 3ll * acco3)
						{
							VistCut3[thir] = beg;
							back3step3[thir] = -3;
						}
					}
					vis3[seco] = 0;
				}
			}
			vis3[firs] = 0;
		}
	}
}

//=============================================forNew循环找环=======================================
void forNew3(int head) //第一层
{
	for (int ac = 0; ac < vistR[head]; ac += 2) //后向遍历头结点的邻接节点，为获得转账金额
	{
		int back1 = GR[head][ac];
		int back1acc = GR[head][ac + 1];
		//int back1acc = migic[(ull)back1 << 32 | head];
		back1Account3[back1] = back1acc;
	}
	vis3[head] = 1;
	int secNode = -1;
	int acco12 = -1;
	for (int sec = 0; sec < vistC[head]; sec += 2)//第二层
	{
		secNode = GC[head][sec];
		acco12 = GC[head][sec + 1];//1->2转账金额
		//acco12 = migic[(ull)head << 32 | secNode];//1->2转账金额
		if (secNode <= head || vis3[secNode]) continue;
		vis3[secNode] = 1;
		int thiNode = -1;
		int acco23 = -1;
		for (int thi = 0; thi < vistC[secNode]; thi += 2) //第三层
		{
			thiNode = GC[secNode][thi];
			acco23 = GC[secNode][thi + 1];//2->3转账金额
			//acco23 = migic[(ull)secNode << 32 | thiNode];//2->3转账金额
			if (thiNode > head && vis3[thiNode] == 0 && VistCut3[thiNode] == head && (5ll * acco23 >= acco12) && (acco23 <= 3ll * acco12))
			{
				if (back1step3[thiNode] == -1) {//三个节点成环,然后判断金额是否满足条件
					int money31 = back1Account3[thiNode];
					bool flag1 = (5ll * acco12 >= money31) && (acco12 <= 3ll * money31);
					bool flag2 = (5ll * money31 >= acco23) && (money31 <= 3ll * acco23);
					if (flag1 && flag2)
					{
						len33[len3Num3] = tem[head];
						len33[len3Num3 + 1] = tem[secNode];
						len33[len3Num3 + 2] = tem[thiNode];
						len3Num3 += 3;
						ansNum3++;
					}
				}
				vis3[thiNode] = 1;
				int fouNode = -1;
				int acco34 = -1;
				for (int fou = 0; fou < vistC[thiNode]; fou += 2)//第四层
				{
					fouNode = GC[thiNode][fou];
					acco34 = GC[thiNode][fou + 1];//3->4转账金额
					//acco34 = migic[(ull)thiNode << 32 | fouNode];//3->4转账金额
					if (fouNode > head && vis3[fouNode] == 0 && VistCut3[fouNode] == head && (5ll * acco34 >= acco23) && (acco34 <= 3ll * acco23))
					{
						if (back1step3[fouNode] == -1) {//四个节点成环
							int money41 = back1Account3[fouNode];
							bool flag1 = (5ll * acco12 >= money41) && (acco12 <= 3ll * money41);
							bool flag2 = (5ll * money41 >= acco34) && (money41 <= 3ll * acco34);
							if (flag1 && flag2)
							{
								len43[len4Num3] = tem[head];
								len43[len4Num3 + 1] = tem[secNode];
								len43[len4Num3 + 2] = tem[thiNode];
								len43[len4Num3 + 3] = tem[fouNode];
								len4Num3 += 4;
								ansNum3++;
							}
						}
						vis3[fouNode] = 1;
						int fifNode = -1;
						int acco45 = -1;
						for (int fif = 0; fif < vistC[fouNode]; fif += 2) //第五层
						{
							fifNode = GC[fouNode][fif];
							acco45 = GC[fouNode][fif + 1];//4->5转账金额
							//acco45 = migic[(ull)fouNode << 32 | fifNode];//4->5转账金额
							if (fifNode > head && vis3[fifNode] == 0 && VistCut3[fifNode] == head && (back1step3[fifNode] == -1 || back2step3[fifNode] == -2 || back3step3[fifNode] == -3) && (5ll * acco45 >= acco34) && (acco45 <= 3ll * acco34))
							{
								if (back1step3[fifNode] == -1) {//五个节点的环
									int money51 = back1Account3[fifNode];
									bool flag1 = (5ll * acco12 >= money51) && (acco12 <= 3ll * money51);
									bool flag2 = (5ll * money51 >= acco45) && (money51 <= 3ll * acco45);
									if (flag1 && flag2)
									{
										len53[len5Num3] = tem[head];
										len53[len5Num3 + 1] = tem[secNode];
										len53[len5Num3 + 2] = tem[thiNode];
										len53[len5Num3 + 3] = tem[fouNode];
										len53[len5Num3 + 4] = tem[fifNode];
										len5Num3 += 5;
										ansNum3++;
									}
								}
								vis3[fifNode] = 1;
								int sixNode = -1;
								int acco56 = -1;
								for (int six = 0; six < vistC[fifNode]; six += 2) //第六层
								{
									sixNode = GC[fifNode][six];
									acco56 = GC[fifNode][six + 1];//5->6转账金额
								   // acco56 = migic[(ull)fifNode << 32 | sixNode];//5->6转账金额
									if (sixNode > head && vis3[sixNode] == 0 && VistCut3[sixNode] == head && (back1step3[sixNode] == -1 || back2step3[sixNode] == -2) && (5ll * acco56 >= acco45) && (acco56 <= 3ll * acco45))
									{
										if (back1step3[sixNode] == -1) {//六个节点的环
											int money61 = back1Account3[sixNode];
											bool flag1 = (5ll * acco12 >= money61) && (acco12 <= 3ll * money61);
											bool flag2 = (5ll * money61 >= acco56) && (money61 <= 3ll * acco56);
											if (flag1 && flag2)
											{
												len63[len6Num3] = tem[head];
												len63[len6Num3 + 1] = tem[secNode];
												len63[len6Num3 + 2] = tem[thiNode];
												len63[len6Num3 + 3] = tem[fouNode];
												len63[len6Num3 + 4] = tem[fifNode];
												len63[len6Num3 + 5] = tem[sixNode];
												len6Num3 += 6;
												ansNum3++;
											}
										}
										vis3[sixNode] = 1;
										int sevNode = -1;
										int acco67 = -1;
										for (int sev = 0; sev < vistC[sixNode]; sev += 2) //第七层
										{
											sevNode = GC[sixNode][sev];
											acco67 = GC[sixNode][sev + 1];//6->7转账金额
										  //  acco67 = migic[(ull)sixNode << 32 | sevNode];//6->7转账金额
											if (sevNode > head && vis3[sevNode] == 0 && VistCut3[sevNode] == head && (5ll * acco67 >= acco56) && (acco67 <= 3ll * acco56))
											{
												if (back1step3[sevNode] == -1) {//七个节点的环
													int money71 = back1Account3[sevNode];
													bool flag1 = (5ll * acco12 >= money71) && (acco12 <= 3ll * money71);
													bool flag2 = (5ll * money71 >= acco67) && (money71 <= 3ll * acco67);
													if (flag1 && flag2)
													{
														//len73.push_back(tem[head]);
														//len73.push_back(tem[secNode]);
														//len73.push_back(tem[thiNode]);
														//len73.push_back(tem[fouNode]);
														//len73.push_back(tem[fifNode]);
														//len73.push_back(tem[sixNode]);
														//len73.push_back(tem[sevNode]);
														len73[len7Num3] = tem[head];
														len73[len7Num3 + 1] = tem[secNode];
														len73[len7Num3 + 2] = tem[thiNode];
														len73[len7Num3 + 3] = tem[fouNode];
														len73[len7Num3 + 4] = tem[fifNode];
														len73[len7Num3 + 5] = tem[sixNode];
														len73[len7Num3 + 6] = tem[sevNode];
														len7Num3 += 7;
														ansNum3++;
													}
												}
											}
										}
										vis3[sixNode] = false;
									}
								}
								vis3[fifNode] = false;
							}
						}
						vis3[fouNode] = false;
					}
				}
				vis3[thiNode] = false;
			}
		}
		vis3[secNode] = false;
	}
	vis3[head] = false;
}




int main()
{
	auto t0 = clock();
	Solution solution;
	solution.readFile();
	/*string testFile = "/data/test_data_38252_9153.txt";
	solution.parseInput(testFile);*/
	auto t1 = clock();
	cout << "输入文件耗时：" << t1 - t0 << endl;
	solution.constructGraph();
	//for (int i = 0;i < maxNum;i++) {
	//    cout << "GC[" << i << "]";
	//    for (int j = 0;j < vistC[i];j++) {
	//        cout << GC[i][j]<<",";
	//    }
	//    cout << endl;
	//}
	auto t2 = clock();
	cout << "创建图耗时：" << t2 - t1 << endl;
	solution.solve();
	auto t3 = clock();
	cout << "solve耗时：" << t3 - t2 << endl;
	//solution.save();
	solution.mmapsave();
	cout << "save耗时：" << clock() - t3 << endl;

	return 0;
}
