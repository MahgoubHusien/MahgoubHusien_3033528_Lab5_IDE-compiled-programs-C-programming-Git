#include <stdio.h>

void combinations(int score){
    int td2p,td1p,td,fg,sfty;
    for (td2p = 0; td2p <= score/8; td2p++){
        for (td1p = 0; td1p <= score/7; td1p++){
            for (td = 0; td <= score/6; td++){
                for (fg = 0; fg <= score/3; fg++){
                    for (sfty = 0; sfty <= score/2; sfty++){
                        if ((td2p*8 + td1p*7 + td*6 + fg*3 + sfty*2)==score){
                            printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", td2p,td1p,td,fg,sfty);
                        }
                    }
                }
            }
        }
    }
}


int main(){
    int score;
    printf("Enter 0 or 1 to STOP\n");
    while (1){
        printf("Enter the NFL score: ");
        scanf("%d", &score);
        if (score < 2){
            break;
        }else{
        printf("possible combinations of scoring plays:\n");
        combinations(score);
    }
    }
    printf("Neither 0 or 1 points is possible in the NFL!");
}