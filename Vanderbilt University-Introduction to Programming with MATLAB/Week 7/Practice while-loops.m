function k=next_prime(n)
prime=n+1;
while isprime(prime)~=1
    prime=prime+1;
end
k=prime