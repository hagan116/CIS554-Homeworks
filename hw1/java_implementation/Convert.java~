import java.lang.Math.*;

public class Convert{

    public static int convert(int number, int base){
	int lsDigit;
	int count = 0;
	int result = 0;
	
	while (number > 0){
	    lsDigit = number % 10;
	    if (lsDigit >= base){
		System.out.println("Invalid input.\n");
		return 0;
	    }
	    else{
		number = number / 10;
		result += (lsDigit * Math.pow((double) base,(double) count));
		count++;
	    }
	}
	return result;
    }
}