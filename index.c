#include <stdio.h>
#include <stdlib.h>

void print_matrix(int **mat, int n){
    printf("\n");
    for(int i = 0; i < n; i++){
        for(int j = 0; j <n; j++){
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

void apply_effect(int **mat, int n){
    int arr[n][n];
    int tmp, fst_x_loc, fst_o_loc;
    
    //storing the rotation of the matrix in the new array
    for(int i=0; i < n; i++){
        tmp = n-1-i;
        for(int j=0; j<n; j++){
            arr[j][tmp] = mat[i][j];
        }
    }
  
    //after rotation copy the rotated matrix to the 'mat' matrix
    for(int i=0; i < n; i++){
        for(int j=0; j<n; j++){
            mat[i][j] = arr[i][j];
        }
    }
  
    printf("\nAfter Clockwise rotation:");
    print_matrix(mat, n);
  
    
    for(int j=0; j < n; j++){
        fst_x_loc = -1; fst_o_loc = -1;
        for(int i=0; i<n; i++){
            //finding the first 1 location and first 0 location in the column
            if(arr[i][j]==1 && fst_x_loc==-1)  fst_x_loc = i;
            else if(fst_o_loc==-1 && arr[i][j]==0) fst_o_loc = i;
        }
        if(fst_x_loc!=-1 && fst_o_loc!=-1){
            // swap the 1 and 0 values until all the 0s are moved to upside
            while(fst_x_loc < fst_o_loc && fst_o_loc < n && fst_x_loc < n){
                tmp = mat[fst_o_loc][j];
                mat[fst_o_loc][j] = mat[fst_x_loc][j];
                mat[fst_x_loc][j] = tmp;
                fst_x_loc++;
                while(fst_x_loc < n && mat[fst_x_loc][j]==0)  fst_x_loc++;
                fst_o_loc++;
                while(fst_o_loc < n && mat[fst_o_loc][j]==1)  fst_o_loc++;
            }
        }
    }
}

int main(){
    int n;
    //reading the size of the matrix
    scanf("%d", &n);
    //allocating the memory dynamically
    int **mat = (int **)malloc(sizeof(int *) * n);
    for(int i = 0 ; i<n;i++){
        mat[i] = (int*)malloc(sizeof(int) * n);
        for(int j =0; j<n;j++){
            scanf("%d", &mat[i][j]);
        }
    }
    // calling the function
    apply_effect(mat, n);
    printf("\nAfter Separation:");
    print_matrix(mat, n);
}
