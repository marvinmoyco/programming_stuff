class stack:
    """
    Stack Data Structure is a data structure that uses Last-In-First-Out (LiFo) where the last data that entered the stack will be the first data to be read/deleted.
    """
    def __init__(self):
        self.data = []

    def push(self,input_data):
        """ Pushes data into the end (or top) of the stack"""
        self.data.append(input_data)
        return "Data {} pushed into the stack.".format(input_data)

    def pop(self):
        """ Takes the data from the end (or top) of the stack """
        last_item = self.data[-1]
        self.data.pop()
        return last_item

    def check_contents(self):
        print("The data inside the stack are:\n {}".format(self.data))
        

class queue:
    """
    Queue is a data structure that is modeled like a line/queue where the first data inside will be the first data that will be taken (First In First Out, FIFO)
    """
    def __init__(self):
        self.data = []

    def push(self,input_data):
        """ Pushes the data at the end of the queue"""
        self.data.append(input_data)
        return "Data {} pushed into the queue.".format(input_data)

    def pop(self):
        """Takes out the data at the front of the queue"""
        first_item = self.data[0]
        self.data.pop(0)
        return first_item

    def check_contents(self):
        print("The data inside the queue are:\n {}".format(self.data))
        

class dequeue:
    """
    Deueue (Double Ended Queue) is a data structure that is modeled like a line/queue but it can push and pop from both the front and the back of the queue/line.
    """
    def __init__(self):
        self.data = []

    def push_front(self,input_data):
        """ Pushes the data at the front of the dequeue"""
        self.data.insert(0,input_data)
        return "Data {} pushed into the front the dequeue.".format(input_data)

    def push_back(self,input_data):
        """ Pushes the data at the end of the dequeue"""
        self.data.append(input_data)
        return "Data {} pushed into the back the dequeue.".format(input_data)

    def pop_front(self):
        """Takes out the data at the front of the dequeue"""
        first_item = self.data[0]
        self.data.pop(0)
        return first_item

    def pop_back(self):
        """Takes out the data at the back of the dequeue"""
        last_item = self.data[-1]
        self.data.pop()
        return last_item

    def check_contents(self):
        print("The data inside the dequeue are:\n {}".format(self.data))

class BT_Node:
    """
    Binary tree is a hiererchal data structure that uses nodes that connects to other nodes.
    Reference: https://www.tutorialspoint.com/python_data_structure/python_binary_tree.htm
    """
    def __init__(self,data=0):
        self.data = data
        self.left_node = None
        self.right_node = None

    def insert(self,data):
        """ When inserting data in a binary tree, if the data to be inserted is less than the parent node, then it will be inserted on the left side.
            If it is greater than the parent node, then the data will be inserted on the right side."""

        if self.data: #If data of parent node is not empty
            if self.data > data:
                if self.left_node is None:
                    self.left_node = BT_Node(data)
                else:
                    self.left_node.insert(data)
            elif self.data < data:
                if self.right_node is None:
                    self.right_node = BT_Node(data)
                else:
                    self.right_node.insert(data)
                    

        else: # If it is empty
            self.data = data

    def print_tree(self):
        if self.left_node:
            self.left_node.print_tree()
        print(self.data)
        if self.right_node:
            self.right_node.print_tree()

