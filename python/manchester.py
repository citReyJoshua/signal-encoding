"""
1 0 1 0 1 1 1 1 0 0
┌─┐ ┌─┐ ┌┐┌┐┌┐┌─┐┌┐
│ │ │ │ │││││││ │││
┘ └─┘ └─┘└┘└┘└┘ └┘└
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

#higher bound
print()
for i in range(length):
    if bits[i]:
        print(top_left, end='')
    else: 
        print(top_right, end='')
    
    if i < length -1:
        if bits[i]:
            print(top_right if bits[i+1] else horizontal, end='')
        else:
            print(space if bits[i+1] else top_left, end='')
    
#middle bound
print()
for i in range(length):
    print(vertical, end='')
    if i < length - 1:
        if bits[i] == bits[i+1]:
            print(vertical, end='')
        else:
            print(space, end='')

# lower bound
print()
for i in range(length):
    if bits[i]:
        print(bottom_right, end='')
    else: 
        print(bottom_left, end='')
    
    if i < length - 1:
        if bits[i]:
            print(bottom_left if bits[i+1] else space, end='')
        else:
            print(horizontal if bits[i+1] else bottom_right, end='')