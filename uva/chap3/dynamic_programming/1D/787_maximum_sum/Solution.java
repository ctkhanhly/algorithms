import java.math.BigInteger;
import java.util.Scanner;
import java.util.ArrayList;
// import java.io.FileWriter;
// import java.io.File;
// import java.io.FileInputStream;
// import java.io.IOException;


//renamed to Main before submit, AC
public class Solution{
    public static final int N = 100;
    public static void main(String[] args)
    {
        
        // try{
            // Scanner sc = new Scanner(new FileInputStream("in.txt"));
            // FileWriter f = new FileWriter(new File("out.txt"));
        Scanner sc = new Scanner(System.in);
        ArrayList<BigInteger> nums = new ArrayList<BigInteger>();
        BigInteger num, pos, neg, mn,mx, prod, zero, endMark;
        endMark = new BigInteger("-999999");
        int sz = 0;
        
        while(sc.hasNextInt()){
            // while(sc.hasNextInt()) {
            num = new BigInteger(Integer.toString(sc.nextInt()));
            if(num.equals(endMark) ) {
                zero = prod = BigInteger.ZERO;
                pos = neg = BigInteger.ONE;
                prod = nums.get(0);
                // System.out.println(sz + " " + prod);
                // System.out.println(nums.size());
                for(int i = 0; i < nums.size(); ++i){
                    mx = pos.multiply(nums.get(i));
                    mn = neg.multiply(nums.get(i));
                    neg = nums.get(i).min(mx.min(mn));
                    pos = nums.get(i).max(mx.max(mn));
                    prod = prod.max(pos);
                }
                
                // f.write(prod + "\n");
                System.out.println(prod);
                nums.clear();
            }
            else nums.add(num);
        }
        
        sc.close();
        // f.close();
        // }catch (IOException e) {}
    
        
        
    }
}


