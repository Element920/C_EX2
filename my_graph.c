#include <stdio.h>
#include "my_mat.h"

int my_graph(){
    int flag = 0;
    char cr;
    int mat[V][V];
    int i=0;
    int j=0;
    while(flag != 1){
        scanf("%c", &cr);
        if(cr == 'D'|| "OEF"){
            flag = 1;
        }
        else if(cr == 'A'){
            matrixInsert(mat);
        }
        else if(cr == 'B'){
            scanf("%d", &i);
            scanf("%d", &j);
            isRoutable(mat, i, j);
        }
        else if(cr == 'C'){
            scanf("%d", &i);
            scanf("%d", &j);
            shortest(mat, i, j);
        }
    }
    return 0;
}