import java.io.*;
import java.util.*;

//Max Beltz
class MyDate implements DateInterface //Calling the interface
{
	int Day;
	int Dow;
	int Month;
	int Year;
	Scanner scan = new Scanner(System.in);
	
	public MyDate() //Default constructor 
	{
		Month = 0;
		Day = 0;
		Year = 0;
		Dow = 0;
	}
	
	public MyDate(int M, int D, int Y, int W) //Constructor with inputs
	{
		Month = M;
		Day = D;
		Year = Y;
		Dow = W;
	}
	
	public int getDay() //Returns the day
	{
		return Day;
	}
	
	public int getDow() //Returns the day of the week
	{
		return Dow;
	}
	
	public int getMonth() //Returns the month
	{
		return Month;
	}
	
	public int getYear() //Returns the year
	{
		return Year;
	}
	
	public void set(int m, int d, int y, int dow) //Allows you to set the date
	{
		Month = m;
		Day = d;
		Year = y;
		Dow = dow;
	}
	
	public boolean LeapYear() //Used to determine if the year is a leap year
	{
		if (Year % 4 == 0) //Year must be divisible by 4
		{
			if (Year % 100 == 0) //If divisible by 100
			{
				if (Year % 400 == 0) //And divisible by 400 then it is a leap year
					return true;
				else //Else it was not a leap year
					return false;
			}
			else //If not divisible by 100 then it is a leap year
				return true;
		}
		else
			return false;
	}
	
	public int CheckMonth() //Determines the last day of the month
	{
		if (Month == 1 || Month == 3 || Month == 5 || Month == 7 || Month == 8 || Month == 10) //These months have 31 days
			return 31;
		else if (Month == 4 || Month == 6 || Month == 9 ||Month == 11) //These months have 30 days 
			return 30;
		else if (Month == 2) //Checks for February
		{
			if (LeapYear() == true) //If it is a leap year
				return 29;
			else //If it is not a leap year
				return 28;
		}
		else //Checks for December
		{
			if (Day == 31) //If it is December 31st
				return -1; //Return -1 to signal a new year
			else
				return 31; //last day in december
		}
	}
	
	public int DowInc() //Used to increase the day of the week
	{
		if (Dow == 6) //If it is Saturday
		{
			Dow = 0; //Make it Sunday
			return Dow;
		}
		else //Increase the day of the week
			return Dow++; 
	}
	
	public void tomorrow() //Used to make the date tomorrow
	{
		if (Day == CheckMonth()) //If if is the last day of the month
		{
			Month++; //Increase the month
			Day = 1; //Make it the first
			DowInc(); //Change the day of the week
		}
		else if (CheckMonth() == -1) //If it is December 31st
		{
			Month = 1; //Make it January 1st
			Day = 1;
			Year++; //increase the year
			DowInc();
		}
		else //Will be used in most cases to just increase the date and DoW
		{
			Day++;
			DowInc();
		}
	}

	public String DowPretty() //Used to translate DoW to the actual Day of the week
	{
		if(Dow == 0)
			return "Sunday";
		else if(Dow == 1)
			return "Monday";
		else if(Dow == 2)
			return "Tuesday";
		else if(Dow == 3)
			return "Wednesday";
		else if(Dow == 4)
			return "Thursday";
		else if(Dow == 5)
			return "Friday";
		else if(Dow == 6)
			return "Saturday";
		else
			return "Error";
	}
	
	public String MonthPretty() //Used to translate Month to the actual Month
	{
		if(Month == 1)
			return "January";
		else if(Month == 2)
			return "February";
		else if(Month == 3)
			return "March";
		else if(Month == 4)
			return "April";
		else if(Month == 5)
			return "May";
		else if(Month == 6)
			return "June";
		else if(Month == 7)
			return "July";
		else if(Month == 8)
			return "August";
		else if(Month == 9)
			return "September";
		else if(Month == 10)
			return "October";
		else if(Month == 11)
			return "November";
		else if(Month == 12)
			return "December";
		else
			return "Error";
	}
	
	public String toString() //Print statement
	{
		return DowPretty() + ", " + MonthPretty() + " " + Day + ", " + Year;
	}

	public void today()
	{
	}
	  
	public void yesterday()
	{
	}
}