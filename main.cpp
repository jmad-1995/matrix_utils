#include <stdio.h>
#include <iostream>
#include <vector>
#include "matrix_utils.h"

using namespace std;

int main(){
// Driver program to test above functions
//please play around with the following vectors

//Part - 1 Example of Matrix transpose
    vector<vector<float> > v  = {{12,1,2},{1,2,3}};
    print2DArray(v);

	vector<vector<float> > vt = MatrixTranspose(v);
	print2DArray(vt);

//------------------------------------------------------------------------------------------------------------------------

//Part - 2 Example of Matrix Multiplication

    vector<vector<float> > vect = {{1,4},{2,1},{0,0},{5,5}};
    print2DArray(vect);

    vector<vector<float> > vect_tr = MatrixTranspose(vect);
    print2DArray(vect);

    vector<vector<float> > newMat =  MatrixMultipy(vect, vect_tr);
    print2DArray(newMat);

	return 0;
}
