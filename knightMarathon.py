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
    
    while(n//2 + 2 - n%2 + 3*count <= 2*n - 1):
        matchset.append(n//2 + 2 - n%2 + 3*count)
        print(n//2 + 2 - n%2 + 3*count)
        count += 1
    # print(matchset)
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
    # print(mid)
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
            k = (n + matchset[mid-1] - 2)//3 + (m - matchset[mid-1]) % 3
    return k

def knightMarathonA(width,length):
    k=0
    m=0
    n=0
    restore=0

    if(width>length):
        m=width
        n=length
    else:
        m=length
        n=width
    
    if(m > 2*n - 1):
        if(n == 1 and m == 2):
            k=3
        else:
            maxnum = n-1
            k = maxnum + 2*((m - 2*n-1) // 4) + ((m - 2*n-1) % 4)
    else:
        if(n == 3 and m == 3):
            k=4
        else:
            restore = (m - (n//2 + 2 - n%2)) // 3
            k = (n + (n//2 + 2 - n%2 + 3*restore) - 2) // 3 + (m - (n//2 + 2 - n%2)) % 3
    return k

def knightMarathonA01(width,length,istwo):
    k=0
    m=0
    n=0
    restore=0

    if(width>length):
        m=width
        n=length
    else:
        m=length
        n=width
    
    if(m > 2*n - 1):
        if(n == 1 and m == 2):
            k=3
        else:
            maxnum = n-1
            k = maxnum + 2*((m - (2*n-1)) // 4) + ((m - (2*n-1)) % 4)
    else:
        if(n == 3 and m == 3):
            k=4
        elif(n == 2 and m == 2):
            if(istwo == 1):
                k=4
            else:
                k=2
        else:
            restore = (m - (n//2 + 2 - n%2)) // 3
            k = (n + (n//2 + 2 - n%2 + 3*restore) - 2) // 3 + (m - (n//2 + 2 - n%2)) % 3
    return k

def inputTri(instr, instr2, instr3):
    size=len(instr)
    count=0
    restoreF=0
    restoreB=0
    restoreF2=0
    restoreB2=0
    restoreF3=0
    restoreB3=0
    width=0
    length=0
    listri=[]
    while(count<size):
        if(instr[count] == " "):
            break
        restoreF = ord(instr[count])-48 + restoreF*10
        count += 1
    count += 1
    while(count<size):
        restoreB = ord(instr[count])-48 + restoreB*10
        count += 1
    # print(restoreF)
    # print(restoreB)
    
    size=len(instr2)
    count=0
    while(count<size):
        if(instr2[count] == " "):
            break
        restoreF2 = ord(instr2[count])-48 + restoreF2*10
        count += 1
    count += 1
    while(count<size):
        restoreB2 = ord(instr2[count])-48 + restoreB2*10
        count += 1
    # print(restoreF2)
    # print(restoreB2)
    width=restoreF2-restoreF
    length=restoreB2-restoreB
    
    size=len(instr3)
    count=0
    while(count<size):
        if(instr3[count] == " "):
            break
        restoreF3 = ord(instr3[count])-48 + restoreF3*10
        count += 1
    count += 1
    while(count<size):
        restoreB3 = ord(instr3[count])-48 + restoreB3*10
        count += 1

    listri.append(abs(width)+1)
    listri.append(abs(length)+1)
    if((restoreF == 1 and restoreB == 1) and (restoreF2 == 0 and restoreB2 == 0)):
        listri.append(1)
    elif((restoreF == 1 and restoreB == restoreB3-1) and (restoreF2 == 0 and restoreB2 == restoreB3)):
        listri.append(1)
    elif((restoreF == restoreF3-1 and restoreB == 1) and (restoreF2 == restoreF3 and restoreB2 == 0)):
        listri.append(1)
    elif((restoreF == restoreF3-1 and restoreB == restoreB3-1) and (restoreF2 == restoreF3 and restoreB2 == restoreB3)):
        listri.append(1)
    elif((restoreF == 0 and restoreB == 0) and (restoreF2 == 1 and restoreB2 == 1)):
        listri.append(1)
    elif((restoreF == 0 and restoreB == restoreB3) and (restoreF2 == 1 and restoreB2 == restoreB3-1)):
        listri.append(1)
    elif((restoreF == restoreF3 and restoreB == 0) and (restoreF2 == restoreF3-1 and restoreB2 == 1)):
        listri.append(1)
    elif((restoreF == restoreF3 and restoreB == restoreB3) and (restoreF2 == restoreF3-1 and restoreB2 == restoreB3-1)):
        listri.append(1)
    else:
        listri.append(0)
    # print(listri)
    return listri

def confirm():
    countA=1
    countB=1
    k=0
    while(countA < 20):
        countB = 1
        while(countB < 20):
            k = knightMarathonA01(countA,countB,0)
            print(countA,countB,k)
            countB += 1
        countA += 1

def kmsTest():
    lenset=[]
    first=""
    second=""
    third=""
    
    first=input()
    second=input()
    third=input()
    lenset=inputTri(second, third, first)
    # print(knightMoveSampleC())
    # print(knightMarathon(1,999999997))
    print(knightMarathonA01(lenset[0],lenset[1],lenset[2]))

def main():
    # kmsTest()
    # inputTri("253 6789","253 6789")
    confirm()
    
if(__name__=="__main__"):
    main()