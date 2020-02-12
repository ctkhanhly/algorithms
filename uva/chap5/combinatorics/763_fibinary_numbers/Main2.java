import java.util.Scanner;
import java.math.BigInteger;
import java.util.Arrays; 
import java.io.*;

class Main2{
    public static void main(String[] args){
        BigInteger[] fib = new BigInteger[105];
        fib[0] = BigInteger.valueOf(1);
        fib[1] = BigInteger.valueOf(2);
        for(int i = 2; i <= 100; ++i){
            fib[i] = fib[i-1].add(fib[i-2]);
        }
        System.out.println(fib[100].toString());
    try{
			Scanner sc = new Scanner(new FileInputStream("in.txt"));
            FileWriter f = new FileWriter(new File("out.txt"));
        // Scanner sc = new Scanner(System.in);    
        BigInteger res;
        String op1, op2;
        int[] ans = new int[105];
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
                f.write("0\n");
                System.out.println(0);
            }
            else{
                System.out.println(res.toString());
                i = Arrays.binarySearch(fib, res);
                sz = i < 0 ? -i-1 : i+1;
                j = i < 0 ? -i-2 : i;
                // System.out.println(sz + " " + res.toString());
                System.out.println(i + " " + sz);
                // System.out.println(i+ " " + fib[i].toString());
                while(res.compareTo(BigInteger.ZERO) > 0){
                    i = Arrays.binarySearch(fib, res);
                    
                    if(i < 0) i = -i-2;
                    // System.out.print(i);
                    for(; j >= i; --j){
                        ans[j] = 0;
                    } 
                    ans[i] = 1;
                    res = res.subtract(fib[i]);
                    // System.out.println(" " + fib[i].toString());
                }
                for(; j >= 0; --j){
                    ans[j] = 0;
                } 
                // System.out.println(sz);
                for(i = sz-1; i >= 0; --i) { System.out.print(ans[i]); f.write(String.valueOf(ans[i]));}
                f.write("\n");
                System.out.println();
            }
            System.out.println(z);
            if(sc.hasNext()) { f.write("\n"); System.out.println();} 
            ++z;
        }
    sc.close();
    f.close();
    }catch (IOException e) {}
    }
}