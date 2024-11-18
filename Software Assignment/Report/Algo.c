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