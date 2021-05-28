//tic tac toe game in cpp

#include <iostream>
#include <stdlib.h>
using namespace std;

//global variable
char board[3][3] = {{'1','2','3'},{'4','5','6',},{'7','8','9'}};
//initialize player
char player = 'O';

//draw the main board
void draw_board()
{
    cout<<"\n\t\t "<<board[0][0]<<" | "<<board[0][1]<<" | "<<board[0][2]<<endl;
    cout<<"\t\t-----------"<<endl;

    cout<<"\t\t "<<board[1][0]<<" | "<<board[1][1]<<" | "<<board[1][2]<<endl;
    cout<<"\t\t-----------"<<endl;

    cout<<"\t\t "<<board[2][0]<<" | "<<board[2][1]<<" | "<<board[2][2]<<endl;

}

//flip player
void flip_player()
{
    if(player=='X')
        player = 'O';
    else
        player = 'X';
}

//place symbol at board
void turn()
{
    char position;
//    flip player
    flip_player();

//    taking input from player
label1:
    cout<<"\n\t\tPlayer "<<player<<"'s turn"<<endl;
    cout<<"\t\tEnter position number ";
    cin>>position;
//    putting value at position
    if(position >'0' && position <'10')
    {
        if(position=='1' && board[0][0] == '1')
        board[0][0] = player;
        else if(position == '2' && board[0][1] == '2')
            board[0][1] = player;
        else if(position == '3' && board[0][2] == '3')
            board[0][2] = player;
        else if(position=='4' && board[1][0] == '4')
            board[1][0] = player;
        else if(position=='5' && board[1][1] == '5')
            board[1][1] = player;
        else if(position=='6' && board[1][2] == '6')
            board[1][2] = player;
        else if(position=='7' && board[2][0] == '7')
            board[2][0]= player;
        else if(position=='8' && board[2][1] == '8')
            board[2][1]= player;
        else if(position=='9' && board[2][2] == '9')
            board[2][2] = player;
        else
            goto label1;


    }
}

//check winner
char check_win()
{
//    check rows winner
    if(board[0][0] == 'X' && board[0][1] == 'X' && board[0][2] == 'X' ||
       board[1][0] == 'X' && board[1][1] == 'X' && board[1][2] == 'X' ||
       board[2][0] == 'X' && board[2][1] == 'X' && board[2][2] == 'X' ||
//     check column winner
       board[0][0] == 'X' && board[1][0] == 'X' && board[2][0] == 'X' ||
       board[0][1] == 'X' && board[1][1] == 'X' && board[2][1] == 'X' ||
       board[0][2] == 'X' && board[1][2] == 'X' && board[2][2] == 'X' ||
//       check diagonal winner
       board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X' ||
       board[2][0] == 'X' && board[1][1] == 'X' && board[0][2] == 'X')
        return 'X';

//      check rows winner
    else if(board[0][0] == 'O' && board[0][1] == 'O' && board[0][2] == 'O' ||
            board[1][0] == 'O' && board[1][1] == 'O' && board[1][2] == 'O' ||
            board[2][0] == 'O' && board[2][1] == 'O' && board[2][2] == 'O' ||
//       check column winner
            board[0][0] == 'O' && board[1][0] == 'O' && board[2][0] == 'O' ||
            board[0][1] == 'O' && board[1][1] == 'O' && board[2][1] == 'O' ||
            board[0][2] == 'O' && board[1][2] == 'O' && board[2][2] == 'O' ||
//       check diagonal winner
            board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O' ||
            board[2][0] == 'O' && board[1][1] == 'O' && board[0][2] == 'O')
        return 'O';

    else if(board[0][0] != '1' && board[0][1] != '2' && board[0][2] != '3' && board[1][0] != '4' &&
            board[1][1] != '5' && board[1][2] != '6' && board[2][0] != '7' && board[2][1] != '8' &&
            board[2][2] != '9')
            return 'D';

}

int main()
{
    char win_or_draw;

    while(1)
    {
        system("cls");
        cout<<"\n~~~~~~~~~~~ WELCOME TO TIC-TAC-TOE GAME ~~~~~~~~~~~"<<endl;

//      display main board
        draw_board();

//        checking for winner
        win_or_draw = check_win();
        if(win_or_draw == 'X')
            {
                cout<<"\n\tCongratulations! Player X is Winner. "<<endl;
                break;
            }
        else if(win_or_draw == 'O')
            {
                cout<<"\n\tCongratulations! Player O is Winner. "<<endl;
                break;
            }
        else if(win_or_draw == 'D')
        {
            cout<<"\n\t Game Draw! "<<endl;
            break;
        }

//      player turn
        turn();

    }

    cout<<"\n\n\t Thanks for playing!"<<endl;
    cout<<"\tDeveloped by PanditProgrammer.com"<<endl;
    system("pause");
//    main function ends
}
