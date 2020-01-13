#include <cstdio>
using namespace std;

int main(){
    int K, N, M, X, Y;
    //cin >> K >> N >> M;
    while(!(scanf("%d%d%d", &K, &N, &M) == 1 && K == 0)) {
        while(K-- > 0){
            //cin >> X >> Y;
            //while(scanf("%d%d", &X, &Y) == 2){
            scanf("%d%d", &X, &Y);
            if(X == N || Y == M){
                printf("divisa\n");
            }
            else if(X < N && Y > M){
                printf("NO\n");
            }
            else if(X < N && Y < M){
                printf("SO\n");
            }
            else if(X > N && Y > M){
                printf("NE\n");
            }
            else{
                printf("SE\n");
            }
            //}
            //--K;
        }
    }
}

/*
#include <stdio.h>

int main() {
    int n, x, y, a, b;
    while(scanf("%d", &n) == 1 && n) {
        scanf("%d %d", &x, &y);
        while(n--) {
            scanf("%d %d", &a, &b);
            if(a == x || b == y)
                puts("divisa");
            else if(a > x && b > y)
                puts("NE");
            else if(a < x && b > y)
                puts("NO");
            else if(a < x && b < y)
                puts("SO");
            else
                puts("SE");
        }
    }
    return 0;
}
*/