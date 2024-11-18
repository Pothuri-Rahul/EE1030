void transpose(int r , int c , float A[r][c] , float B[c][r]){
    for(int i = 0 ; i < r ; i++){
        for(int j = 0 ; j < c ; j++){
            B[j][i] = A[i][j] ;
        }
    }
}