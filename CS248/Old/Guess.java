import java.io.*;
import java.util.*;

class Guess
{
	static String insult()//Used to randomly select insuts. When called will return a random insult
	{
		int number = (int)(6*Math.random());//used for the selection of the insult
		String insults[] = {"nerd","you fool","lame O",", I hope your mother is proud","sucks to suck","-_-"}; //selection of insults
		String insult = insults[number];
		return insult; //should return a random insult
	}
	
	static void game() //The actual guessing game
	{
		Scanner scan = new Scanner(System.in);
		int rand; //The random number
		int guess; //Will be determined byuser input
		rand = (int)(1+100*Math.random()); //The number you are seeking 
		guess = -1; //Initialized here as this can never be the answer
		while (rand != guess) //loop for the guessing process
		{
			System.out.print("Enter your guess: ");
			guess = scan.nextInt();
			if (guess > rand) //Guess too high
				System.out.println("Too high " + insult());
			else if (guess < rand) //Guess too low
				System.out.println("Too low, " + insult());
			else //Guessed correctly
				System.out.println("Congradulations, you did it");
		}
	}
	public static void main(String [] args)
	{
		Scanner scan = new Scanner(System.in);
		String cont = "Yes"; //Initialized so it runs the first time
		
		while (!cont.equals("No")) //No means they are done
		{
			if (cont.equals("Yes")) //They wish to continue
			{
				System.out.println("I have a number between 1 and 100.  Can you guess it?");
				game(); //Runs the actual guessing game
			}
			else //Invalid input
				System.out.println("I'm sorry, I didnt understand that");
			System.out.print("Would you like to continue? (Yes/No): ");
			cont = scan.nextLine(); //Checks if they want to play again
		}
		
	}
	
}