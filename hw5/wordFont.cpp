/*
    Sam Hagan
    CIS554 Homework 5
    wordFont.cpp
 
    This class implements a WordFont object that has only one public method: start().
    When start is called, WordFont infinitely loops, prompts the user for input values, 
    and prints formatted representations of the users input string.
*/

#include "wordFont.h"
#include <iostream>
#include <vector>
using namespace std;

WordFont::WordFont(){
}

/*
 The start() method loops infinitely, prompting the user for a string, and other necessary
 variables needed to draw the string.
*/
void WordFont::start() {
    for (;;){
        string userWord;
        cout << "Enter a word (8 letters or less), using a, e, i, o, u, c, b, d, f, g, h, j, l, s, t: ";
        cin >> userWord;
        
        char userPixel;
        cout << "Enter the pixel character you want to use to draw: ";
        cin >> userPixel;
    
        int fontSize;
        cout << "Enter font size: ";
        cin >> fontSize;
    
        int bold;
        cout << "Bold font? (0=No, 1=Yes) ";
        cin >> bold;
        cout << endl;
        
        int printedWordLength = (fontSize + 2) * userWord.length(); // Add 2 extra spaces per letter for whitespace
        wordVector.assign(fontSize,vector<char>(printedWordLength, ' '));
        drawWord(userWord, userPixel, fontSize, bold);
        printWord();
        cout << endl;
        
        char response;
        cout << "Continue? (y/n) ";
        cin >> response;
        if (response == 'n'){
            break;
        }
    }
}

/*
 The drawWord method iterates through the user's entered word, and draws
 each letter in the wordVector two-dimensional array.
*/
void WordFont::drawWord(string word, char pixel, int fontSize, int bold){
    bool useBold;
    if (bold == 1){
        useBold = true;
    }
    else {
        useBold = false;
    }
    for (int i = 0; i < word.length(); i++){
        switch (word.at(i)) {
                case 'a':
                    drawA(i, pixel, fontSize, useBold);
                    break;
                case 'e':
                    drawE(i, pixel, fontSize, useBold);
                    break;
                case 'i':
                    drawI(i, pixel, fontSize, useBold);
                    break;
                case 'o':
                    drawO(i, pixel, fontSize, useBold);
                    break;
                case 'u':
                    drawU(i, pixel, fontSize, useBold);
                    break;
                case 'c':
                    drawC(i, pixel, fontSize, useBold);
                    break;
                case 'b':
                    drawB(i, pixel, fontSize, useBold);
                    break;
                case 'd':
                    drawD(i, pixel, fontSize, useBold);
                    break;
                case 'f':
                    drawF(i, pixel, fontSize, useBold);
                    break;
                case 'g':
                    drawG(i, pixel, fontSize, useBold);
                    break;
                case 'h':
                    drawH(i, pixel, fontSize, useBold);
                    break;
                case 'j':
                    drawJ(i, pixel, fontSize, useBold);
                    break;
                case 'k':
                    drawK(i, pixel, fontSize, useBold);
                    break;
                case 'l':
                    drawL(i, pixel, fontSize, useBold);
                    break;
                case 'm':
                    drawM(i, pixel, fontSize, useBold);
                    break;
                case 'n':
                    drawN(i, pixel, fontSize, useBold);
                    break;
                case 'r':
                    drawR(i, pixel, fontSize, useBold);
                    break;
                case 's':
                    drawS(i, pixel, fontSize, useBold);
                    break;
                case 't':
                    drawT(i, pixel, fontSize, useBold);
                    break;
                default:
                    cout << "Word contains an unrecognized letter.";
                    return;
                
                
        }
    }
}
/*
 printWord() is a method that prints the two-dimensional vector called wordVector
 to the terminal.
*/
void WordFont::printWord(){
    for (int row = 0; row < wordVector.size(); row++){
        for (int col = 0; col < wordVector.at(0).size(); col++){
            cout << wordVector[row][col];
        }
        cout << endl;
    }
}

/*
 drawA is a method that draws the letter A at the appropriate spot in the two-
 dimensional array holding the user's entered word by setting the correct spots
 equal to the user's entered pixel character.
 
 Parameters:
    (int) position - the position of the letter in the word
    (char) pixel - the pixel used to draw the word
    (int) fontSize - the font size of the word
    (bool) useBold - a boolean value representing whether or not to use bold
*/
void WordFont::drawA(int position, char pixel, int fontSize, bool useBold){
    if (useBold){                               // If the user indicated they want to draw bold
        drawBoldA(position, pixel, fontSize);   // draw the letter in bold
        return;                                 // and leave this method
    }
    int startingSpot = (fontSize+2) * position;
    int endingSpot = startingSpot + fontSize;
    int crossRow = (fontSize/2);

    for (int row = 0; row < fontSize; row++){
        for (int col = startingSpot; col < endingSpot; col++){
            if (row == 0){ // Check row conditions
                wordVector[row][col] = pixel;
            }
            else if(row == crossRow){
                wordVector[row][col] = pixel;
            }
            
            if (col == startingSpot){ // Check column conditions
                wordVector[row][col] = pixel;
            }
            else if (col == (endingSpot-1)){
                wordVector[row][col] = pixel;
            }
            
        }
    }
}

