#include <iostream>
#include <cstdlib>
#include <typeinfo>
using namespace std;
char col1,col2;
int row1,row2;
bool checkmate{false};
bool player{true};
bool valid{true};
int index{0};
char dead[2][16]{};
int dead_counterw=0,dead_counterb=0;
int not_p ;
int normal =1;
char relived;
char chessboard[8][8]
{'R','N','B','Q','K','B','N','R',

'P','P','P','.','P','P','P','P',

'p','*','.','*','.','*','.','*',
'*','.','*','.','*','.','*','.',

'.','*','.','*','.','*','.','*',
'*','.','*','.','*','.','*','.',

'.','p','p','*','p','p','p','p',
'r','n','b','q','k','b','n','r'
};
void draw(){
   // while(!checkmate)
    system("cls");
    cout<<"dead from White : ";
    for(int i=0;i<16;i++){
        cout<<" "<<dead[0][i]<<" ";
    }
    cout<<endl;
    for(int i=1;i<13;i++){
        cout<<"#";
            }
    cout<<endl;
for(int i=0;i<8;i++){
    cout<<"# ";
    for(int j=0;j<8;j++){
        cout<<chessboard[i][j];
    }
    cout<<" #";
    cout<<endl;
}
for(int i=1;i<13;i++){
        cout<<"#";
            }
    cout<<endl;
    cout<< "dead from Black : ";
     for(int i=0;i<16;i++){
            // remember to add new variable to let the for loop loop from which it stops
        cout<<" "<<dead[1][i]<<" ";
    }
cout<<endl;
 //   }

    }
void move(int col1_val,int row1_val,int col2_val,int row2_val){
    if(chessboard[row2_val][col2_val]!='.'&&chessboard[row2_val][col2_val]!='*'){
        if(player){
            if(chessboard[row2_val][col2_val]=='K')
                checkmate=true;
            dead[1][dead_counterb]=chessboard[row2_val][col2_val];
            dead_counterb++;
        }
        else{
             if(chessboard[row2_val][col2_val]=='k')
                checkmate=true;
            dead[0][dead_counterw]=chessboard[row2_val][col2_val];
            dead_counterw++;
        }
    }
    char temp=chessboard[row1_val][col1_val];
    if(col1_val%2==0&&row1_val%2==0)
        chessboard[row1_val][col1_val]='.';
    else if(col1_val%2==1&&row1_val%2==1)
        chessboard[row1_val][col1_val]='.';
    else
        chessboard[row1_val][col1_val]='*';
    chessboard[row2_val][col2_val]=temp;
}
void play(){
    if(normal){
cout<<"play-"<<player<<":";
cin>>col1;
cin>>row1;
cin>>col2;
cin>>row2;
col1-=65;
col2-=65;
row1-=1;
row2-=1;}
 /**else{
    not_p=!player;
    normal=1;
     for(int i=0;i<16;i++){
        cout<<" "<<dead[not_p][i]<<" ";
    }
    cout<<endl;
    cin>>relived;*/
 /**   if(relived!='s'){
    for(int i=0 ;i<16;i++){
        if(relived==dead[not_p][i]){
            if(not_p){
                dead[not_p][i]='P';
            }
            else{
                dead[not_p][i]='p';
            }

        }
    }
    }*/
 //}
}
void in_between(int col1_val_b,int row1_val_b,int col2_val_b,int row2_val_b,int x,int y){
    //this function shows if there is a character between the bishop and the second position
    index=1;
        while(index<abs(col2_val_b-col1_val_b)){
            col1_val_b+=x;
            row1_val_b+=y;
            if(chessboard[row1_val_b][col1_val_b]=='.'||chessboard[row1_val_b][col1_val_b]=='*'){

            }
            else{
                valid=false;
                break;
            }
            index++;
        }
}

