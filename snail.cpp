/* 
    Kata Link: https://www.codewars.com/kata/521c2db8ddc89b9b7a0000c1/cpp

    Kata Description:   Snail Sort

    Given an n x n array, return the array elements arranged from outermost elements to the middle element, traveling clockwise.

    array = [[1,2,3],
            [4,5,6],
            [7,8,9]]
    snail(array) #=> [1,2,3,6,9,8,7,4,5]
    For better understanding, please follow the numbers of the next array consecutively:

    array = [[1,2,3],
            [8,9,4],
            [7,6,5]]
    snail(array) #=> [1,2,3,4,5,6,7,8,9]

 */


// May 23, 2020 

// This kata took a while to solve but I had the most fun out of all my kata challenges!

#include <vector>

std::vector<int> snail(const std::vector<std::vector<int>> &snail_map) {
  int n = snail_map[0].size();      //gets the length of the matrix
    std::vector<int> pattern;
    std::vector<int> result;
    std::string direction[4] = {"right","down", "left", "up"};  

    //creating snail algorithm
    //[n, n-1, n-1, n-2, n-2, n-3, n-3] : pattern repeats as long as the number is greater than zero
    //ex, move n times right; move n-1 times down; move n-1 times left; (this algorithm represents how to move through matrix in the snail pattern)

    //makes the snail pattern
    int term = n;
    while(term > 0){
        //if its the first number it only appends once
        if(term == n){
            pattern.push_back(term);
        }else{
            //push number twice
            pattern.push_back(term);
            pattern.push_back(term);
        }
        term--;
    }

    int current = 0, row = 0, column = 0;

    //going to cycle through direction array and move according ot elements in pattern
    for(int i = 0; i < pattern.size(); i++){
        int distance = pattern[i];  
        //moving right 
        if(direction[current] == "right"){
            int col_inc = 0;
            for(int i = 0; i < distance; i++){
                result.push_back(snail_map[row][column]);
                //keeps track of column increments to avoid out of array bound error, total number of col_inc is always one less than distance
                if(col_inc < distance-1){
                    column++;
                    col_inc++;
                }
            }
            //adjustment for the next direction (down), move starting point inorder to not append duplicates
            row++;
        }

        if(direction[current] == "down"){
            int row_inc = 0;
            for(int i = 0; i < distance; i++){
                result.push_back(snail_map[row][column]);
                //keeps track of row increments to avoid out of array bound error, total number of row_in is always one less than distance
                if(row_inc < distance-1){
                    row++;
                    row_inc++;
                }
            }
            //adjustment for the next direction (left), move starting point inorder to not append duplicates
            column--;
        }

        if(direction[current] == "left"){
            int col_dec = 0;
            for(int i = 0; i < distance; i++){
                result.push_back(snail_map[row][column]);
                //keeps track of column decrements to avoid out of array bound error, total number of col_dec is always one less than distance
                if(col_dec < distance-1){
                    col_dec++;
                    column--;
                }
            }
            //adjustment for next direction (up), move starting point inorder to not append duplicates
            row--;
        }

        if(direction[current] == "up"){
            int row_dec = 0;
            for(int i = 0; i < distance; i++){
                result.push_back(snail_map[row][column]);
                //keeps track of column decrements
                if(row_dec < distance-1){
                    row_dec++;
                    row--;
                }
            }
            //adjustment for next direction (right), move starting point inorder to not append duplicates
            column++;
        }
        //changing direction
        if(direction[current] == "up"){
            current = 0;
        }else{
            current++;
        }
    }
  return result;
}