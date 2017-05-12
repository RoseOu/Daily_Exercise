#coding:utf-8
from __future__ import print_function
import random
import sys
import pygame
from pygame.locals import *
from sys import exit
import time

WIDTH=5
HEIGHT=5
CELLNUM = WIDTH * HEIGHT
LEN=128
SCREEN_SIZE = (WIDTH * LEN, HEIGHT * LEN)
BG_COLOR = (0,0,0)
FONT_COLOR = (255,255,255)
GRID_COLOR = (50,122,166)
S_COLOR = (50,50,50)

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
	nx=0
	ny=0
	directions=[N,E,S,W]
	Reset_Directions(directions, 4)
	screen.fill(GRID_COLOR, (cx*LEN+2, cy*LEN+2, LEN-2, LEN-2))
	pygame.display.flip()

	i=0
	while i<4:
		nx = cx + DX[directions[i]]
		ny = cy + dy = DY[directions[i]]
		if ((nx < WIDTH) & (nx >= 0)) & ((ny < HEIGHT) & (ny >= 0)):
			if grid[ny*WIDTH+nx] == 0:
				grid[cy*WIDTH+cx] = (grid[cy*WIDTH+cx] | directions[i])
				grid[ny*WIDTH+nx] = (grid[ny*WIDTH+nx] | OPPOSITE[directions[i]])
				if directions[i]==S:
					pygame.draw.line(screen, GRID_COLOR, (cx*LEN,(cy+1)*LEN), ((cx+1)*LEN,(cy+1)*LEN))
				elif directions[i]==E:
					pygame.draw.line(screen, GRID_COLOR, ((cx+1)*LEN,(cy*LEN)), ((cx+1)*LEN,(cy+1)*LEN))
				elif directions[i]==W:
					pygame.draw.line(screen, GRID_COLOR, (cx*LEN,(cy*LEN)), (cx*LEN,(cy+1)*LEN))
				elif directions[i]==N:
					pygame.draw.line(screen, GRID_COLOR, (cx*LEN,(cy*LEN)), ((cx+1)*LEN,(cy)*LEN))
				event = pygame.event.wait()
				if event.key == K_DOWN:
					carve_passage(nx,ny,grid)
		i=i+1
		pygame.display.flip()
		if i==4:
			event = pygame.event.wait()
			if event.key == K_DOWN:
				screen.fill(S_COLOR, (cx*LEN+2, cy*LEN+2, LEN-2, LEN-2))
				pygame.display.flip()
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

	i=0
	while i<HEIGHT:
		j=0
		while j<WIDTH:
			print(grid[j+i*WIDTH],end='  ')
			j=j+1
		print('\n')
		i=i+1

if __name__ == '__main__':
	pygame.init()
	screen = pygame.display.set_mode(SCREEN_SIZE, 0, 32)
	pygame.event.set_blocked(None)
	pygame.event.set_allowed((KEYDOWN, QUIT))

	pygame.display.set_caption('Maze')
	pygame.display.update()

	screen.fill(BG_COLOR)
	pygame.display.flip()

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
	STATUS=1
	while STATUS:
		event = pygame.event.wait()
		if event.key == K_LEFT:  #显示全部格子
			y=0
			while y < HEIGHT:
				x=0
				while x < WIDTH:
					pygame.draw.line(screen, FONT_COLOR, (x*LEN,(y+1)*LEN), ((x+1)*LEN,(y+1)*LEN))
					pygame.draw.line(screen, FONT_COLOR, ((x+1)*LEN,(y*LEN)), ((x+1)*LEN,(y+1)*LEN))
					pygame.display.flip()
					x=x+1
				y=y+1
		elif event.key == K_RIGHT:  #选择生成迷宫
			sx = random.choice(range(0,WIDTH))
			sy = random.choice(range(0,HEIGHT))
			carve_passage(sx, sy, grid)
			Print_Maze(grid)
		elif event.key == K_DOWN:  #选择求解迷宫
			pass
		elif event.key == K_UP:  #退出
			pygame.time.delay(1000)
			STATUS=0
