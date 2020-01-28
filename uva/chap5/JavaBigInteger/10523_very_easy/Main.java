import java.util.Scanner;
import java.math.BigInteger;


//AC
class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        while(sc.hasNext()){
            BigInteger i = new BigInteger("1");
            BigInteger N = sc.nextBigInteger();
            BigInteger A = sc.nextBigInteger();
            BigInteger res = BigInteger.ZERO;
            for(; i.compareTo(N) <= 0; i = i.add(BigInteger.ONE)){
                
                res = res.add(i.multiply(A.pow(i.intValue())));
                // System.out.println(i.toString() + " " + res.toString());
            }
            System.out.println(res.toString());
        }
    }
}