void logic(int col1_val,int row1_val,int col2_val,int row2_val){
    index=1;
    valid=true;
  char character =chessboard[row1_val][col1_val];
  int temp;
  if(player){
        if(chessboard[row2_val][col2_val]>97){
            valid=false;
            return;
        }
  switch (character){
case 'p':
    if(col1_val==col2_val){
    if(row1_val==6){
            if(row1_val-1==row2_val||row1_val-2==row2_val){

            }
            else
                valid=false;
    }
    else if(row1_val<6){
            if(row1_val-1==row2_val){
                if(row2_val==0){
                    system("cls");
                    normal=0;
                 //   play();
                    cin>> chessboard[0][0];
                //    chessboard[row2_val][col2_val]=relived;
                    system("cls");
                    draw();
                 //   chessboard[row2_val][col2_val]=relived;
                }
            }
            else
                valid=false;
    }
    }
    else
        valid=false;
    break;
case 'r':
   if(row1_val==row2_val){

        if(col1_val>col2_val){

        while(index<col1_val-col2_val){
            temp=chessboard[row1_val][col1_val-index];
            if(temp=='.'||temp=='*'){
            }
            else{
                valid=false;
                break;
                }
                 index++;
        }
        }
        else if(col1_val<col2_val){

         while(index<col2_val-col1_val){
            temp=chessboard[row1_val][col1_val+index];
            if(temp!='.'||temp!='*'){


            }
            else{

                valid=false;
                break;
                }
           index++;
        }

        }
        else
            valid=false;
    }
    else if(col1_val==col2_val){
        if(row1_val>row2_val){
        while(index<row1_val-row2_val){
            temp=chessboard[row1_val-index][col1_val];
            if(temp=='.'||temp=='*'){
            }
            else{
                valid=false;
                break;
                }
            index++;
        }
        }
        else if(row1_val<row2_val){
        while(index<row2_val-row1_val){
            temp=chessboard[row1_val+index][col1_val];
            if(temp=='.'||temp=='*'){

            }
            else{
                valid=false;
                break;
                }
            index++;
        }

        }
        else
            valid=false;
    }
    else
        valid=false;
  break;
case 'n':
    if(col2_val==col1_val-2||col2_val==col1_val+2){
        if(row2_val==row1_val-1||row2_val==row1_val+1){

        }
        else
            valid=false;
    }
    else if(row2_val==row1_val-2||row2_val==row1_val+2){
        if(col2_val==col1_val-1||col2_val==col1_val+1){
        }
        else
            valid=false;
    }
    else
        valid=false;
    break;
case 'b':
    if((abs(row1_val-row2_val)+1)==(abs(col1_val-col2_val)+1)){
    if(row1_val>row2_val){
        if(col1_val>col2_val){
          in_between(col1_val, row1_val, col2_val, row2_val,-1,-1);
        }
        else if(col2_val>col1_val){
          in_between( col1_val, row1_val, col2_val, row2_val,1,-1);
        }
        else
            valid=false;
    }
    else if(row1_val<row2_val){
        if(col1_val>col2_val){
        in_between( col1_val, row1_val, col2_val, row2_val,-1,1);
        }
        else if(col2_val>col1_val){
        in_between( col1_val, row1_val, col2_val, row2_val,1,1);
        }
    else
        valid=false;

    }
    }
    else
       valid=false;
    break;
case 'q':
    if(row1_val==row2_val){

        if(col1_val>col2_val){

        while(index<col1_val-col2_val){
            temp=chessboard[row1_val][col1_val-index];
            if(temp=='.'||temp=='*'){
            }
            else{
                valid=false;
                break;
                }
                 index++;
        }
        }
        else if(col1_val<col2_val){

         while(index<col2_val-col1_val){
            temp=chessboard[row1_val][col1_val+index];
            if(temp!='.'||temp!='*'){


            }
            else{

                valid=false;
                break;
                }
           index++;
        }

        }
        else
            valid=false;
    }
    else if(col1_val==col2_val){
        if(row1_val>row2_val){
        while(index<row1_val-row2_val){
            temp=chessboard[row1_val-index][col1_val];
            if(temp=='.'||temp=='*'){
            }
            else{
                valid=false;
                break;
                }
            index++;
        }
        }
        else if(row1_val<row2_val){
        while(index<row2_val-row1_val){
            temp=chessboard[row1_val+index][col1_val];
            if(temp=='.'||temp=='*'){

            }
            else{
                valid=false;
                break;
                }
            index++;
        }

        }
        else
            valid=false;
    }
    else if(((abs(row1_val-row2_val)+1)/(abs(col1_val-col2_val)+1))==1){
    if(row1_val>row2_val){
        if(col1_val>col2_val){
          in_between(col1_val, row1_val, col2_val, row2_val,-1,-1);
        }
        else if(col2_val>col1_val){
          in_between( col1_val, row1_val, col2_val, row2_val,1,-1);
        }
        else
            valid=false;
    }
    else if(row1_val<row2_val){
        if(col1_val>col2_val){
        in_between( col1_val, row1_val, col2_val, row2_val,-1,1);
        }
        else if(col2_val>col1_val){
        in_between( col1_val, row1_val, col2_val, row2_val,1,1);
        }
    else
        valid=false;

    }
    else
       valid=false;
       }
    else
        valid=false;


    break;
case 'k':
    if((col2_val==col1_val&&row2_val==row1_val+1)||(col2_val==col1_val&&row2_val==row1_val-1)||
       (row1_val==row2_val&&col2_val==col1_val+1)||(row1_val==row2_val&&col2_val==col1_val-1)||
       (row1_val+1==row2_val&&col2_val==col1_val+1)||(row1_val+1==row2_val&&col2_val==col1_val-1)||
       (row1_val-1==row2_val&&col2_val==col1_val-1)||(row1_val-1==row2_val&&col2_val==col1_val+1)
       ){

    }
    else
        valid=false;
    break;
default:
    valid=false;
    break;

  }

}
else{
        if(chessboard[row2_val][col2_val]>=65&&chessboard[row2_val][col2_val]<=90){
            valid=false;
            return;
        }
        switch (character){
        case 'P':
            if(col1_val==col2_val){
                if(row1_val==1){
                    if(row1_val+1==row2_val||row1_val+2==row2_val){

                }
                else
                    valid=false;
            }
            else if(row1_val>1){
                if(row1_val+1==row2_val){
                if(row2_val==7){
                    system("cls");
                    normal=0;
                    play();
                }

                }
                else
                    valid=false;
        }
        }
          else
             valid=false;
            break;
    case 'R':
    if(row1_val==row2_val){
        if(col1_val>col2_val){
        while(index<col1_val-col2_val){
            temp=chessboard[row1_val][col1_val-index];
            if(temp=='.'||temp=='*'){
            }
            else{
                valid=false;
                break;
                }
                 index++;
        }
        }
        else if(col1_val<col2_val){

         while(index<col2_val-col1_val){
            temp=chessboard[row1_val][col1_val+index];
            if(temp!='.'||temp!='*'){


            }
            else{

                valid=false;
                break;
                }
           index++;
        }

        }
        else
            valid=false;
    }
    else if(col1_val==col2_val){
        if(row1_val>row2_val){
        while(index<row1_val-row2_val){
            temp=chessboard[row1_val-index][col1_val];
            if(temp=='.'||temp=='*'){
            }
            else{
                valid=false;
                break;
                }
            index++;
        }
        }
        else if(row1_val<row2_val){
        while(index<row2_val-row1_val){
            temp=chessboard[row1_val+index][col1_val];
            if(temp=='.'||temp=='*'){

            }
            else{
                valid=false;
                break;
                }
            index++;
        }

        }
        else
            valid=false;
    }
    else
        valid=false;
            break;
    case 'N':
    if(col2_val==col1_val-2||col2_val==col1_val+2){
        if(row2_val==row1_val-1||row2_val==row1_val+1){

        }
        else
            valid=false;
    }
    else if(row2_val==row1_val-2||row2_val==row1_val+2){
        if(col2_val==col1_val-1||col2_val==col1_val+1){
        }
        else
            valid=false;
    }
    else
        valid=false;
        break;
    case 'B':
    if(((abs(row1_val-row2_val)+1)/(abs(col1_val-col2_val)+1))==1){
    if(row1_val>row2_val){
        if(col1_val>col2_val){
          in_between(col1_val, row1_val, col2_val, row2_val,-1,-1);
        }
        else if(col2_val>col1_val){
          in_between( col1_val, row1_val, col2_val, row2_val,1,-1);
        }
        else
            valid=false;
    }
    else if(row1_val<row2_val){
        if(col1_val>col2_val){
        in_between( col1_val, row1_val, col2_val, row2_val,-1,1);
        }
        else if(col2_val>col1_val){
        in_between( col1_val, row1_val, col2_val, row2_val,1,1);
        }
    else
        valid=false;

    }
    }
    else
       valid=false;
        break;
    case 'Q':
        if(row1_val==row2_val){

        if(col1_val>col2_val){

        while(index<col1_val-col2_val){
            temp=chessboard[row1_val][col1_val-index];
            if(temp=='.'||temp=='*'){
            }
            else{
                valid=false;
                break;
                }
                 index++;
        }
        }
        else if(col1_val<col2_val){

         while(index<col2_val-col1_val){
            temp=chessboard[row1_val][col1_val+index];
            if(temp!='.'||temp!='*'){


            }
            else{

                valid=false;
                break;
                }
           index++;
        }

        }
        else
            valid=false;
    }
    else if(col1_val==col2_val){
        if(row1_val>row2_val){
        while(index<row1_val-row2_val){
            temp=chessboard[row1_val-index][col1_val];
            if(temp=='.'||temp=='*'){
            }
            else{
                valid=false;
                break;
                }
            index++;
        }
        }
        else if(row1_val<row2_val){
        while(index<row2_val-row1_val){
            temp=chessboard[row1_val+index][col1_val];
            if(temp=='.'||temp=='*'){

            }
            else{
                valid=false;
                break;
                }
            index++;
        }

        }
        else
            valid=false;
    }
    else if((abs(row1_val-row2_val)+1)==(abs(col1_val-col2_val)+1)){
    if(row1_val>row2_val){
        if(col1_val>col2_val){
          in_between(col1_val, row1_val, col2_val, row2_val,-1,-1);
        }
        else if(col2_val>col1_val){
          in_between( col1_val, row1_val, col2_val, row2_val,1,-1);
        }
        else
            valid=false;
    }
    else if(row1_val<row2_val){
        if(col1_val>col2_val){
        in_between( col1_val, row1_val, col2_val, row2_val,-1,1);
        }
        else if(col2_val>col1_val){
        in_between( col1_val, row1_val, col2_val, row2_val,1,1);
        }
    else
        valid=false;

    }
    else
       valid=false;
       }
    else
        valid=false;

        break;
    case 'K':
        if((col2_val==col1_val&&row2_val==row1_val+1)||(col2_val==col1_val&&row2_val==row1_val-1)||
       (row1_val==row2_val&&col2_val==col1_val+1)||(row1_val==row2_val&&col2_val==col1_val-1)||
       (row1_val+1==row2_val&&col2_val==col1_val+1)||(row1_val+1==row2_val&&col2_val==col1_val-1)||
       (row1_val-1==row2_val&&col2_val==col1_val-1)||(row1_val-1==row2_val&&col2_val==col1_val+1)
       ){

    }
    else
        valid=false;
        break;
        default:
            valid=false;
            break;
        }
        }

}

int main()
{
//cout<<typeid(abs(-12)).name()<<endl;

int choice{1};
while(choice){
checkmate=false;
while(!checkmate){
draw();
play();
logic(col1,row1,col2,row2);
if(valid){
    move(col1,row1,col2,row2);
    player=(!player);
    }
else
    cout<<"the move is invalid"<<endl;
}
system("cls");
cout<< "checkmate..."<<endl;
if(player)
    cout<<"congratulations Black you won"<<endl;
else
    cout<<"congratulations White you won"<<endl;
//system("cls");
cout<<"do you want to play another game : 1-yes  0-no ";
cin>>choice;
}
cout<<"hello"<<endl;
}


