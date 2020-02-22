name = input("Enter file:")
if len(name) < 1 : name = "mbox-short.txt"
handle = open(name)
d = dict()
for l in handle:
    s = str(l)
    if s.startswith("From"):
        for j in s.split():
            if j.count(":") == 2:
                t = j.split(":")[0]
                d[t] = d.get(t,0) + 1
v = []
for i, j in d.items():
    v.append((i, j))
v.sort(key = lambda x: x[0])
for i, j in v:
    print(i, j)
    
    