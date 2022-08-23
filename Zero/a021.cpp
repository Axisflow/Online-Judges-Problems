/*
我們都知道電腦擅長於各種數字的計算，可是，我們又知道各種程式語言的變數又都有上限，比如整數只有232 或 264 個。如果要計算更大的數字時又該如何計算呢? 就交給聰明的您來解決囉。

以 + 代表加法
以 - 代表減法
以 * 代表乘法
以 / 代表除法 (取商數)
*/

#include<iostream>
#include<vector>

using namespace std;

short compare(vector<short>* x, vector<short>* y) {
    int sizeX = x->size(), sizeY = y->size();
    if(sizeX > sizeY) {
        return 1;
    } else if(sizeX < sizeY) {
        return -1;
    } else {
        for(vector<short>:: iterator itX = x->begin(), itY = y->begin(); itX != x->end(); itX++, itY++) {
            if(*itX > *itY) return 1;
            else if(*itX < *itY) return -1;
        }
        return 0;
    }
}

void reverse(vector<short>* x) {
    int sizeX = x->size();
    short tmp;

    for(int i=0; i<sizeX/2; i++) {
        tmp = (*x)[i];
        (*x)[i] = (*x)[sizeX-i-1];
        (*x)[sizeX-i-1] = tmp;
    }
}

void add(vector<short> x, vector<short> y, vector<short> *result) {
    int sizeX = x.size(), sizeY = y.size(), sizeMax = max(sizeX, sizeY);
    short c=0, xi, yi, sum;

    for(int i=0; i<sizeMax; i++) {
        xi = (sizeX > i ? x[sizeX - i - 1] : 0);
        yi = (sizeY > i ? y[sizeY - i - 1] : 0);

        sum = xi + yi + c;
        result->push_back(sum%10);
        c = sum / 10;
    }
    if(c != 0) result->push_back(c);
}

void componement(vector<short>* x) {
    for(vector<short>:: iterator it=x->begin(); it!=x->end(); it++) *it = 9-*it;
}

void decrese(vector<short> x, vector<short> y, vector<short> *result) {
    short comp = compare(&x, &y), c=1, xi, yi, sum;
    vector<short> *_x, *_y;
    if(comp == 1) {
        _x = &x;
        _y = &y;
    } else if(comp == -1) {
        _x = &y;
        _y = &x;
    } else {
        result->push_back(0);
        return;
    }

    componement(_y);
    int sizeX = _x->size(), sizeY = _y->size(), sizeMax = sizeX;
    for(int i=0; i<sizeMax; i++) {
        xi = (*_x)[sizeX - i - 1];
        yi = (sizeY > i ? (*_y)[sizeY - i - 1] : 9);

        sum = xi + yi + c;
        result->push_back(sum%10);
        c = sum / 10;
    }
    
    for(; *(result->end()-1) == 0;) result->pop_back();

    if(comp == -1) *(result->end()-1) *= -1;
}

void mutliply(vector<short> x, vector<short> y, vector<short> *result) {
    vector<vector<short>> list = {{0,0,0,0,0,0,0,0,0,0},
                                  {0,1,2,3,4,5,6,7,8,9},
                                  {0,2,4,6,8,10,12,14,16,18},
                                  {0,3,6,9,12,15,18,21,24,27},
                                  {0,4,8,12,16,20,24,28,32,36},
                                  {0,5,10,15,20,25,30,35,40,45},
                                  {0,6,12,18,24,30,36,42,48,54},
                                  {0,7,14,21,28,35,42,49,56,63},
                                  {0,8,16,24,32,40,48,56,64,72},
                                  {0,9,18,27,36,45,54,63,72,81}};
    int sizeX = x.size(), sizeY = y.size(), c=0, sum;

    for(int i=0; i<sizeY+sizeX-1; i++) {
        sum=c;
        for(int j=0; j<sizeY; j++) {
            if(i-j >= 0 && i-j < sizeX) sum += list[x[sizeX-i+j-1]][y[sizeY-j-1]];
        }
        result->push_back(sum%10);
        c = sum / 10;
    }
    if(c != 0) result->push_back(c);
}

void mutliplyConstance(vector<short> x, short y, vector<short> *result) {
    if(y == 0) {
        result->push_back(0);
        return;
    }

    vector<vector<short>> list = {{0,0,0,0,0,0,0,0,0,0},
                                  {0,1,2,3,4,5,6,7,8,9},
                                  {0,2,4,6,8,10,12,14,16,18},
                                  {0,3,6,9,12,15,18,21,24,27},
                                  {0,4,8,12,16,20,24,28,32,36},
                                  {0,5,10,15,20,25,30,35,40,45},
                                  {0,6,12,18,24,30,36,42,48,54},
                                  {0,7,14,21,28,35,42,49,56,63},
                                  {0,8,16,24,32,40,48,56,64,72},
                                  {0,9,18,27,36,45,54,63,72,81}};
    int sizeX = x.size(), c=0, sum;

    for(vector<short>::iterator it = x.end()-1; it != x.begin()-1; it--) {
        sum = list[*it][y] + c;
        result->push_back(sum%10);
        c = sum / 10;
    }
    if(c != 0) result->push_back(c);
}

void divide(vector<short> x, vector<short> y, vector<short> *result) {
    int sizeX = x.size(), sizeY = y.size(), c, sum;
    short comp;
    vector<short> tmp, tmp_mutli, miner, leave;

    for(int i=0; i<sizeY-1; i++) {
        tmp.push_back(x[i]);
    }

    for(int i=sizeX-sizeY; i>=0; i--) {
        tmp.push_back(x[sizeX-i-1]);
        c = 0;
        for(int j=0; j<=9; j++) {
            tmp_mutli.clear();
            mutliplyConstance(y, j, &tmp_mutli);
            reverse(&tmp_mutli);
            comp = compare(&tmp, &tmp_mutli);
            
            if(comp == 1) {
                c = j;
                miner = tmp_mutli;
            }
            else if(comp == -1) break;
            else {
                c = j;
                miner = tmp_mutli;
                break;
            } 
        }
        if(i!=sizeX-sizeY || c!=0) result->push_back(c);

        leave.clear();
        decrese(tmp, miner, &leave);
        reverse(&leave);

        if(leave.size() == 1 && leave[0] == 0) tmp.clear();
        else tmp = leave;
    }

    if(result->size() == 0) result->push_back(0);
    reverse(result);
}

int main() {
    vector<short> x, y, result;
    char c, waitfor = 'x', operate;

    while(c = cin.get()) {
        if(c == ' ') {
            if(waitfor == 'x') {
                waitfor = 'o';
            } else if(waitfor == 'o') {
                waitfor = 'y';
            }
        } else if(c == '\n' || c == EOF) {
            if(operate == '+') {
                add(x, y, &result);
            } else if(operate == '-') {
                decrese(x, y, &result);
            } else if(operate == '*') {
                mutliply(x, y, &result);
            } else if(operate == '/') {
                divide(x, y, &result);
            }

            for(int i = result.size() - 1; i >= 0; i--) cout << result[i];
            cout << endl;

            waitfor = 'x';
            x.clear(); y.clear(); result.clear();

            if(c == EOF) break;
        } else {
            if(waitfor == 'x') {
                x.push_back(c - '0');
            } else if(waitfor == 'y') {
                y.push_back(c - '0');
            } else if(waitfor == 'o') {
                operate = c;
            }
        }
    }

    return 0;
}