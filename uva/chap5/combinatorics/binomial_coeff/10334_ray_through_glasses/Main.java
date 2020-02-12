import java.util.Scanner;
import java.math.BigInteger;

//ACs
/*
This is how I understand the problem...hopefully it's right
assume n=3

//n=2 accounts for both light coming from middle and bottom~~~n=1

n-2 rays have the same directions as n=> bounces off bottom, && reflected at the middle
 - doesn't count the case when it bounces off the top since it overlaps with n-1 case
n-1: must bounce off from the top and pass through 2 panes of glasses 
f(n) = f(n-2) + f(n-1)
*/
class Main{
    public static void main(String[] args){
        BigInteger[] fibs = new BigInteger[1004];
        fibs[0] = BigInteger.valueOf(1);
        fibs[1] = BigInteger.valueOf(2);
        // fibs[0] = 1;
        // fibs[1] = 2;
        for(int i = 2; i < 1004; ++i){
            fibs[i] = fibs[i-1].add(fibs[i-2]);
        }
        Scanner sc = new Scanner(System.in);
        int n;
        while(sc.hasNext()){
            n = sc.nextInt();
            System.out.println(fibs[n].toString());
        }
    }
}