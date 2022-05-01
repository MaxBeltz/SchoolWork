public class Camper implements Comparable
{
	String Name;
	int Age;
	char Sex;
	
	public Camper (String N, int A, char S)
	{
		Name = N;
		Age = A;
		Sex = S;
	}
	
	public Camper()
	{
		Name = "ERROR";
		Age = -1;
		Sex = 'x';
	}
	
	public int compareTo(Object y)
	{
		Camper temp = (Camper)y;
		return Name.compareTo(temp.Name);
	}
	
	public String toString()
	{
		return ("Name: " + Name + "\nAge: " + Age + "\nSex: " + Sex);
	}
}