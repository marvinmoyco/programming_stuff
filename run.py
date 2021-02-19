#!/usr/bin/env python3


from linear_data_structures import *


if __name__ == "__main__":
    check = True
    while check:
        mode_input = int(input("Choose a data structure: (1) Stack, \n(2) Queue, \n(3) Dequeue: "))
        if mode_input >=1 and mode_input <= 3:
            check = False
        else:
            check = True

    if mode_input == 1: #Stack
        print("Mode: Stack")
        s = stack()
        print("Populating stack using push()...")
        for i in range(10):
            s.push(i)
        
        print(s.check_contents())

        print("Removing 3 elements on the stack...")
        for i in range(3):
            s.pop()

        print(s.check_contents())

    elif mode_input == 2: #Queue
        print("Mode: Queue")
        q = queue()

        print("Populating queue...")

        for i in range(10):
            q.push(i)

        print(q.check_contents())

        print("Removing 4 elements in queue...")

        for i in range(4):
            q.pop()

        print(q.check_contents())


    elif mode_input == 3: #Dequeue
        print("Mode: Dequeue")

        dq = dequeue()

        print("Populating dequeue in front...")

        for i in range(10):
            dq.push_front(i)

        print(dq.check_contents())

        print("Populating dequeue in the back...")

        for i in range(10):
            dq.push_back(i)

        print(dq.check_contents())

        print("Removing 4 elements from the front...")

        for i in range(4):
            dq.pop_front()

        print(dq.check_contents())

        print("Removing 5 elements in the back...")

        for i in range(5):
            dq.pop_back()

        print(dq.check_contents())
