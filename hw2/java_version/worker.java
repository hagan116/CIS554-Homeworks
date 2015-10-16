import java.util.Scanner;

public class Worker{
    
    int hourlyPay;
    int commissionPay;
    int piecePay;
    int managerPay;
    Scanner s;

    public Worker(){
	s = new Scanner(System.in);
	hourlyPay = 0;
	piecePay = 0;
	commissionPay = 0;
	managerPay = 0;
    }

    public void calculatePay(){
	while (true){
	    int paycode;
	    System.out.print("Enter paycode (-1 to end): ");
	    paycode = s.nextInt();
	    if (paycode == -1){
		break;
	    }
	    else {
		switch (paycode) {
		case 1:
		    addManager();
		    System.out.println();
		    break;
		case 2:
		    addHourly();
                    System.out.println();
                    break;
		case 3:
		    addCommission();
                    System.out.println();
                    break;
		case 4:
		    addPiece();
		    System.out.println();
		default:
		    System.out.println("Unknown paycode.");
		    System.out.println();
		    break;
		}
	    }
	}
    }
    
    public void addManager(){
	double salary;
	System.out.println("Manager Selected.");
	System.out.print("Enter weekly salary: ");
	salary = s.nextInt();
	managerPay += salary;
	System.out.println();
	System.out.println("Manager's pay is $");
    }
    
    public void addHourly(){

    }
    
    public void addCommission(){

    }
    
    public void addPiece(){

    }
    
    private void printChart(){
	
    }
}