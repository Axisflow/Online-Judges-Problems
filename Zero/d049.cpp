/*
國父孫中山於 1911 年武昌起義推翻滿清創立中華民國，並訂次年 (1912) 年為中華民國元年。從此國民政府便以中華民國國號記年至今。請寫一程式，將輸入的西元年份轉換成民國年份後輸出。
*/

#include<iostream>

using namespace std;

int main() {
	int y;

	cin >> y;
	cout << y - 1911 << '\n';
	
	return 0;
}