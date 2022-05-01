import java.io.*;
import java.util.*;

class Hunt
{ 

	public static Room[] makeDungeon() throws IOException //Used to make the dungeon by reading in a file
	{
		int numr; //Number of rooms
		int nums; //Number of spiders
		int nump; //Number of pits
		int numa; //Number of supply rooms (a for arrows)
		int numb; //Number of bat rooms
		Scanner read=new Scanner(new FileReader("Wump.txt")); //Used to read in the file to make the dungeon
		
		numr = read.nextInt(); //The first number is the number of rooms
		nums = read.nextInt(); //The second number is the number of spider roms
		nump = read.nextInt(); //The third number is the number of pitt rooms
		numa = read.nextInt(); //The fourth number is the number of supply rooms
		numb = read.nextInt(); //The number of bat rooms
		Room [] Dungeon; //What will actually hold the Dungeon
		Dungeon = new Room[numr]; 
		for (int i = 0; i < numr; i++) //The room creator for the Dungeon
			{
				Room tempRoom = new Room(); //Will be used for placing in the array
				tempRoom.rnum = read.nextInt(); //Number of the room
				for (int j = 0; j < 3; j++) //Adjacent rooms
					tempRoom.adjacent[j] = read.nextInt();
				read.nextLine(); //Used to break the line when reading 
				tempRoom.description= read.nextLine(); //The unique description
				Dungeon[i] = tempRoom; //Passes the room int the dungeon
			}
		setHazard(Dungeon, nums, nump, numa, numb); //Used to add the special events to random rooms of the dungeon
		return Dungeon;
	}
	
	public static void setHazard(Room[] Dungeon, int Spidc, int Pitc, int Suppc, int Batc) //Used to add the special events to random rooms of the dungeon
	{
		int Rand; //Used to store the random numbers
		int Wumpc = 0; //Used to count the number of Wumpi
		while(Spidc > 0) //Will cintinue until the number of spider rooms is equal to that given in the file
		{
			Rand = ((int)(Math.random()* (Dungeon.length - 1)) + 1); //Random number generator excluding the number 1 
			if(Dungeon[Rand].special == 0) //If the room does not have anything special in it
			{
				Dungeon[Rand].special = 1; //Special 1 = spiders
				Spidc--;
			}
		}
		while(Pitc > 0) //Same as above but with pitts
		{
			Rand = ((int)(Math.random()* (Dungeon.length - 1)) + 1);
			if(Dungeon[Rand].special == 0)
			{
				Dungeon[Rand].special = 2; //Special 2 = pitt
				Pitc--;
			}
		}
		while(Wumpc < 1) //There will only be one wumpus
		{
			Rand = ((int)(Math.random()* (Dungeon.length - 1)) + 1);
			if(Dungeon[Rand].special == 0)
			{
				Dungeon[Rand].special = 3; //Special 3 = wumpus
				Wumpc++;
			}
		}
		while(Suppc > 0) //Same as above but with supply rooms
		{
			Rand = ((int)(Math.random()* (Dungeon.length - 1)) + 1);
			if(Dungeon[Rand].special == 0)
			{
				Dungeon[Rand].special = 4; //Special 4 = supply room
				Suppc--;
			}
		}
		while(Batc > 0) //Same as above but with batt rooms
		{
			Rand = ((int)(Math.random()* (Dungeon.length - 1)) + 1);
			if(Dungeon[Rand].special == 0)
			{
				Dungeon[Rand].special = 5; //Special 5 = batt rooms
				Batc--;
			}
		}
	}
	
	public static void specialToText(Room [] Dungeon, int [] Adj) //Used to desply the special charecteristics of adjacent rooms
	{
		int check = 0;
		for(int i = 0; i < 3; i++) //Used to check all adjacent rooms
		{
			check = (Adj[i] - 1);
			if (Dungeon[check].special == 1)
				System.out.println("You hear a faint clicking noise.");
			else if (Dungeon[check].special == 2)
				System.out.println("You smell a dank odor.");
			else if (Dungeon[check].special == 3)
				System.out.println("You smell some nasty Wumpus!");
			else if (Dungeon[check].special == 4)
				System.out.println("You see the faint light of a tourch.");
			else if (Dungeon[check].special == 3)
				System.out.println("You hear the flapping of dozens of tiny wings.");
			else 
				System.out.print(""); //If there is nothing in the room
		}
	}
	
	public static boolean Move(int num, Room current) //Used to move between rooms
	{
		boolean possible = false; //Defaults to not possible 
		for (int i = 0; i < 3; i ++) //If the room that they want to move is adjacent to the current room
		{
			if(current.adjacent[i] == num)
				possible = true; //It is possible to move
		}
		return possible; //return if it is possible to move
	}
	
