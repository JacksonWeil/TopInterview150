/*

First attempt: --- naive
SPEED: 35 ms
 BEAT: 9.06%
  MEM: 21.95 MB
 BEAT: 10.03% --- so much for saving mem with a bitmap... at least it runs 
              

Jackson Weil 1/22/2024

DESC: given a 9 x 9 sudoku board represented as a 2-D vector of chars within '1'-'9' or '.', return whether the board is valid
      i.e. rows, cols, and 3x3 boxes (each w/ respect to itself) contain only '.' or unique entries


CREDIT:


INTUITION: check each row, check each col, check each box - likely maintain presence of a number w/ a bitmapping, or some other low-mem representation
           *** remember to reset the mapping b/t each check --- return false if we encounter a local repeat


NOTES: monster0Freason on leetcode has sets to track rows, cols and subGrids and only does 1 pass over the entire board, processing along rows, cols, and subgrids within an iteration --- same complexity but may be quicker in practice

*/

#include <vector>
#include <iostream>
#include <cstdio>
using namespace std;

class Solution {

    public:
        bool isValidSudoku(vector<vector<char>>& board) {

            int i, j; // row itr, col itr
            int b; // box itr --- 9 boxes, I can mul and div i and j to reach the desired entries
            int bitmap; // if the a bit is set, that means (board[i][j] - '1') has occurred --- make sure to ignore '.' in the mapping

            // check all rows
            for(i = 0; i < 9; i++) { // may as well be explicit as I have no intention of generalizing the solution --- if I do... easy fix
                bitmap = 0;
                for (j = 0; j < 9; j++) {
                    // ignore '.'
                    if (board[i][j] == '.') {
                        cout << "continuing on dot..." << endl;
                        continue;
                    }

                    printf("shamt: %d\n", (int)(board[i][j] - '1'));

                    // see if number is present in bitmap --- if yes, ret false | if no, set its bit
                    if ((bitmap & (1 << ((int)(board[i][j] - '1')))) > 0) {
                        
                        return false;

                    } else {
                        bitmap |= 1 << ((int)(board[i][j] - '1'));
                    }
                }
            }

            // check all cols --- swap i and j
            for(i = 0; i < 9; i++) { // may as well be explicit as I have no intention of generalizing the solution --- if I do... easy fix
                bitmap = 0;
                for (j = 0; j < 9; j++) {
                    // ignore '.'
                    if (board[j][i] == '.') {
                        cout << "continuing on dot..." << endl;
                        continue;
                    }

                    printf("shamt: %d\n", (int)(board[j][i] - '1'));

                    // see if number is present in bitmap --- if yes, ret false | if no, set its bit
                    if ((bitmap & (1 << ((int)(board[j][i] - '1')))) > 0) {
                        return false;
                    } else {
                        bitmap |= 1 << (int)(board[j][i] - '1');
                    }
                }
            }

            // check all boxes --- use b variable here
            for (b = 0; b < 9; b++) {

                bitmap = 0;

                for(i = 3 * (b / 3); i < 3 + 3 * (b / 3); i++) { // may as well be explicit as I have no intention of generalizing the solution --- if I do... easy fix
                    
                    for (j = 3 * (b % 3); j < 3 + 3 * (b % 3); j++) {
                        // ignore '.'
                        if (board[i][j] == '.') {
                            cout << "continuing on dot..." << endl;
                            continue;
                        }

                        printf("shamt: %d\n", (int)(board[i][j] - '1'));

                        // see if number is present in bitmap --- if yes, ret false | if no, set its bit
                        if ((bitmap & (1 << (int)(board[i][j] - '1'))) > 0) {
                            return false;
                        } else {
                            bitmap |= (1 << ((int)(board[i][j] - '1')));
                        }
                    }
                }
            }



            return true;
        }

};