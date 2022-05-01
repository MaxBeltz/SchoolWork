public class Party
{
	String pName; //Name on the paryt
	int pNum; //Number of people
	int pTime; //Time they arrived
	
	public Party() //Generic constructors, if any values remain there is an error
	{
		pName = "Error";
		pNum = -1;
		pTime = -1;
	}
	
	public Party (String Name, int Num, int Time) //Constructors with data
	{
		pName = Name;
		pNum = Num;
		pTime = Time;
	}
	
	public String toString() //Should only be printed when dequed 
	{
		return "Table for " + pName;
	}
}