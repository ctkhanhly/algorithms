import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Scanner;
import java.io.FileWriter;
import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;


public class Main {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		try{
			Scanner sc = new Scanner(new FileInputStream("in.txt"));
            FileWriter f = new FileWriter(new File("out.txt"));
			ArrayList<BigInteger> list = new ArrayList<BigInteger>();
			BigInteger el, end, pro, maxPro;
			end = new BigInteger("-999999");
			// Scanner sc = new Scanner(System.in);
			while(sc.hasNext()){
				el = sc.nextBigInteger();
				if(el.compareTo(end)!=0)list.add(el);
				else{
					maxPro = list.get(0);
					for(int i = 0; i < list.size(); i++){
						pro = BigInteger.ONE;
						for(int j = i; j < list.size(); j++){
							pro = pro.multiply(list.get(j));
							maxPro = maxPro.max(pro);
						}
					}
				f.write(maxPro+"\n");
				// System.out.println(maxPro);
				list.clear();
				}
			}
			sc.close();
			f.close();
		}catch (IOException e) {}
		
	}

}

//https://www.cs.swarthmore.edu/~newhall/unixhelp/Java_files.html