i = int(input())  
for j in range(1, i+1):  
    m  = [int(s) for s in input().split()]
    if m[0] + m[1] > m[2]:  
        print"Case #%d: true"%j  
    else:  
        print "Case #%d: false"%j  