/*
 drawBoldA is a helper method that gets called from drawA when its boolean parameter
 useBold is true. It achieves similar functionality to drawA, but draws letters bold
 by adding another line to each edge of the letter
 
 Parameters:
    (int) position - the position of the letter in the word
    (char) pixel - the pixel used to draw the word
    (int) fontSize - the font size of the word
*/
void WordFont::drawBoldA(int position, char pixel, int fontSize){
    int startingSpot = (fontSize+2) * position;
    int endingSpot = startingSpot + fontSize;
    int crossRow = (fontSize/2);
    
    for (int row = 0; row < fontSize; row++){
        for (int col = startingSpot; col < endingSpot; col++){
            if (row == 0){ // Check row conditions
                wordVector[row][col] = pixel;
                wordVector[row+1][col] = pixel;
            }
            else if(row == crossRow){
                wordVector[row][col] = pixel;
                wordVector[row+1][col] = pixel;
            }
            
            if (col == startingSpot){ // Check column conditions
                wordVector[row][col] = pixel;
                wordVector[row][col+1] = pixel;
            }
            else if (col == (endingSpot-1)){
                wordVector[row][col] = pixel;
                wordVector[row][col-1] = pixel;
            }
            
        }
    }
}

/*
 drawE is a method that draws the letter E at the appropriate spot in the two-
 dimensional array holding the user's entered word by setting the correct spots
 equal to the user's entered pixel character.
 
 Parameters:
 (int) position - the position of the letter in the word
 (char) pixel - the pixel used to draw the word
 (int) fontSize - the font size of the word
 (bool) useBold - a boolean value representing whether or not to use bold
 */
void WordFont::drawE(int position, char pixel, int fontSize, bool useBold){
    if (useBold){
        drawBoldE(position, pixel, fontSize);
        return;
    }
    int startingSpot = (fontSize+2) * position;
    int endingSpot = startingSpot + fontSize;
    int crossRow = (fontSize/2);
    for (int row = 0; row < fontSize; row++){
        for (int col = startingSpot; col < endingSpot; col++){
            if (row == 0){ // Check row conditions
                wordVector[row][col] = pixel;
            }
            else if(row == crossRow){
                wordVector[row][col] = pixel;
            }
            else if(row == (fontSize-1)){
                wordVector[row][col] = pixel;
            }
            
            if (col == startingSpot){ // Check column conditions
                wordVector[row][col] = pixel;
            }
            
        }
    }
}

/*
 drawBoldE is a helper method that gets called from drawE when its boolean parameter
 useBold is true. It achieves similar functionality to drawE, but draws letters bold
 by adding another line to each edge of the letter
 
 Parameters:
 (int) position - the position of the letter in the word
 (char) pixel - the pixel used to draw the word
 (int) fontSize - the font size of the word
 */
void WordFont::drawBoldE(int position, char pixel, int fontSize){
    int startingSpot = (fontSize+2) * position;
    int endingSpot = startingSpot + fontSize;
    int crossRow = (fontSize/2);
    for (int row = 0; row < fontSize; row++){
        for (int col = startingSpot; col < endingSpot; col++){
            if (row == 0){ // Check row conditions
                wordVector[row][col] = pixel;
                wordVector[row+1][col] = pixel;
            }
            else if(row == crossRow){
                wordVector[row][col] = pixel;
                wordVector[row-1][col] = pixel;
            }
            else if(row == (fontSize-1)){
                wordVector[row][col] = pixel;
                wordVector[row-1][col] = pixel;
            }
            
            if (col == startingSpot){ // Check column conditions
                wordVector[row][col] = pixel;
                wordVector[row][col+1] = pixel;
            }
            
        }
    }
}
/*
 drawI is a method that draws the letter I at the appropriate spot in the two-
 dimensional array holding the user's entered word by setting the correct spots
 equal to the user's entered pixel character.
 
 Parameters:
 (int) position - the position of the letter in the word
 (char) pixel - the pixel used to draw the word
 (int) fontSize - the font size of the word
 (bool) useBold - a boolean value representing whether or not to use bold
 */
void WordFont::drawI(int position, char pixel, int fontSize, bool useBold){
    if (useBold){
        drawBoldI(position, pixel, fontSize);
        return;
    }
    int startingSpot = (fontSize+2) * position;
    int endingSpot = startingSpot + fontSize;
    int crossCol = startingSpot + (fontSize/2);
    
    for (int row = 0; row < fontSize; row++){
        for (int col = startingSpot; col < endingSpot; col++){
            if (col == crossCol){ // Check column conditions
                wordVector[row][col] = pixel;
            }
            
        }
    }

}

/*
 drawBoldI is a helper method that gets called from drawI when its boolean parameter
 useBold is true. It achieves similar functionality to drawI, but draws letters bold
 by adding another line to each edge of the letter
 
 Parameters:
 (int) position - the position of the letter in the word
 (char) pixel - the pixel used to draw the word
 (int) fontSize - the font size of the word
 */
