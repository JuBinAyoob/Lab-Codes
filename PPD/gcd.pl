gc:-read(A),read(B),gcd(A,B,X),write('gcd is'),write(X).
gcd(A,A,A).
gcd(A,B,C):- A<B,gcd(B,A,C).
gcd(A,B,C):- A>B,G is A-B,gcd(B,G,C).
g:-write('enter 2 values'),gc.
