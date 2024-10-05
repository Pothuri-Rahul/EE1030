import numpy as np
import ctypes
func=ctypes.CDLL('/home/rahulpothur/git/EE1030/matgeo/matgeo1/Codes/fun.so')
A=[1,5]
B=[2,3]
C=[-2,-11]

if func.sub(3*B[0],2*A[0])==C[0] and func.sub(3*B[1],2*A[1])==C[1] :
    print("Rank 1 and thus A,B,C collinear")
else:
    print("A,B,C not collinear")
