#ifndef MATRIX_H
#define MATRIX_H
#include "complex.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <fstream>
#include <math.h>
#include <ctime>
#include <vector>
#include <algorithm>
#include <list>
#include <iterator>
#include <numeric>

class Matrix{
    private:
        int nmb_of_rows, nmb_of_cols;
        Complex** matrix;

    public:
        Matrix(); //kesz
        Matrix(int _row_amount,int _col_amount); //kesz
        int get_nmb_of_rows(); //kesz
        int get_nmb_of_cols(); //kesz
        Complex** get_matrix(); //kesz
        void show(); //kesz
        double det(); 
        double det_default(int i_start, int j_start,int i_end,int j_end); //kesz
        void set_ij(Complex number,int row_number,int col_number); //kesz
        ~Matrix(); //kesz
        friend vector<Complex> operator*(Matrix m1,vector<Complex> _z);
};

Matrix operator*(Matrix m1,Matrix m2);

Matrix operator+(Matrix m1,Matrix m2);

Matrix operator-(Matrix m1,Matrix m2);

#endif