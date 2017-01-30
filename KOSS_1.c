#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

char bf[5][5];

void print()
{
    int k,l;
    for(k=0;k<5;k++)
    {
        for (l=0;l<5;l++)
        {
            printf(" %c ",bf[k][l]);
        }
        printf("\n");
    }
}

void main()
{
    //Variable declaration
    int level,a,b,turn,bturn,i,j,g1,g2;
    printf("Welcome to the game of battleship!\n");
    printf("Type your prefered level and press Enter/Return \n");
    printf("Level 1 - Cry Baby(20 turns)\nLevel 2 - U can do it(16 turns)\nLevel 3 - Ready for the challenege(12 turns)\nLevel 4 - Just i m possible(8 turns)\n");
    printf("Level ");
    scanf("%d", &level);
    if((level<1)||(level>4))
        exit(0);
    printf("\nYou have choosen Level %d\n", level);
    turn = (24 - (level*4));
    printf("You will get %d turns to guess the location of the ship\n", turn);

    for(i=0;i<5;i++)
        for(j=0;j<5;j++)
            bf[i][j] = 'X';
    printf("Type the co-ordinates of your guess\n");
    print();
    time_t t;
    srand(time(&t));
    a = rand()%5;
    b = rand()%5;
    printf("%d %d",a,b);
    while(turn>0)
    {
        scanf("%d %d",&g1,&g2);
        g1--;
        g2--;
        if((g1<0)||(g1>4)||(g2<0)||(g2>4))
        {
            printf("Out of bounds!! You went out of the battlefield\n");
            printf("Turns left = %d\n",turn);
        }
        if((g2==a) && (g1==b))
        {
            bturn = turn;
            turn = -1;
            bf[a][b] = '!';
            print();
            break;
        }
        if(bf[g2][g1]=='O')
        {
            printf("You have already tried the grid!! Try another one\nTurns left = %d\n",turn);
        }
        if(bf[g2][g1]=='X')
        {
            bf[g2][g1] = 'O';
            print();
            turn--;
            printf("Turns left = %d\n",turn);
        }
    }
    if (turn == -1)
    {
        printf("CONGRATULATIONS !!!!! You bombed the battleship\n");
        printf("Your score = %d\n",(bturn*level));
    }
    else
    {
        printf("So sorry.... You lost\nYour score = 0\n");
    }
    printf("Thanks for playing BATTLESHIP\nnd have a very nice day");
}
