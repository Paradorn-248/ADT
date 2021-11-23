_list = [[1, 2, 3, 4, 5], [10, 9, 8, 7, 6], [11, 12, 13, 14, 15]]
lst = []
summy = []
# for col in range (len(_list[0])): #len(_list) = 3
#     _lst = []
#     for row in range(len(_list)): #len(_list[col]) = 5
#         _lst.append(_list[row][col])
#     print(f"Sum of column{col+1} = {sum(_lst)}")
#     summy.append(sum(_lst))
#     lst.append(_lst)
# print(f"Sum of each column : {summy}")
# col
for col in range(len(_list[0])) :
    summ = 0
    for row in range(len(_list)) :
        summ += _list[row][col] 
    print(f"Sum of column{col+1} = {summ}")
    lst.append(summ) 
print(f"Sum of each column : {lst}")
print(f"Sum of all numbers : {sum(lst)}")
# row
lst2 = list()
for row in range(len(_list)) :
    summ = sum(_list[row])
    print(f"Sum of row{row+1} = {summ}")
    lst2.append(summ) 
print(f"Sum of each row : {lst2}")
print(f"Sum of all numbers : {sum(lst2)}")