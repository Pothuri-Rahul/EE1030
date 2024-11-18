#include <stdio.h>
#include <math.h>

void Multiply(int n,float A[n][n],float B[n][n],float AB[n][n]){
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            AB[i][j] = 0 ;
        }
    }
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            for(int k = 0 ; k < n ; k++){
            AB[i][j] = AB[i][j] + ( A[i][k] * B[k][j] );
            }
        }
    }
}

void transpose(int r , int c , float A[r][c] , float B[c][r]){
    for(int i = 0 ; i < r ; i++){
        for(int j = 0 ; j < c ; j++){
            B[j][i] = A[i][j] ;
        }
    }
}


void qrDecomposition(int n , float A[n][n] , float Q[n][n] , float R[n][n]){
    
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            Q[i][j] = 0 ;
            R[i][j] = 0 ;
        }
    }
    
    for(int k = 0 ; k < n ; k++){
        double normSqr = 0;
        for(int i = 0 ; i < n ; i++){
            normSqr = normSqr + pow(A[i][k] , 2);
        }
        R[k][k] = sqrt(normSqr);
        for(int i = 0 ; i < n ; i++){
            Q[i][k] = A[i][k]/R[k][k] ;
        }
        for (int j = k + 1 ; j < n; j++) {
            R[k][j] = 0;
            for (int i = 0 ; i < n ; i++) {
                R[k][j] = R[k][j] + ( Q[i][k] * A[i][j] );
            }
            for (int i = 0 ; i < n ; i++) {
                A[i][j] = A[i][j] - ( Q[i][k] * R[k][j] );
            }
        }
    }
}


void Algorithm(int n , float A[n][n] , float result[n]){
    float Q[n][n] , R[n][n];
    
    for(int x = 0 ; x < 1000 ; x++){
        float A1[n][n];
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                A1[i][j] = A[i][j];
            }
        }
        qrDecomposition(n , A1 , Q , R);
        Multiply(n , R , Q , A);
        double nonDiagNorm = 0;
        for (int i = 0 ; i < n ; i++) {
            for (int j = 0 ; j < n ; j++) {
                if (i != j) {
                    nonDiagNorm = nonDiagNorm + pow(A[i][j] , 2 );
                }
            }
        }
        for (int i = 0 ; i < n ; i++) {
        result[i] = A[i][i];
        
        } 
        if (sqrt(nonDiagNorm) < pow(10,-100)) {
            break;
        }
    }
    
    
}


int main(){
    int n;
    printf("Enter the size of the matrix: ");
    scanf("%d",&n);
    float A[n][n];
    float result[n];
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            scanf("%f", &A[i][j]);
        }
    }
    Algorithm( n , A , result);
    for(int i = 0 ; i < n ; i++){
        printf("%f ",result[i]);
    }
    
    return 0;
}
