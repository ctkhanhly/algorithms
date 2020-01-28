import java.util.Scanner;
import java.math.BigInteger;
import java.util.ArrayList;


//AC
class Main{
    public static final int INF = 11000;
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        ArrayList<Integer> arr = new ArrayList<Integer>();
        
        for(int i = 2; i <= 10000; ++i){
            if(BigInteger.valueOf(i).isProbablePrime(10))
                arr.add(i);
        }
        // int[] coin = new int[10100];
        while(sc.hasNext()){
            int num = sc.nextInt();
            if(num == 0) break;
            int sum = 0;
            int ans = 0;
            int i = 0,start = 0;
            // while( i < arr.size() && arr.get(i) <= num) ++i;
            // --i; 
            // for(int j = 0; j <= num; ++j) coin[j] = 0;
            // coin[0]=1;
            // for(int)
            while(i< arr.size() && arr.get(i) <= num){
                sum += arr.get(i);
                if(sum == num) ++ans;
                if(sum > num){
                    while(sum > num && start < i) {sum-= arr.get(start); ++start;}
                    if(sum == num) ++ans;
                }
                ++i;
            }
            System.out.println(ans);
        }
    }
}