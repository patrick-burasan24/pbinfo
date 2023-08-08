#include <fstream>
#include <algorithm>    
typedef long long int ll;
typedef unsigned long long int ull;

using namespace std;

const unsigned long VMAX = 2642245;

ifstream fin("cubprim.in");
ofstream fout("cubprim.out");

ll N, M, i, j, tmp, ciur[VMAX + 5];
ull x;

struct elem {
    int index;
    ll root;
    ull value;
} v[200005];

inline ll cubeRoot( const ull &X ) {
    if (!X) return 0;
    ull st = 1, dr = VMAX, mid;
    while ( st <= dr ) {
        mid = ( st + dr ) >> 1;
        if ( 1ULL * mid * mid * mid == X )  
            return mid;
        else if ( 1ULL * mid * mid * mid < X )
            st = mid + 1;
        else    
            dr = mid - 1;
    }
    return -1;
}

inline bool cmp( const elem &A, const elem &B ) {
    if ( A.value == B.value )
        return A.index < B.index;
    return A.value > B.value;
}


int main() {
    unsigned long sqr = sqrt( VMAX );
    for ( i = 4; i <= VMAX; i += 2 )
        ciur[i] = 1;
    for ( i = 3; i <= sqr; i += 2 )
        if ( !ciur[i] )
            for ( j = i * i; j <= VMAX; j += 2 * i )
                ciur[j] = 1;
    fin >> N;
    M = 0;
    for ( i = 1; i <= N; i++ ) {
        fin >> x;
        tmp = cubeRoot( x );
        if ( tmp != -1 && ciur[tmp] == 0 ) {
            M++;
            v[M].index = i;
            v[M].root = tmp;
            v[M].value = x;
        }
    }
    fout << M << '\n';
    sort( v + 1, v + M + 1, cmp );
    for ( i = 1; i <= M; i++ )
        fout << v[i].index << ' ' << v[i].root << ' ' << v[i].value << '\n';
    fin.close();
    fout.close();
    return 0;
}