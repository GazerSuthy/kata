# Kata link: https://www.codewars.com/kata/561bed6a31daa8df7400000e 

def nQueen(n):
    queen_list = []

    #create 2D grid
    grid = [["-" for i in range(n)] for j in range(n)]
    row, col = (0,0)
    backtrack = False    
    count = 0   
           
    #main while loop, ensures that there is n number of queens
    while len(queen_list) != n:

        queenPlaced = 0               
       
        #Backtrack bascially finds the currents last queen's position and tries to find a better spot for the queen so that a queen can fit in the next row
        #If this function tries to backtrack while their are no queens on the board, it means that a solution does not exist
       
        if backtrack == True:
            if len(queen_list) == 0:
                return []
            last_queen = queen_list[-1]
            grid[last_queen[0]][last_queen[1]] = "-"     
            queen_list.pop()
            #sets current position to the next column of the previous queen
            row = last_queen[0]
            col = last_queen[1] + 1 

            #if the current position column is out of bounds, meaning there are no more possible queen placements, it backtracks again
            if col <  n:
                backtrack = False
                
        else:
            #going through each index in row to find safe spot for queen to be placed
            for index in range(col,n):
                valid_spot = checkSpot(row,index,queen_list)
                if(valid_spot == True):
                    grid[row][index] = "Q"      
                    queen_list.append((row,index))   
                    queenPlaced += 1
                    #col is reset to zero for the next row
                    col = 0                             
            
            #if a queen is not placed in a row, function backtracks to the previous row
            if queenPlaced == 0:
                backtrack = True
            else:
                row += 1            
                    
    for x in range(n):
        print(grid[x])
    print("------------------------------")
    print("Solution: (row, col)")
    print(queen_list)
            

            

#function returns through if the current position is safe from a queen attack, using queen attack patterns 
def checkSpot(row, col, queens):
    #first queen
    if len(queens) == 0:
        return True

    #check to see if the current row is safe
    for x in queens:
        if x[0] == row:
            return False

    #check to see if the current col is safe
    for x in queens:
        if x[1] == col:
            return False

    #check to see if the current position is safe from diagonals 
    checkDiag = row + col
    for x in queens:
        if (x[0] + x[1]) == checkDiag:
            return False

    #check to see if the current position is safe from reverse diagonals
    checkRevDiag = row - col
    for x in queens:
        if(x[0] - x[1]) == checkRevDiag:
            return False

    return True


nQueen(4)

'''
Output
['-', 'Q', '-', '-']
['-', '-', '-', 'Q']
['Q', '-', '-', '-']
['-', '-', 'Q', '-']
------------------------------
Solution: (row, col)
[(0, 1), (1, 3), (2, 0), (3, 2)]
'''
    

