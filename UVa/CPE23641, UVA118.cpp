#include<iostream>
#include<map>

using namespace std;

typedef struct posface {
    int x;
    int y;
} Point_Face;

struct cmp {
    bool operator() (const Point_Face &x, const Point_Face &y) const {
        return (x.x < y.x || (x.x == y.x && x.y < y.y));
    }
};

int main() {
    int max_x, max_y;
    int x, y, i;
    char face;
    bool lost;
    string s;
    map<Point_Face, bool, cmp> scent;

    cin >> max_x >> max_y;
    while(cin >> x >> y >> face >> s) {
        lost = false;
        for(int i = 0; i < s.length() && !lost; i++) {
            switch(s[i]) {
                case 'R':
                    switch(face) {
                        case 'N':
                            face = 'E';
                            break;
                        case 'E':
                            face = 'S';
                            break;
                        case 'S':
                            face = 'W';
                            break;
                        case 'W':
                            face = 'N';
                            break;
                    }
                    break;
                case 'L':
                    switch(face) {
                        case 'N':
                            face = 'W';
                            break;
                        case 'W':
                            face = 'S';
                            break;
                        case 'S':
                            face = 'E';
                            break;
                        case 'E':
                            face = 'N';
                            break;
                    }
                    break;
                case 'F':
                    switch(face) {
                        case 'N':
                            if (y < max_y) 
                                y++;
                            else if(scent.count({x, y}) == 0) {
                                    lost = true;
                                    scent[{x, y}] = true;
                            }
                            break;
                        case 'E':
                            if (x < max_x)
                                x++;
                            else if(scent.count({x, y}) == 0) {
                                    lost = true;
                                    scent[{x, y}] = true;
                            }
                            break;
                        case 'S':
                            if (y > 0)
                                y--;
                            else if(scent.count({x, y}) == 0) {
                                    lost = true;
                                    scent[{x, y}] = true;
                            }
                            break;
                        case 'W':
                            if (x > 0)
                                x--;
                            else if(scent.count({x, y}) == 0) {
                                    lost = true;
                                    scent[{x, y}] = true;
                            }
                            break;
                    }
                    break;
            }
        }
        
        cout << x << ' ' << y << ' ' << face << (lost ? " LOST\n" : "\n");
    }

    return 0;
}