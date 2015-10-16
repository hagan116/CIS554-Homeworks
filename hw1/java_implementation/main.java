import java.util.Scanner;

class Main{

    public static void main(String[] args){
    
	Scanner in  = new Scanner(System.in);
	System.out.println("Please enter a number: ");
	int number = in.nextInt();
	System.out.println("And its base: ");
	int base = in.nextInt();
	int result = Convert.convert(number,base);
	System.out.print("Answer: " + result);
	
    }
}