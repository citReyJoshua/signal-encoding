"""
1 0 1 0 1 1 1 1 0 0
┐┌┐ ┌┐┌─┐ ┌─┐ ┌┐┌┐┌
│││ │││ │ │ │ │││││
└┘└─┘└┘ └─┘ └─┘└┘└┘
"""

# string values
top_left = '┌'
top_right = '┐'
bottom_right = '┘'
bottom_left = '└'
horizontal = '─'
vertical = '│'
space = ' '

# user input
n = input()
bits = [int(i) for i in n.split()]

for bit in bits:
    print(bit, end=' ')

#initial values
length = len(bits)
state = False # True is high False is low
to_print = top_right if bits[0] else top_left

# upper bound
print()
for i in range(length):
    if bits[i]:
        state = not state
        to_print = top_right if state else top_left
    print(to_print, end='')
    
    if i < length - 1:
        if state:
            print(space if bits[i+1] else top_left,end='')
        else:
            print(horizontal if bits[i+1] else top_right, end='')

#middle bound
print()
for i in range(length):
    print(vertical, end='')

    if i < length - 1:
            print(vertical if not bits[i+1] else space, end='')

            

# lower bound
state = False
to_print = bottom_left if bits[0] else top_right
print()
for i in range(length):
    if bits[i]:
        state = not state
        to_print = bottom_left if state else bottom_right
    print(to_print, end='')
    
    if i < length - 1:
        if state:
            print(horizontal if bits[i+1] else bottom_right,end='')
        else:
            print(space if bits[i+1] else bottom_left, end='')