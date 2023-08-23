#importok
import numpy as np
import py
import sympy as sp
import math
import matplotlib.pyplot as plt
from sympy.vector import CoordSys3D
from sympy.solvers import solve
from sympy.solvers.solveset import linsolve
from sympy.solvers import solve
from sympy import Symbol
from fractions import *

#Valtozok deklaralasa

print("1.Feladat\n")
R=3.99
L= 5.56 * 10 ** -4
Tc=0.0352
Jr=4.53*10**-6
Jt=0.00003
omega=5060
om=omega * 2 * math.pi / 60
U=24
i_n=1.33
Br=2*10**-6
N=71

print(f'R: {R}')
print(f'L: {L}')
print(f'k_m: {Tc}')
print(f'J_r: {Jr}')
print(f'i_n: {i_n}')
print(f'N: {N}')

#Idoallando szamitas
s=Symbol('s')
t=Symbol('t', real=True, positive=True)
szamlalo= N * Tc
negyfoku= N ** 2 * L * Jr + Jt * L
masodfoku= N ** 2 * Jr * R + N ** 2 * Br * L + R * Jt
konst= N ** 2 * Br * R + N ** 2 * Tc ** 2
nevezo=((L * N ** 2 * Jr + L * Jt) * pow(s,2) + (R * Jr * N ** 2 + L * Br * N ** 2 + R * Jt) * s + (R * Br * N ** 2 + N ** 2 * Tc ** 2))

#Atviteli fuggveny
W_u_o= szamlalo / nevezo
print(f'Wuo: {W_u_o}')

s1= (-masodfoku + math.sqrt((masodfoku) ** 2 - 4 * negyfoku * konst)) / (2 * negyfoku)
s2= (-masodfoku - math.sqrt((masodfoku) ** 2 - 4 * negyfoku * konst)) / (2 * negyfoku)
print("s1= ", s1) #1-es polus
print("s2= ", s2) #2-es polus

#Idoallandok szamolasa
print("6. Feladat\n")
T_1= -1 / s1
print(f'T1: {T_1}')
T_2= -1 / s2
print(f'T2: {T_2}')

#Inverz Laplace transzformacio
def invL(func):
    return sp.inverse_laplace_transform(func, s, t)
print(W_u_o)
W_u_o= W_u_o / s
#W_u.apart(s)
print(W_u_o)
W_u_o= sp.apart(W_u_o)
print(W_u_o)

#print(f'teszt: {}')
W_u_L=invL(W_u_o)
print(f'Wuo inverz laplace: {W_u_L}')

#Atmeneti fuggveny abrazolasa
kiemelt=0.3975675192758122/szamlalo
kiemelt2=0.003930295534870896/szamlalo
kiemelt3=0.4014978148106831/szamlalo
def inverse(t):
  return szamlalo*(kiemelt+kiemelt2*math.e**(-7107.127650401143 *t)-kiemelt3*math.e**(-69.57226425578507*t))
xlist=np.linspace(0,0.5,1000000)
ylist=inverse(xlist)
plt.figure(num=1000,dpi=120)
plt.plot(xlist,ylist)
plt.xlabel("t")
plt.ylabel("f(t)")
plt.show()

W_u_i=sp.Function('W_u_i')(s)
W_u_i= ((Jt + Jr) * s + Br) / ((L * Jr + L * Jt) * s ** 2 + (R * Jr + R * Jt + Br * L) * s + (R * Br + Tc ** 2))
print(f'Wui: {W_u_i}')

W_m_o=sp.Function('W_m_o')(s)
W_m_o= (L * s + R) / ((L * Jr * N ** 2 + L * Jt) * s ** 2 + (R * Jt + R * Jr * N ** 2 + Br * L * N ** 2) * s + (R * Br * N ** 2 + Tc ** 2))
print(f'Wmo: {W_m_o}')

W_m_i=sp.Function('W_m_i')(s)
W_m_i= (N * Tc) / ((L * Jr * N ** 2 + L * Jt) * s ** 2 + (R * Jt + R * Jr * N ** 2 + Br * L * N ** 2) * s + (R * Br * N ** 2 + Tc ** 2 * N ** 2))
print(f'Wmi: {W_m_i}')

print('8. Feladat\n')

u_omega_all= N * Tc / (R * Br * N ** 2 + Tc ** 2 * N ** 2)
print(f'u->omega allandosult: {u_omega_all}')

u_i_all= Br / (R * Br + Tc ** 2)
print(f'u->i allandosult: {u_i_all}')

m_omega_all= -R / (R * Br * N ** 2 + Tc ** 2 * N ** 2)
print(f'M_t->omega allandosult: {m_omega_all}')

m_i_all= N * Tc / ((R * Br * N ** 2 + Tc ** 2 * N ** 2))
print(f'M_t->i allandosult: {m_i_all}')

#Motor fordulatszama
I= W_u_o * U * N
xinverz=invL(I)
print(f'x inverz laplace: {xinverz}')


tmp=szamlalo*N*U
def fordulatszam(t):
    return tmp*60/(2*math.pi)*(kiemelt+kiemelt2*math.e**(-7107.051760647081*t)-kiemelt3*math.e**(-69.64863329367395*t))

xlist=np.linspace(0,0.5,10000000)
ylist=fordulatszam(xlist)
plt.figure(num=1000,dpi=120)
plt.plot(xlist,ylist)
plt.xlabel("t")
plt.ylabel("RPM")
plt.show()

#Maximalis terhelo nyomatek
M_max= (i_n - U * Br / (R * Br + Tc ** 2)) / (N * Tc / (R * Br * N ** 2 + Tc ** 2 * N ** 2))
print(f'Maximalis terhelo nyomatek: {M_max}')

#Szorgalmi
print('Szorgalmi:\n')
Br1=10*Br
Br2=0.1*Br
M_max1= (i_n - U * Br1 / (R * Br1 + Tc ** 2)) / (N * Tc / (R * Br1 * N ** 2 + Tc ** 2 * N ** 2))
print(M_max1)

M_max2= (i_n - U * Br2 / (R * Br2 + Tc ** 2)) / (N * Tc / (R * Br2 * N ** 2 + Tc ** 2 * N ** 2))
print(M_max2)
