#include<stdio.h>
#include<stdlib.h>

int main() {
    int n, d, ni, x, y, now_distance, max_distance, mode, record;

    while(scanf("%d %d", &n, &d)) {
        int *ns = (int *)malloc(sizeof(int) * n);;

        for(int i=0; i<n; i++) {
            scanf("%d", ns+i);
        }

        x = 0; y = 0;
        now_distance = 0;
        max_distance = 0;
        mode = 1;
        record = 0;
        for(int i=0; i<n; i++) {
            if(*(ns+i) == 1) {
                x++;
                if(mode == 0) {
                    mode = 1;
                }

                now_distance++;

                record = 1;
            } else {
                y++;
                if(mode == 1) {
                    mode = 0;
                    if(now_distance > max_distance) max_distance = now_distance;
                }

                if(x-d <= y && y <= x+d && record == 1) {
                    now_distance++;
                    if(now_distance > max_distance) max_distance = now_distance;
                } else {
                    x = 0;
                    y = 0;
                    record = 0;
                    now_distance = 0;
                }
            }
        }

        printf("%d\n", max_distance);
        free(ns);
    }
    return 0;
}