void WordFont::drawBoldI(int position, char pixel, int fontSize){
    int startingSpot = (fontSize+2) * position;
    int endingSpot = startingSpot + fontSize;
    int crossCol = startingSpot + (fontSize/2);
    
    for (int row = 0; row < fontSize; row++){
        for (int col = startingSpot; col < endingSpot; col++){
            if (col == crossCol){ // Check column conditions
                wordVector[row][col] = pixel;
                wordVector[row][col+1] = pixel;
            }
            
        }
    }
}

/*
 drawO is a method that draws the letter O at the appropriate spot in the two-
 dimensional array holding the user's entered word by setting the correct spots
 equal to the user's entered pixel character.
 
 Parameters:
 (int) position - the position of the letter in the word
 (char) pixel - the pixel used to draw the word
 (int) fontSize - the font size of the word
 (bool) useBold - a boolean value representing whether or not to use bold
 */
void WordFont::drawO(int position, char pixel, int fontSize, bool useBold){
    if (useBold){
        drawBoldO(position, pixel, fontSize);
        return;
    }
    int startingSpot = (fontSize+2) * position;
    int endingSpot = startingSpot + fontSize;
    
    for (int row = 0; row < fontSize; row++){
        for (int col = startingSpot; col < endingSpot; col++){
            if (row == 0){
                wordVector[row][col] = pixel;
            }
            else if (row == (fontSize-1)){
                wordVector[row][col] = pixel;
            }
            
            if (col == startingSpot){
                wordVector[row][col] = pixel;
            }
            else if (col == (endingSpot-1)){
                wordVector[row][col] = pixel;
            }
            
        }
    }
}

/*
 drawBoldO is a helper method that gets called from drawO when its boolean parameter
 useBold is true. It achieves similar functionality to drawO, but draws letters bold
 by adding another line to each edge of the letter
 
 Parameters:
 (int) position - the position of the letter in the word
 (char) pixel - the pixel used to draw the word
 (int) fontSize - the font size of the word
 */
void WordFont::drawBoldO(int position, char pixel, int fontSize){
    int startingSpot = (fontSize+2) * position;
    int endingSpot = startingSpot + fontSize;
    
    for (int row = 0; row < fontSize; row++){
        for (int col = startingSpot; col < endingSpot; col++){
            if (row == 0){
                wordVector[row][col] = pixel;
                wordVector[row+1][col] = pixel;
            }
            else if (row == (fontSize-1)){
                wordVector[row][col] = pixel;
                wordVector[row-1][col] = pixel;
            }
            
            if (col == startingSpot){
                wordVector[row][col] = pixel;
                wordVector[row][col+1] = pixel;
            }
            else if (col == (endingSpot-1)){
                wordVector[row][col] = pixel;
                wordVector[row][col-1] = pixel;
            }
            
        }
    }
}

/*
 drawU is a method that draws the letter U at the appropriate spot in the two-
 dimensional array holding the user's entered word by setting the correct spots
 equal to the user's entered pixel character.
 
 Parameters:
 (int) position - the position of the letter in the word
 (char) pixel - the pixel used to draw the word
 (int) fontSize - the font size of the word
 (bool) useBold - a boolean value representing whether or not to use bold
 */
void WordFont::drawU(int position, char pixel, int fontSize, bool useBold){
    if (useBold){
        drawBoldU(position, pixel, fontSize);
        return;
    }
    int startingSpot = (fontSize+2) * position;
    int endingSpot = startingSpot + fontSize;
    
    for (int row = 0; row < fontSize; row++){
        for (int col = startingSpot; col < endingSpot; col++){
            if (row == (fontSize-1)){ // Check row conditions
                wordVector[row][col] = pixel;
            }
            
            if (col == startingSpot){ // Check column conditions
                wordVector[row][col] = pixel;
            }
            else if (col == (endingSpot-1)){
                wordVector[row][col] = pixel;
            }
            
        }
    }
    
}

/*
 drawBoldU is a helper method that gets called from drawU when its boolean parameter
 useBold is true. It achieves similar functionality to drawU, but draws letters bold
 by adding another line to each edge of the letter
 
 Parameters:
 (int) position - the position of the letter in the word
 (char) pixel - the pixel used to draw the word
 (int) fontSize - the font size of the word
 */
void WordFont::drawBoldU(int position, char pixel, int fontSize){
    int startingSpot = (fontSize+2) * position;
    int endingSpot = startingSpot + fontSize;
    
    for (int row = 0; row < fontSize; row++){
        for (int col = startingSpot; col < endingSpot; col++){
            if (row == (fontSize-1)){ // Check row conditions
                wordVector[row][col] = pixel;
                wordVector[row-1][col] = pixel;
            }
            
            if (col == startingSpot){ // Check column conditions
                wordVector[row][col] = pixel;
                wordVector[row][col+1] = pixel;
            }
            else if (col == (endingSpot-1)){
                wordVector[row][col] = pixel;
                wordVector[row][col-1] = pixel;
            }
            
        }
    }
}

/*
 drawC is a method that draws the letter C at the appropriate spot in the two-
 dimensional array holding the user's entered word by setting the correct spots
 equal to the user's entered pixel character.
 
 Parameters:
 (int) position - the position of the letter in the word
 (char) pixel - the pixel used to draw the word
 (int) fontSize - the font size of the word
 (bool) useBold - a boolean value representing whether or not to use bold
 */
