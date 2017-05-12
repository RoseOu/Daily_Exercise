## 迷宫生成与求解

博客地址：[迷宫生成与求解](http://roseou.github.io/2017/05/09/%E8%BF%B7%E5%AE%AB%E7%94%9F%E6%88%90%E4%B8%8E%E6%B1%82%E8%A7%A3/)

### cpp  

--maze_generate.cpp : 迷宫生成代码  

--maze_solve.cpp : 迷宫求解代码 

--maze.cpp : 迷宫生成与求解代码 

### py 

--mazegenerate_plain.py : 迷宫生成代码 

--mazegenerate_game.py : 迷宫生成加图形界面代码 

--mazesolve_plain.py : 迷宫求解代码 

--mazesolve_game.py : 迷宫求解加图形界面代码 

--mazeplain.py : 迷宫生成与求解代码 

--mazegame.py : 迷宫生成与求解加图形界面代码 

#### mazegame.py运行说明：

Step 1:运行 

`python mazegame.py`

Step 2:先生成一个全部都是墙的迷宫 

按键盘方向键←键

Step 3:选择迷宫生成 

按键盘方向键→键

Step 4:一步步进行迷宫生成 

按键盘方向键↓键，一步一步按直到回溯到最初的单元

Step 5:选择迷宫求解 

按键盘方向键↑键

Step 6:一步步进行迷宫求解 

按键盘方向键↓键，一步一步按直到到达出口

