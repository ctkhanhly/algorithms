import java.util.Scanner;
import java.math.BigInteger;
import java.io.*;


//AC
class Main{
    public static void main(String[] args){
        
        // try{
            Scanner sc = new Scanner(System.in);
            // Scanner sc = new Scanner(new FileInputStream("in.txt"));
            // FileWriter f = new FileWriter(new File("out.txt"));
            BigInteger n;
            String num;
            int val;
            while(sc.hasNext()){
                n = sc.nextBigInteger();
                val = n.intValue();
                if(val == 0) break;
                System.out.println(n.toString() + "! --");
                // f.write(n.toString() + "! --\n");
                for(int i = 2; i < val; ++i)
                    n = n.multiply(BigInteger.valueOf(i));
                int[] ans = new int[10];
                for(int i = 0; i < 10; ++i) 
                    ans[i] = 0;
                num = n.toString();
                // System.out.println(num);
                for(int i = 0; i < num.length(); ++i)
                    ++ans[Character.getNumericValue(num.charAt(i))];
                
                for(int i = 0; i < 10; ++i){
                    // f.write("(" + i + ")\t" + ans[i]);
                    if(i == 0 || i == 5){
                        // f.write(String.format("%6s%5d", "(" + i +")",ans[i]));
                        System.out.printf("%6s%5d", "(" + i +")",ans[i]);
                    }
                    else{
                        // f.write(String.format("%7s%5d", "(" + i +")",ans[i]));
                        System.out.printf("%7s%5d", "(" + i +")",ans[i]);
                    }
                    if(i ==4 || i == 9) {System.out.println(); } //f.write("\n");}
                    // else { System.out.print("\t"); f.write("\t"); }
                }
            }
            // sc.close();
            // f.close();
        // } catch(IOException e){}
        

    }
}