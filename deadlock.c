#include<stdio.h>

int main()
{
int n, m;
printf("Number of process:");
scanf("%d", &n);
printf("Number of Resource:");
scanf("%d", &m);

int maxx[n][m], alloc[n][m], avi[m], need[n][m];

//for allocation scan
printf("Please enter allocation value\n");
for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
        scanf("%d", &alloc[i][j]);
    }
}

//for max scan
printf("Please enter Maximum value\n");
for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
        scanf("%d", &maxx[i][j]);
    }
}

// for available scan
printf("Please enter Available value\n");
for(int i=0; i<m; i++) {
    scanf("%d", &avi[i]);
}

//for finding need matrix
printf("The need Matrix for this system:\n");
for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
        need[i][j] = maxx[i][j] - alloc[i][j];
    }
}
// Safety Algorithm 

int finish[n], avi2[m], cnt=0, safeSequence[n];
for(int i=0; i<n; i++) {
    // finish array is used as a checker, if the process got the resources or not from available
    // initially all the index is put to zero as no process got the resources fro available
    finish[i] = 0;
}
/*this avi2 array is a dupilicate of avi array available, 
this array is used to store the new available values which changes with each process resource allocation */
for(int i=0; i<m; i++) {
    avi2[i] = avi[i];
}
//k for loop for checking all the process 
for(int k=0; k<n; k++) {
    for(int i=0; i<n; i++) {
        if(finish[i]==0) {
            int flag = 0;
            for(int j=0; j<m; j++) {
                if(need[i][j] > avi2[j]) {
                    flag=1; break;
                }
            }
                if(flag==0) {
                    for(int a=0; a<m; a++) {
                        avi2[a]=avi2[a]+alloc[i][a];
                    }
                    safeSequence[cnt++] = i;
                    finish[i] = 1;
                }
        }
    }
}

for(int i=0; i<n; i++){
        printf("\n");
    for(int j=0; j<m; j++){
        printf("%d ", need[i][j]);
    }
}
printf("\n");
printf("The Safe Sequence for this system:\n");
for(int i=0; i<n; i++) {
    printf("->P%d", safeSequence[i]);
}
printf("\n");
printf("The Available resource after the safety check:\n");
for(int i=0; i<m; i++) {
    printf("%d ", avi2[i]);
}




}