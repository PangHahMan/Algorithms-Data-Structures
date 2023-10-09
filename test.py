def is_prime(num):
   if num < 2:
       return False
   for i in range(2, int(num**0.5) + 1):
       if num % i == 0:
           return False
   return True

def prime_numbers_less_than(n):
   primes = []
   for num in range(2, n):
       if is_prime(num):
           primes.append(num)
   return primes

n = int(input("请输入一个大于2的自然数："))
result = prime_numbers_less_than(n)
print("小于该数字的所有素数组成的列表：", result)


