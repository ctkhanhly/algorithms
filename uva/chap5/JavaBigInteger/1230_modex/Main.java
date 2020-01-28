import java.util.Scanner;
import java.math.BigInteger;



//AC
class Main{
    public static void main(String[] args){
        Scanner sc  = new Scanner(System.in);
        int T = sc.nextInt();
        for(int z = 0; z< T; ++z){
            BigInteger x = sc.nextBigInteger();
            BigInteger y = sc.nextBigInteger();
            BigInteger n = sc.nextBigInteger();
            System.out.println(x.modPow(y,n));
        }
        sc.nextInt();
    }
}