#coding:utf-8
from __future__ import print_function
import random

WIDTH=3
HEIGHT=3

N=1
E=4
S=2
W=8

DX=[0,0,0,0,0,0,0,0,0]
DY=[0,0,0,0,0,0,0,0,0]
OPPOSITE=[0,0,0,0,0,0,0,0,0]

def Reset_Directions(directions,size):
	i=0
	while i<size - 1:
		r=i+random.choice(range(0,size-i))
		temp=directions[i]
		directions[i] = directions[r]
		directions[r] = temp
		i=i+1
	return 0

def carve_passage(cx,cy,grid):
	dx=0
	dy=0
	nx=0
	ny=0
	directions=[N,E,S,W]
	Reset_Directions(directions, 4)
	# print(directions)

	i=0
	print(cx,cy)
	while i<4:
		dx=DX[directions[i]]
		dy = DY[directions[i]]
		nx = cx + dx
		ny = cy + dy
		if ((nx < WIDTH) & (nx >= 0)) & ((ny < HEIGHT) & (ny >= 0)):
			if grid[ny*WIDTH+nx] == 0:
				grid[cy*WIDTH+cx] = (grid[cy*WIDTH+cx] | directions[i])
				grid[ny*WIDTH+nx] = (grid[ny*WIDTH+nx] | OPPOSITE[directions[i]])
				carve_passage(nx,ny,grid)
		i=i+1
	return 0

def Print_Maze(grid):
	print(" ",end='')
	x=0
	while x < (WIDTH * 2):
		print("_",end='')
		x=x+1
	print("\n",end='')

	y=0
	while y < HEIGHT:
		print("|",end='')
		x=0
		while x < WIDTH:
			if (grid[x+y*WIDTH] & S) != 0:
				print(" ",end='')
			else:
				print("_",end='')
			if (grid[x+y*WIDTH] & E) != 0:
				if (grid[x+y*WIDTH] | grid[y*WIDTH+(x+1)]) & S != 0:
					print(" ",end='')
				else:
					print("_",end='')
			else:
				print("|",end='')
			x=x+1
		y=y+1
		print("\n",end='')
	print(grid)


if __name__ == '__main__':
	OPPOSITE[N] = S
	OPPOSITE[E] = W
	OPPOSITE[S] = N
	OPPOSITE[W] = E

	DX[N] = 0
	DX[E] = 1
	DX[S] = 0
	DX[W] = -1

	DY[N] = -1
	DY[E] = 0
	DY[S] = 1
	DY[W] = 0

	grid=[0]*(WIDTH*HEIGHT)

	carve_passage(0, 0, grid)
	Print_Maze(grid)
