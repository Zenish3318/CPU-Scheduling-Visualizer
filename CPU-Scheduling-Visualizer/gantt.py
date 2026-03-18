import matplotlib.pyplot as plt

process=[]
start=[]
end=[]

with open("output.txt") as f:
    for line in f:
        p,s,e=line.split()
        process.append(p)
        start.append(int(s))
        end.append(int(e))

fig, ax = plt.subplots()

for i in range(len(process)):
    ax.barh(process[i], end[i]-start[i], left=start[i])

ax.set_xlabel("Time")
ax.set_title("CPU Scheduling Gantt Chart")

plt.show()