void WordFont::drawC(int position, char pixel, int fontSize, bool useBold){
    if (useBold){
        drawBoldC(position, pixel, fontSize);
        return;
    }
    int startingSpot = (fontSize+2) * position;
    int endingSpot = startingSpot + fontSize;
    
    for (int row = 0; row < fontSize; row++){
        for (int col = startingSpot; col < endingSpot; col++){
            if (row == 0){ // Check row conditions
                wordVector[row][col] = pixel;
            }
            else if (row == (fontSize-1)){
                wordVector[row][col] = pixel;
            }
            
            if (col == startingSpot) { // Check column condition
                wordVector[row][col] = pixel;
            }
        }
    }
}

/*
 drawBoldC is a helper method that gets called from drawC when its boolean parameter
 useBold is true. It achieves similar functionality to drawC, but draws letters bold
 by adding another line to each edge of the letter
 
 Parameters:
 (int) position - the position of the letter in the word
 (char) pixel - the pixel used to draw the word
 (int) fontSize - the font size of the word
 */
void WordFont::drawBoldC(int position, char pixel, int fontSize){
    int startingSpot = (fontSize+2) * position;
    int endingSpot = startingSpot + fontSize;
    
    for (int row = 0; row < fontSize; row++){
        for (int col = startingSpot; col < endingSpot; col++){
            if (row == 0){ // Check row conditions
                wordVector[row][col] = pixel;
                wordVector[row+1][col] = pixel;
            }
            else if (row == (fontSize-1)){
                wordVector[row][col] = pixel;
                wordVector[row-1][col] = pixel;
            }
            
            if (col == startingSpot) { // Check column condition
                wordVector[row][col] = pixel;
                wordVector[row][col+1] = pixel;
            }
        }
    }
}

/*
 drawB is a method that draws the letter B at the appropriate spot in the two-
 dimensional array holding the user's entered word by setting the correct spots
 equal to the user's entered pixel character.
 
 Parameters:
 (int) position - the position of the letter in the word
 (char) pixel - the pixel used to draw the word
 (int) fontSize - the font size of the word
 (bool) useBold - a boolean value representing whether or not to use bold
 */
void WordFont::drawB(int position, char pixel, int fontSize, bool useBold){
    if (useBold){
        drawBoldB(position,pixel,fontSize);
        return;
    }
    int startingSpot = (fontSize+2) * position;
    int endingSpot = startingSpot + fontSize;
    int crossRow = (fontSize/2);
    
    for (int row = 0; row < fontSize; row++){
        for (int col = startingSpot; col < endingSpot; col++){
            if (row == 0){ //Row conditions
                if (col == (endingSpot-1)){ // Round the B edges to make it look better
                    continue;
                }
                wordVector[row][col] = pixel;
            }
            else if (row == (fontSize-1)){
                if (col == (endingSpot-1)){
                    continue;
                }
                wordVector[row][col] = pixel;
            }
            else if (row == crossRow){
                if (col == (endingSpot-1)){
                    continue;
                }
                wordVector[row][col] = pixel;
            }
            
            if (col == startingSpot){ //Column conditions
                wordVector[row][col] = pixel;
            }
            else if (col == (endingSpot-1)){
                wordVector[row][col] = pixel;
            }
        }
    }
}

/*
 drawBoldB is a helper method that gets called from drawB when its boolean parameter
 useBold is true. It achieves similar functionality to drawB, but draws letters bold
 by adding another line to each edge of the letter
 
 Parameters:
 (int) position - the position of the letter in the word
 (char) pixel - the pixel used to draw the word
 (int) fontSize - the font size of the word
 */
void WordFont::drawBoldB(int position, char pixel, int fontSize){
    int startingSpot = (fontSize+2) * position;
    int endingSpot = startingSpot + fontSize;
    int crossRow = (fontSize/2);
    
    for (int row = 0; row < fontSize; row++){
        for (int col = startingSpot; col < endingSpot; col++){
            if (row == 0){ //Row conditions
                if (col == (endingSpot-1)){ // Round the B edges to make it look less like an 8
                    continue;
                }
                wordVector[row][col] = pixel;
                wordVector[row+1][col] = pixel;
            }
            else if (row == (fontSize-1)){
                if (col == (endingSpot-1)){
                    continue;
                }
                wordVector[row][col] = pixel;
                wordVector[row-1][col] = pixel;
            }
            else if (row == crossRow){
                if (col == (endingSpot-1)){
                    continue;
                }
                wordVector[row][col] = pixel;
                wordVector[row-1][col] = pixel;
            }
            
            if (col == startingSpot){ //Column conditions
                wordVector[row][col] = pixel;
                wordVector[row][col+1] = pixel;
            }
            else if (col == (endingSpot-1)){
                wordVector[row][col] = pixel;
                wordVector[row][col-1] = pixel;
            }
        }
    }
}

