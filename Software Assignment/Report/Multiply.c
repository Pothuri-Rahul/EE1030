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