

def itob(i):
    current = i
    rest = 0
    last = current
    num = 0
    index = 0
    while (current > 1):
        current = div2(current)
        rest = last - current - current
        num = num + multiply(rest, pow10(index))
        print(rest)
        index = index + 1
    return num


def pow10(x):
    pass

def multiply(x, y):
    pass

def div2(x):
    pass

def laenge(x):
    pass

def getListLength(l):
    length = laenge(l)
    con_len = 0
    i = length
    nums = []
    current = l
    this = 0
    last = 0
    no_delim = 0
    while (l > 0):
        if (current - pow10(i) > 0):
            this = 1
        else:
            this = 0
        if (last != this):
            con_len = con_len + 1
            nums.append([])
        else:
            no_delim  = no_delim + 1
            nums[con_len].append(this)
        last = this
