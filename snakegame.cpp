#include<iostream>
#include<stdlib.h>
#include<conio.h>



using namespace std;
bool gameOver;
const int width = 60;
const int height = 20;
int x, y, fruitX, fruitY, score;
int tailX[100], tailY[100];
int nTail;
enum eDirecton { STOP = 0, LEFT, RIGHT, UP, DOWN};
eDirecton dir;

void setup(){
    gameOver=false;
    dir=STOP;
    x=width/2;
    y=height/2;
    tailY[1]=y;
    tailX[1]=x;
    fruitX=rand()%width+1;
    fruitY=rand()%height+1;
    score=0;
    nTail=1;
}

void draw(){
    system("CLS");
    for(int i=0;i<width+2;i++)cout<<"#";
    cout<<endl;
    for(int i=1;i<=height;i++){
        for(int j=0;j<width+2;j++){
            if(j==0||j==width+1)cout<<"#";
            else{
                bool pt=false;
                for(int p=1;p<=nTail;p++){
                    if(tailX[p]==j && tailY[p]==i){
                        pt=true;
                        break;
                    }
                }
                if(pt)cout<<"o";
                else{
                    if(i==fruitY && j==fruitX)cout<<"F";
                    else cout<<" ";
                }
            }
        }
        cout<<endl;
    }
    for(int j=0;j<width+2;j++)cout<<"#";
    cout<<endl;
    cout<<"SCORE :"<<score<<endl;
}

void input(){

    if(kbhit()){
        switch(getch()){

        case 'a':
            dir = LEFT;
            break;
        case 'd':
            dir = RIGHT;
            break;
        case 'w':
            dir = UP;
            break;
        case 's':
            dir = DOWN;
            break;
        default:
            gameOver = true;
            break;
        }
            
        }
       
    }


void logic(){
    int  tempx=tailX[1],tempy=tailY[1]; 
    for(int i=2;i<=nTail;i++){
            int tempx2=tailX[i],temp2y=tailY[i];
            tailX[i]=tempx;
            tailY[i]=tempy;
            tempx=tempx2;
            tempy=temp2y;
    }
    switch (dir)
    {
    case LEFT:
        x--;
        break;
    case RIGHT:
        x++;
        break;
    case UP:
        y--;
        break;
    case DOWN:
        y++;
        break;
    default:
        break;
    }
    
    if(x>width)x=1;
    if(y>height)y=1;
    if(x<1)x=width;
    if(y<1)y=height;
    //now I need to add the logic for gameover due to self collision
    for(int i=2;i<=nTail;i++){
        if(x==tailX[i]&&y==tailY[i]){
            gameOver=true;
        }
    }
    if(x==fruitX && y==fruitY){
            nTail++;
            score+=10;
            fruitX=rand()%width+1;
            fruitY=rand()%height+1;
     }
    tailX[1]=x;
    tailY[1]=y;
   
}
int main(){
    setup();
    while(!gameOver){
        draw();
        input();
        logic();
    }
    cout<<"GAME OVER!";
    
    return 0;

}