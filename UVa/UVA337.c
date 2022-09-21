#include<stdio.h>

typedef struct P {
    short r;
    short c;
} point;

inline void rowBegin(point *p) {
    p->c = 0;
}

void clear(char img[10][10]) {
    for(int r = 0; r < 10; r++) for(int c = 0; c < 10; c++) img[r][c] = EOF;
}

inline void nextRow(point *p) {
    if(p->r < 9) p->r++;
}

void erase(char img[10][10], point *p) {
    for(int c = p->c; c < 9; c++) img[p->r][c] = img[p->r][c + 1];

    img[p->r][9] = EOF;
}

inline void initialCursor(point *p) {
    p->r = 0; p->c = 0;
}

inline void changeMode(short *mode, short newmode) {
    *mode = newmode;
}

inline void previousColumn(point *p) {
    if(p->c > 0) p->c--;
}

inline void nextColume(point *p) {
    if(p->c < 9) p->c++;
}

inline void previousRow(point *p) {
    if(p->r > 0) p->r--;
}

inline void changeCursor(point *p, point *newp) {
    p->r = newp->r; p->c = newp->c;
}

void write(char img[10][10], point *p, short *mode, char ch) {
    if(*mode) {
        for(int c = 8; c >= p->c; c--) img[p->r][c + 1] = img[p->r][c];
        img[p->r][p->c] = ch;
    } else {
        img[p->r][p->c] = ch;
    }

    if(p->c < 9) p->c++;
}

void printIMG(char img[10][10]) {
    printf("+----------+\n");
    for(int r = 0; r < 10; r++) {
        printf("|");
        for(int c = 0; c < 10; c++) {
            if(img[r][c] == EOF) printf(" ");
            else printf("%c", img[r][c]);
        }
        printf("|\n");
    }
    printf("+----------+\n");
}

int main() {
    char ch, img[10][10];
    short mode;
    int N, cases = 0;
    point cur, tmp;

    while(scanf("%d", &N) != EOF && N) {
        printf("Case %d\n", ++cases);
        getchar();
        clear(img);
        initialCursor(&cur);
        mode = 0;

        while(N > 0 && (ch = getchar()) != EOF) {
            switch(ch) {
                case '^':
                    ch = getchar();
                    switch(ch) {
                        case 'b':
                            rowBegin(&cur);
                            break;
                        case 'c':
                            clear(img);
                            break;
                        case 'd':
                            nextRow(&cur);
                            break;
                        case 'e':
                            erase(img, &cur);
                            break;
                        case 'h':
                            initialCursor(&cur);
                            break;
                        case 'i':
                            changeMode(&mode, 1);
                            break;
                        case 'l':
                            previousColumn(&cur);
                            break;
                        case 'o':
                            changeMode(&mode, 0);
                            break;
                        case 'r':
                            nextColume(&cur);
                            break;
                        case 'u':
                            previousRow(&cur);
                            break;
                        case '^':
                            write(img, &cur, &mode, '^');
                            break;
                        default:
                            tmp.r = ch - '0';
                            tmp.c = getchar() - '0';
                            changeCursor(&cur, &tmp);
                            break;
                    }
                    break;
                case '\n':
                    --N;
                    break;
                default:
                    write(img, &cur, &mode, ch);
                    break;
            }
        }

        printIMG(img);
    }

    return 0;
}