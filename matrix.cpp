#include "complex.h"
#include "matrix.h"
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

using namespace std;

Matrix::Matrix(){
    nmb_of_rows=3;
    nmb_of_cols=3;
    matrix=new Complex* [nmb_of_rows];
    for (int i = 0; i < nmb_of_rows; i++)
    {
        matrix[i]=new Complex[nmb_of_cols];
    }
    for (int i = 0; i < nmb_of_rows; i++)
    {
        for (int j = 0; j < nmb_of_cols; j++)
        {
            matrix[i][j]=null_elem();           
        }
    }  
}

Matrix::Matrix(int _row_amount,int _col_amount){
    nmb_of_rows=_row_amount;
    nmb_of_cols=_col_amount;
    matrix=new Complex* [nmb_of_rows];
    for (int i = 0; i < nmb_of_rows; i++)
    {
        matrix[i]=new Complex[nmb_of_cols];
    }
    for (int i = 0; i < nmb_of_rows; i++)
    {
        for (int j = 0; j < nmb_of_cols; j++)
        {
            matrix[i][j]=null_elem();          
        }
    }     
}

Matrix::~Matrix(){
    for (int i = 0; i < nmb_of_rows; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}
    
int Matrix::get_nmb_of_rows(){
    return nmb_of_rows;
}

int Matrix::get_nmb_of_cols(){
    return nmb_of_cols;
}

Complex** Matrix::get_matrix(){
    return matrix;
}

void Matrix::show(){
    cout<<"A matrix:"<<endl;
    for (int i = 0; i < nmb_of_rows; i++)
    {
        for (int j = 0; j < nmb_of_cols; j++)
        {
            matrix[i][j].show();
            if(j!=(nmb_of_cols-1))
                cout<<" ";
        }
        cout<<endl;
    }
}

void Matrix::set_ij(Complex number,int row_number,int col_number){
    matrix[row_number-1][col_number-1]=number;        
}

double Matrix::det(){
    if(nmb_of_rows!=nmb_of_cols){
        cout<<"Nem szamolhato determinans nem negyzetes matrixra"<<endl;
        return 0;
    }    
}

double Matrix::det_default(int i_start, int j_start,int i_end,int j_end){
    return matrix[i_start-1][j_start-1]*matrix[i_end-1][j_end-1]-matrix[i_start-1][j_end-1]*matrix[i_end-1][j_start-1];
}

vector<Complex> operator*(Matrix m1,vector<Complex> _z){
    vector<Complex> eredmeny;
    Complex** matrix=m1.get_matrix();
    Complex szorzat;
    int sor_szam=m1.get_nmb_of_rows();
    int oszlop_szam=m1.get_nmb_of_cols();
    for (int i = 0; i < sor_szam; i++)
    {
        szorzat=Complex(0,0);
        for (int j = 0; j < oszlop_szam; j++)
        {
            szorzat=szorzat+matrix[i][j]*_z[j];
            eredmeny.push_back(szorzat);
        }    
    }

    return eredmeny;    
}