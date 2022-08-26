#include<iostream>

using namespace std;

int main() {
    int N, faces[6], tmp;
    string cmd;

    while(cin >> N && N != 0) {
        for(int i = 0; i < 6; i++) faces[i] = i;

        for(int i = 0; i < N; i++) {
            cin >> cmd;
            if(cmd == "north") {
                tmp = faces[4];
                faces[4] = faces[5];
                faces[5] = faces[1];
                faces[1] = faces[0];
                faces[0] = tmp;
            } else if(cmd == "east") {
                tmp = faces[0];
                faces[0] = faces[2];
                faces[2] = faces[5];
                faces[5] = faces[3];
                faces[3] = tmp;
            } else if(cmd == "south") {
                tmp = faces[0];
                faces[0] = faces[1];
                faces[1] = faces[5];
                faces[5] = faces[4];
                faces[4] = tmp;
            } else if(cmd == "west") {
                tmp = faces[3];
                faces[3] = faces[5];
                faces[5] = faces[2];
                faces[2] = faces[0];
                faces[0] = tmp;
            }
        }

        cout << faces[0] + 1 << endl;
    }
    
    return 0;
}