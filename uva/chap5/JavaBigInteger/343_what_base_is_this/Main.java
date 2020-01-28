import java.util.Scanner;
import java.math.BigInteger;
import java.util.ArrayList;
import java.io.FileWriter;
import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;


//AC
//min base = 2 lol
class Main{
    public static void main(String[] args){
        // try{
            Scanner sc = new Scanner(System.in);
            // Scanner sc = new Scanner(new FileInputStream("in.txt"));
            // FileWriter f = new FileWriter(new File("out.txt"));
            while(sc.hasNext()){
                BigInteger res = BigInteger.ZERO;
                String op1str = sc.next();
                String op2str = sc.next();
                BigInteger op1;
                BigInteger op2;
                boolean found = false;
                int i = 0, j = 0;
                ArrayList<BigInteger> arr1 = new ArrayList<BigInteger>();
                ArrayList <BigInteger> arr2 = new ArrayList<BigInteger>();
                for(int k = 0; k < op1str.length(); ++k) i = Math.max(i, Character.getNumericValue(op1str.charAt(k))+1);
                for(int k = 0; k < op2str.length(); ++k) j = Math.max(j, Character.getNumericValue(op2str.charAt(k))+1);
                // System.out.println(i + " " + j);
                i = Math.max(i, 2);
                j = Math.max(j,2);
                for(int a = i; a <= 36 && !found; ++a){
                    op1 = addNum(op1str, new BigInteger(String.valueOf(a)));
                    arr1.add(op1);
                }
                for(int b = j;b <= 36; ++b){
                    op2 = addNum(op2str, new BigInteger(String.valueOf(b)));
                    arr2.add(op2);
                }
                for(int a = 0; a < arr1.size() && !found; ++a){
                    for(int b = 0; b < arr2.size(); ++b){
                    if(arr1.get(a).equals(arr2.get(b))){
                        // f.write(op1str + " (base " + (a+i) + ") = " + op2str + " (base " + (b+j) + ")\n");
                        System.out.println(op1str + " (base " + (a+i) + ") = " + op2str + " (base " + (b+j) + ")");
                            found = true;
                            break;
                    }
                    }
                }
                //base 1 => uni character => equal in any base
                if(!found) {
                    // f.write(op1str + " is not equal to "+ op2str + " in any base 2..36\n");
                    System.out.println(op1str + " is not equal to "+ op2str + " in any base 2..36");
                }
            }
            sc.close();
            // f.close();
        // }catch (IOException e) {};
        
    }
    public static BigInteger addNum(String opstr, BigInteger base){
        BigInteger op = BigInteger.ZERO;
        int n = opstr.length();
        BigInteger num;
        for(int k = 0; k < n; ++k){
            num = new BigInteger(String.valueOf(Character.getNumericValue(opstr.charAt(k))) );
            op = op.add(num.multiply(base.pow(n-k-1)));
        }
        return op;
    }
}