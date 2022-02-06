#include<stdio.h>
#include<math.h>

int main(){
    int num;
    scanf("%d", &num);

    int player, target;
    double properbility, tmp;
    for(int i=1; i<=num; i++) {
        scanf("%d %lf %d", &player, &properbility, &target);

        if(properbility == 0){
            printf("0.0000\n", i);
            continue;
        }

        double now_proper = 0, target_proper;

        for(int j=1;j<=player;j++){
            tmp = properbility*pow(1-properbility, (double)j-1);
            now_proper += tmp;

            if(j==target){
                target_proper = tmp;
            }
        }

        printf("%.4lf\n", i, target_proper/now_proper);
    }

    return 0;
}
