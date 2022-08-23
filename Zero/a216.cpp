/*
數數是班上聰明又漂亮的女生，有一天……，她愛上了明明。

她對明明說：「我們的愛，若是錯誤，願你我沒有白白受苦。呃，不是，我們的愛就像是函數！」

明明說，「是啊，我對妳的愛是與日俱增呢！」

數數開心地說，「你的意思是，你在第 n 天對我的愛若用函數 f(n) 來描述，那麼，f(n) = n + f(n-1)。也就是說，每一天都比前一天多了一單位的愛，並且與舊的愛累積起來嗎？」

明明點了點頭，然後問，「那麼，妳呢？」

數數說，「我在第 n 天對你的愛若是 g(n)，則會滿足 g(n) = f(n) + g(n-1) 關係！」

於是，明明笑了笑，摟著數數說，我一定會更加愛妳的！

註：在第一天的時候，f(1) = g(1) = 1。 
*/

#include<iostream>

using namespace std;

long long f(int n) {
    return (long long) n * (n+1) / 2;
}

long long g(int n) {
    return (long long) n * (n+1) * (n+2) / 6;
}

int main() {
    int n;
    while(cin >> n) cout << f(n) << ' ' << g(n) << endl;

    return 0;
}