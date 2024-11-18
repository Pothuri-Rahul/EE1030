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