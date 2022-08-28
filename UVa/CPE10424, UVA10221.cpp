#include<iostream>
#include<iomanip>
#include<cmath>

#define PI 3.1415926535897932384626433832795
#define EARTH 6440

using namespace std;

int main() {
    int s, a;
    double adis, cdis;
    string type;

    while (cin >> s >> a >> type) {
        if(type == "deg") {
            adis = PI * (s + EARTH) * (a%360 > 180 ? 360-a%360 : a%360) / 180;
            cdis = sin((a%360 > 180 ? 360-a%360 : a%360) * PI / 360.0) * (s + EARTH) * 2;
        } else if(type == "min") {
            adis = PI * (s + EARTH) * (a%21600 > 10800 ? 21600-a%21600 : a%21600) / 10800;
            cdis = sin((a%21600 > 10800 ? 21600-a%21600 : a%21600) * PI / 21600.0) * (s + EARTH) * 2;
        }

        cout << fixed << setprecision(6) << adis << ' ' << cdis << endl;
    }
    


    return 0;
}