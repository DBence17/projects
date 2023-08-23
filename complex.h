#ifndef COMPLEX_H
#define COMPLEX_H
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

class Complex{

    public:
        double re,im;
        Complex(); //kesz
        Complex(double _re,double _im); //kesz
        double get_re(); //kesz
        void set_re(double _re);
        double get_im(); //kesz
        void set_im(double _im);
        void show(); //kesz
        Complex komplementer(); //kesz
        ~Complex(){}; //kesz
        friend void operator+=(Complex z1,Complex z2);
};

Complex null_elem(); //kesz

double operator*(Complex z1,Complex z2); //kesz

Complex operator*(Complex z1,double x); //kesz

Complex operator*(double x,Complex z1); //kesz

Complex operator*(Complex z1,int x); //kesz

Complex operator*(int x,Complex z1); //kesz

Complex operator+(Complex z1,Complex z2); //kesz

void operator+=(Complex z1,Complex z2); // nem mukodik teljesen

Complex operator+(Complex z1,double x); //kesz

Complex operator+(Complex z1,int x); //kesz

Complex operator+(double x,Complex z1); //kesz

Complex operator+(int x,Complex z1); //kesz

Complex operator-(Complex z1,Complex z2); //kesz

Complex operator-(Complex z1, double x); //kesz

Complex operator-(Complex z1,int x); //kesz

Complex operator-(double x,Complex z1); //kesz

Complex operator-(int x,Complex z1); //kesz

#endif