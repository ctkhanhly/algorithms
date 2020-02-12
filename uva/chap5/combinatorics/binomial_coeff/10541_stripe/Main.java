import java.util.Scanner;
import java.math.BigInteger;

class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        int n,k;
        BigInteger[][] dp = new BigInteger[205][105];
        for(int z = 0; z < T; ++z){
            n = sc.nextInt();
            k = sc.nextInt();
            for(int i = 0; i < k; ++i){
                n-= sc.nextInt();
            }
            //n+1Ck
            for(int i = 0; i <= k; ++i) dp[0][i] = BigInteger.ZERO;
            dp[0][0] = BigInteger.ONE;
            for(int i = 1; i <= n+1; ++i)
                for(int j = 0; j <= k; ++j){
                    // if(j == 0) dp[i][j] = BigInteger.ONE;
                    if(j == 0 || j == i) dp[i][j] = BigInteger.ONE;
                    else dp[i][j] = dp[i-1][j].add(dp[i-1][j-1]);
                }
            //else if(k == 0) System.out.println(1);
            if(n+1<k) System.out.println(0);
            else System.out.println(dp[n+1][k]);
        }
    }
}