/*
 drawD is a method that draws the letter D at the appropriate spot in the two-
 dimensional array holding the user's entered word by setting the correct spots
 equal to the user's entered pixel character.
 
 Parameters:
 (int) position - the position of the letter in the word
 (char) pixel - the pixel used to draw the word
 (int) fontSize - the font size of the word
 (bool) useBold - a boolean value representing whether or not to use bold
 */
void WordFont::drawD(int position, char pixel, int fontSize, bool useBold){
    if (useBold){
        drawBoldD(position, pixel, fontSize);
        return;
    }
    int startingSpot = (fontSize+2) * position;
    int endingSpot = startingSpot + fontSize;
    
    for (int row = 0; row < fontSize; row++){
        for (int col = startingSpot; col < endingSpot; col++){
            if (row == 0){
                if (col == (endingSpot-1)){ // Curve the top right edge of D so it doesn't look like O
                    continue;
                }
                wordVector[row][col] = pixel;
            }
            else if (row == (fontSize-1)){
                if (col == (endingSpot-1)){ // Curve the bottom right edge of D so it doesn't look like O
                    continue;
                }
                wordVector[row][col] = pixel;
            }
            if (col == startingSpot){ // Column conditions
                wordVector[row][col] = pixel;
            }
            else if (col == endingSpot-1){
                wordVector[row][col] = pixel;
            }
        }
    }
}

/*
 drawBoldD is a helper method that gets called from drawD when its boolean parameter
 useBold is true. It achieves similar functionality to drawD, but draws letters bold
 by adding another line to each edge of the letter
 
 Parameters:
 (int) position - the position of the letter in the word
 (char) pixel - the pixel used to draw the word
 (int) fontSize - the font size of the word
 */
void WordFont::drawBoldD(int position, char pixel, int fontSize){
    int startingSpot = (fontSize+2) * position;
    int endingSpot = startingSpot + fontSize;
    
    for (int row = 0; row < fontSize; row++){
        for (int col = startingSpot; col < endingSpot; col++){
            if (row == 0){
                if (col == (endingSpot-1)){ // Curve the top right edge of D so it doesn't look like O
                    continue;
                }
                wordVector[row][col] = pixel;
                wordVector[row+1][col] = pixel;
            }
            else if (row == (fontSize-1)){
                if (col == (endingSpot-1)){ // Curve the bottom right edge of D so it doesn't look like O
                    continue;
                }
                wordVector[row][col] = pixel;
                wordVector[row-1][col] = pixel;
            }
            if (col == startingSpot){ // Column conditions
                wordVector[row][col] = pixel;
                wordVector[row][col+1] = pixel;
            }
            else if (col == endingSpot-1){
                wordVector[row][col] = pixel;
                wordVector[row][col-1] = pixel;
            }
        }
    }
}

/*
 drawF is a method that draws the letter F at the appropriate spot in the two-
 dimensional array holding the user's entered word by setting the correct spots
 equal to the user's entered pixel character.
 
 Parameters:
 (int) position - the position of the letter in the word
 (char) pixel - the pixel used to draw the word
 (int) fontSize - the font size of the word
 (bool) useBold - a boolean value representing whether or not to use bold
 */
void WordFont::drawF(int position, char pixel, int fontSize, bool useBold){
    if (useBold){
        drawBoldF(position, pixel, fontSize);
        return;
    }
    int startingSpot = (fontSize+2) * position;
    int endingSpot = startingSpot + fontSize;
    int crossRow = (fontSize/2);
    
    for (int row = 0; row < fontSize; row++){
        for (int col = startingSpot; col < endingSpot; col++){
            if (row == 0){
                wordVector[row][col] = pixel;
            }
            else if (row == crossRow){
                wordVector[row][col] = pixel;
            }
            
            if (col == startingSpot){
                wordVector[row][col] = pixel;
            }
        }
    }
}

/*
 drawBoldF is a helper method that gets called from drawF when its boolean parameter
 useBold is true. It achieves similar functionality to drawF, but draws letters bold
 by adding another line to each edge of the letter
 
 Parameters:
 (int) position - the position of the letter in the word
 (char) pixel - the pixel used to draw the word
 (int) fontSize - the font size of the word
 */
void WordFont::drawBoldF(int position, char pixel, int fontSize){
    int startingSpot = (fontSize+2) * position;
    int endingSpot = startingSpot + fontSize;
    int crossRow = (fontSize/2);
    
    for (int row = 0; row < fontSize; row++){
        for (int col = startingSpot; col < endingSpot; col++){
            if (row == 0){
                wordVector[row][col] = pixel;
                wordVector[row+1][col] = pixel;
            }
            else if (row == crossRow){
                wordVector[row][col] = pixel;
                wordVector[row+1][col] = pixel;
            }
            
            if (col == startingSpot){
                wordVector[row][col] = pixel;
                wordVector[row][col+1] = pixel;
            }
        }
    }
}

/*
 drawG is a method that draws the letter G at the appropriate spot in the two-
 dimensional array holding the user's entered word by setting the correct spots
 equal to the user's entered pixel character.
 
 Parameters:
 (int) position - the position of the letter in the word
 (char) pixel - the pixel used to draw the word
 (int) fontSize - the font size of the word
 (bool) useBold - a boolean value representing whether or not to use bold
 */
