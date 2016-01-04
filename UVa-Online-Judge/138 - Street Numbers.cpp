// Brute force.
// Run time : 0.366 sec.

#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
    int tc = 10;
    long long x = 8;
    double h;

    while(tc) {
        h = sqrt((x*x + x) >> 1);

        if(int(h) == h) {
            printf("%10d%10lld\n", int(h), x);
            --tc;
        }

        ++x;
    }

    return 0;
}


// Alternatively, just get the output of the above program
// and print them directly.
// Run time : 0.000 sec.

/*
#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
	int arr[] = {
         6,         8,
        35,        49,
       204,       288,
      1189,      1681,
      6930,      9800,
     40391,     57121,
    235416,    332928,
   1372105,   1940449,
   7997214,  11309768,
  46611179,  65918161 };

	for(int i = 0; i < 20; i+=2)
		printf("%10d%10d\n", arr[i], arr[i+1]);

    return 0;
}
*/
