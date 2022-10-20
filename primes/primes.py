primes = []

def is_prime(n):
  for i in primes:
    if (n%i) == 0:
      return False
  return True

for x in range(2, 1000000):
  if is_prime(x):
    primes.append(x)
  
  #if x % 5000 == 0: print("Completed", x / 1000000 * 100, "%")

print(len(primes))

with open('primes.txt', 'w') as f:
  for number in primes:
      f.write(f"{number}\n")