//
// Created by drsmith on 1/27/2020.
//

#include "MatchingGame.h"
#include <ctype.h>
#include <cstdlib>
#include <ctime>

bool isMatch(int a, int b)
{
    return a == b;
}
bool hasMatches(char arr[][size])
{
    return boardFilled(arr);
}
bool boardFilled(char arr[][size])
{
    for(int i=0; i<size; i++)
    {
        for(int j=0; j<size; j++)
            if(isalpha(arr[i][j]))
                    return false;
    }
    return true;
}

bool coordsEqual(coords a, coords b)
{

}

bool notSet(char arr[][size], coords c)
{
    return isdigit(arr[c.row][c.col]);
}



void randomizeMatches(char arr[])
{
    for(int i=(size*size)-1; i>=0; i--)
    {
        int j = rand() % (size*size);
        char temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

int getUserInput()
{
    int ans;
    std::cin >> ans;
    return ans;
}

void createBoard(char arr[][size])
{

    char matches[size*size];
    generateMatches(matches);
    randomizeMatches(matches);
    int count = 0;
    for(int i=0; i<size; i++)
    {
        for(int j=0; j<size; j++)
        {
            coords c = {i, j};
            setBoard(arr, c, matches[count++]);
        }
    }
}

void setBoard(char arr[][size], coords c, char value)
{
    arr[c.row][c.col] = value;
}

void printBoard(char arr[][size])
{
    for(int i=0; i<size; i++)
    {
        for(int j=0; j<size; j++)
        {
            std::cout.width(3);
            std::cout << arr[i][j];
        }
        std::cout << std::endl;
    }
}

void setBackBoard(char arr[][size])
{
    int count = 1;
    for(int i=0; i<size; i++)
    {
        for(int j=0; j<size; j++)
        {
            arr[i][j] = (char)48+(count++);
        }
    }
}
void output(std::string message, char var)
{
    std::cout << message << " " << var << std::endl;
}

void generateMatches(char arr[])
{
    int siz = (size*size)-1;
    char c = 65;
    for(int i=0; i<siz; i++)
    {

        arr[i] = c;
        arr[siz--] = c;
        if(c > 65 + 24)
            c = 65;
        else {
            c++;
        }
    }
}

void start()
{
    srand(time(NULL));
    char hidden[size][size];
    char display[size][size];
    setBackBoard(display);
    createBoard(hidden);
    while(boardFilled(display))
    {
        printBoard(display);
        int i = getUserInput();
        int i2 = getUserInput();
        coords c = convertToCords((char)i+48);
        coords c2 = convertToCords((char)i2+48);
        char val1 = getBoardValue(hidden, c);
        char val2 = getBoardValue(hidden, c2);
        setBoard(display, c, val1 );
        setBoard(display, c, val2 );
       // printBoard(display);
        if(!isMatch(i, i2))
        {
            setBoard(display, c, val1 );
            setBoard(display, c, val1 );
        }

    }
}

coords convertToCords(int num)
{
    coords x = {(num-1)/size, ((num-1)%size)};

    return x;
}
coords getCoords(int from, int to)
{
    int row = (rand()%(to -from + 1) + from);
    int col = (rand()%(to -from + 1) + from);
    coords rowCol = {row, col};
    return rowCol;
}

void convertCoordsTest() {
    char ans;
    do{
    output("enter a num.", NULL);
    int a = getUserInput();
    coords x = convertToCords(a);
    std::string s = "row = " + std::to_string(x.row) + ", col = " + std::to_string(x.col);
    output(s, NULL);
    output("Repeat?", NULL);
    ans = getUserInput();
    }while(ans =='y');
}
char getBoardValue(char arr[][size], coords c)
{
    return arr[c.row][c.col];
}