	public static void printGame(Room current, Room [] Dungeon, int [] Adj) //Prints the current gamestate
	{
		System.out.println("You are in room " + current.rnum); 
		System.out.println(current.description);
		System.out.println("There are tunnels to rooms " + current.adjacent[0] + ", " + current.adjacent[1] + ", and " + current.adjacent[2]);
		specialToText(Dungeon, Adj);
		System.out.println("You have " + current.Arrow + " Arrows");
	}
	
	public static boolean Shoot(Room Current, int room, Room [] Dungeon) //Used to shoot 
	{

		if(Move(room, Current)) //If you can move to the room you can shoot at it
		{
			if(Dungeon[room-1].special == 1) //Shoots a spider
			{
				System.out.println("You hear your arrow hit the ground then a clicking noise as something engulfs the arrow");
				Current.Arrow--; //Loose an arrow
				return false; //You did not win
			}
			else if(Dungeon[room-1].special == 2) //Shoots a pitt
			{
				System.out.println("You wait to hear any sign of your arrow, you wait and wait. The arrow is lost but you never heard it hit the ground");
				Current.Arrow--;
				return false;
			}
			else if(Dungeon[room-1].special == 3) //Shoots the Wumpus
			{
				System.out.println("You hear the sound of an arrow hitting flesh, your arrow has struck true");
				Current.Arrow--;
				return true; //You win
			}
			else //You shoot nothing
			{
				System.out.println("You hear your arrow hit the ground, you may have hit nothing but at least you know that room is safe");
				Current.Arrow--;
				return false;
			}
		}
		else //You cannot shot in that room
		{
			System.out.println("You shoot in the general direction, however since you are not adjacent to it the arrow hits the wall and breaks");
			Current.Arrow --;
			return false;
		}
	}
	
	public static boolean checkHazzerd(Room [] Dungeon, int move) //Checks to see if you enter a special room
	{
		if (Dungeon[move].special == 1) //Spiders
		{
			System.out.println("You see a massive group of spiders as they begin to engulf you");
			System.out.println("GAME OVER");
			return true; //You die
		}
		else if (Dungeon[move].special == 2) //Pitt
		{
			System.out.println("You begin to fall and fall");
			System.out.println("GAME OVER");
			return true;
		}
		else if (Dungeon[move].special == 3) //Wumpus
		{
			System.out.println("You see the wumpus, then everything goes black");
			System.out.println("GAME OVER");
			return true;
		}
		else if (Dungeon[move].special == 4) //Supply room
		{
			System.out.println("You find a supply room that is full of arrows. You replenish your arrows.");
			Dungeon[move].Arrow = 3;
			return false; //You do not die
		}
		else if (Dungeon[move].special == 5) //Batt room
		{
			System.out.println("As soon as you step in the room");
			Dungeon[move].Arrow = 3;
			return false;
		}
		else //Nothing special in the room
			return false;
	}

	
	public static void playGame(Room [] Dungeon) //Used to play the game
	{
		Room currentRoom = new Room(); //Your current location 
		currentRoom = Dungeon[0]; //YOu start in the first room
		String action; //What you want to do
		int room; //Used for movement and shoots
		Scanner scan=new Scanner(System.in); //Used for input
		while(currentRoom.rnum != -1) //While not an error in creation of the dungeon
		{	
			printGame(currentRoom, Dungeon, currentRoom.adjacent); //Prints the gamestate
			System.out.println("(M)ove or (S)hoot");
			action = scan.next(); //Takes the action of the player
			if (action.equals("M")) //If they waht to move 
			{
				System.out.println("Where would you like to move?");
				room = scan.nextInt(); //Where would they like to move
				if (Move(room, currentRoom)) //If they can moove
					currentRoom = Dungeon[room-1];
				else //They cannot move
					System.out.println("You cannot move there");
				if (Dungeon[room-1].special == 5) //If you move into the bat room you are moved into an random room
				{
					System.out.println("You begin to see bats as they pick you up and take you to a random room");
					room = ((int)(Math.random()* Dungeon.length)); 
					currentRoom = Dungeon[room-1];
				}
				if (checkHazzerd(Dungeon, room-1)) //If you enter a room that kills you
					return;
			}
			else if (action.equals("S") && currentRoom.Arrow > 0) //If you want to shoot and have arrows
			{
				System.out.println("Where would you like to shoot?");
				room = scan.nextInt();
				if (Shoot(currentRoom, room, Dungeon)) //If you killed the wumpus
				{
					System.out.println("Congradulations, you killed the Wumpus!");
					return;
				}
			}
			else
				System.out.println("You cannot do that");
		}
	}
	
	public static void main (String [] args) throws IOException
	{
		Room [] Dungeon;
		Dungeon = makeDungeon(); //Makes the dungeon
		playGame(Dungeon); //Plays the game
	}
}