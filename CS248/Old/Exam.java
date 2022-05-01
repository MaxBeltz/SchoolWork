import java.io.*;
import java.util.*;

class Exam
{
	public static double ave(int [] num, int len) //Function to compute average
	{
		double ave = 0; //Will eventually return the average
		for (int i = 0; i < len; i++) //Runs through all the scores
			ave = ave + num[i];
		ave = ave/len; //Total devided by amount of entries
		return ave; //Final Average
	}
	
	public static int Max(int [] num, int len) //Maximum function
	{
		int max = 0; //Starts at the lowest possible value so it will be changed
		for (int i = 0; i < len; i++) //runs through all entries
		{
			if (num[i] > max) //If the number in sequence is greater then the current maximum
				max = num[i]; //The larger number becomes the maximum
		}
		return max; //After the loop max will be the largest value
	}
	
	
	public static int Min(int [] num, int len) //Used to find minimum
	{
		int min = 100; //Initialized at maximum so next value will be lower
		for (int i = 0; i < len; i++) //Runs through all scores
		{
			if (num[i] < min) //If checked score is less than regestered min
				min = num[i]; //Checked file becomes new min
		}
		return min; //Should return lowest value
	}
	
	public static double Median(int [] num, int len) //Used to calculate median
	{
		int copy []; 
		copy = new int[len]; //This will be a copy of the inputed array
		int refrence; //Used to store the smallest store in each iteration
		double median = 0; //Will eventually return the median
		for(int i = 0; i < len; i++) //The actual copying of the Array into copy
			copy[i] = num[i];
		for(int j = 0; j < len; j++) //Used to sort the array
		{
			int least = 100; //Used to negate the smallest values after use
			refrence = 0; //Used to keep track of where the smallest value was located
			for(int i = 0; i < len; i++) //For finding the smallest in the copy array
			{
				if ( copy[i] < least) //If this checked value is less than the defined lowest value
				{
					least = copy[i]; //replace the lowest value
					refrence = i; //Take refrence of the position of the lowest value
				}
			}
			num[j] = least; //Gives the lowest value to the next open value 
			copy[refrence] = 100; //Places a large value in the location that had the smallest value so its not repeated
		}
		if (len % 2 == 0) //If an even number of entries
			median = ((num[len/2] + num[len/2-1])/2); //Finds the average of the two middle terms
		else //An odd number of entries
			median = num[len/2]; //Returns the middle value
		return median;
	}
	
	public static void Grades(int [] num, int len)
	{
		int A = 0; //Counters for each grade value
		int B = 0;
		int C = 0;
		int D = 0;
		int F = 0;
		for (int i = 0; i < len; i++) //Used for adding to the grade counters 
		{
			if ( num[i] >= 90)
				A++;
			else if ( num[i] >= 80)
				B++;
			else if ( num[i] >= 70)
				C++;
			else if ( num[i] >= 60)
				D++;
			else
				F++;
		}
		System.out.print("A: " + A + "\n" + "B: " + B + "\n" + "C: " + C + "\n" +
			"D: " + D + "\n" + "F: " + F + "\n");
	}
			
	public static void main (String [] args) throws IOException
	{
		Scanner scan = new Scanner (System.in); //Creates the input
		System.out.println("***Welcome to the Exam Statistics Program!!***\n\n");
		System.out.print("Please enter the name of your data file: ");
		String input; //Used for the file
		input = scan.nextLine();
		Scanner read = new Scanner(new FileReader(input)); //Used to read in the file
		int entries = read.nextInt(); //Reads in the amount of entries
		int [] scores; //Used to store the scores
		scores = new int[entries];
		for (int i = 0; i < entries; i++) //Reads in the rest of the scores
			scores[i] = read.nextInt();
		int max = Max(scores, entries); //Finds the Maximum
		int min = Min(scores, entries); //Finds the Minimum
		double aver = ave(scores, entries); //Finds average 
		double median = Median(scores, entries); //Finds Mean
		System.out.println("Maximum: " + max); 
		System.out.println("Min: " + min);
		System.out.println("Average: " + aver);
		System.out.println("Mean: " + median);
		Grades(scores, entries);
	}
}