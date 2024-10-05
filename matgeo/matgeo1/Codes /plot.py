import matplotlib.pyplot as plt

with open("data.txt", 'r') as f:
    L = f.readlines()

a = []
for line in L:
    row = line.strip().split() 
    row = [int(x) for x in row] 
    a.append(row)

A = a[0]
B = a[1]
C = a[2]

fig, ax = plt.subplots()


ax.scatter([A[0], B[0], C[0]], [A[1], B[1], C[1]], label=['A', 'B', 'C'])


ax.plot([A[0], B[0]], [A[1], B[1]], color='gray')
ax.plot([B[0], C[0]], [B[1], C[1]], color='gray')


ax.text(A[0], A[1], f'A({A[0]}, {A[1]})', fontsize=10, ha='right')
ax.text(B[0], B[1], f'B({B[0]}, {B[1]})', fontsize=10, ha='right')
ax.text(C[0], C[1], f'C({C[0]}, {C[1]})', fontsize=10, ha='right')


ax.set_xlabel('X')
ax.set_ylabel('Y')

ax.grid(True)


ax.legend()


plt.savefig('../figs/fig.png')


plt.show()

