# Its an additional question nothing to do with CC syllabus
# and its a little advanced level question requires the knowledge of recursion

# Write a function wrapGifts that finds the maximum number of gifts that can be wrapped using a single strip of wrapping paper of a given width. Each gift has a specific length, and you can only wrap gifts if their total length fits within the paper width without cutting the paper.

# Example
# wrapGifts([2,3,4,5], 7)
# wrapGifts([1, 1, 1, 1, 1, 1, 1], 3)
# wrapGifts([1, 2, 3, 4, 5], 6)
# arr = [1, 2, 4, 7, 9, 11, 13, 35]
# sum = 35 which is sum of 2, 4, 7, 9, 13






def count_gifts(elements_included,sum_till_now, next_element_to_include,count):
    if next_element_to_include== len(arr):
        if sum_till_now == sum:
            return 1
        return 0
    if sum_till_now+arr[next_element_to_include] == sum:
        return count + 1
    if sum_till_now + arr[next_element_to_include] > sum:
        return 0
    
    a1 = count_gifts(elements_included, sum_till_now,next_element_to_include+1, count)
    elements_included.append(arr[next_element_to_include])
    a2 = count_gifts(elements_included, sum_till_now+arr[next_element_to_include], next_element_to_include+1, count+1)
    return max(a1,a2)
        

    
    

# arr = [2,3,4,5]
# sum = 7
# arr = [1,2,3,4,5,6,7]
# sum = 6
# arr = [1, 2, 4, 7, 9, 11, 13, 15]
# sum = 9
arr = [1, 2, 4, 7, 9, 11, 13, 35]
sum = 35
counter = 0
for i in range(len(arr)):
    counter = max(counter,count_gifts([arr[i]],arr[i],i+1,1))
print(counter)
