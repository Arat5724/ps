from math import *

n = 500
chunk = int(sqrt(n * 2))
q = int(chunk / 4 + 1)
chunk *= 2
result = 0
for j in range(n, 0, -1):
    i = n - j
    if (chunk == 0):
        print(j)
        break
    result += int(j / chunk)
    if i % q == 0 and chunk > 1:
        chunk -= 1


print(chunk, result)
