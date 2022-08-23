/*
文文很喜歡偶數，他甚至有收集偶數的習慣。你給他一個範圍的連續整數，他就會把其中的偶數留下來收藏。如今他又拿到了一個範圍的整數，請問他這次收藏了幾個偶數？對文文來說，0 也算是一個偶數哦！
*/

#include <iostream>
using namespace std;
int main() {
	int a, b;
	while (cin >> a >> b) {
		int m = a / 2, n = b / 2;
		int sum = n - m;

		cout << sum + (a + 1) % 2 << endl;
	}

	return 0;
}