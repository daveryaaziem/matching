//
// Created by drsmith on 1/27/2020.
//

#ifndef MATCHING_MATCHINGGAME_H
#define MATCHING_MATCHINGGAME_H
#include <iostream>
struct coords{
    int row;
    int col;
};
const int size = 4;
bool isMatch(int a, int b);
bool hasMatches(char arr[][size]);
bool boardFilled(char arr[][size]);
bool coordsEqual(coords a, coords b);
bool notSet(char arr[][size], coords b);
void printBoard(char arr[][size]);
int getUserInput();
void output(std::string message, char var);
void start();
void createBoard(char arr[][size]);
void setBoard(char arr[][size], coords rowCol, char value);
void generateMatches(char arr[]);
void randomizeMatches(char arr[]);
void convertCoordsTest();
coords convertToCords(int c);
coords getCoords(int from, int to);
char getBoardValue(char arr[][size], coords c);
void setBackBoard(char arr[][size]);
#endif //MATCHING_MATCHINGGAME_H