void WordFont::drawG(int position, char pixel, int fontSize, bool useBold){
    if (useBold){
        drawBoldG(position, pixel, fontSize);
        return;
    }
    int startingSpot = (fontSize+2) * position;
    int endingSpot = startingSpot + fontSize;
    int crossRow = (fontSize/2);
    int crossCol = startingSpot + (fontSize/2);
    
    for (int row = 0; row < fontSize; row++){
        for (int col = startingSpot; col < endingSpot; col++){
            if (row == 0){ // Row constraints
                wordVector[row][col] = pixel;
            }
            else if (row == (fontSize-1)){
                wordVector[row][col] = pixel;
            }
            else if ((row == crossRow) && (col > crossCol)){
                wordVector[row][col] = pixel;
            }
            
            if (col == startingSpot){ // Column constraints
                wordVector[row][col] = pixel;
            }
            else if ((col == endingSpot-1) && (row > crossRow)){
                wordVector[row][col] = pixel;
            }
        }
    }
}

/*
 drawBoldG is a helper method that gets called from drawG when its boolean parameter
 useBold is true. It achieves similar functionality to drawG, but draws letters bold
 by adding another line to each edge of the letter
 
 Parameters:
 (int) position - the position of the letter in the word
 (char) pixel - the pixel used to draw the word
 (int) fontSize - the font size of the word
 */
void WordFont::drawBoldG(int position, char pixel, int fontSize){
    int startingSpot = (fontSize+2) * position;
    int endingSpot = startingSpot + fontSize;
    int crossRow = (fontSize/2);
    int crossCol = startingSpot + (fontSize/2);
    
    for (int row = 0; row < fontSize; row++){
        for (int col = startingSpot; col < endingSpot; col++){
            if (row == 0){ // Row constraints
                wordVector[row][col] = pixel;
                wordVector[row+1][col] = pixel;
            }
            else if (row == (fontSize-1)){
                wordVector[row][col] = pixel;
                wordVector[row-1][col] = pixel;
            }
            else if ((row == crossRow) && (col > crossCol)){
                wordVector[row][col] = pixel;
                wordVector[row-1][col] = pixel;
            }
            
            if (col == startingSpot){ // Column constraints
                wordVector[row][col] = pixel;
                wordVector[row][col+1] = pixel;
            }
            else if ((col == endingSpot-1) && (row > crossRow)){
                wordVector[row][col] = pixel;
                wordVector[row][col-1] = pixel;
            }
        }
    }
}

/*
 drawH is a method that draws the letter H at the appropriate spot in the two-
 dimensional array holding the user's entered word by setting the correct spots
 equal to the user's entered pixel character.
 
 Parameters:
 (int) position - the position of the letter in the word
 (char) pixel - the pixel used to draw the word
 (int) fontSize - the font size of the word
 (bool) useBold - a boolean value representing whether or not to use bold
 */
void WordFont::drawH(int position, char pixel, int fontSize, bool useBold){
    if (useBold){
        drawBoldH(position, pixel, fontSize);
        return;
    }
    int startingSpot = (fontSize+2) * position;
    int endingSpot = startingSpot + fontSize;
    int crossRow = (fontSize/2);
    
    for (int row = 0; row < fontSize; row++){
        for (int col = startingSpot; col < endingSpot; col++){
            if (row == crossRow){
                wordVector[row][col] = pixel;
            }
            if (col == startingSpot){
                wordVector[row][col] = pixel;
            }
            else if (col == (endingSpot-1)){
                wordVector[row][col] = pixel;
            }
        }
    }
}

/*
 drawBoldH is a helper method that gets called from drawH when its boolean parameter
 useBold is true. It achieves similar functionality to drawH, but draws letters bold
 by adding another line to each edge of the letter
 
 Parameters:
 (int) position - the position of the letter in the word
 (char) pixel - the pixel used to draw the word
 (int) fontSize - the font size of the word
 */
void WordFont::drawBoldH(int position, char pixel, int fontSize){
    int startingSpot = (fontSize+2) * position;
    int endingSpot = startingSpot + fontSize;
    int crossRow = (fontSize/2);
    
    for (int row = 0; row < fontSize; row++){
        for (int col = startingSpot; col < endingSpot; col++){
            if (row == crossRow){
                wordVector[row][col] = pixel;
                wordVector[row-1][col] = pixel;
            }
            if (col == startingSpot){
                wordVector[row][col] = pixel;
                wordVector[row][col+1] = pixel;
            }
            else if (col == (endingSpot-1)){
                wordVector[row][col] = pixel;
                wordVector[row][col-1] = pixel;
            }
        }
    }
}

/*
 drawJ is a method that draws the letter J at the appropriate spot in the two-
 dimensional array holding the user's entered word by setting the correct spots
 equal to the user's entered pixel character.
 
 Parameters:
 (int) position - the position of the letter in the word
 (char) pixel - the pixel used to draw the word
 (int) fontSize - the font size of the word
 (bool) useBold - a boolean value representing whether or not to use bold
 */
