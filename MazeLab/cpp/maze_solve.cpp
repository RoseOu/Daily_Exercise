#include <iostream>
using namespace std;

#define WIDTH 3
#define HEIGHT 3

enum {N=1,E=4,S=2,W=8};  //东南西北四个方向
int DX[9];
int DY[9];
int FACE[9];
int TURNRIGHT[9];
int TURNLEFT[9];

void solve_maze(int grid[WIDTH][HEIGHT],int maze[WIDTH][HEIGHT]){
	  int righthand=W;
	  int cx=0,cy=0,dx,dy,nx,ny;

    dx = DX[FACE[righthand]];
    dy = DY[FACE[righthand]];

    maze[cx][cy]=1;
    int flag=1;
    while(1){
    	if((cx == (WIDTH-1)) && (cy == (HEIGHT-1)) && (grid[cx][cy] & righthand) == 0){
    		maze[cx][cy]=flag;
    		flag++;
    		break;
    	}
    	if((grid[cx][cy] & righthand) !=  0){
    		righthand=TURNRIGHT[righthand];
    		maze[cx][cy]=flag;
    		flag++;
    		cx=cx+DX[FACE[righthand]];
    		cy=cy+DY[FACE[righthand]];
    	}else{
    		if((grid[cx][cy] & FACE[righthand]) !=  0){
    			maze[cx][cy]=flag;
    			flag++;
    			cx=cx+DX[FACE[righthand]];
    			cy=cy+DY[FACE[righthand]];
    		}else{
    			righthand=TURNLEFT[righthand];
    		}
    	}
    }

  	for(int i=0;i<WIDTH;i++){
    	for(int j=0;j<HEIGHT;j++){
      		cout<<maze[j][i]<<" ";
    	}
    	cout<<endl;
  	}
}

int main(){
    FACE[N]=W;
	  FACE[E]=N;
	  FACE[S]=E;
	  FACE[W]=S;

	  TURNRIGHT[N]=E;
	  TURNRIGHT[E]=S;
	  TURNRIGHT[S]=W;
	  TURNRIGHT[W]=N;

	  TURNLEFT[N]=W;
	  TURNLEFT[E]=N;
	  TURNLEFT[S]=E;
	  TURNLEFT[W]=S;

  	DX[N] = 0;
  	DX[E] = 1;
  	DX[S] = 0;
  	DX[W] = -1;

  	DY[N] = -1;
  	DY[E] = 0;
  	DY[S] = 1;
  	DY[W] = 0;

  	int grid[WIDTH][HEIGHT]={{4,6,5},{10,9,12},{2,3,9}};
  	int maze[WIDTH][HEIGHT]={0,0,0,0,0,0,0,0,0};

  	solve_maze(grid,maze);

  	return 0;
}
