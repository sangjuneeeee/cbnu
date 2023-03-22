i, k, nineline = 0, 0, ""

for i in range(2, 10) :
    nineline = nineline + ("# %d단 # " % i)

print(nineline)

for i in range(1, 10) :
    nineline = ""
    for k in range(2, 10) :
        nineline = nineline + str("%2dX%2d=%2d" % (k, i, k * i))
    print(nineline)