/*
珊珊在美國讀書，有一天覺得昏沉沉的全身不舒服，心想自己是不是發燒了。到藥局買了一支體溫計量了一下體溫，發現她的體溫是華氏 104 度。習慣了台灣的攝氏，她一時還不知道自己的體溫到底有多燒。你能不能幫她寫個程式，把華氏的溫度轉成攝氏的溫度。
*/

#include<iostream>
#include<iomanip>

using namespace std;
int main() {
	int f;
	while (cin >> f) {
		cout << fixed << setprecision(3) << (f - 32) / 1.8 << endl;
	}

	return 0;
}