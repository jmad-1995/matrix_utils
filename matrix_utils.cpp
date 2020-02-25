#include <stdio.h>
#include <iostream>
#include "matrix_utils.h"

using namespace std;
/**
 * Checks if input matrix is valid.
 *
 * @param matrix Input Matrix.
 * @return a vector with three values, first value is 1 if the matrix is valid else 0 if invalid. Second value and third value are the number of rows and number of columns respectively.
 */
vector<int> checkValidMatrix(vector<vector<float> > &matrix){
    //cout<<"Entering Check valid matrix"<<endl;
    int rows = matrix.size();
    int cols = matrix[0].size();
    vector<int> ret = {0,-1,-1};
    for(int r=0;r<rows;r++){
        if(matrix[r].size() != cols){
            cout<<"checkValidMatrix: Given matrix is invalid"<<endl;
            //throw 0;
            return ret;
        }
    }
    if(rows == 0 || cols ==0){
        cout<<"checkValidMatrix: We consider empty matrices as invalid too"<<endl;
        return ret;
    }
    ret = {1,rows, cols};
    return ret;
}

/**
 * Prints a 2d array.
 *
 * @param matrix Input Matrix.
 * @return outputs the array on standard output if valid.
 */
void print2DArray(vector<vector<float> > matrix){
    vector<int> result = checkValidMatrix(matrix);
    if(result[0]!= 0){
        int nr = result[1];
        int nc = result[2];
        cout<<"print2DArray"<<endl;
        for(int r = 0; r < nr; r++){
            for(int c = 0; c < nc; c++){
                cout << matrix[r][c] << "\t";
            }
            cout<<endl;
        }
        cout<<endl;
    }
}

/**
 * Get transpose of input matrix.
 *
 * @param matrix Input Matrix.
 * @return Transpose of the matrix if valid else empty two dimensional vector.
 */
vector<vector<float> > MatrixTranspose(vector<vector<float>> &matrix){
    vector<int> result = checkValidMatrix(matrix);
    if(result[0] != -1) {
        int rows, cols;
        rows = result[1];
        cols = result[2];
        vector<vector<float> > newMatrix(cols);
        // create a new 2d vector of opposite dims
        for(int i =0;i<cols;i++){
            vector<float> r(rows);
            newMatrix[i] = r;
        }
        // populate the elements in the new matrix one by one
        for(int r =0;r<rows;r++){
            for(int c=0;c<cols;c++){
                newMatrix[c][r] = matrix[r][c];
            }
        }
        return newMatrix;
    }
    vector<vector<float>> newMatrix = {{}};
    return newMatrix;
}

/**
 * Multiply two valid matrices.
 *
 * @param matrixA Input Matrix one.
 * @param matrixB Input Matrix two.
 * @return Result of matrix multiplication of matrix one and two if both of them are valid and follow matrix multiplication properties.
 */
vector<vector<float> > MatrixMultipy(vector<vector<float> > &matrixA, vector<vector<float> > &matrixB){
    vector<int> mat1_dims = checkValidMatrix(matrixA);
    vector<int> mat2_dims = checkValidMatrix(matrixB);
    vector<vector<float>> matrix = {{}};

    // First check if they are valid matrices
    if(mat1_dims[0]==1 && mat2_dims[0]==1){
        if(mat1_dims[2] == mat2_dims[1]){
            // If they are, and cols of 1st matrix and rows of 2nd
            // matrix are same; proceed to do the multiplication
            //cout<<"Entered a valid matrix"<<endl;
            int r1,r2,c1,c2;
            r1 = mat1_dims[1];
            r2 = mat2_dims[1];
            c1 = mat1_dims[2];
            c2 = mat2_dims[2];
            // construct new matrix of dimensions r1*c2
            vector<vector<float> > newMatrix(r1);
            for(int i =0;i<r1;i++){
                vector<float> r(c2);
                newMatrix[i] = r;
            }
            // Populate the elements of new array by
            // doing a row wise - column wise multiplcation
            // on old arrays to get an element in new array
            // using vanilla matrix multiplication
            for(int r = 0; r<r1; r++){
                for(int c = 0;c<c2; c++){
                    newMatrix[r][c] = 0;
                    for (int k = 0; k < c1; k++)  {
                        newMatrix[r][c] += matrixA[r][k] * matrixB[k][c];
                    }
                }
            }
            return newMatrix;
        }
        else{
            cout<<"Please use correct matrix dimensions, "
                <<"you can only multiply matrices of dims m*n and n*p "<<endl;
        }
    }       return matrix;
}