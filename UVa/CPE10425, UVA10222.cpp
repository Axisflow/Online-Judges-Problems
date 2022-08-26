#include<iostream>

using namespace std;

int main() {
    char c;
    char remap[128];
    remap[' '] = ' ';
    remap['\n'] = '\n';
    remap['a'] = ';';
    remap['b'] = 'c';
    remap['c'] = 'z';
    remap['d'] = 'a';
    remap['e'] = 'q';
    remap['f'] = 's';
    remap['g'] = 'd';
    remap['h'] = 'f';
    remap['i'] = 'y';
    remap['j'] = 'g';
    remap['k'] = 'h';
    remap['l'] = 'j';
    remap['m'] = 'b';
    remap['n'] = 'v';
    remap['o'] = 'u';
    remap['p'] = 'i';
    remap['q'] = ']';
    remap['r'] = 'w';
    remap['s'] = '\'';
    remap['t'] = 'e';
    remap['u'] = 't';
    remap['v'] = 'x';
    remap['w'] = '\\';
    remap['x'] = '/';
    remap['y'] = 'r';
    remap['z'] = '.';
    remap['A'] = ';';
    remap['B'] = 'c';
    remap['C'] = 'z';
    remap['D'] = 'a';
    remap['E'] = 'q';
    remap['F'] = 's';
    remap['G'] = 'd';
    remap['H'] = 'f';
    remap['I'] = 'y';
    remap['J'] = 'g';
    remap['K'] = 'h';
    remap['L'] = 'j';
    remap['M'] = 'b';
    remap['N'] = 'v';
    remap['O'] = 'u';
    remap['P'] = 'i';
    remap['Q'] = ']';
    remap['R'] = 'w';
    remap['S'] = '\'';
    remap['T'] = 'e';
    remap['U'] = 't';
    remap['V'] = 'x';
    remap['W'] = '\\';
    remap['X'] = '/';
    remap['Y'] = 'r';
    remap['Z'] = '.';
    remap['['] = 'o';
    remap[']'] = 'p';
    remap['\\'] = '[';
    remap[';'] = 'k';
    remap['\''] = 'l';
    remap[','] = 'n';
    remap['.'] = 'm';
    remap['/'] = ',';
    
    while((c = cin.get()) != EOF) cout << remap[c];

    return 0;
}