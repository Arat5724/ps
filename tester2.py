from math import *

# a = [0] * 3

# for i in range(0, 3):
#     a[i] = [0] * 3
# n = 0
# for g in range(1, 3):
#     for h in range(1, 4):
#         if (h != g):
#             for i in range(2, 5):
#                 if (i != g and i != h):
#                     # g h i
#                     c1 = (g == 1) or (h == 1)

#                     c2 = (g == 2) or (h == 2) or (
#                         i == 2)

#                     if c1 and c2:
#                         # if c1 and c2 and (not a[h - 1][i - 2]):
#                         print(n, g, h, i)
#                         # print('{{{0}, {1}, {2}}}, '.format(i - 1, j - 2, k - 3))
#                         a[h - 1][i - 2] = n
#                         n += 1
# print(n)


def rec5():
    a = [0] * 5

    for i in range(0, 5):
        a[i] = [0] * 5
        for j in range(0, 5):
            a[i][j] = [0] * 5
    n = 0
    for g in range(1, 4):
        for h in range(1, 5):
            if (h != g):
                for i in range(1, 6):
                    if (i != g and i != h):
                        for j in range(2, 7):
                            if (j != g and j != h and j != i):
                                for k in range(3, 8):
                                    if (k != g and k != h and k != i and k != j):
                                        # g h i j k
                                        c1 = (g == 1) or (h == 1) or (
                                            i == 1)

                                        c2 = (g == 2) or (h == 2) or (
                                            i == 2) or (j == 2)

                                        c3 = (g == 3) or (h == 3) or (i == 3) or (
                                            j == 3) or (k == 3)

                                        if c1 and c2 and c3 and (not a[i - 1][j - 2][k - 3]):
                                            print(g, h, i,
                                                  j, k)
                                            # print('{{{0}, {1}, {2}}}, '.format(i - 1, j - 2, k - 3))
                                            a[i - 1][j - 2][k - 3] = 1
                                            n += 1


def rec(n):
    depth = 3 * n - 1
    d = 2 * n - 1
    len = 2 * n + 1
    arr = [0] * len
    arr_init(arr, len, 2 * n - 2)
    numbers = [0] * (3 * n - 1)
    res = rec2(n, 1, 3 * n, 0, numbers, arr)
    print(res)


def rec2(n, now, depth, bit, numbers, arr):
    if (now == depth):
        check1 = 1
        for j in range(1, 2 * n):
            s = j - n if j - n > 0 else 1
            e = j + n + 1
            check2 = False
            for k in range(s, e):
                check2 |= (numbers[k - 1] == j)
            check1 &= check2
            if not check1:
                break

        temp = arr
        for j in range(1, 2 * n):
            temp = temp[numbers[j + n - 1] - j]

        if check1 and not temp:
            # for j in numbers:
            #     print(j, end=' ')
            # print("\n", end="")
            # print(check1, temp)
            temp = arr
            for j in range(1, 2 * n - 1):
                temp = temp[numbers[j + n - 1] - j]
            temp[numbers[3 * n - 2] - 2 * n + 1] = 1
            return (1)
        else:
            return (0)
    else:
        e = now + n + 1
        s = now - n if now - n > 0 else 1

        result = 0
        for i in range(s, e):
            if not (bit & (1 << (i - 1))):
                temp = numbers[:]
                temp[now - 1] = i
                result += rec2(n, now + 1, depth, bit |
                               (1 << (i - 1)), temp, arr)
        return result


def arr_init(arr, len, depth):
    if (depth):
        for i in range(len):
            arr[i] = [0] * len
            arr_init(arr[i], len, depth - 1)


def main():
    # rec5()
    rec(int(input()))


if __name__ == '__main__':
    main()


