#include<stdio.h>

short static inline _abs(short x) {
    if(x < 0) return -x;
    else return x;
}

const short inSameArea(short king, short queen, short place) {
    if(king%8 == queen%8)
    if((queen > king && place > king) || (queen < king && place < king)) return 1;
    else return 0;
}

const char* movequeen(short king, short queen, short place) {
    if(king != queen) {
        if(((queen%8 == place%8 && (king%8 != queen%8 || inSameArea(king, queen, place))) || (queen/8 == place/8 && (king/8 != queen/8 || inSameArea(king, queen, place)))) && queen != place) {
            if((_abs(king - place) == 1) || (_abs(king - place) == 8)) return "Move not allowed";
            else {
                if((king == 0 && place == 9) || (king == 7 && place == 15) || (king == 56 && place == 49) || (king == 63 && place == 54)) return "Stop";
                else return "Continue";
            }
        } else return "Illegal move";
    } else return "Illegal state";
}

int main() {
    short queen, king, place;

    while(scanf("%hd %hd %hd", &king, &queen, &place) != EOF) printf("%s\n", movequeen(king, queen, place));

    return 0;
}