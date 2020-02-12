import java.util.Scanner;
import java.math.BigInteger;
import java.util.Arrays; 
import java.io.*;


//AC
class Main{
    public static void main(String[] args){
        BigInteger[] fib = new BigInteger[105];
        fib[0] = BigInteger.valueOf(1);
        fib[1] = BigInteger.valueOf(2);
        for(int i = 2; i <= 100; ++i){
            fib[i] = fib[i-1].add(fib[i-2]);
        }
        // System.out.println(fib[100].toString());
    // try{
			// Scanner sc = new Scanner(new FileInputStream("in.txt"));
            // FileWriter f = new FileWriter(new File("out.txt"));
        Scanner sc = new Scanner(System.in);    
        BigInteger res;
        String op1, op2;
        int i,j,n,m,sz, z = 1;
        while(sc.hasNext()){
            op1 = sc.next();
            op2 = sc.next();
            n = op1.length();
            m = op2.length();
            res = BigInteger.valueOf(0);
            // System.out.println(op1 + " " + op2);
            // i = j = 0;
            i = 0;
            j = 0;
            while(i < n || j < m){
                if(i < n) {
                    if(op1.charAt(i) == '1') res = res.add(fib[n-1-i]);
                    // System.out.println("op1 " + op1.charAt(i) + " " + res.toString());
                    ++i;
                }
                if(j < m){
                    if(op2.charAt(j) == '1') res = res.add(fib[m-1-j]);
                    ++j;
                }
            }
            if(res.equals(BigInteger.ZERO)){
                // f.write("0\n");
                System.out.println(0);
            }
            else{
                for(i = 100; i >= 0; --i){
                    if(res.compareTo(fib[i]) >=0) break;
                }
                for(; i >= 0; --i){
                    if(res.compareTo(fib[i]) >= 0)
                        {System.out.print(1);// f.write("1");
                        res = res.subtract(fib[i]);}
                    else 
                        {System.out.print(0); }//f.write("0");}
                    
                }
                // f.write("\n");
                System.out.println();
            }
            // System.out.println(z);
            if(sc.hasNext()) { System.out.println();} //f.write("\n");} 
            ++z;
        }
    sc.close();
    // f.close();
    // }catch (IOException e) {}
    }
}