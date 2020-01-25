/**
 * Jason Katsaros
 */

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

int main() {
    int maxMatrixLength = 1000;
    int maxKernelLength = 9;

    //Initialize arrays for holding all of the file values==========
    float **inputArr = new float*[maxMatrixLength];
    for (int i = 0; i < maxMatrixLength; ++i) {
        inputArr[i] = new float[maxMatrixLength];
    }

    float **kernelArr = new float*[maxKernelLength];
    for (int i = 0; i < maxKernelLength; ++i) {
        kernelArr[i] = new float[maxKernelLength];
    }
    //Initialize arrays for holding all of the file values==========

    //Read in matrix from file/command line=========================
    string line;
    int i = 0;
    int j = 0;
    bool k = false;
    float num;

    while (getline(cin, line)) {
        if (line.length() == 0) { //the line between input matrix and kernel matrix is blank
            k = true;
            j = 0; //reset to the first row
        }

        istringstream stream(line); //line will be streamed, one number at a time
        i = 0; //resets to first column after finishing the row
        while(stream >> num) { //each number is put into the float 'num'
            if (!k) { //which matrix are we dealing with
                inputArr[j][i] = num;
            } else {
                kernelArr[j][i] = num;
            }
            i++; //shift to the right in the matrix for the next number
        }
        j++; //shift down in the matrix for the next row
    }
    //Read in matrix from file/command line=========================

    //TODO: 2D-Convolution

    //TODO: 2D-Convolution

    //Delete arrays=================================================
    for (int i = 0; i < maxMatrixLength; ++i) {
        delete [] inputArr[i];
    }
    delete [] inputArr;

    for (int i = 0; i < maxKernelLength; ++i) {
        delete [] kernelArr[i];
    }
    delete [] kernelArr;
    //Delete arrays=================================================

    return 0;
}