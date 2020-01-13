#include <iostream>
#include <string>
using namespace std;


//Given 2 numbers, output their sum in one line
int main(){
    //case 1 input style, given the number of tests
    int TC, a, b;
    int TC, a, b;
    while (TC--) { // shortcut to repeat until 0
        scanf("%d", &TC); // number of test cases while (TC--) { // shortcut to repeat until 0
        scanf("%d %d", &a, &b); // compute answer
        printf("%d\n", a + b); // on the fly 
    }
    //case 2 input style, special values
    int a, b;
    // stop when both integers are 0
    while (scanf("%d %d", &a, &b), (a || b))//comma operator, only the right most expression is considered
    printf("%d\n", a + b);

    //case 3:
    int a, b;
    // scanf returns the number of items read while (scanf("%d %d", &a, &b) == 2)
    while (scanf("%d %d", &a, &b) == 2)
    // or you can check for EOF, i.e.
    // while (scanf("%d %d", &a, &b) != EOF)
    printf("%d\n", a + b);



    // output format: “Case [NUMBER]: [ANSWER]”
    int a, b, c = 1;
    while (scanf("%d %d", &a, &b) != EOF)
    // notice the two ‘\n’
    printf("Case %d: %d\n\n", c++, a + b);

    //output blank lines only between test cases.
    int a, b, c = 1;
    while (scanf("%d %d", &a, &b) != EOF) {
        if (c > 1) printf("\n"); // 2nd/more cases
        printf("Case %d: %d\n", c++, a + b);
    }


    int k, ans, v;
    while (scanf("%d", &k) != EOF) {
    ans = 0;
    while (k--) { scanf("%d", &v); ans += v; } printf("%d\n", ans);
    }
}