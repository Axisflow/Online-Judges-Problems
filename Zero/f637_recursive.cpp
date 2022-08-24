/*
DF-express (深度優先圖像表示式) 是一個具有高度資料壓縮能力的四元樹表示法。雖然主要為二階黑白圖片所設計，但是透過位元平面 (bit-plane) 或是 3D 表示法，亦可用來壓縮灰階圖片。

本題中所處理的圖片為二階的黑白圖片，也就是每個像素非黑即白，沒有中間的灰色。圖片大小為 n×n，n 是 2 的冪次，也就是存在某個非負整數 k 使得 n = 2k。

一個 n×n 的黑白影像可以用下列遞迴方式編碼：

如果每一格像素都是白色，我們用0來表示； 如果每一格像素都是黑色，我們用1來表示； 否則，並非每一格像素都同色，先將影像均等劃分為四個邊長為 n/2 的小正方形後，然後表示如下：先寫下2，之後依續接上左上、右上、左下、右下四塊的編碼。

DF Expression
一個壓縮後的影像會表示成一個由 0、1、2 組成的字串 S。在這個問題中，根據字串 S 以及影像尺寸 n，請計算原始影像中有多少個像素是 1。
*/

#include<iostream>

using namespace std;

int sum(string &dfs, int &nowloc, int size) {
    if(size == 0) return 0;
    else {
        if(dfs[nowloc] == '1') return size * size;
        else if(dfs[nowloc] == '2') {
            return sum(dfs, nowloc += 1, size / 2) + sum(dfs, nowloc += 1, size / 2) + sum(dfs, nowloc += 1, size / 2) + sum(dfs, nowloc += 1, size / 2);
        } else return 0;
    }
}

int main() {
    string S;
    int n, loc = 0;

    cin >> S >> n;
    cout << sum(S, loc, n) << endl;
    
    return 0;
}