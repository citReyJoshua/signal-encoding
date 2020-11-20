"""
1 0 1 1 0 0 1 0 1
───┐ ┌─────┐   ┌─
   │ │     │   │
   └─┘     └───┘
"""

# string values
top_left = '┌'
top_right = '┐'
bottom_right = '┘'
bottom_left = '└'
horizontal = '─'
vertical = '│'
space = ' '

n = input()
bits = [int(i) for i in n.split()]

for bit in bits:
    print(bit, end=space)


# initial values
length = len(bits)
changed_state = False
print_state = space
if bits[0]:
    print_state = horizontal

# upper bound
print()
for i in range(length):

    print(print_state, end='')
    if i != length-1:
        changed_state = bits[i+1] == 1
    else:
        changed_state = False

    if(changed_state):
        if print_state == space:
            print(top_left, end='')
            print_state = horizontal
        else:
            print(top_right, end='')
            print_state = space
    else:
        print(print_state, end='')

# middle bound
print()
for i in range(length):

    print(space, end='')
    if i != length-1:
        changed_state = bits[i+1] == 1
    else:
        changed_state = False

    if(changed_state):
        print(vertical, end='')
    else:
        print(space, end='')


# lower bound

# condition
if bits[0]:
    print_state = space
else:
    print_state = horizontal
print()
for i in range(length):

    print(print_state, end='')
    if i != length-1:
        changed_state = bits[i+1] == 1
    else:
        changed_state = False

    if(changed_state):
        if print_state == space:
            print(bottom_left, end='')
            print_state = horizontal
        else:
            print(bottom_right, end='')
            print_state = space
    else:
        print(print_state, end='')

print()
