#!/usr/bin/python
import sys

filename = sys.argv[1]
fid = open(filename,'r')
fileLines = fid.readlines()
fid.close()

arr = [0]*26
for lineStr in fileLines:
        l = lineStr.lower()
        flag = 0
        for i in range(len(lineStr)):
                if(l[i] >='a' and l[i] <='z'):
                        arr[ord(l[i])-ord('a')]=1

        for i in range(0,26):
                if(arr[i] == 0):
                        flag=1
                        sys.stdout.write( (chr)(ord('a')+i))
        if(flag==0):
                sys.stdout.write( "NULL")
        sys.stdout.write( "\n")
        for i in range(0,26):
                arr[i]=0
