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

def knightMarathon(width,length):
    k=0
    m=0
    n=0
    count=0
    sp=0
    ep=0
    mid=0
    size=0
    isexist=False
    matchset=[]
    if(width>length):
        m=width
        n=length
    else:
        m=length
        n=width
    
    while(n//2 + 2 - n%2 + 3*count != 2*n - 1):
        matchset.append(n//2 + 1 + 3*count)
        count += 1
    
    size=len(matchset)
    ep=size-1
    while(sp<=ep):
        mid=(sp+ep) // 2
        if(m > matchset[mid]):
            sp = mid+1
        elif(m < matchset[mid]):
            ep = mid-1
        else:
            isexist=True
            break;
    if(sp>ep):
        mid=sp
    
    if(isexist):
        k = (m+n-2) // 3
    else:
        k = exception(n,m,matchset,mid)
    return k

def exception(n,m,matchset,mid):
    num=len(matchset)
    maxnum=0
    k=0
    maxnum = (n + matchset[num-1]-2) // 3
    if(m > 2*n - 1):
        if(n==1 and m == 2):
            k = 3
        else:
            k = maxnum + 2*((m-matchset[num-1]) // 4) + ((m-matchset[num-1]) % 4)
    else:
        if(n == 3 and m == 3):
            k = 4
        else:
            k = (n + matchset[mid] - 2)//3 + (m - matchset[mid]) % 3
    return k

def kmsTest():
    # print(knightMoveSampleC())
    print(knightMoveSampleC())

def main():
    kmsTest()
    
if(__name__=="__main__"):
    main()