m = 10 ** 10
with (open("powers.csv", "r") as file):
    for line in file:
        n, pwr = [int(v) for v in line.split(",")]
        pwr1 = pow(n, n, m)
        if pwr != pwr1:
            print(f"Error: {n}, {pwr}, {pwr1}")
