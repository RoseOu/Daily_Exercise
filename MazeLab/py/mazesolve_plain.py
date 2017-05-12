#coding:utf-8

from __future__ import print_function

WIDTH=3
HEIGHT=3

N=1
E=4
S=2
W=8

DX=[0,0,0,0,0,0,0,0,0]
DY=[0,0,0,0,0,0,0,0,0]
FACE=[0,0,0,0,0,0,0,0,0]
TURNRIGHT=[0,0,0,0,0,0,0,0,0]
TURNLEFT=[0,0,0,0,0,0,0,0,0]

def solve_maze(grid,maze):
    righthand=W
    cx=0
    cy=0

    dx=DX[FACE[righthand]]
    dy=DY[FACE[righthand]]

    maze[cy*WIDTH+cx]=1
    flag=1
    index=1
    num=0

    while index==1:
        if cx==WIDTH-1 and cy==HEIGHT-1 and grid[cy*WIDTH+cx] & righthand == 0:
            maze[cy*WIDTH+cx]=flag
            flag=flag+1
            index=0
        if grid[cy*WIDTH+cx] & righthand != 0:
            righthand=TURNRIGHT[righthand]
            maze[cy*WIDTH+cx]=flag
            flag=flag+1
            cx=cx+DX[FACE[righthand]]
            cy=cy+DY[FACE[righthand]]
            num=num+1
        else:
            if grid[cy*WIDTH+cx] & FACE[righthand] != 0:
                maze[cy*WIDTH+cx]=flag
                flag=flag+1
                cx=cx+DX[FACE[righthand]]
                cy=cy+DY[FACE[righthand]]
                num=num+1
            else:
                righthand=TURNLEFT[righthand]
    i=0
    while i<HEIGHT:
        j=0
        while j<WIDTH:
            print(maze[j+i*WIDTH],end=' ')
            j=j+1
        print("\n")
        i=i+1

if __name__ == '__main__':
    FACE[N]=W
    FACE[E]=N
    FACE[S]=E
    FACE[W]=S

    TURNRIGHT[N]=E
    TURNRIGHT[E]=S
    TURNRIGHT[S]=W
    TURNRIGHT[W]=N

    TURNLEFT[N]=W
    TURNLEFT[E]=N
    TURNLEFT[S]=E
    TURNLEFT[W]=S

    DX[N]=0
    DX[E]=1
    DX[S]=0
    DX[W]=-1

    DY[N]=-1
    DY[E]=0
    DY[S]=1
    DY[W]=0

    grid=[4,10,2,6,9,3,5,12,9]
    maze=[0,0,0,0,0,0,0,0,0]

    solve_maze(grid,maze)
    print(maze)
