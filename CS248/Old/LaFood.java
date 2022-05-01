import java.io.*;
import java.util.*;

class LaFood
{

	public static void main(String [] args) throws IOException
	{
		Scanner scan=new Scanner(new FileReader("LaFood.txt")); //Used to read in file
		char Action = 'S'; //S as default because it should never be used
		int time = 0; //Used to track current time
		double avetime = 0; //Used to calculate the average time
		double counter = 0; //Used to coubt the number of people for the averande
		Party print = new Party(); //Our party class that will pass into the link list
		QueueLL line = new QueueLL(); //Our queue of parties
		while (Action != 'Q') //While the file is not at an end
		{
			Action = scan. next().charAt(0); //Scan for the next action
			if (Action == 'A') //Party arrives
			{
				Party enter = new Party(); //Create party with parameters 
				enter.pTime = scan.nextInt();
				enter.pNum = scan.nextInt();
				enter.pName = scan.nextLine();
				line.enqueue(enter); //Enter the queue
				System.out.println(enter.pName + " Party of " + enter.pNum);  //Aknowledge that they have arrived
				System.out.println("Please wait at the Bar");
				
			}
			else if (Action == 'T') //If a table is ready
			{
				time = scan.nextInt(); //Sets current time for calculation
				print = (Party)line.dequeue(); //Saves the next table 
				System.out.println(print); //Print the party who is next
				avetime = avetime + (time - print.pTime)*print.pNum; //Adds the average time for calculations
				counter = counter + print.pNum; //Adds the number of people for calculations
			}
			else if (Action == 'Q') //End of file
			{
				System.out.println("We are now closed");
				System.out.println("Unseated tables: ");
				print = (Party)line.dequeue(); //Used to check remaining tables
				while( print!= null) //While there are remaining tables
				{
					System.out.println(print);
					print = (Party)line.dequeue();
				}
				System.out.println("Average wait time: ");
				System.out.println((avetime/counter) - ((avetime/counter)%.01)); //Calculates average wait time with 2 decimal points
			}
		}
	}
}