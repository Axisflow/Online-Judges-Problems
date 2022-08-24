/*
在一個神奇的國度裡，有一種兔子，它只吃蘿蔔，且每天只吃一個，蘿蔔有四種顏色，分別為：紅蘿蔔，白蘿蔔，黃蘿蔔，發霉的蘿蔔（黑色），兔子吃了蘿蔔之後，體重會有不同的變化，紅蘿蔔吃了胖xg，白蘿蔔吃了胖yg，黃蘿蔔吃了瘦zg(醃黃蘿蔔真難吃...)，發霉的蘿蔔吃了瘦wg(附加狀態：中毒...)，現在給你x,y,z,w問你幾天後，兔子的體重！

p.s.中毒會使兔子每天瘦ng(中毒當天不算),且中毒狀態可累加，m是兔子初始的體重。早上先中毒，晚上才吃東西。

上面的敘述很重要，要仔細看！
*/

#include<iostream>

using namespace std;

int main() {
    int cases, w, x, y, z, n, m, poi;
    bool lineEnd;
    char c;
    
    cin >> cases;
    for (int ca = 0; ca < cases; ca++) {
        cin >> x >> y >> z >> w >> n >> m;
        cin.get();

        poi = 0;
        lineEnd = false;
        while(m > 0) {
            c = cin.get();
            
            if(c != ' ' && c != '\n') {
                m -= poi;
                if(m <= 0) break;
            }

            if(c == '0') {
                
            } else if(c == '1') {
                m += x;
            } else if(c == '2') {
                m += y;
            } else if(c == '3') {
                m -= z;
            } else if(c == '4') {
                m -= w;
                poi += n;
            } else if(c == '\n') {
                lineEnd = true;
                break;
            }
        }
        
        if(!lineEnd) while((c = cin.get()) != '\n');
        
        if(m <= 0) cout << "bye~Rabbit";
        else cout << m << 'g';

        cout << endl;
    }
    
    return 0;
}