def fff():
    a = [0] * 9

    for i in range(0, 9):
        a[i] = [0] * 9
        for j in range(0, 9):
            a[i][j] = [0] * 9
            for k in range(0, 9):
                a[i][j][k] = [0] * 9
                for l in range(0, 9):
                    a[i][j][k][l] = [0] * 9
                    for p in range(0, 9):
                        a[i][j][k][l][p] = [0] * 9
                        for q in range(0, 9):
                            a[i][j][k][l][p][q] = [0] * 9

    n = 0
    for g in range(1, 6):
        for h in range(1, 7):
            if (h != g):
                for i in range(1, 8):
                    if (i != g and i != h):
                        for j in range(1, 9):
                            if (j != g and j != h and j != i):
                                for k in range(1, 10):
                                    if (k != g and k != h and k != i and k != j):
                                        for l in range(2, 11):
                                            if (l != g and l != h and l != i and l != j and l != k):
                                                for m in range(3, 12):
                                                    if (m != g and m != h and m != i and m != j and m != k and m != l):
                                                        for o in range(4, 13):
                                                            if (o != g and o != h and o != i and o != j and o != k and o != l and o != m):
                                                                for p in range(5, 14):
                                                                    if (p != g and p != h and p != i and p != j and p != k and p != l and p != m and p != o):
                                                                        for q in range(6, 15):
                                                                            if (q != g and q != h and q != i and q != j and q != k and q != l and q != m and q != o and q != p):
                                                                                for r in range(7, 16):
                                                                                    if (r != g and r != h and r != i and r != j and r != k and r != l and r != m and r != o and r != p and r != q):

                                                                                        # g h i j   k   l m o p q r
                                                                                        c1 = (g == 1) or (h == 1) or (
                                                                                            i == 1) or (j == 1) or (k == 1)

                                                                                        c2 = (g == 2) or (h == 2) or (
                                                                                            i == 2) or (j == 2) or (k == 2) or (l == 2)

                                                                                        c3 = (g == 3) or (h == 3) or (i == 3) or (
                                                                                            j == 3) or (k == 3) or (l == 3) or (m == 3)

                                                                                        c4 = (g == 4) or (h == 4) or (i == 4) or (j == 4) or (
                                                                                            k == 4) or (l == 4) or (m == 4) or (o == 4)

                                                                                        c5 = (g == 5) or (h == 5) or (i == 5) or (j == 5) or (
                                                                                            k == 5) or (l == 5) or (m == 5) or (o == 5) or (p == 5)

                                                                                        c6 = (h == 6) or (i == 6) or (j == 6) or (k == 6) or (
                                                                                            l == 6) or (m == 6) or (o == 6) or (p == 6) or (q == 6)

                                                                                        c7 = (i == 7) or (j == 7) or (k == 7) or (l == 7) or (
                                                                                            m == 7) or (o == 7) or (p == 7) or (q == 7) or (r == 7)

                                                                                        if c1 and c2 and c3 and c4 and c5 and c6 and c7 and (not a[k - 1][l - 2][m - 3][o - 4][p - 5][q - 6][r - 7]):
                                                                                            # print(n, g, h, i,
                                                                                            #       j, k, l, m, o)
                                                                                            # print('{{{0}, {1}, {2}}}, '.format(i - 1, j - 2, k - 3))
                                                                                            a[k - 1][l - 2][m - 3][o -
                                                                                                                   4][p - 5][q - 6][r - 7] = 1
                                                                                            n += 1

    print(n)


# a = [0] * 5

# for i in range(0, 5):
#   a[i] = [0] * 5
#   for j in range(0, 5):
#     a[i][j] = [0] * 5
# n = 1
# for i in range(1, 6):
#   for j in range(2, 7):
#     for k in range(3, 8):
#         for h in range(1, 5):
#           for g in range(1, 4):
#             # g h i j k
#             c0 = (k != i != g != h != i != j != k != h != j) and (k != g != j)

#             c1 = (g == 1) or (h == 1) or (i == 1)

#             c2 = (g == 2) or (h == 2) or (i == 2) or (j == 2)

#             c3 = (g == 3) or (h == 3) or (i == 3) or (j == 3) or (k == 3)

#             c4 = (h == 4) or (i == 4) or (j == 4) or (k == 4)

#             c5 = (i == 5) or (j == 5) or (k == 5)

#             if c0 and c1 and c2 and c3 and (not a[i - 1][j - 2][k - 3]):
#               if c4 and c5:
#                 print(n, g, h, i, j, k)
#               # print('{{{0}, {1}, {2}}}, '.format(i - 1, j - 2, k - 3))
#               a[i - 1][j - 2][k - 3] = n
#               n += 1
# print(n)
# print(a)

# b = [0] * 5

# for i in range(0, 5):
#   b[i] = [0] * 5
#   for j in range(0, 5):
#     b[i][j] = [0] * 5
#     for k in range(0, 5):
#       b[i][j][k] = [0] * 5

# nlist = [0] * n
# for i in range(n):
#   nlist[i] = []

# for i in range(1, 6):
#   for j in range(2, 7):
#     for k in range(3, 8):
#       for l in range(4, 9):
#         for h in range(1, 5):
#           for g in range(1, 4):
#             # g h i j k l
#             cl = (g != l) and (h != l) and (i != l) and (j != l) and (k != l)

#             c0 = (k != i != g != h != i != j != k != h != j) and (k != g != j)

#             c1 = (g == 1) or (h == 1) or (i == 1)

#             c2 = (g == 2) or (h == 2) or (i == 2) or (j == 2)

#             c3 = (g == 3) or (h == 3) or (i == 3) or (j == 3) or (k == 3)

#             c4 = (h == 4) or (i == 4) or (j == 4) or (k == 4) or (l == 4)

#             if cl and c0 and c1 and c2 and c3 and c4 and (not b[i - 1][j - 2][k - 3][l - 4]):
#                 print(g, h, i, j, k, l, a[j - 2][k - 3][l - 4])
#                 nlist[a[i - 1][j - 2][k - 3]].append(a[j - 2][k - 3][l - 4])
#                 b[i - 1][j - 2][k - 3][l - 4] = 1

# print(nlist)
