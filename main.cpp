/**
 * Jason Katsaros
 */

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

void sequential_convolution(float **inputArr, int inputWidth, int inputHeight, float **kernelArr, int kernelWidth, int kernelHeight, float **outputArr) {
    int temp = 0;
}

void test_print(float **array, int width, int height) {
    int i = 0;
    int j = 0;

    for (j = 0; j < height; j++) {
        for (i = 0; i < width; i++) {
            cout << array[j][i] << "   |    ";
        }
        cout << endl;
    }
}

int main(int argc, char **argv) {
    int maxMatrixLength = 1000;
    int maxKernelLength = 9;
    int inputWidth = 0;
    int inputHeight = 0;
    int kernelWidth = 0;
    int kernelHeight = 0;

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

    //Read in matrix from file======================================
    char *trace_file = nullptr;
    trace_file = argv[1]; //file is the only argument provided from the command line

    int i = 0;
    int j = 0;
    bool k = false;
    float num;

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
    }
    kernelWidth = i;
    kernelHeight = j;
    //Read in matrix from file======================================

    //Initialize output array=======================================
    int outputWidth = inputWidth + (kernelWidth - 1);
    int outputHeight = inputHeight + (kernelHeight - 1);

    float **outputArr = new float*[outputHeight];
    for (int i = 0; i < outputHeight; ++i) {
        kernelArr[i] = new float[outputWidth];
    }
    //Initialize output array=======================================

    //test print====================================================
    test_print(inputArr, inputWidth, inputHeight);
    test_print(kernelArr, kernelWidth, kernelHeight);
    //test print====================================================

    //TODO: 2D-Convolution Sequential
    //Sequential 2D-Convolution=====================================
    sequential_convolution(inputArr, inputWidth, inputHeight, kernelArr, kernelWidth, kernelHeight, outputArr);
    //Sequential 2D-Convolution=====================================
    //TODO: 2D-Convolution GPU
    //GPU 2D-Convolution============================================

    //GPU 2D-Convolution============================================

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