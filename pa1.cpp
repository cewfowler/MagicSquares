//
//  MagicSquares.cpp
//  CPP
//
//  Created by Christian on 9/26/16.
//  Copyright © 2016 Christian. All rights reserved.
//

#include "pa1.h"
#include <iostream>

class MagicSquares {
    int size;
    int numBoxes;
    int magicSquare[15][15] = {};
    
public:
    MagicSquares(int size){
        //declares a size variable with the N value, the total number of boxes, and an array to hold the magic square
        this->size = size;
        this->numBoxes = size * size;
        
        //boolean used to keep the while-loop running until all squares are filled
        bool allSquaresFilled = false;
        
        //sets the start points to build the magic square
        int i = 2;
        int column = size / 2;
        int row = 0;
        
        // this algorithm begins by placing a 1 in the center square of the top row, then incrementally placing subsequent numbers in the square one unit above and to the right
        magicSquare[row][column] = 1;
        
        while (!allSquaresFilled) {
            //sets two variables to the possible next spot for a number
            int holdRow = row - 1;
            int holdColumn = column + 1;
            
            //rounds the variables
            if (holdRow < 0){
                holdRow = size - 1;
            }
            if (holdColumn >= size) {
                holdColumn = 0;
            }
            
            //checks if the next spot is open to have a number placed
            if (magicSquare[holdRow][holdColumn] == 0){
                row = holdRow;
                column = holdColumn;
                magicSquare[row][column] = i;
            }
            
            //if not, it goes one row down
            else if (row + 1 < size){
                row = row + 1;
                magicSquare[row][column] = i;
            }
            
            //increments the number to add
            i++;
            
            //returns when all boxes have a number
            if (i > numBoxes){
                allSquaresFilled = true;
            }
        }
    }
    
    
    void print() {
        int rowValues[15] ={};
        int columnValues[15] ={};
        int diagonalValues[2] = {};
        
        for (int i = 0; i < size; i++){
            for (int j = 0; j < size; j++){
                //prints magic square
                int x = magicSquare[i][j];
                printf("%d\t", x);
                
                //adds each value in row/column/diagonal to the corresponding element in the array
                rowValues[i] += magicSquare[i][j];
                columnValues[i] += magicSquare[j][i];
                if (i == j){
                    diagonalValues[0] += magicSquare[i][j];
                    diagonalValues[1] += magicSquare[size - 1 - i][j];
                }
                
            }
            
            puts("");
        }
        
        //prints all the row sums
        printf("The row values are: ");
        for (int i = 0; i < size; i++) {
            printf("%d ", rowValues[i]);
        }
        puts("");
        
        //prints all the column sums
        printf("The column values are: ");
        for (int i = 0; i < size; i++) {
            printf("%d ", columnValues[i]);
        }
        puts("");
        
        //prints diagonal sums
        printf("The diagonal values are: ");
        for (int i = 0; i < 2; i++) {
            printf("%d ", diagonalValues[i]);
        }
        puts("");

        
        
    }
    
    void rotate90(){
        int copy[size][size];
        
        //copies all the necessary numbers from magicSquare into copy
        for (int i = 0; i < size; i ++){
            for (int j = 0; j < size; j++){
                copy[i][j] = magicSquare[i][j];
            }
        }
        
        //replaces magicSquare with the rotation by setting the rows of the copy equal to the columns of magicSquare
        for (int i = 0; i < size; i++){
            for (int j = 0; j < size; j++){
                magicSquare[j][size - 1 - i] = copy[i][j];
            }
        }
        
        //end of magicSquares class
    };
};



int main (int argc, char ** argv){
    double input = 0;
    printf("Please enter the size of the square matrix (must be an odd number): ");
    
    //accepts input
    std::cin >> input;
    
    //erases any string
    std::cin.clear();
    std::cin.ignore(1000,'\n');
    
    //checks if user entered a decimal
    if (input != (int)input){
        printf("You entered a decimal...\n");
        return 0;
    }
    
    int size = (int)input;
    
    //makes sure size is within range
    if (size >= 3 && size <=15 && size % 2 == 1){
        MagicSquares x = MagicSquares(size);
        x.print();
        puts("");
        x.rotate90();
        x.print();
        puts("");
        x.rotate90();
        x.print();
    }
    
    //if not, returns a message letting user know it is not valid input
    else {
        printf("That is not an acceptable input.\n");
    }
    
    return 0;
    
    
    
}


