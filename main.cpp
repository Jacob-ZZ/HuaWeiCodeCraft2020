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
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>
#include <bits/stdc++.h>

using namespace std;

#pragma warning(disable:4996)
//#define InAddress   "/data/test_data_28.txt"
//#define OutAddress	"/data/result/result_28.txt"
#define InAddress   "/data/test_data.txt"
#define OutAddress	"/projects/student/result.txt"

int GC[280000][50] = { 0 };//出度图
int GR[280000][255] = { 0 };//入度图

int user1[280000] = { 0 };
int user2[280000] = { 0 };
int cnt = 0;//代表输入数据的总个数
int maxNum = 0;//表示最大Id；

int first[280000] = { 0 };
int next_i[280000] = { 0 };

int vistC[280000] = { 0 };
int vistR[280000] = { 0 };

int test_data_size;
int maxNum1 = 0;

//---------------------第一个线程
int len3[3 * 500000]; int len3Num = 0;
int len4[4 * 500000]; int len4Num = 0;
int len5[5 * 1000000]; int len5Num = 0;
int len6[6 * 2000000]; int len6Num = 0;
int len7[7 * 3000000]; int len7Num = 0;
int* ans[] = { len3,len4,len5,len6,len7 }; int ansNum = 0;

int vis[280000];
int VistCut[300000] = { 0 };
int back1step[300000] = { 0 };
int back2step[300000] = { 0 };
int back3step[300000] = { 0 };

//-----------------------第二个线程
int len31[3 * 500000]; int len31Num = 0;
int len41[4 * 500000]; int len41Num = 0;
int len51[5 * 1000000]; int len51Num = 0;
int len61[6 * 2000000]; int len61Num = 0;
int len71[7 * 3000000]; int len71Num = 0;
int* ans1[] = { len31,len41,len51,len61,len71 }; int ansNum1 = 0;

int vis1[280000];
int VistCut1[300000] = { 0 };
int back1step1[300000] = { 0 };
int back2step1[300000] = { 0 };
int back3step1[300000] = { 0 };

//-----------------------第三个线程
int len32[3 * 500000];  int len32Num = 0;
int len42[4 * 500000];  int len42Num = 0;
int len52[5 * 1000000]; int len52Num = 0;
int len62[6 * 2000000]; int len62Num = 0;
int len72[7 * 3000000]; int len72Num = 0;
int* ans2[] = { len32,len42,len52,len62,len72 }; int ansNum2 = 0;

int vis2[280000];
int VistCut2[300000] = { 0 };
int back1step2[300000] = { 0 };
int back2step2[300000] = { 0 };
int back3step2[300000] = { 0 };


//-----------------------第四个线程

int len33[3 * 500000];  int len33Num = 0;
int len43[4 * 500000];  int len43Num = 0;
int len53[5 * 1000000]; int len53Num = 0;
int len63[6 * 2000000]; int len63Num = 0;
int len73[7 * 3000000]; int len73Num = 0;
int* ans3[] = { len33,len43,len53,len63,len73 }; int ansNum3 = 0;

int vis3[280000];
int VistCut3[300000] = { 0 };
int back1step3[300000] = { 0 };
int back2step3[300000] = { 0 };
int back3step3[300000] = { 0 };


//char c[1500000 * 80] = { 0 };	int cntc = 0;
//char char7f[1500000 * 80] = { 0 };	int char7fl = 0;	int len7fl = 0;
//char char7s[1500000 * 80] = { 0 };	int char7sl = 0;	int len7sl = 0;
//char char7t[1500000 * 80] = { 0 };	int char7tl = 0;	int len7tl = 0;
//char char7m[1500000 * 80] = { 0 };	int char7ml = 0;	int len7ml = 0;
//
char c[1500000 * 80] = { 0 };	int cntc = 0;
char char7f1[1500000 * 80] = { 0 };	int char7fl1 = 0;	int len7fl1 = 0;
char char7f2[1500000 * 80] = { 0 };	int char7fl2 = 0;	int len7fl2 = 0;
char char7f3[1500000 * 80] = { 0 };	int char7fl3 = 0;	int len7fl3 = 0;
char char7s1[1500000 * 80] = { 0 };	int char7sl1 = 0;	int len7sl1 = 0;
char char7s2[1500000 * 80] = { 0 };	int char7sl2 = 0;	int len7sl2 = 0;
char char7t[1500000 * 80] = { 0 };	int char7tl = 0;	int len7tl = 0;
char char7m[1500000 * 80] = { 0 };	int char7ml = 0;	int len7ml = 0;

int length1 = 0;
int length2 = 0;
int length3 = 0;
int length4 = 0;

void forNew(int head);
void backCut(int beg);
void frontCut(int beg);
void forThread(int start, int end);

void forNew1(int head);
void backCut1(int beg);
void frontCut1(int beg);
void forThread1(int start, int end);

void forNew2(int head);
void backCut2(int beg);
void frontCut2(int beg);
void forThread2(int start, int end);

void forNew3(int head);
void backCut3(int beg);
void frontCut3(int beg);
void forThread3(int start, int end);

