#include<stdio.h>

int main(){
    int num;
    scanf("%d", &num);

    int jolly[num-1];
    for(int i = 0; i < num-1; i++) jolly[i]=0;

    int tmp1, tmp2, diff, cont=1; scanf("%d", &tmp1);
    for(int i = 1; i < num; i++, tmp1 = tmp2){
        scanf("%d", &tmp2);
        if(cont){
            diff = tmp2-tmp1;

            if(diff==0 || (diff<0?diff=-diff:diff)>=num){
                if(cont) printf("Not jolly");
                cont = 0;
            }

            if(jolly[diff-1]==0){
                jolly[diff-1] = 1;
            } else {
                if(cont) printf("Not jolly");
                cont = 0;
            }
        }
    }

    if(cont) printf("Jolly");

    printf("\n");
    return 0;
}
