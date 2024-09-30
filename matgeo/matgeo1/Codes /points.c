#include <stdio.h>
int main(){
	int A[2]={1,5},B[2]={2,3},C[2]={-2,-11};
	FILE *ptr;
	ptr=fopen("data.txt","w");
	for (int i=0;i<2;i++){

	fprintf(ptr, "%d ",A[i]);
	}
	fprintf(ptr,"\n");
	for (int i=0;i<2;i++){
                
        fprintf(ptr, "%d ",B[i]);
        }
	fprintf(ptr,"\n");
	for (int i=0;i<2;i++){
                
        fprintf(ptr, "%d ",C[i]);
        }
	return 0;
}
