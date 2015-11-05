/*
 Sam Hagan
 CIS554 Homework 5
 wordFont.h
 
 The header file for the WordFont class.
 */

#include <string>
#include <vector>

using namespace std;

class WordFont {
public:
    WordFont();
    void start();
    
private:
    void drawWord(string, char, int, int);
    void printWord();
    void drawA(int, char, int, bool);
    void drawBoldA(int, char, int);
    
    void drawE(int, char, int, bool);
    void drawBoldE(int, char, int);
    
    void drawI(int, char, int, bool);
    void drawBoldI(int, char, int);
    
    void drawO(int, char, int, bool);
    void drawBoldO(int, char, int);
    
    void drawU(int, char, int, bool);
    void drawBoldU(int, char, int);
    
    void drawC(int, char, int, bool);
    void drawBoldC(int, char, int);
    
    void drawB(int, char, int, bool);
    void drawBoldB(int, char, int);
    
    void drawD(int, char, int, bool);
    void drawBoldD(int, char, int);
    
    void drawF(int, char, int, bool);
    void drawBoldF(int, char, int);
    
    void drawG(int, char, int, bool);
    void drawBoldG(int, char, int);
    
    void drawH(int, char, int, bool);
    void drawBoldH(int, char, int);
    
    void drawJ(int, char, int, bool);
    void drawBoldJ(int, char, int);
    
    void drawL(int, char, int, bool);
    void drawBoldL(int, char, int);
    
    void drawN(int, char, int, bool);
    
    void drawS(int, char, int, bool);
    void drawBoldS(int, char, int);
    
    void drawT(int, char, int, bool);
    void drawBoldT(int, char, int);
    
    vector<vector<char> > wordVector;
};
