import java.util.Scanner;
import java.math.BigInteger;
import java.lang.StringBuffer;

//AC
class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        while(sc.hasNext()){
            BigInteger num = sc.nextBigInteger();
            // String rev = new StringBuffer(num.toString()).reverse().toString();
            BigInteger rev = new BigInteger(new StringBuffer(num.toString()).reverse().toString());
            if(num.isProbablePrime(10) && rev.isProbablePrime(10) && !rev.equals(num))
                System.out.println(num.toString() + " is emirp.");
            else if(num.isProbablePrime(10))
                System.out.println(num.toString() + " is prime.");
            else 
                System.out.println(num.toString() + " is not prime.");
        }
    }
}