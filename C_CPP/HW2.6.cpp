// HW2.6.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//
#include <iostream>
#include<fstream>
#include<cmath>
#include <vector> 
#include <string>
#include <algorithm>
#include <time.h> 
#include <stdlib.h>
#include <stdio.h> 

using namespace std;
const int maxn = 10005;

typedef struct Point
{
    int x;
    int y;
} point;

point scooter[maxn];
point station[maxn];
int carCount = 0;
int stationCount = 0;
int** Distance;
int* maxGasCount = new int[stationCount];//最大該站車數
int* currentGasCount = new int[stationCount];//目前該站車數
int* isStationGasValid = new int[stationCount];//目前該車能不能去該站，should be initialize to 1
int* pairSolution = new int[carCount];//解Array，存放每個car要去的station的Index
int minDistance = INT_MAX;//memorize solution

//對給定的一組解計算它的總距離
int distanceInSolution(int pairSolution[], int carCount) {
    int result = 0;
    for (int i = 0; i < carCount; i++) {
        int gasIndex = pairSolution[i];
        result += Distance[i][gasIndex];
    }
    // cout << "here" << endl;
    return result;
}

void printSolution(int currentSolution[], int carCount) {
    // cout << "solution:";
    for (int i = 0; i < carCount; i++) {
        cout << currentSolution[i];
    }
    cout << endl;
}

//DFS
void findSolutionDFS(int depth, int currentSolution[], int carCount, int stationCount) {
    // cout << "depth: " << depth << endl;
    if (depth == (carCount - 1)) {
        // 跑了一組解出來，計算這組解的距離然後看是不是最小
        
        // printSolution(currentSolution, carCount);
        int distance = distanceInSolution(currentSolution, carCount);
        minDistance = min(minDistance, distance);
        return;
    }
    //檢查所有目前這台車可以去的加油站
    for (int i = 0; i < stationCount; i++) {
        if (isStationGasValid[i]) {  //有一個站還有空位
            currentGasCount[i] += 1; // 正在加油的數量加1
            if (currentGasCount[i] == maxGasCount[i]) {
                isStationGasValid[i] = 0; //如果滿了就記起來
            }

            //進下一層DFS
            currentSolution[depth] = i;
            findSolutionDFS(depth + 1, currentSolution, carCount, stationCount);
            currentSolution[depth] = 0;

            currentGasCount[i] -= 1; //試完一組可能的解，Backtracking，將目前正在加油的數量減回來
            if (currentGasCount[i] < maxGasCount[i]) {
                isStationGasValid[i] = 1; // 如果還有空位就加回來
            }
        }
    }

}

int main()
{
    //存電動機車資訊    
    ifstream inputfile("D:\\OneDrive\\Visual Studio Project\\LeetCode\\C\\map_escooter.txt");
    if (!inputfile.is_open()) {
        cout << "Error opening file";
    }
    string rest;
    while (getline(inputfile, rest)) {
        carCount++;
    }
    inputfile.clear();
    inputfile.seekg(0, inputfile.beg);
    for (int i = 0; i < carCount; i++) {
        string rest;
        inputfile >> scooter[i].x >> scooter[i].y;
        getline(inputfile, rest);
    }
    inputfile.close();

    //存站點資訊
    ifstream inputfile2("D:\\OneDrive\\Visual Studio Project\\LeetCode\\C\\map_station_nm.txt");
    if (!inputfile2.is_open()) {
        cout << "Error opening file";
    }
    string rest2;
    while (getline(inputfile2, rest2)) {
        stationCount++;
    }
    inputfile2.clear();
    inputfile2.seekg(0, inputfile2.beg);
    for (int i = 0; i < stationCount; i++) {
        string rest2;
        inputfile2 >> station[i].x >> station[i].y;
        getline(inputfile2, rest2);
    }
    inputfile2.close();

    int s = 0;
    Distance = new int* [carCount];
    for (int i = 0; i < carCount; i++) {
        Distance[i] = new int[stationCount];
    }
    for (int i = 0; i < carCount; i++) {     //對每台車i
        pairSolution[i] = 0;//初始化
        for (int j = 0; j < stationCount; j++) { //計算跟每個站點j的距離
            s = int(sqrt((station[j].x - scooter[i].x) * (station[j].x - scooter[i].x) + (station[j].y - scooter[i].y) * (station[j].y - scooter[i].y)));
            Distance[i][j] = s;
        }
    }

    for (int i = 0; i < stationCount; i++) {
        maxGasCount[i] = i + 1;
        isStationGasValid[i] = 1;
    }

    double START, END;
    START = clock();
    findSolutionDFS(0, pairSolution, carCount, stationCount);
    END = clock();

    cout << "總行駛距離: " << minDistance << "公尺" << endl;
    cout << "電動機車總耗能: " << 0.25 * (minDistance / 1000) << "度電/公里" << endl;
    cout << "(設電動機車每公里耗電量為 0.25 度電/公里)" << endl;

    cout << "進行運算所花費的時間："
        << (END - START) / 1000 << " 秒" << endl;

    system("pause");
    return 0;
}
