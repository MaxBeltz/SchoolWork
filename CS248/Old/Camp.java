import java.io.*;
import java.util.*;

class Camp
{
	public static void printHelp() //Multiple print statement to make it pretty
	{
		System.out.println("H	Help: print a list of commands");
		System.out.println("E name age sex	Enroll a new camper (insert)");
		System.out.println("W name	Withdraw a camper (delete)");
		System.out.println("D name	Display the age and gender of a camper");
		System.out.println("A	Print the average age of the campers");
		System.out.println("L	List all campers names in alphabetical order");
		System.out.println("S	Print the number of boy and girl campers");
		System.out.println("P	List all campers names in preorder");
		System.out.println("Q	Quit");
	}
	
	public static void main(String [] args) throws IOException
	{
		char Com = 'z';
		Scanner read = new Scanner(new FileReader("Camp.txt"));
		BST camp = new BST();
		String Name = "Error";
		int Age = -1;
		char Sex = 'x';
		String use = "Error";
		Camper trans = new Camper();
		System.out.println("Welcome to camp");
		while (Com != 'Q')
		{
			System.out.println(" ");
			Com = read.next().charAt(0);
			if (Com == 'H')
				printHelp();
			if (Com == 'E')
			{
				System.out.println("Command E");
				Name = read.next();
				Age = read.nextInt();
				Sex = read.next().charAt(0);
				Camper temp = new Camper (Name, Age, Sex);
				camp.insert(temp);
				System.out.println("Camper Added " + temp.Name + ", " + temp.Age + ", " + temp.Sex);
			}
			if (Com == 'W')
			{
				System.out.println("Command W");
				use = read.next();
				trans.Name = use;
				trans = (Camper)camp.delete(trans);
				if (trans.Name == null)
					System.out.println("ERROR CAMPER DOES NOT EXIST");
				else
					System.out.println("Camper Removed " + trans.Name + ", " + trans.Age + ", " + trans.Sex);
			}
			if (Com == 'D')
			{
				System.out.println("Command D");
				use = read.next();
				trans.Name = use;
				trans = (Camper)camp.lookup(trans);
				System.out.println(trans);
			}
			if (Com == 'A')
			{
				System.out.println("Command A");
				if (camp.count == 0)
					System.out.println("There are no campers");
				else
				{
					camp.reset(0);
					double avecomp = 0;
					while (camp.hasNext())
					{
						trans = (Camper)camp.getNext();
						avecomp = (avecomp + trans.Age);
					}
					avecomp = (avecomp / camp.count);
					System.out.println("Average Age: " + avecomp);
				}
			}
			if (Com == 'L')
			{
				System.out.println("Command L");
				if (camp.count == 0)
					System.out.println("There are no campers");
				else
				{
					System.out.println("The campers that are regesterd:");
					camp.reset(1);
					while (camp.hasNext())
						{
							trans = (Camper)camp.getNext();
							System.out.println(trans.Name);
						}
				}
			}
			if (Com == 'S') 
			{
				System.out.println("Command S");
				int countM = 0;
				int countF = 0;
				if (camp.count == 0)
					System.out.println("There are no campers");
				else
				{
					camp.reset(0);
					while (camp.hasNext())
						{
							trans = (Camper)camp.getNext();
							if (trans.Sex == 'M')
								countM++;
							else
								countF++;
						}
						System.out.println("Number of Males: " + countM);
						System.out.println("Number of Feales: " + countF);
				}
			}
			if (Com == 'P')
			{
				System.out.println("Command P");
				if (camp.count == 0)
					System.out.println("There are no campers");
				else
				{	
					camp.reset(0);
					while (camp.hasNext())
						{
							trans = (Camper)camp.getNext();
							System.out.println(trans.Name);
						}
				}
			}
		}
		System.out.println("Enjoy Camp");
	}	
}	