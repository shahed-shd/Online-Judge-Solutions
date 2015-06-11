#include <iostream>
using namespace std;

int main()
{
    int n;

    cin >> n;

    for(int i = 1; i <= n; ++i)
        cout << i << ' ';

    return 0;
}


/*
Everybody who knows quick sort will recognize that
the tsar's program is quick sort of N numbers.
Let we have a sorted array with n numbers.
Let l-r+1=k. Then function P() will increase the value of c by k+1
because it will visit all x elements to distribute them
into part smaller than or equal to x and part greater or equal to x.
That increases c by k.
But the i and j iterators must be equal
so there is also one additional increase of c.
Because we have a sorted array function P() will partition him
into part consisting of 1 element and part consisting of l-r elements.
The part consisting of 1 element will be ignored
and there won't be any increase of c.
In the part with l-r elements it will do the same - partitioned it into 1 and l-r-1.
So let begin with l-r+1=N. Then the function Q() will go to l-r+1=N-1 and so on to l-r+1=2.
For those calls of function Q() c will be increased with:
N+1 + N + N-1 + ... + 5 + 4 + 3 = (N+1)*(N+1+1)/2 - 1 - 2 = N*N + 3*N + 2/2 - 3
= N*N + 3*N + 2 - 3*2/2 = N*N + 3*N - 4 / 2.
So if we give a sorted array to the tsar's program it will print what we want.

What is more, we prove that for sorted array quick sort is very bad algorithm with such bad complexity.

Note: If the median element was chosen in a different way
the solution won't be so easy.
But it can be done if we try all permutations of array
with elements from [1;n] and check for c.
*/
