from cs50 import get_int

while True:
    n = get_int("Height: ")
    if 0 < n and n <= 8:
        for i in range(1, n + 1):
            print(" " * (n - i), end="")
            print("#" * i, end="  ")
            print("#" * i)

        break
