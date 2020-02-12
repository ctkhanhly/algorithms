import java.util.Scanner;
import java.math.BigInteger;


//AC
class Main{
    public static int compute(int a, int b, int n, int x){
        return (BigInteger.valueOf(a).multiply(BigInteger.valueOf(x).pow(2)).mod(BigInteger.valueOf(n)).intValue() + b) %n;
    }
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n,a,b,t,h,cnt;   
        while(sc.hasNext()){
            n = sc.nextInt();
            if(n == 0) break;
            a = sc.nextInt();
            b = sc.nextInt();
            cnt = 0;
            t = compute(a,b,n,0);
            h = compute(a,b,n,compute(a,b,n,0));
            while(t != h) {
                t = compute(a,b,n,t); h = compute(a,b,n,compute(a,b,n,h));
            }
            cnt = 1;
            h = compute(a,b,n,t);
            while(t != h) {
                ++cnt; h = compute(a,b,n,h);
            }
            System.out.println(n-cnt);
        }
    }
}