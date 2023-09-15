
/* Kata link: https://www.codewars.com/kata/554ca54ffa7d91b236000023/cpp

    Kata Description: Delete occurrences of an element if it occurs more than n times

    Given a list lst and a number N, create a new list that contains each number of lst at most N times without reordering. For example if N = 2, and the input is [1,2,3,1,2,1,2,3], you take [1,2,3,1,2], drop the next [1,2] since this would lead to 1 and 2 being in the result 3 times, and then take 3, which leads to [1,2,3,1,2,3].

    Example
    delete_nth ([1,1,1,1],2) # return [1,1]
    delete_nth ([20,37,20,21],1) # return [20,37,21]

 */


#include <vector>


// May 5, 2020

std::vector<int> deleteNth(std::vector<int> arr, int n)
{
  // warning! this solution may trigger people but i wanted pratice with 2D arrays, allow me :)
    
    //2D array, [0] row keeps track of unique number, [1] row keeps track of occurance of that unique num

    std::vector<int> copy;     
    std::vector<int> result;
    int size = 0;      

    //copying elements from arr to copy 
    for(int i = 0 ; i < arr.size(); i++){
        copy.push_back(arr[i]);
    }
    
    //finding unique num
    // if array is [2,3,4,4,3,2] it will only find [2,3,4,0,0,0]
    for(int i = 0; i < copy.size(); i++){
        int unique = copy[i];
        for(int j = i+1; j < copy.size(); j++){
            if(unique == copy[j]){
                copy[j] = 0;
            }
        }
    }
    
    //finding the size of unique num
    for(int i = 0; i < copy.size(); i++){
        if(copy[i] != 0){
            size++;
        }
    }
    int value_occurance[2][size];           //creates 2D array [0] row keeps track of unique value, [1] row keeps track of occuranes
    int k = 0;                              //keeps track of row index

    //storing unique num in value occurance
    for(int i = 0; i < copy.size(); i++){
        if(copy[i] != 0){
            value_occurance[0][k] = copy[i];
            value_occurance[1][k] = 1;          //each value has 1 occurance so far
            k++;
        }
    }

    //appending to result vector as long as occurance is less or equal to n
    for(int i = 0; i < arr.size(); i++){
        for(int j = 0; j < size; j++){
            //if the occurance row[1][j] is less than n, it will append the value to the result vector
            if(arr[i] == value_occurance[0][j] && value_occurance[1][j] <= n){  //if statement basically locates where the arr[i] value is in row[0][j] and checks the occurance value in row[1][j]
                result.push_back(arr[i]);
                value_occurance[1][j] += 1;        //increse the occurance #
            }
        }
    }
    return result;
}