# Bubble sort

def bubble_sort(input_data):

    sorted_data = input_data #Initialize return data

    sort_flag = False

    while sort_flag == False:
        swap_flag = False
        for i in range(len(input_data)-1):

            if sorted_data[i] > sorted_data[i+1]:
                swap_flag = True
                #temp = sorted_data[i]
                #sorted_data[i] = sorted_data[i+1]
                #sorted_data[i+1] = temp
                sorted_data[i],sorted_data[i+1] = sorted_data[i+1],sorted_data[i]

        if swap_flag == False:
            break 

    return sorted_data

def insertion_sort(input_data):

    sorted_data = input_data

    

    return sorted_data

d1 = [1,2,3,4,5,6,7]
d2 = [3,2,5,6,7,8,9,3,21,323,45,67,89,43,689,2131,7]
print(bubble_sort(d1))
print(bubble_sort(d2))