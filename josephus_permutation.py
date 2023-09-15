def josephus(items,k):
    
    allZero = False
    list = []
    count = 1       
    numZero = 0

    #loops until every element in items is "popped", '0' character represents character being popped
    while allZero != True:
        #structured so that only one of these conditions will work
        for x in range(len(items)):
            #if element is zero, it will move on to the next index
            if items[x] == '0':
                x += 1                      
            #else if statementsallow count to be either reset or only incremented
            elif count == k:
                list.append(items[x])
                items[x] = '0'
                count = 1
            else:
                count += 1

        #check to see if all the elements are zero
        for x in items:
            if x == '0':
                numZero += 1

        if numZero == len(items):
            allZero = True
        else:
            #reset numZero for the next loop cycle
            numZero = 0
            allZero = False

    return list
            
ans = josephus([1,2,3,4,5,6,7,8,9,10], 2)
print(ans)
