import java.util.Scanner;
import java.math.BigInteger;
import java.lang.StringBuilder;
// import java.lang.*; 
// import java.io.*; 
// import java.util.*; 

//AC
class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        for(int z = 0; z < T; ++z){
            BigInteger op1 = sc.nextBigInteger();
            // String space = sc.next();
            BigInteger op2 = sc.nextBigInteger();

            // System.out.println(op1.toString() + " " + op2.toString());

            StringBuilder opstr = new StringBuilder();
            opstr.append(op1.toString());
            opstr = opstr.reverse();
            op1 = new BigInteger(opstr.toString());

            opstr = new StringBuilder();
            opstr.append(op2.toString());
            opstr = opstr.reverse();
            op2 = new BigInteger(opstr.toString());
            
            opstr = new StringBuilder();
            // System.out.println(op1.toString() + " " + op2.toString());
            opstr.append(op1.add(op2).toString());
            opstr = opstr.reverse();
            System.out.println(new BigInteger(opstr.toString()).toString());
        }
    }
}