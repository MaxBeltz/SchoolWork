import java.io.*;
import java.util.*;

public class Room{
	
	int rnum; //Number of rooms
	int [] adjacent = new int[3]; //There will always be 3 adjacent rooms	
	String description; //The description of each room
	int special; //Determines if there are any hazzards or if it is a regular room
	static int Arrow = 3; //Amount of arrows that is shared throughout all rooms
	
	public Room () //Base constructor for rooms
	{
		rnum = -1; //If not changed then sign of error
		description = "INITIALIZE"; //If not changed then sign of error
		for (int i = 0; i < 3; i++) //If not changed then sign of error
			adjacent[i] = -1;
		special = 0; //Nothing special about this room
	}
		
	public Room (int n, int [] adj, String des, int spec) //Constructor with inputs
	{
		rnum = n;
		description = des;
		for (int i = 0; i < 3; i++)
			adjacent[i] = adj[i];
		special = spec;
	}
	
	public int retrunNumber() //Returns number of the room
	{
		return rnum;
	}
	
	public int [] returnAdjacent() //Returns the adjacent rooms
	{
		return adjacent;
	}
	
	public String returnDescription() //Returns descriptions
	{
		return description;
	}
	
	public String toString() //Should only be used as testing and not actually in the program.
	{
		return rnum + ", " + adjacent[1] + ", " + adjacent[2] + ", " + adjacent[3] + ", " + description + ", " + special; 
	}
	
	
}