void write3_6();
void int2char(int a[], int len, int timelen);
void int2char7(int a[], int fir, int end, char res[], int charlen);

void mmwrite(char* ans, char* str, char* c);
void mmwrite1(char* ans, char* str, char* c, char* char7f1, char* char7f2);
void mmwrite2(char* ans, char* str, char* c, char* char7f1, char* char7f2, char* char7f3, char* char7s1);
void mmwrite3(char* ans, char* str, char* c, char* char7f1, char* char7f2, char* char7f3, char* char7s1, char* char7s2, char* char7t, char* char7m);

class Solution {
public:
    void char2int(char*& ch)
    {
        int num1[2] = { 0 };
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
        while (*ch != '\n')
        {
            ch++;
        }
        ch++;

        *(user1 + cnt) = num1[0];
        *(user2 + cnt) = num1[1];
        cnt++;


    }
    void readFile()
    {
        char* buf = (char*)malloc(280000 * 35 * sizeof(char));
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
        maxNum1 = (*max_element(user1, (user1 + cnt))) + 1;
        maxNum = maxNum1 > 50000 ? 50000 : maxNum1;
    }
    void constructGraph() {

        int k = 0;
        int sizenum = 0;

        for (int i = 0; i < maxNum; i++)
            first[i] = -1;
        for (int i = 0; i < cnt; i++)
            next_i[i] = -1;
        for (int i = 0; i < cnt; i++)
        {
            next_i[i] = first[user1[i]];
            first[user1[i]] = i;
        }
        for (int i = 0; i < maxNum; i++)
        {
            sizenum = 0;
            k = first[i];
            if (k != -1)
            {
                GC[i][sizenum] = user2[k];
                sizenum++;
            }
            while (k != -1)
            {
                k = next_i[k];
                if (k >= 0)
                {
                    GC[i][sizenum] = user2[k];
                    sizenum++;
                }
            }
            sort(GC[i], GC[i] + sizenum);
            vistC[i] = sizenum;
        }

        for (int i = 0; i < maxNum; i++)
            first[i] = -1;
        for (int i = 0; i < cnt; i++)
            next_i[i] = -1;
        for (int i = 0; i < cnt; i++)
        {
            next_i[i] = first[user2[i]];
            first[user2[i]] = i;
        }
        for (int i = 0; i < maxNum; i++)
        {
            sizenum = 0;
            k = first[i];
            if (k != -1)
            {
                GR[i][sizenum] = user1[k];
                sizenum++;
            }
            while (k != -1)
            {
                k = next_i[k];
                if (k >= 0)
                {
                    GR[i][sizenum] = user1[k];
                    sizenum++;
                }
            }
            sort(GR[i], GR[i] + sizenum);
            vistR[i] = sizenum;
        }
    }
    void solve()
    {
        length1 = maxNum1 / 20;
        length2 = length1 * 2;
        length3 = length1 * 3;
        length4 = maxNum;
        thread forOne(forThread, 0, length1);
        thread forTwo(forThread1, length1, length2);
        thread forThree(forThread2, length2, length3);
        thread forFour(forThread3, length3, length4);
        forOne.join();
        forTwo.join();
        forThree.join();
        forFour.join();

    }


    //---------------------------多线程输出
    void writeThread1()
    {

        /*thread theOne(write3_6);
        thread theTwo(int2char7, len7, 0, len7Num, char7f, char7fl);
        thread theThree(int2char7, len71, 0, len71Num, char7s, char7sl);
        thread theFour(int2char7, len72, 0, len72Num, char7t, char7tl);
        thread theFife(int2char7, len73, 0, len73Num, char7m, char7ml);
        theOne.join();
        theTwo.join();
        theThree.join();
        theFour.join();
        theFife.join();*/
        thread theOne(write3_6);

        thread theTwo(int2char7, len7, 0, len7Num / 3, char7f1, char7fl1);
        thread theThree(int2char7, len7, len7Num / 3, 2 * len7Num / 3, char7f2, char7fl2);
        thread theFour(int2char7, len7, 2 * len7Num / 3, len7Num, char7f3, char7fl3);

        thread theFife(int2char7, len71, 0, len71Num / 2, char7s1, char7sl1);
        thread theSix(int2char7, len71, len71Num / 2, len71Num, char7s2, char7sl2);

        thread theSev(int2char7, len72, 0, len72Num, char7t, char7tl);
        thread theEig(int2char7, len73, 0, len73Num, char7m, char7ml);
        theOne.join();
        theTwo.join();
        theThree.join();
        theFour.join();
        theFife.join();
        theSix.join();
        theSev.join();
        theEig.join();
    }
    //void save() {
    //    printf("Total Loops %d\n", (int)(ansNum + ansNum1 + ansNum2 + ansNum3));
    //    int i = 0;
    //    char str[20];
    //    FILE* fp = fopen(OutAddress, "w+");
    //    //写入总数
    //    sprintf(str, "%d\n", (int)(ansNum + ansNum1 + ansNum2 + ansNum3));
    //    fwrite(str, sizeof(char), strlen(str), fp);
    //    writeThread1();
    //    fwrite(c, sizeof(char), strlen(c), fp);
    //    fwrite(char7f, sizeof(char), strlen(char7f), fp);
    //    fwrite(char7s, sizeof(char), strlen(char7s), fp);
    //    fwrite(char7t, sizeof(char), strlen(char7t), fp);
    //    fwrite(char7m, sizeof(char), strlen(char7m), fp);
    //    fclose(fp);

