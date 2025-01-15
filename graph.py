import matplotlib.pyplot as plt

with open('times.csv') as f:
    lines = f.readlines()
    lines.pop(0)
    x = [i for i in range(1, len(lines)+1)]
    insertion = [int(line.split(',')[0]) for line in lines]
    search = [int(line.split(',')[1]) for line in lines]
    deletion = [int(line.split(',')[2]) for line in lines]

plt.figure()
plt.title('AVL Tree')
plt.plot(x, insertion, label='Insertion')
plt.plot(x, search, label='Search')
plt.plot(x, deletion, label='Deletion')
plt.xlabel('Number of elements')
plt.ylabel('Time (ms)')
plt.legend()
plt.show()