#include "Complex.h"
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

Complex::Complex(){
    re=0;
    im=0;
}

Complex::Complex(double _re,double _im){
    re=_re;
    im=_im;
}

double Complex::get_re(){
    return re;
}

void Complex::set_re(double _re){
    re=_re;
}

double Complex::get_im(){
    return im;
}
void Complex::set_im(double _im){
    im=_im;
}

Complex null_elem(){
    Complex null_el=Complex(0,0);
    return null_el;
}

void Complex::show(){ 
    if(re!=0){
        if(im>0)
            cout<<re<<"+"<<im<<"i";
        if(im<0)
            cout<<re<<im<<"i";
        if(im==0)
            cout<<re;
    }
    if(re==0){
        if(im>0)
            cout<<im<<"i";
        if(im<0)
            cout<<im<<"i";
        if(im==0)
            cout<<re;
    }
}

Complex Complex::komplementer(){
    return Complex(re,-im);
}

double operator*(Complex z1,Complex z2){
    return z1.get_re()*z2.get_re()-z1.get_im()*z2.get_im();
}

Complex operator*(Complex z1,double x){
    return Complex(z1.get_re()*x,z1.get_im()*x);
}

Complex operator*(double x,Complex z1){
    return Complex(z1.get_re()*x,z1.get_im()*x);
}

Complex operator*(Complex z1,int x){
    return Complex(z1.get_re()*x,z1.get_im()*x);
}

Complex operator*(int x,Complex z1){
    return Complex(z1.get_re()*x,z1.get_im()*x);
}

Complex operator+(Complex z1,Complex z2){
    return Complex(z1.get_re()+z2.get_re(),z1.get_im()+z2.get_im());
}

void operator+=(Complex z1,Complex z2){
    z1.set_re(z1.get_re()+z2.get_re());
    z1.set_im(z1.get_im()+z2.get_im());
}

Complex operator+(Complex z1,double x){
    return Complex(z1.get_re()+x,z1.get_im());
}

Complex operator+(Complex z1,int x){
    return Complex(z1.get_re()+x,z1.get_im());
}


Complex operator+(double x,Complex z1){
    return Complex(z1.get_re()+x,z1.get_im());
}


Complex operator+(int x,Complex z1){
    return Complex(z1.get_re()+x,z1.get_im());
}

Complex operator-(Complex z1,Complex z2){
    return Complex(z1.get_re()-z2.get_re(),z1.get_im()-z2.get_im());
}

Complex operator-(Complex z1, double x){
    return Complex(z1.get_re()-x,z1.get_im());
}

Complex operator-(Complex z1,int x){
    return Complex(z1.get_re()-x,z1.get_im());
}

Complex operator-(double x,Complex z1){
    return Complex(x-z1.get_re(),-z1.get_im());
}

Complex operator-(int x,Complex z1){
    return Complex(x-z1.get_re(),-z1.get_im());
}
