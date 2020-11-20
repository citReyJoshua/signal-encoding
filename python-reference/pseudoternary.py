"""
1 0 0 1 1 1 0 1 0 0 0 0 0 1 1 1 1 
 ┌─┐       ┌─┐   ┌─┐ ┌─┐         
─┘ │ ┌─────┘ └─┐ │ │ │ │ ┌───────
   └─┘         └─┘ └─┘ └─┘       
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

# initial values
print_state = space
pos_state = False  # True means upper bound, False means lower bound
length = len(bits)

# for upper bound
print()
for i in range(length):

    if not bits[i]:
        pos_state = not pos_state
        if pos_state:
            print_state = horizontal
        else:
            print_state = space
    else:
        print_state = space

    print(print_state, end='')

    if(i != length - 1):
        if print_state == horizontal:
            print(top_right, end='')
        else:
            if pos_state:
                print(space, end='')
            else:
                if not bits[i+1]:
                    print(top_left, end='')
                else:
                    print(space, end='')

# middle bound
print()
pos_state = False
for i in range(length):
    if not bits[i]:
        pos_state = not pos_state
        print_state = space
    else:
        print_state = horizontal

    print(print_state, end='')

    if i != length - 1:
        if not bits[i]:
            if bits[i+1]:
                if pos_state:
                    print(bottom_left, end='')
                else:
                    print(top_left, end='')
            else:
                print(vertical, end='')
        else:
            if not bits[i+1]:
                if pos_state:
                    print(top_right, end='')
                else:
                    print(bottom_right, end='')
            else:
                print(horizontal, end='')

# lower bound
print()
pos_state = False
for i in range(length):

    if not bits[i]:
        pos_state = not pos_state
        if pos_state:
            print_state = space
        else:
            print_state = horizontal
    else:
        print_state = space

    print(print_state, end='')

    if(i != length - 1):
        if print_state == horizontal:
            print(bottom_right, end='')
        else:
            if pos_state:
                if not bits[i+1]:
                    print(bottom_left, end='')
                else:
                    print(space, end='')
            else:
                print(space, end='')

print()
