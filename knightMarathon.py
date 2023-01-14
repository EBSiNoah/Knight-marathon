# -*- coding: utf-8 -*-
"""
Created on Fri Jan  6 21:03:56 2023

@author: NOPE
"""
import copy

def knightMoveSample():
    Dset=[]
    restore=[]
    a=0
    b=0
    isA=False
    isB=False
    for m in range(1,100):
        restore.clear()
        for n in range(1,100):
            if((2*n-m-1)%3==0 and (2*n-m-1)>0):
                a=(2*n-m-1)//3
                isA=True
            if((2*m-n-1)%3==0 and (2*m-n-1)>0):
                b=(2*m-n-1)//3
                isB=True
        if(isA and isB):
            restore.append(a)
            restore.append(b)
            restore.append(m)
            restore.append(n)
            Dset.append(copy.deepcopy(restore))
    return Dset

def knightMoveSampleB():
    Dset=[]
    restore=[]
    a=0
    b=0
    n=1
    m=1
    isA=False
    isB=False
    while(m<10):
        n=1
        while(n<10):
            if((2*n-m)%3==0 and (2*n-m)>0):
                a=(2*n-m)//3
                isA=True
            if((2*m-n)%3==0 and (2*m-n)>0):
                b=(2*m-n)//3
                isB=True
            if((isA and isB) and a-b == n-m):
                restore.append(a)                   
                restore.append(b)
                restore.append(m)
                restore.append(n)
                Dset.append(copy.deepcopy(restore))
                restore.clear()
            n+=1
        m+=1
    return Dset

def knightMoveSampleC():
    Dset=[]
    restore=[]
    a=0
    b=0
    n=1
    m=1
    isA=False
    isB=False
    while(m<30):
        n=1
        isA=False
        isB=False
        while(n<30):
            if((2*n-m-1)%3==0 and (2*n-m-1)>=0):
                a=(2*n-m-1)//3
                isA=True
            if((2*m-n-1)%3==0 and (2*m-n-1)>=0):
                b=(2*m-n-1)//3
                isB=True
            if((isA and isB) and a-b == n-m):
                restore.append(a)                   
                restore.append(b)
                restore.append(m)
                restore.append(n)
                Dset.append(copy.deepcopy(restore))
                restore.clear()
            n+=1
        m+=1
    return Dset

def setsample():
    Triset=[]
    restore=[]
    k=1
    l=1
    while(k<30):
        l=1
        while(l<30):
            if((2*k-l)%3==0):
                restore.append(k)
                restore.append(l)
                Triset.append(copy.deepcopy(restore))
                restore.clear()
            l+=1
        k+=1
    
    return Triset

def kmsTest():
    # print(knightMoveSampleC())
    print(setsample())

def main():
    kmsTest()
    
if(__name__=="__main__"):
    main()