void WordFont::drawJ(int position, char pixel, int fontSize, bool useBold){
    if (useBold){
        drawBoldJ(position, pixel, fontSize);
        return;
    }
    int startingSpot = (fontSize+2) * position;
    int endingSpot = startingSpot + fontSize;
    int crossCol = startingSpot + (fontSize/2);
    
    for (int row = 0; row < fontSize; row++){
        for (int col = startingSpot; col < endingSpot; col++){
            if (row == 0){
                wordVector[row][col] = pixel;
            }
            else if ((row == (fontSize-1)) && (col < crossCol)){
                wordVector[row][col] = pixel;
            }
            if (col == crossCol){
                wordVector[row][col] = pixel;
            }
        }
    }
}

/*
 drawBoldJ is a helper method that gets called from drawJ when its boolean parameter
 useBold is true. It achieves similar functionality to drawJ, but draws letters bold
 by adding another line to each edge of the letter
 
 Parameters:
 (int) position - the position of the letter in the word
 (char) pixel - the pixel used to draw the word
 (int) fontSize - the font size of the word
 */
void WordFont::drawBoldJ(int position, char pixel, int fontSize){
    int startingSpot = (fontSize+2) * position;
    int endingSpot = startingSpot + fontSize;
    int crossCol = startingSpot + (fontSize/2);
    
    for (int row = 0; row < fontSize; row++){
        for (int col = startingSpot; col < endingSpot; col++){
            if (row == 0){
                wordVector[row][col] = pixel;
                wordVector[row+1][col] = pixel;
            }
            else if ((row == (fontSize-1)) && (col < crossCol)){
                wordVector[row][col] = pixel;
                wordVector[row-1][col] = pixel;
            }
            if (col == crossCol){
                wordVector[row][col] = pixel;
                wordVector[row][col+1] = pixel;
            }
        }
    }
}

/*
 drawK is a method that draws the letter K at the appropriate spot in the two-
 dimensional array holding the user's entered word by setting the correct spots
 equal to the user's entered pixel character.
 
 Parameters:
 (int) position - the position of the letter in the word
 (char) pixel - the pixel used to draw the word
 (int) fontSize - the font size of the word
 (bool) useBold - a boolean value representing whether or not to use bold
 */
void WordFont::drawK(int position, char pixel, int fontSize, bool useBold){
    int startingSpot = (fontSize+2) * position;
    int endingSpot = startingSpot + fontSize;
    int crossRow = (fontSize/2);
    
    for (int row = 0; row < fontSize; row++){
        for (int col = startingSpot; col < endingSpot; col++){
            
            if (col == startingSpot){
                wordVector[row][col] = pixel;
            }
        }
    }
}

/*
 drawL is a method that draws the letter L at the appropriate spot in the two-
 dimensional array holding the user's entered word by setting the correct spots
 equal to the user's entered pixel character.
 
 Parameters:
 (int) position - the position of the letter in the word
 (char) pixel - the pixel used to draw the word
 (int) fontSize - the font size of the word
 (bool) useBold - a boolean value representing whether or not to use bold
 */
void WordFont::drawL(int position, char pixel, int fontSize, bool useBold){
    if (useBold){
        drawBoldL(position, pixel, fontSize);
        return;
    }
    int startingSpot = (fontSize+2) * position;
    int endingSpot = startingSpot + fontSize;
    
    for (int row = 0; row < fontSize; row++){
        for (int col = startingSpot; col < endingSpot; col++){
            if (row == (fontSize-1)){
                wordVector[row][col] = pixel;
            }
            if (col == startingSpot){
                wordVector[row][col] = pixel;
            }
        }
    }
}

/*
 drawBoldL is a helper method that gets called from drawL when its boolean parameter
 useBold is true. It achieves similar functionality to drawL, but draws letters bold
 by adding another line to each edge of the letter
 
 Parameters:
 (int) position - the position of the letter in the word
 (char) pixel - the pixel used to draw the word
 (int) fontSize - the font size of the word
 */
void WordFont::drawBoldL(int position, char pixel, int fontSize){
    int startingSpot = (fontSize+2) * position;
    int endingSpot = startingSpot + fontSize;
    
    for (int row = 0; row < fontSize; row++){
        for (int col = startingSpot; col < endingSpot; col++){
            if (row == (fontSize-1)){
                wordVector[row][col] = pixel;
                wordVector[row-1][col] = pixel;
            }
            if (col == startingSpot){
                wordVector[row][col] = pixel;
                wordVector[row][col+1] = pixel;
            }
        }
    }
}

void WordFont::drawM(int position, char pixel, int fontSize, bool useBold){
    int startingSpot = (fontSize+2) * position;
    int endingSpot = startingSpot + fontSize;
    
    for (int row = 0; row < fontSize; row++){
        for (int col = startingSpot; col < endingSpot; col++){
        }
    }
}

void WordFont::drawN(int position, char pixel, int fontSize, bool useBold){
    int startingSpot = (fontSize+2) * position;
    int endingSpot = startingSpot + fontSize;
    
    for (int row = 0; row < fontSize; row++){
        for (int col = startingSpot; col < endingSpot; col++){
            if (row == col){
                wordVector[row][col] = pixel;
            }
            if (col == startingSpot){
                wordVector[row][col] = pixel;
            }
            else if (col == (endingSpot -1)){
                wordVector[row][col] = pixel;
            }
        }
    }
}

