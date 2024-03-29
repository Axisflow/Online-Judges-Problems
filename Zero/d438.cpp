/*
Hello, World程式指的是只在計算機螢幕上輸出「Hello, World!」（意為「世界，你好！」）這行字元串的計算機程式。一般來說，這是每一種計算機程式語言中最基本、最簡單的程式，亦通常是初學者所編寫的第一個程式。它還可以用來確定該語言的編譯器、程式開發環境，以及執行環境是否已經安裝妥當。

將輸出字元串 "Hello World" 作為第一個範例程式，現在已經成為程式語言學習的傳統。該程式因 Brian Kernighan 和丹尼斯·里奇（Dennis M. Ritchie）所著的計算機程式設計教程《C語言程式設計》（The C Programming Language）中使用而廣泛流傳；但這本書並不是 "Hello World" 的濫觴，雖然這是一個普遍存在的錯誤認知。

「Hello World」範常式式最早出現於 1972 年，由貝爾實驗室成 員 Brian Kernighan 撰寫的內部技術文件《Introduction to the Language B》之中。不久同作者於 1974 年所撰寫的《Programming in C: A Tutorial》，也延用這個範例；而以本文件擴編改寫的《C語言程式設計》也保留了這個範例程式。

起初，"hello, world" 程式的標準列印內容必須滿足「全小寫，無驚嘆號，逗點後需空一格」。不過沿用至今，完全恪守傳統的反而罕見。
*/

#include <iostream>

using namespace std;

int main()
{
    cout << "hello, world" << endl;
    return 0;
}