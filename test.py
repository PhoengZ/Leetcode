class product:
    def __init__(self, name, category, price):
        self.name = name
        self.category = category
        self.price = price

def sol(inp):
    m = dict()
    val = 0
    for i in inp:
        if i.category not in m:
            m[i.category] = dict()
            m[i.category][i.price%100] = 1
        else:
            if i.price%100 not in m[i.category]:
                m[i.category][i.price%100] = 1
            else:
                m[i.category][i.price%100] +=1
    for i in m:
        for j in m[i]:
            # print(j)
            if (100-j)%100 == j:
                val += (m[i][j]*(m[i][(100-j)%100]-1))//2
            else:
                val += (m[i][j]*(m[i][(100-j)%100]))/2
    val = int(val)
    return val

inp = [product("item1", "A", 130), product("item2", "B", 200), product("item3", "A", 70), product("item4", "A", 400), product("item5", "B", 250)]
print(sol(inp))