void WordFont::drawR(int position, char pixel, int fontSize, bool useBold){
    int startingSpot = (fontSize+2) * position;
    int endingSpot = startingSpot + fontSize;
    
    for (int row = 0; row < fontSize; row++){
        for (int col = startingSpot; col < endingSpot; col++){
        }
    }
}

/*
 drawS is a method that draws the letter S at the appropriate spot in the two-
 dimensional array holding the user's entered word by setting the correct spots
 equal to the user's entered pixel character.
 
 Parameters:
 (int) position - the position of the letter in the word
 (char) pixel - the pixel used to draw the word
 (int) fontSize - the font size of the word
 (bool) useBold - a boolean value representing whether or not to use bold
 */
void WordFont::drawS(int position, char pixel, int fontSize, bool useBold){
    if (useBold){
        drawBoldS(position, pixel, fontSize);
        return;
    }
    int startingSpot = (fontSize+2) * position;
    int endingSpot = startingSpot + fontSize;
    int crossRow = (fontSize/2);
    
    for (int row = 0; row < fontSize; row++){
        for (int col = startingSpot; col < endingSpot; col++){
            if (row == 0){ // Row constraints
                wordVector[row][col] = pixel;
            }
            else if (row == (fontSize-1)){
                wordVector[row][col] = pixel;
            }
            else if (row == crossRow){
                wordVector[row][col] = pixel;
            }
            
            if ((col == startingSpot) && (row < crossRow)){
                wordVector[row][col] = pixel;
            }
            
            else if ((col == (endingSpot-1)) && (row > crossRow)){
                wordVector[row][col] = pixel;
            }
        }
    }
}

/*
 drawBoldS is a helper method that gets called from drawS when its boolean parameter
 useBold is true. It achieves similar functionality to drawS, but draws letters bold
 by adding another line to each edge of the letter
 
 Parameters:
 (int) position - the position of the letter in the word
 (char) pixel - the pixel used to draw the word
 (int) fontSize - the font size of the word
 */
void WordFont::drawBoldS(int position, char pixel, int fontSize){
    int startingSpot = (fontSize+2) * position;
    int endingSpot = startingSpot + fontSize;
    int crossRow = (fontSize/2);
    
    for (int row = 0; row < fontSize; row++){
        for (int col = startingSpot; col < endingSpot; col++){
            if (row == 0){ // Row constraints
                wordVector[row][col] = pixel;
                wordVector[row+1][col] = pixel;
            }
            else if (row == (fontSize-1)){
                wordVector[row][col] = pixel;
                wordVector[row-1][col] = pixel;
            }
            else if (row == crossRow){
                wordVector[row][col] = pixel;
                wordVector[row-1][col] = pixel;
            }
            
            if ((col == startingSpot) && (row < crossRow)){
                wordVector[row][col] = pixel;
                wordVector[row][col+1] = pixel;
            }
            
            else if ((col == (endingSpot-1)) && (row > crossRow)){
                wordVector[row][col] = pixel;
                wordVector[row][col-1] = pixel;
            }
        }
    }
}

/*
 drawT is a method that draws the letter T at the appropriate spot in the two-
 dimensional array holding the user's entered word by setting the correct spots
 equal to the user's entered pixel character.
 
 Parameters:
 (int) position - the position of the letter in the word
 (char) pixel - the pixel used to draw the word
 (int) fontSize - the font size of the word
 (bool) useBold - a boolean value representing whether or not to use bold
 */
void WordFont::drawT(int position, char pixel, int fontSize, bool useBold){
    if (useBold){
        drawBoldT(position, pixel, fontSize);
        return;
    }
    int startingSpot = (fontSize+2) * position;
    int endingSpot = startingSpot + fontSize;
    int crossCol = startingSpot + (fontSize/2);
    
    for (int row = 0; row < fontSize; row++){
        for (int col = startingSpot; col < endingSpot; col++){
            if (row == 0){
                wordVector[row][col] = pixel;
            }
            if (col == crossCol){
                wordVector[row][col] = pixel;
            }
        }
    }
}

/*
 drawBoldT is a helper method that gets called from drawT when its boolean parameter
 useBold is true. It achieves similar functionality to drawT, but draws letters bold
 by adding another line to each edge of the letter
 
 Parameters:
 (int) position - the position of the letter in the word
 (char) pixel - the pixel used to draw the word
 (int) fontSize - the font size of the word
 */
void WordFont::drawBoldT(int position, char pixel, int fontSize){
    int startingSpot = (fontSize+2) * position;
    int endingSpot = startingSpot + fontSize;
    int crossCol = startingSpot + (fontSize/2);
    
    for (int row = 0; row < fontSize; row++){
        for (int col = startingSpot; col < endingSpot; col++){
            if (row == 0){
                wordVector[row][col] = pixel;
                wordVector[row+1][col] = pixel;
            }
            if (col == crossCol){
                wordVector[row][col] = pixel;
                wordVector[row][col+1] = pixel;
            }
        }
    }
}


