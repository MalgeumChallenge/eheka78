# https://www.acmicpc.net/problem/1759
# 1759번
# 암호 만들기

L, C = map(int, input().split())
words = input().split()
words.sort()

def method(arr):
    if len(arr) == L:
        # 최소 한 개의 모음(a, e, i, o, u)과 최소 두 개의 자음
        v_count = 0
        for i in arr:
            if i in ['a', 'e', 'i', 'o', 'u']:
                v_count += 1
        c_count = L - v_count

        if v_count >= 1 and c_count >= 2:
            st = ""
            for i in range(L):
                st += arr[i]
            print(st)
            return

    for i in range(len(arr), C):
        if arr[-1] < words[i]:
            arr.append(words[i])
            method(arr)
            arr.pop()

for i in range(C - L + 1):
    a = [words[i]]
    method(a)