    //}

    void mmapsave() {
        writeThread1();
        char str[20];
        sprintf(str, "%d\n", (int)(ansNum + ansNum1 + ansNum2 + ansNum3));
        int result_data_size = strlen(str) + strlen(c) + strlen(char7f1) + strlen(char7f2) + strlen(char7f3) + strlen(char7s1) + strlen(char7s2) + strlen(char7t) + strlen(char7m);
        int fd2 = open(OutAddress, O_RDWR | O_CREAT | O_TRUNC, 0666);
        /* 增大文件大小，以用于映射 */
        off_t lengthh = lseek(fd2, result_data_size - 1, SEEK_END);
        write(fd2, "\0", 1);


        char* ans = (char*)mmap(NULL, lengthh, PROT_READ | PROT_WRITE, MAP_SHARED, fd2, 0);

        thread wri(mmwrite, ans, str, c);
        thread wri1(mmwrite1, ans, str, c, char7f1, char7f2);
        thread wri2(mmwrite2, ans, str, c, char7f1, char7f2, char7f3, char7s1);
        thread wri3(mmwrite3, ans, str, c, char7f1, char7f2, char7f3, char7s1, char7s2,char7t, char7m);
        wri.join();
        wri1.join();
        wri2.join();
        wri3.join();

    }
};
void mmwrite(char* ans, char* str, char* c)
{
    memcpy(ans, str, strlen(str));
    memcpy(ans + strlen(str), c, strlen(c));
    
}
void mmwrite1(char* ans, char* str, char* c, char* char7f1, char* char7f2)
{
    //memcpy(ans + strlen(str) + strlen(c), char7f, strlen(char7f));
    memcpy(ans + strlen(str) + strlen(c), char7f1, strlen(char7f1));
    memcpy(ans + strlen(str) + strlen(c) + strlen(char7f1), char7f2, strlen(char7f2));
    
}
void mmwrite2(char* ans, char* str, char* c, char* char7f1, char* char7f2, char* char7f3, char* char7s1)
{
    //memcpy(ans + strlen(str) + strlen(c) + strlen(char7f), char7s, strlen(char7s));
    memcpy(ans + strlen(str) + strlen(c) + strlen(char7f1) + strlen(char7f2), char7f3, strlen(char7f3));
    memcpy(ans + strlen(str) + strlen(c) + strlen(char7f1) + strlen(char7f2) + strlen(char7f3), char7s1, strlen(char7s1));
   
}
void mmwrite3(char* ans, char* str, char* c, char* char7f1, char* char7f2, char* char7f3, char* char7s1, char* char7s2, char* char7t, char* char7m) {
   /* memcpy(ans + strlen(str) + strlen(c) + strlen(char7f) + strlen(char7s), char7t, strlen(char7t));
    memcpy(ans + strlen(str) + strlen(c) + strlen(char7f) + strlen(char7s) + strlen(char7t), char7m, strlen(char7m));*/
    
    memcpy(ans + strlen(str) + strlen(c) + strlen(char7f1) + strlen(char7f2) + strlen(char7f3) + strlen(char7s1), char7s2, strlen(char7s2));
    memcpy(ans + strlen(str) + strlen(c) + strlen(char7f1) + strlen(char7f2) + strlen(char7f3) + strlen(char7s1) + strlen(char7s2), char7t, strlen(char7t));
    memcpy(ans + strlen(str) + strlen(c) + strlen(char7f1) + strlen(char7f2) + strlen(char7f3) + strlen(char7s1) + strlen(char7s2) + strlen(char7t), char7m, strlen(char7m));
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
void write3_6()
{
    int2char(len3, len3Num, 3);
    int2char(len31, len31Num, 3);
    int2char(len32, len32Num, 3);
    int2char(len33, len33Num, 3);
    int2char(len4, len4Num, 4);
    int2char(len41, len41Num, 4);
    int2char(len42, len42Num, 4);
    int2char(len43, len43Num, 4);
    int2char(len5, len5Num, 5);
    int2char(len51, len51Num, 5);
    int2char(len52, len52Num, 5);
    int2char(len53, len53Num, 5);
    int2char(len6, len6Num, 6);
    int2char(len61, len61Num, 6);
    int2char(len62, len62Num, 6);
    int2char(len63, len63Num, 6);
    c[cntc] = '\0';

}

void int2char7(int a[], int fir, int end, char res[], int charlen)
{
    char b[11];
    int cntb = 0;
    int tem = 0;
    for (int i = fir;i < end;i++)
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
}

void forThread(int start, int end)
{
    for (int i = start;i < end;i++)
    {
        frontCut(i);
        backCut(i);
        int lin1 = -1;
        int lin2 = -1;
        int lin3 = -1;
        forNew(i);
        //恢复为初始值0的状态
        for (int j = 0;j < vistR[i];j++)
        {
            lin1 = GR[i][j];
            back1step[GR[i][j]] = 0;
            for (int k = 0;k < vistR[lin1];k++)
            {
                lin2 = GR[lin1][k];
                back2step[lin2] = 0;
                for (int q = 0;q < vistR[lin2];q++)
                {
                    lin3 = GR[lin2][q];
                    back3step[lin3] = 0;
                }
            }
        }
    }
}

void forThread1(int start, int end)
{
    for (int i = start;i < end;i++)
    {
        frontCut1(i);
        backCut1(i);
        int lin1 = -1;
        int lin2 = -1;
        int lin3 = -1;
        forNew1(i);
        //恢复为初始值0的状态
        for (int j = 0;j < vistR[i];j++)
        {
            lin1 = GR[i][j];
            back1step1[GR[i][j]] = 0;
            for (int k = 0;k < vistR[lin1];k++)
            {
                lin2 = GR[lin1][k];
                back2step1[lin2] = 0;
                for (int q = 0;q < vistR[lin2];q++)
                {
                    lin3 = GR[lin2][q];
                    back3step1[lin3] = 0;
                }
            }
        }
    }
}
void forThread2(int start, int end)
{
    for (int i = start;i < end;i++)
    {
        frontCut2(i);
        backCut2(i);
        int lin1 = -1;
        int lin2 = -1;
        int lin3 = -1;
        forNew2(i);
        //恢复为初始值0的状态
        for (int j = 0;j < vistR[i];j++)
        {
            lin1 = GR[i][j];
            back1step2[GR[i][j]] = 0;
            for (int k = 0;k < vistR[lin1];k++)
            {
                lin2 = GR[lin1][k];
                back2step2[lin2] = 0;
                for (int q = 0;q < vistR[lin2];q++)
                {
                    lin3 = GR[lin2][q];
                    back3step2[lin3] = 0;
                }
            }
        }
    }
}
void forThread3(int start, int end)
{
    for (int i = start;i < end;i++)
    {
        frontCut3(i);
        backCut3(i);
        int lin1 = -1;
        int lin2 = -1;
        int lin3 = -1;
        forNew3(i);
        //恢复为初始值0的状态
        for (int j = 0;j < vistR[i];j++)
        {
            lin1 = GR[i][j];
            back1step3[GR[i][j]] = 0;
            for (int k = 0;k < vistR[lin1];k++)
            {
                lin2 = GR[lin1][k];
                back2step3[lin2] = 0;
                for (int q = 0;q < vistR[lin2];q++)
                {
                    lin3 = GR[lin2][q];
                    back3step3[lin3] = 0;
                }
            }
        }
    }
}

//----------------------------------------第1个线程
void frontCut(int beg) {
    int firs = -1;
    for (int i = 0; i < vistC[beg]; i++) {
        firs = GC[beg][i];
        if (firs > beg && vis[firs] == 0) {
            VistCut[firs] = beg;
            vis[firs] = 1;
            for (int j = 0; j < vistC[firs]; j++) {
                int seco = GC[firs][j];
                if (seco > beg && vis[seco] == 0) {
                    VistCut[seco] = beg;
                    vis[seco] = 1;
                    for (int k = 0; k < vistC[seco]; k++) {
                        int thir = GC[seco][k];
                        if (thir > beg && vis[thir] == 0) {
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

void backCut(int beg) {
    int firs = -1;
    for (int i = 0; i < vistR[beg]; i++) {
        firs = GR[beg][i];
        if (firs > beg && vis[firs] == 0) {
            VistCut[firs] = beg;
            back1step[firs] = -1;
            vis[firs] = 1;
            for (int j = 0; j < vistR[firs]; j++) {
                int seco = GR[firs][j];
                if (seco > beg && vis[seco] == 0) {
                    VistCut[seco] = beg;
                    back2step[seco] = -2;
                    vis[seco] = 1;
                    for (int k = 0; k < vistR[seco]; k++) {
                        int thir = GR[seco][k];
                        if (thir > beg && vis[thir] == 0) {
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

void forNew(int head) //第一层
{
    vis[head] = 1;
    int secNode = -1;
    for (int sec = 0; sec < vistC[head]; sec++)//第二层
    {
        secNode = GC[head][sec];
        if (secNode <= head || vis[secNode] == 1) continue;
        vis[secNode] = 1;
        int thiNode = -1;
        for (int thi = 0;thi < vistC[secNode];thi++) //第三层
        {
            thiNode = GC[secNode][thi];
            if (thiNode > head && vis[thiNode] == 0)
            {
                if (back1step[thiNode] == -1) {//三个节点成环
                    len3[len3Num] = head; len3[len3Num + 1] = secNode;
                    len3[len3Num + 2] = thiNode;
                    len3Num += 3;
                    ansNum++;
                }
                vis[thiNode] = 1;
                int fouNode = -1;
                for (int fou = 0;fou < vistC[thiNode];fou++)//第四层
                {
                    fouNode = GC[thiNode][fou];
                    if (fouNode > head && vis[fouNode] == 0 && VistCut[fouNode] == head)
                    {
                        if (back1step[fouNode] == -1) {//四个节点成环
                            len4[len4Num] = head; len4[len4Num + 1] = secNode;
                            len4[len4Num + 2] = thiNode; len4[len4Num + 3] = fouNode;
                            len4Num += 4;
                            ansNum++;
                        }
                        vis[fouNode] = 1;
                        int fifNode = -1;
                        for (int fif = 0;fif < vistC[fouNode];fif++) //第五层
                        {
                            fifNode = GC[fouNode][fif];
                            if (fifNode > head && vis[fifNode] == 0 && VistCut[fifNode] == head && (back1step[fifNode] == -1 || back2step[fifNode] == -2 || back3step[fifNode] == -3))
                            {
                                if (back1step[fifNode] == -1) {//五个节点的环
                                    len5[len5Num] = head; len5[len5Num + 1] = secNode;len5[len5Num + 2] = thiNode;
                                    len5[len5Num + 3] = fouNode; len5[len5Num + 4] = fifNode;
                                    len5Num += 5;
                                    ansNum++;
                                }
                                vis[fifNode] = 1;
                                int sixNode = -1;
                                for (int six = 0;six < vistC[fifNode];six++) //第六层
                                {
                                    sixNode = GC[fifNode][six];
                                    if (sixNode > head && vis[sixNode] == 0 && VistCut[sixNode] == head && (back1step[sixNode] == -1 || back2step[sixNode] == -2))
                                    {
                                        if (back1step[sixNode] == -1) {//六个节点的环
                                            len6[len6Num] = head; len6[len6Num + 1] = secNode;len6[len6Num + 2] = thiNode;
                                            len6[len6Num + 3] = fouNode;
                                            len6[len6Num + 4] = fifNode; len6[len6Num + 5] = sixNode;
                                            len6Num += 6;
                                            ansNum++;
                                        }
                                        vis[sixNode] = 1;
                                        int sevNode = -1;
                                        for (int sev = 0;sev < vistC[sixNode];sev++) //第七层
                                        {
                                            sevNode = GC[sixNode][sev];
                                            if (sevNode > head && vis[sevNode] == 0 && VistCut[sevNode] == head)
                                            {
                                                if (back1step[sevNode] == -1)
                                                {//七个节点的环
                                                    len7[len7Num] = head; len7[len7Num + 1] = secNode;len7[len7Num + 2] = thiNode;
                                                    len7[len7Num + 3] = fouNode;len7[len7Num + 4] = fifNode;
                                                    len7[len7Num + 5] = sixNode; len7[len7Num + 6] = sevNode;
                                                    len7Num += 7;
                                                    ansNum++;
                                                }
                                            }
                                        }
                                        vis[sixNode] = 0;
                                    }
                                }
                                vis[fifNode] = 0;
                            }
                        }
                        vis[fouNode] = 0;
                    }
                }
                vis[thiNode] = 0;
            }
        }
        vis[secNode] = 0;
    }
    vis[head] = 0;
}

//-----------------------------------第2个线程
void frontCut1(int beg) {
    int firs = -1;
    for (int i = 0; i < vistC[beg]; i++) {
        firs = GC[beg][i];
        if (firs > beg && vis1[firs] == 0) {
            VistCut1[firs] = beg;
            vis1[firs] = 1;
            for (int j = 0; j < vistC[firs]; j++) {
                int seco = GC[firs][j];
                if (seco > beg && vis1[seco] == 0) {
                    VistCut1[seco] = beg;
                    vis1[seco] = 1;
                    for (int k = 0; k < vistC[seco]; k++) {
                        int thir = GC[seco][k];
                        if (thir > beg && vis1[thir] == 0) {
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

void backCut1(int beg) {
    int firs = -1;
    for (int i = 0; i < vistR[beg]; i++) {
        firs = GR[beg][i];
        if (firs > beg && vis1[firs] == 0) {
            VistCut1[firs] = beg;
            back1step1[firs] = -1;
            vis1[firs] = 1;
            for (int j = 0; j < vistR[firs]; j++) {
                int seco = GR[firs][j];
                if (seco > beg && vis1[seco] == 0) {
                    VistCut1[seco] = beg;
                    back2step1[seco] = -2;
                    vis1[seco] = 1;
                    for (int k = 0; k < vistR[seco]; k++) {
                        int thir = GR[seco][k];
                        if (thir > beg && vis1[thir] == 0) {
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

void forNew1(int head) //第一层
{
    vis1[head] = 1;
    int secNode = -1;
    for (int sec = 0; sec < vistC[head]; sec++)//第二层
    {
        secNode = GC[head][sec];
        if (secNode <= head || vis1[secNode] == 1) continue;
        vis1[secNode] = 1;
        int thiNode = -1;
        for (int thi = 0;thi < vistC[secNode];thi++) //第三层
        {
            thiNode = GC[secNode][thi];
            if (thiNode > head && vis1[thiNode] == 0)
            {
                if (back1step1[thiNode] == -1) {//三个节点成环
                    len31[len31Num] = head; len31[len31Num + 1] = secNode;
                    len31[len31Num + 2] = thiNode;
                    len31Num += 3;
                    ansNum1++;
                }
                vis1[thiNode] = 1;
                int fouNode = -1;
                for (int fou = 0;fou < vistC[thiNode];fou++)//第四层
                {
                    fouNode = GC[thiNode][fou];
                    if (fouNode > head && vis1[fouNode] == 0 && VistCut1[fouNode] == head)
                    {
                        if (back1step1[fouNode] == -1) {//四个节点成环
                            len41[len41Num] = head; len41[len41Num + 1] = secNode;
                            len41[len41Num + 2] = thiNode; len41[len41Num + 3] = fouNode;
                            len41Num += 4;
                            ansNum1++;
                        }
                        vis1[fouNode] = 1;
                        int fifNode = -1;
                        for (int fif = 0;fif < vistC[fouNode];fif++) //第五层
                        {
                            fifNode = GC[fouNode][fif];
                            if (fifNode > head && vis1[fifNode] == 0 && VistCut1[fifNode] == head && (back1step1[fifNode] == -1 || back2step1[fifNode] == -2 || back3step1[fifNode] == -3))
                            {
                                if (back1step1[fifNode] == -1) {//五个节点的环
                                    len51[len51Num] = head; len51[len51Num + 1] = secNode;len51[len51Num + 2] = thiNode;
                                    len51[len51Num + 3] = fouNode; len51[len51Num + 4] = fifNode;
                                    len51Num += 5;
                                    ansNum1++;
                                }
                                vis1[fifNode] = 1;
                                int sixNode = -1;
                                for (int six = 0;six < vistC[fifNode];six++) //第六层
                                {
                                    sixNode = GC[fifNode][six];
                                    if (sixNode > head && vis1[sixNode] == 0 && VistCut1[sixNode] == head && (back1step1[sixNode] == -1 || back2step1[sixNode] == -2))
                                    {
                                        if (back1step1[sixNode] == -1) {//六个节点的环
                                            len61[len61Num] = head; len61[len61Num + 1] = secNode;len61[len61Num + 2] = thiNode;
                                            len61[len61Num + 3] = fouNode;
                                            len61[len61Num + 4] = fifNode; len61[len61Num + 5] = sixNode;
                                            len61Num += 6;
                                            ansNum1++;
                                        }
                                        vis1[sixNode] = 1;
                                        int sevNode = -1;
                                        for (int sev = 0;sev < vistC[sixNode];sev++) //第七层
                                        {
                                            sevNode = GC[sixNode][sev];
                                            if (sevNode > head && vis1[sevNode] == 0 && VistCut1[sevNode] == head)
                                            {
                                                if (back1step1[sevNode] == -1)
                                                {//七个节点的环
                                                    len71[len71Num] = head; len71[len71Num + 1] = secNode;len71[len71Num + 2] = thiNode;
                                                    len71[len71Num + 3] = fouNode;len71[len71Num + 4] = fifNode;
                                                    len71[len71Num + 5] = sixNode; len71[len71Num + 6] = sevNode;
                                                    len71Num += 7;
                                                    ansNum1++;
                                                }
                                            }
                                        }
                                        vis1[sixNode] = 0;
                                    }
                                }
                                vis1[fifNode] = 0;
                            }
                        }
                        vis1[fouNode] = 0;
                    }
                }
                vis1[thiNode] = 0;
            }
        }
        vis1[secNode] = 0;
    }
    vis1[head] = 0;
}

//-----------------------------------第3个线程

void frontCut2(int beg) {
    int firs = -1;
    for (int i = 0; i < vistC[beg]; i++) {
        firs = GC[beg][i];
        if (firs > beg && vis2[firs] == 0) {
            VistCut2[firs] = beg;
            vis2[firs] = 1;
            for (int j = 0; j < vistC[firs]; j++) {
                int seco = GC[firs][j];
                if (seco > beg && vis2[seco] == 0) {
                    VistCut2[seco] = beg;
                    vis2[seco] = 1;
                    for (int k = 0; k < vistC[seco]; k++) {
                        int thir = GC[seco][k];
                        if (thir > beg && vis2[thir] == 0) {
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

void backCut2(int beg) {
    int firs = -1;
    for (int i = 0; i < vistR[beg]; i++) {
        firs = GR[beg][i];
        if (firs > beg && vis2[firs] == 0) {
            VistCut2[firs] = beg;
            back1step2[firs] = -1;
            vis2[firs] = 1;
            for (int j = 0; j < vistR[firs]; j++) {
                int seco = GR[firs][j];
                if (seco > beg && vis2[seco] == 0) {
                    VistCut2[seco] = beg;
                    back2step2[seco] = -2;
                    vis2[seco] = 1;
                    for (int k = 0; k < vistR[seco]; k++) {
                        int thir = GR[seco][k];
                        if (thir > beg && vis2[thir] == 0) {
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

void forNew2(int head) //第一层
{
    vis2[head] = 1;
    int secNode = -1;
    for (int sec = 0; sec < vistC[head]; sec++)//第二层
    {
        secNode = GC[head][sec];
        if (secNode <= head || vis2[secNode] == 1) continue;
        vis2[secNode] = 1;
        int thiNode = -1;
        for (int thi = 0;thi < vistC[secNode];thi++) //第三层
        {
            thiNode = GC[secNode][thi];
            if (thiNode > head && vis2[thiNode] == 0)
            {
                if (back1step2[thiNode] == -1) {//三个节点成环
                    len32[len32Num] = head; len32[len32Num + 1] = secNode;
                    len32[len32Num + 2] = thiNode;
                    len32Num += 3;
                    ansNum2++;
                }
                vis2[thiNode] = 1;
                int fouNode = -1;
                for (int fou = 0;fou < vistC[thiNode];fou++)//第四层
                {
                    fouNode = GC[thiNode][fou];
                    if (fouNode > head && vis2[fouNode] == 0 && VistCut2[fouNode] == head)
                    {
                        if (back1step2[fouNode] == -1) {//四个节点成环
                            len42[len42Num] = head; len42[len42Num + 1] = secNode;
                            len42[len42Num + 2] = thiNode; len42[len42Num + 3] = fouNode;
                            len42Num += 4;
                            ansNum2++;
                        }
                        vis2[fouNode] = 1;
                        int fifNode = -1;
                        for (int fif = 0;fif < vistC[fouNode];fif++) //第五层
                        {
                            fifNode = GC[fouNode][fif];
                            if (fifNode > head && vis2[fifNode] == 0 && VistCut2[fifNode] == head && (back1step2[fifNode] == -1 || back2step2[fifNode] == -2 || back3step2[fifNode] == -3))
                            {
                                if (back1step2[fifNode] == -1) {//五个节点的环
                                    len52[len52Num] = head; len52[len52Num + 1] = secNode;len52[len52Num + 2] = thiNode;
                                    len52[len52Num + 3] = fouNode; len52[len52Num + 4] = fifNode;
                                    len52Num += 5;
                                    ansNum2++;
                                }
                                vis2[fifNode] = 1;
                                int sixNode = -1;
                                for (int six = 0;six < vistC[fifNode];six++) //第六层
                                {
                                    sixNode = GC[fifNode][six];
                                    if (sixNode > head && vis2[sixNode] == 0 && VistCut2[sixNode] == head && (back1step2[sixNode] == -1 || back2step2[sixNode] == -2))
                                    {
                                        if (back1step2[sixNode] == -1) {//六个节点的环
                                            len62[len62Num] = head; len62[len62Num + 1] = secNode;len62[len62Num + 2] = thiNode;
                                            len62[len62Num + 3] = fouNode;
                                            len62[len62Num + 4] = fifNode; len62[len62Num + 5] = sixNode;
                                            len62Num += 6;
                                            ansNum2++;
                                        }
                                        vis2[sixNode] = 1;
                                        int sevNode = -1;
                                        for (int sev = 0;sev < vistC[sixNode];sev++) //第七层
                                        {
                                            sevNode = GC[sixNode][sev];
                                            if (sevNode > head && vis2[sevNode] == 0 && VistCut2[sevNode] == head)
                                            {
                                                if (back1step2[sevNode] == -1)
                                                {//七个节点的环
                                                    len72[len72Num] = head; len72[len72Num + 1] = secNode;len72[len72Num + 2] = thiNode;
                                                    len72[len72Num + 3] = fouNode;len72[len72Num + 4] = fifNode;
                                                    len72[len72Num + 5] = sixNode; len72[len72Num + 6] = sevNode;
                                                    len72Num += 7;
                                                    ansNum2++;
                                                }
                                            }
                                        }
                                        vis2[sixNode] = 0;
                                    }
                                }
                                vis2[fifNode] = 0;
                            }
                        }
                        vis2[fouNode] = 0;
                    }
                }
                vis2[thiNode] = 0;
            }
        }
        vis2[secNode] = 0;
    }
    vis2[head] = 0;
}

//-------------------------第4个线程
void frontCut3(int beg) {
    int firs = -1;
    for (int i = 0; i < vistC[beg]; i++) {
        firs = GC[beg][i];
        if (firs > beg && vis3[firs] == 0) {
            VistCut3[firs] = beg;
            vis3[firs] = 1;
            for (int j = 0; j < vistC[firs]; j++) {
                int seco = GC[firs][j];
                if (seco > beg && vis3[seco] == 0) {
                    VistCut3[seco] = beg;
                    vis3[seco] = 1;
                    for (int k = 0; k < vistC[seco]; k++) {
                        int thir = GC[seco][k];
                        if (thir > beg && vis3[thir] == 0) {
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

void backCut3(int beg) {
    int firs = -1;
    for (int i = 0; i < vistR[beg]; i++) {
        firs = GR[beg][i];
        if (firs > beg && vis3[firs] == 0) {
            VistCut3[firs] = beg;
            back1step3[firs] = -1;
            vis3[firs] = 1;
            for (int j = 0; j < vistR[firs]; j++) {
                int seco = GR[firs][j];
                if (seco > beg && vis3[seco] == 0) {
                    VistCut3[seco] = beg;
                    back2step3[seco] = -2;
                    vis3[seco] = 1;
                    for (int k = 0; k < vistR[seco]; k++) {
                        int thir = GR[seco][k];
                        if (thir > beg && vis3[thir] == 0) {
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

void forNew3(int head) //第一层
{
    vis3[head] = 1;
    int secNode = -1;
    for (int sec = 0; sec < vistC[head]; sec++)//第二层
    {
        secNode = GC[head][sec];
        if (secNode <= head || vis3[secNode] == 1) continue;
        vis3[secNode] = 1;
        int thiNode = -1;
        for (int thi = 0;thi < vistC[secNode];thi++) //第三层
        {
            thiNode = GC[secNode][thi];
            if (thiNode > head && vis3[thiNode] == 0)
            {
                if (back1step3[thiNode] == -1) {//三个节点成环
                    len33[len33Num] = head; len33[len33Num + 1] = secNode;
                    len33[len33Num + 2] = thiNode;
                    len33Num += 3;
                    ansNum3++;
                }
                vis3[thiNode] = 1;
                int fouNode = -1;
                for (int fou = 0;fou < vistC[thiNode];fou++)//第四层
                {
                    fouNode = GC[thiNode][fou];
                    if (fouNode > head && vis3[fouNode] == 0 && VistCut3[fouNode] == head)
                    {
                        if (back1step3[fouNode] == -1) {//四个节点成环
                            len43[len43Num] = head; len43[len43Num + 1] = secNode;
                            len43[len43Num + 2] = thiNode; len43[len43Num + 3] = fouNode;
                            len43Num += 4;
                            ansNum3++;
                        }
                        vis3[fouNode] = 1;
                        int fifNode = -1;
                        for (int fif = 0;fif < vistC[fouNode];fif++) //第五层
                        {
                            fifNode = GC[fouNode][fif];
                            if (fifNode > head && vis3[fifNode] == 0 && VistCut3[fifNode] == head && (back1step3[fifNode] == -1 || back2step3[fifNode] == -2 || back3step3[fifNode] == -3))
                            {
                                if (back1step3[fifNode] == -1) {//五个节点的环
                                    len53[len53Num] = head; len53[len53Num + 1] = secNode;len53[len53Num + 2] = thiNode;
                                    len53[len53Num + 3] = fouNode; len53[len53Num + 4] = fifNode;
                                    len53Num += 5;
                                    ansNum3++;
                                }
                                vis3[fifNode] = 1;
                                int sixNode = -1;
                                for (int six = 0;six < vistC[fifNode];six++) //第六层
                                {
                                    sixNode = GC[fifNode][six];
                                    if (sixNode > head && vis3[sixNode] == 0 && VistCut3[sixNode] == head && (back1step3[sixNode] == -1 || back2step3[sixNode] == -2))
                                    {
                                        if (back1step3[sixNode] == -1) {//六个节点的环
                                            len63[len63Num] = head; len63[len63Num + 1] = secNode;len63[len63Num + 2] = thiNode;
                                            len63[len63Num + 3] = fouNode;
                                            len63[len63Num + 4] = fifNode; len63[len63Num + 5] = sixNode;
                                            len63Num += 6;
                                            ansNum3++;
                                        }
                                        vis3[sixNode] = 1;
                                        int sevNode = -1;
                                        for (int sev = 0;sev < vistC[sixNode];sev++) //第七层
                                        {
                                            sevNode = GC[sixNode][sev];
                                            if (sevNode > head && vis3[sevNode] == 0 && VistCut3[sevNode] == head)
                                            {
                                                if (back1step3[sevNode] == -1)
                                                {//七个节点的环
                                                    len73[len73Num] = head; len73[len73Num + 1] = secNode;len73[len73Num + 2] = thiNode;
                                                    len73[len73Num + 3] = fouNode;len73[len73Num + 4] = fifNode;
                                                    len73[len73Num + 5] = sixNode; len73[len73Num + 6] = sevNode;
                                                    len73Num += 7;
                                                    ansNum3++;
                                                }
                                            }
                                        }
                                        vis3[sixNode] = 0;
                                    }
                                }
                                vis3[fifNode] = 0;
                            }
                        }
                        vis3[fouNode] = 0;
                    }
                }
                vis3[thiNode] = 0;
            }
        }
        vis3[secNode] = 0;
    }
    vis3[head] = 0;
}


int main()
{
    auto t0 = clock();
    Solution solution;
    solution.readFile();
    auto t1 = clock();
    cout << "输入文件耗时：" << t1 - t0 << endl;
    solution.constructGraph();
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

//华为软件精英挑战赛西北赛区初赛 强行亮一波 代码 0.27s