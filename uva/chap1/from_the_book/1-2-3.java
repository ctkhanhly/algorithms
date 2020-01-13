import java.util.Scanner;

public static void main(String[] args){
    Scanner kboard = new Scanner(System.in);
    String numsExp = kboard.nextLine();
    kboard.close();
    String[] nums = numsExp.split(" ");
    int[] allNumbers = new int[nums.length];
    for(int i = 0; i < nums.length; i++){
        allNumbers[i] = Integer.parseInt(nums[i]);
    }
    int sum = 0;
    for(int num: allNumbers){
        sum += num;
    }
    System.out.println(sum);
}