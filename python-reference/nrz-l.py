"""
1 0 1 1 0 0 1 0 1
─┐ ┌───┐   ┌─┐ ┌─
 │ │   │   │ │ │
 └─┘   └───┘ └─┘
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
changed_state = False
length = len(bits)

# for upper bound
print()
for i in range(length):
    if not i == length-1:
        changed_state = not (bits[i] == bits[i+1])
    else:
        changed_state = False

    if bits[i]:
        print(horizontal, end='')
    else:
        print(space, end='')

    if changed_state:
        if bits[i]:
            print(top_right, end='')
        else:
            print(top_left, end='')
    else:
        if bits[i]:
            print(horizontal, end='')
        else:
            print(space, end='')

# for middle bound
print()
for i in range(length):
    if not i == length - 1:
        changed_state = not bits[i] == bits[i+1]
    else:
        changed_state = False

    print(space, end='')

    if changed_state:
        print(vertical, end='')
    else:
        print(space, end='')

# for lower bound
print()
for i in range(length):
    if not i == length - 1:
        changed_state = not bits[i] == bits[i+1]
    else:
        changed_state = False

    if not bits[i]:
        print(horizontal, end='')
    else:
        print(space, end='')

    if changed_state:
        if bits[i]:
            print(bottom_left, end='')
        else:
            print(bottom_right, end='')
    else:
        if not bits[i]:
            print(horizontal, end='')
        else:
            print(space, end='')

print()
