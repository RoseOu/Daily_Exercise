#include <stdio.h>
#include <time.h>
#include <string>
#include <stdlib.h>
#include <iostream>
using namespace std;

#define WIDTH 3
#define HEIGHT 3

enum {N=1,E=4,S=2,W=8};  //东南西北四个方向
int DX[9];
int DY[9];
int OPPOSITE[9];
int FACE[9];
int TURNRIGHT[9];
int TURNLEFT[9];

int reset_directions(int *directions, int size){
    for(int i=0; i<(size - 1); i++) {
        int r = i + (rand() % (size - i));
        int temp = directions[i];
        directions[i] = directions[r];
        directions[r] = temp;
    }
    return 0;
}

int destroy_wall(int cx, int cy, int **grid) {

    int nx, ny;
    int directions[4] = {N, E, S, W};

    reset_directions(directions, 4); //重置方向顺序

    for(int i = 0; i < 4; i++) {
        nx = cx + DX[directions[i]];  //下一个要走单元（即当前起点与选择的墙相隔的单元）
        ny = cy + DY[directions[i]];

        if ( ((nx < WIDTH) & (nx >= 0)) & ((ny < HEIGHT) & (ny >= 0)) ) { //如果下一个单元在grid里，没有超出范围
            if (grid[nx][ny] == 0) {  //如果下一个要走的单元未被访问
                grid[cx][cy] = (int)((int)grid[cx][cy] | (int)directions[i]);  //拆墙，即存放连通方向
                grid[nx][ny] = (int)((int)grid[nx][ny] | (int)OPPOSITE[directions[i]]);
                destroy_wall(nx, ny, grid);  //重复步骤
            }
        }
    }
    return 0;
}

void print_maze(int **grid){
    int x,y;

    cout<<" ";
    for(x = 0; x < (WIDTH * 2); x++) {
        cout<<"_";
    }
    cout<<endl;

  for(y = 0; y < HEIGHT; y++) {
    cout<<"|";
    for(x = 0; x < WIDTH; x++) {
      if((grid[x][y] & S) !=  0){
        cout<<" ";
      }else{
        cout<<"_";
      }
      if((grid[x][y] & E) != 0){
        if(( (grid[x][y] | grid[x + 1][y]) & S) != 0){
          cout<<" ";
        }else{
          cout<<"_";
        }
      }else{
        cout<<"|";
      }
    }
    cout<<endl;
  }

  for(int i=0;i<WIDTH;i++){
    for(int j=0;j<HEIGHT;j++){
      cout<<grid[i][j]<<" ";
    }
    cout<<endl;
  }
}

void solve_maze(int **grid,int **maze){
    int righthand=W;
    int cx=0,cy=0,nx,ny;

    maze[cx][cy]=1;  //maze用来存放迷宫求解的路径顺序
    int flag=1;
    while(1){
        if((cx == (WIDTH-1)) && (cy == (HEIGHT-1)) && (grid[cx][cy] & righthand) == 0){ //当处于右下角的单元并且右手边有墙时即到出口
            maze[cx][cy]=flag;
            flag++;
            break;
        }
        if((grid[cx][cy] & righthand) !=  0){  //当右侧无墙
            righthand=TURNRIGHT[righthand];   //右转90度
            maze[cx][cy]=flag;
            flag++;
            cx=cx+DX[FACE[righthand]];     //前进一步
            cy=cy+DY[FACE[righthand]];
        }else{                               //右侧有墙
            if((grid[cx][cy] & FACE[righthand]) !=  0){   //前方无墙
                maze[cx][cy]=flag;
                flag++;
                cx=cx+DX[FACE[righthand]];    //前进一步
                cy=cy+DY[FACE[righthand]];
            }else{
                righthand=TURNLEFT[righthand];   //左转90度
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


int main() {
    int sx,sy;
    OPPOSITE[N] = S;    //反方向
    OPPOSITE[E] = W;
    OPPOSITE[S] = N;
    OPPOSITE[W] = E;

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

    int **grid;   //存放迷宫连通状态
    grid=new int *[WIDTH];
    for(int i=0;i<WIDTH;i++){  
        grid[i]=new int[HEIGHT];
    }

    for(int i=0;i<WIDTH;i++){     //全部置0
        for(int j=0;j<HEIGHT;j++){
            grid[i][j]=0;
        }
    }

    srand((int)time(0));   //生成随机数种子
    sx=rand() % WIDTH;     //随机选择起点
    sy=rand() % HEIGHT;

    destroy_wall(sx, sy, grid);
    print_maze(grid);

    int **maze;   //存放迷宫连通状态
    maze=new int *[WIDTH];
    for(int i=0;i<WIDTH;i++){  
        maze[i]=new int[HEIGHT];
    }

    for(int i=0;i<WIDTH;i++){     //全部置0
        for(int j=0;j<HEIGHT;j++){
            maze[i][j]=0;
        }
    }

    cout<<endl;
    solve_maze(grid,maze);

    return 0;

}
