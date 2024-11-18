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
    printf("Eigenvalues of the given Mastrix are : \n");
    for(int i = 0 ; i < n ; i++){
        printf("%f ",result[i]);
    }
    
    return 0;
}

