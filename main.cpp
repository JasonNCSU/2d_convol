/**
 * Jason Katsaros
 */

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

void sequential_convolution(double **inputArr, int inputWidth, int inputHeight, double **kernelArr, int kernelWidth, int kernelHeight, double **outputArr) {
    int temp = 0;
}

void print(double **array, int width, int height) {
    int i = 0;
    int j = 0;

    for (j = 0; j < height; j++) {
        printf("row %d: ", j);
        for (i = 0; i < width; i++) {
            printf("%.3f | ", array[j][i]);
        }
        printf("\n");
    }
    printf("\n");
}

int main(int argc, char **argv) {
    int maxMatrixLength = 1000;
    int maxKernelLength = 9;
    int inputWidth = 0;
    int inputHeight = 0;
    int kernelWidth = 0;
    int kernelHeight = 0;

    //Initialize arrays for holding all of the file values==========
    double **inputArr = new double*[maxMatrixLength];
    for (int i = 0; i < maxMatrixLength; ++i) {
        inputArr[i] = new double[maxMatrixLength];
    }

    double **kernelArr = new double*[maxKernelLength];
    for (int i = 0; i < maxKernelLength; ++i) {
        kernelArr[i] = new double[maxKernelLength];
    }
    //Initialize arrays for holding all of the file values==========

    //Read in matrix from file======================================
    char *trace_file = nullptr;
    trace_file = argv[1]; //file is the only argument provided from the command line

    int i = 0;
    int j = 0;
    bool k = false;
    double num;

    string line;
    ifstream input(trace_file);
    while (getline(input, line)) {
        if (line.length() == 0) { //the line between input matrix and kernel matrix is blank
            k = true; //swap to h-matrix from input-matrix
            inputWidth = i;
            inputHeight = j;
            j = 0; //reset to the first row
        }
        else {
            stringstream stream(line); //line will be streamed, one number at a time
            i = 0; //resets to first column after finishing the row
            while(stream >> num) { //each number is put into the double 'num'
                if (!k) { //which matrix are we dealing with
                    inputArr[j][i] = num;
                } else {
                    kernelArr[j][i] = num;
                }
                i++; //shift to the right in the matrix for the next number
            }
            j++; //shift down in the matrix for the next row
        }
    }
    kernelWidth = i;
    kernelHeight = j;
    //Read in matrix from file======================================

    //Initialize output array=======================================
    int outputWidth = inputWidth + (kernelWidth - 1);
    int outputHeight = inputHeight + (kernelHeight - 1);

    double **outputArr = new double*[outputHeight];
    for (int i = 0; i < outputHeight; ++i) {
        outputArr[i] = new double[outputWidth];
    }
    //Initialize output array=======================================

    //test print====================================================
    print(inputArr, inputWidth, inputHeight);
    print(kernelArr, kernelWidth, kernelHeight);
    //test print====================================================

    //TODO: 2D-Convolution Sequential
    //Sequential 2D-Convolution=====================================
    sequential_convolution(inputArr, inputWidth, inputHeight, kernelArr, kernelWidth, kernelHeight, outputArr);
    //Sequential 2D-Convolution=====================================
    //TODO: 2D-Convolution GPU
    //GPU 2D-Convolution============================================

    //GPU 2D-Convolution============================================

    //Delete arrays=================================================
    for (i = 0; i < maxMatrixLength; ++i) {
        delete [] inputArr[i];
    }
    delete [] inputArr;

    for (i = 0; i < maxKernelLength; ++i) {
        delete [] kernelArr[i];
    }
    delete [] kernelArr;
    //Delete arrays=================================================

    return 0;
}