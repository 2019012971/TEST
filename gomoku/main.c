#include <stdio.h>
#include <stdlib.h>

#define N 15

void initGame();
void printfChessboard();
void playchess();
int judge(int,int);

//定义一个数组并为每个元素赋值为0
int chessboard[N+1][N+1]={0};
//用来记录玩家1还是玩家2，奇数是玩家1，偶数是玩家2
int whoseTurn = 0;

int main()
{
    //初始化游戏，显示欢迎界面并进入棋盘
    initGame();

    //通过循环让玩家轮流落子
    while(1){
        //每次循环自增1，做到2人轮流
        whoseTurn++;

        //自定义函数，用来执行落子操作
        playchess();
    }
    return 0;
}

void initGame(void){
    char c;
    printf("欢迎您进入游戏，按Y进入，其他键退出^_^");
    scanf("%c", &c);
    //判断读入的字符是否为Y
    if(c!='Y' && c!='y'){
        exit(0);
    }
    //清屏，windows为"cls"
    system("clear");

    //打印出棋盘
    printfChessboard();
}

void printfChessboard(){
    int i,j;

    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            if(i==0){
                printf("%3d",j);//打印出列号
            }else if(j==0){
                printf("%3d",i);//打印出行号
            }else if(chessboard[i][j]==1){
                printf("  x");//windows下空格占两列
            }else if(chessboard[i][j]==2){
                printf("  *");
            }
        }
        printf("\n");
    }
}

void playchess(void){
    int i,j;

    if(whoseTurn%2==1){
        printf("轮到玩家1，请输入棋子的位置，格式为行号+空格+列号");
        scanf("%d %d",&i, &j);
        //判断位置是否被占用
        while(chessboard[i][j]!=0){
            printf("您要下的位置已被占用，请重新输入行号+空格+列号");
            scanf("%d %d", &i, &j);
        }
        chessboard[i][j]=1;
    }else{
        printf("轮到玩家2，请输入棋子的位置，格式为行号+空格+列号");
        scanf("%d %d",&i, &j);
        //判断位置是否被占用
        while(chessboard[i][j]!=0){
            printf("您要下的位置已被占用，请重新输入行号+空格+列号");
            scanf("%d %d", &i, &j);
        }
        chessboard[i][j]=2;
    }

    //重新打印出棋盘
    system("clear");
    printfChessboard();

    if( judge(i,j) ){
        if(whoseTurn%2 ==1){
            printf("玩家1获胜\n");
            exit(0);
        }else{
            printf("玩家2获胜\n");
            exit(0);
        }
    }

}

int judge(int x, int y){
    int i,j,k;
    //int t = 2-whoseTurn%2;
    const int step[4][2]={{-1,0},{0,1},{1,1},{1,0}};
    for(i=0;i<4;i++){
        const int d[2]={-1,1};
        int count =1 ;
        for(j=0;j<2;j++){
            for(k=1;k<=4;k++){
                int row = x+k*d[j]*step[i][0];
                int col = y+k*d[j]*step[i][1];
                if( row>=1 && row<=N && col>=1 &&
                col<=N &&
                chessboard[x][y]==chessboard[row][col]){
                    count++;
                }else{
                    break;
                }
            }
        }
        if(count>=5){
            return 1;
        }
    }
    return 0;
}
