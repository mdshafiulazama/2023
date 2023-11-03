def count_non_beautiful_subarrays(arr):
    result = 0
    i = 0
    while i < len(arr):
        count = 1
        while i + 1 < len(arr) and arr[i] == arr[i + 1]:
            count += 1
            i += 1
        result += (count * (count + 1)) // 2
        i += 1
    return result
T = int(input())
for t in range(1, T + 1):
    N = int(input())
    A = list(map(int, input().split()))
    non_beautiful_count = count_non_beautiful_subarrays(A)
    print(f"case {t}: {N * (N + 1) // 2 - non_beautiful_count}")