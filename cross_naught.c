#include <stdio.h>
int turn = 1;
void display(int n, int board[n])
{
    int i;
    for (i = 1; i < 10; i++)
    {
        if (board[i] == 3)
            printf("X ");
        if (board[i] == 2)
            printf("_ ");
        if (board[i] == 5)
            printf("O ");
        if (i % 3 == 0)
            printf("\n");
    }
}
int checkwin(int n, int board[n], int num)
{
    int test[3][8] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {1, 4, 7}, {2, 5, 8}, {3, 6, 9}, {1, 5, 9}, {3, 5, 7}};
    int i, n = num * num * num;
    for (i = 0; i < 9; i++)
    {
        if (board[test[i][0]] * board[test[i][1]] * board[test[i][2]] == n)
            return n;
    }
}
int poswin(int n, int num, int board[])
{
    int i;
    if (board[1] * board[2] * board[3] == num * num * 2)
    {
        for (i = 1; i < 4; i++)
        {
            if (board[i] == 2)
            {
                return i;
            }
        }
    }
    else if (board[4] * board[5] * board[6] == num * num * 2)
    {
        for (i = 4; i < 7; i++)
        {
            if (board[i] == 2)
            {
                return i;
            }
        }
    }
    else if (board[7] * board[8] * board[9] == num * num * 2)
    {
        for (i = 7; i < 10; i++)
        {
            if (board[i] == 2)
            {
                return i;
            }
        }
    }
    else if (board[1] * board[4] * board[7] == num * num * 2)
    {
        if (board[1] == 2)
            return 1;
        else if (board[4] == 2)
            return 4;
        else if (board[7] == 2)
            return 7;
    }
    else if (board[2] * board[5] * board[8] == num * num * 2)
    {
        if (board[2] == 2)
            return 2;
        else if (board[5] == 2)
            return 5;
        else if (board[8] == 2)
            return 8;
    }
    else if (board[3] * board[6] * board[9] == num * num * 2)
    {
        if (board[3] == 2)
            return 3;
        else if (board[6] == 2)
            return 6;
        else if (board[9] == 2)
            return 9;
    }
    else if (board[1] * board[5] * board[9] == num * num * 2)
    {
        if (board[1] == 2)
            return 1;
        else if (board[5] == 2)
            return 5;
        else if (board[9] == 2)
            return 9;
    }
    else if (board[3] * board[5] * board[7] == num * num * 2)
    {
        if (board[3] == 2)
            return 3;
        else if (board[5] == 2)
            return 5;
        else if (board[7] == 2)
            return 7;
    }
    return 0;
}
int make_two(int n, int board[n])
{
    if (board[5] == 2)
        return 5;
    else if (board[2] == 2)
        return 2;
    else if (board[4] == 2)
        return 4;
    else if (board[6] == 2)
        return 6;
    else if (board[8] == 2)
        return 8;
    return 0;
}
void go(int pos, int n, int board[n])
{
    if (turn % 2 == 0) // even turn put X
    {
        board[pos] = 5;
    }
    else // even turn put X
    {
        board[pos] = 3;
    }
    turn = turn + 1;
}
int main()
{
    int who, i, user = -1, n = 10, x, y;
    printf("Enter 1 to choose X and 2 to choose O\n");
    scanf("%d", &who);
    int board[n];
    for (i = 1; i < 10; i++)
    {
        board[i] = 2;
    }
    int flag = 0;
    /*******************/
    if (who == 2)
    {
        go(1, n, board);
        display(n, board);
        printf("Your turn\nEnter the position where you want to put O\n");
        scanf("%d", &user);
        go(user, n, board);
        if (board[9] == 2)
        {
            go(9, n, board);
        }
        else
            go(3, n, board);
        display(n, board);
        printf("Your turn\nEnter the position where you want to put O\n");
        scanf("%d", &user);
        go(user, n, board);
        x = poswin(n, 3, board);
        y = poswin(n, 5, board);
        if (x != 0)
        {
            go(x, n, board);
            printf("Computer Won!\n");
            display(n, board);
            return 0;
        }
        else if (y != 0)
        {
            go(y, n, board);
        }
        else if (board[7] == 2)
        {
            go(7, n, board);
        }
        else
        {
            go(3, n, board);
        }
        display(n, board);
        printf("Your turn\nEnter the position where you want to put O\n");
        scanf("%d", &user);
        go(user, n, board);
        x = poswin(n, 3, board);
        y = poswin(n, 5, board);
        if (x != 0)
        {
            go(x, n, board);
            printf("Computer won!\n");
            display(n, board);
            return 0;
        }
        else if (y != 0)
        {
            go(y, n, board);
        }
        else
        {
            go(make_two(n, board), n, board);
        }
        display(n, board);
        printf("Your turn,\nEnter the valid position where you want to put X\n");
        scanf("%d", &user);
        go(user, n, board);
        x = poswin(n, 3, board);
        y = poswin(n, 5, board);
        if (x != 0)
        {
            go(x, board, turn);
            printf("Computer won!\n");
        }
        else if (y!= 0)
        {
            go(y, n, board);
        }
        else
        {
            go(make_two(n,board), n, board);
        }
        display(n, board);

        if (!flag)
        {
            printf("DRAW!\n");
        }
    }
    /***********************/
    if (who == 1)
    {
        display(n, board);
        printf("Your turn,\nEnter the valid position where you want to put X\n");
        scanf("%d", &user);
        go(user, n, board);
        if (board[5] == 2)
        {
            go(5, n, board);
        }
        else
        {
            go(1, n, board);
        }
        display(n, board);
        printf("Your turn,\nEnter the valid position where you want to put X \n");
        scanf("%d", &user);
        go(user, n, board);
        x = poswin(n, 3, board);
        y = poswin(n, 5, board);
        if (x != 0)
        {
            go(x, n, board);
        }
        else
        {
            go(make_two(n, board), n, board);
        }
        display(n, board);
        printf("Your turn,\nEnter the valid position where you want to put X \n");
        scanf("%d", &user);
        go(user, n, board);
        x = poswin(n, 3, board);
        y = poswin(n, 5, board);
        go(user, board, turn);
        if (checkwin(n,board,3) == 27 || checkwin(n,board,5) == 125)
        {
            printf("User Win\n");
            return 0;
        }
        if (y != 0)
        {
            go(y, n, board);
            display(n, board);
            printf("Computer won !\n");
            return 0;
        }
        else if (x != 0)
        {
            go(x, n, board);
        }
        else
        {
            go(make_two(n, board), n, board);
        }
        display(n, board);
        printf("Your turn,\nEnter the valid position where you want to put X \n");
        scanf("%d", &user);
        go(user, n, board);
        x = poswin(n, 3, board);
        y = poswin(n, 5, board);
        if (checkwin(n,board,3) == 27 || checkwin(n,board,5) == 125)
        {
            printf("User Win\n");
            return 0;
        }
        if (y != 0)
        {
            go(y, n, board);
            display(n, board);
            printf("Computer won !\n");
            return 0;
        }
        else if (x != 0)
        {
            go(x, n, board);
        }
        else
        {
            go(make_two(n, board), n, board);
        }
        display(n, board);
        printf("Your turn,\nEnter the valid position where you want to put X \n");
        scanf("%d", &user);
        go(user, n, board);
        if (poswin2(3, board) == 27 || poswin2(5, board) == 125)
        {
            printf("User Win\n");
            return 0;
        }
        display(n,board);
        if (!flag)
        {
            printf("DRAW!\n");
        }
        display(n, board);
    }
    return 0;
}
