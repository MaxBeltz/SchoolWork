import java.io.*;
import javax.swing.*;
import java.util.*;
import java.awt.event.*;
import java.awt.*;
import java.awt.image.BufferedImage;
import javax.imageio.ImageIO;

//javac Game.java
//java Game

class Terminator extends WindowAdapter  //ends the game
{
	public void windowClosing(WindowEvent e)
	{
		System.out.println("Game closing...");
		System.exit(0);
	}
}

/*public class TTTBoard extends JFrame implements ActionListener{
	boardSpace[] spacesArray = new boardSpace[9];
	JLabel boardlabel, xlabel;
	Container container;
	ImageIcon xicon, oicon;
	int[][] winConditions = {
		//horizontal wins
		{0, 1, 2},
		{3, 4, 5},
		{6, 7, 8},
		//vertical wins
		{0, 3, 6},
		{1, 4, 7},
		{2, 5, 8},
		//diagonal wins
		{0, 4, 8},
		{2, 4, 6}
	};
	
	//create the board
    public void Board()
	{
		String gameboard = ("src/TicTacToeBoard.png");
		try 
        {
			BufferedImage boardimg = ImageIO.read(new File(gameboard));
			ImageIcon boardicon = new ImageIcon(boardimg);
			JLabel boardlabel = new JLabel(boardicon);
			boardlabel.setBounds(0, 0, 800, 600);
			container.add(boardlabel, 4, 4);
		} 
        catch (IOException e) 
        {
			e.printStackTrace();
		}
	}
	
	public int[][] getWinConditions(){
		return winConditions;
	}
	
	public boardSpace[] getSpaceArray(){
		return spacesArray;
	}
	
	public Container getContainer(){
		return container;
	}
}*/

public class Game extends JFrame implements ActionListener //the class is the entire rest of the file
{
	TTTBoard ticTac;
	int availableSpaces;
    int scene = 0; // 0 = title, 1 = game, 2 = game over
	boolean opening = false;
	boolean playersTurn = false;
	int [][] winConditions = ticTac.getWinConditions();
	boardSpace [] spacesArray = ticTac.getSpaceArray();
	Container container = ticTac.getContainer();
	
	// create the moves
    public void Moves()// X's and O's concider pushing the 2 if statements into one
    {
		for (int i=0;i<spacesArray.length;i++)
		{
			if (spacesArray[i].ownership == 1) 
			{
				try 
				{
					BufferedImage oimg = ImageIO.read(new File("src/O.png"));
					ImageIcon oicon = new ImageIcon(oimg);
					JLabel olabel = new JLabel(oicon);
					olabel.setBounds(spacesArray[i].xval, spacesArray[i].yval, 150, 150);
					container.add(olabel, 5, 5);
				}
				catch (IOException e)
				{
					e.printStackTrace();
				}
			}
		}

		for (int i=0;i<spacesArray.length;i++)
		{
			if (spacesArray[i].ownership == 2) 
			{
				try 
				{
					BufferedImage ximg = ImageIO.read(new File("src/X.png"));
					ImageIcon xicon = new ImageIcon(ximg);
					JLabel xlabel = new JLabel(xicon);
					xlabel.setBounds(spacesArray[i].xval, spacesArray[i].yval, 120, 120);
					container.add(xlabel, 5, 5);
				} 
				catch (IOException e) 
				{
					e.printStackTrace();
				}
			}
		}
	}

    public Game()
	{
		setTitle("Tic Tac Toe");
		Terminator kill=new Terminator();
		addWindowListener(kill);

		setSize(800,800);

		container = new JLayeredPane();

		for(int i=0;i<spacesArray.length;i++)
		{
			spacesArray[i] = new boardSpace();
		}

		//         [i].setButtonBounds( x,  y, wide, high)
		spacesArray[0].setButtonBounds(186,  61, 120, 120);
		spacesArray[1].setButtonBounds(341,  61, 120, 120);
		spacesArray[2].setButtonBounds(496,  61, 120, 120);
		spacesArray[3].setButtonBounds(186, 241, 120, 120);
		spacesArray[4].setButtonBounds(341, 241, 120, 120);
		spacesArray[5].setButtonBounds(496, 241, 120, 120);
		spacesArray[6].setButtonBounds(186, 421, 120, 120);
		spacesArray[7].setButtonBounds(341, 421, 120, 120);
		spacesArray[8].setButtonBounds(496, 421, 120, 120);

		for(int i=0;i<spacesArray.length;i++)
		{
			container.add(spacesArray[i].button, 0, 0);
			spacesArray[i].button.addActionListener(this);
			spacesArray[i].button.setVisible(true); //buttons don't work without this for some reason???
		}
		
		if (!opening)
		{
			try 
			{
				BufferedImage openimg = ImageIO.read(new File("src/title.png"));
				ImageIcon openicon = new ImageIcon(openimg);
				JLabel openlabel = new JLabel(openicon);
				openlabel.setBounds(0, 0, 800, 600);
				container.add(openlabel, 1, 1);
			} 
			catch (IOException e) 
			{
				e.printStackTrace();
			}
			add(container);
			setVisible(true);
			
			ActionEvent s = null;
			actionPerformed(s);
			opening = true;
		}
	}
	
	public void actionPerformed(ActionEvent s)
	{
		if (scene == 1){
			if (playersTurn){ // make player move based on button
				for(int i=0;i<spacesArray.length;i++){
					if(s != null && s.getSource()==spacesArray[i].button){
						if(spacesArray[i].ownership == 0){
							System.out.println("Player made move " + i);
							spacesArray[i].ownership = 2;
							Moves();
							finalScreen(checkWin());
							playersTurn = false;
							if (checkWin() == 0) { AIMoves(); }
						}
						else {
							System.out.println("Player tried to make move " + i + ", but that space is taken!");
						}
					}
				}
			}
			else { // if AI turn
				System.out.println("Player tried to make a move during the AI's turn");
			}
		}
		else if (scene==0){
			if (s != null && s.getSource()==spacesArray[7].button){
				System.out.println("Start");
				playersTurn = false;
				ticTac.Board();
			}
			else { System.out.println("irrelevant button pressed"); return; }
			scene = 1;
			if (!playersTurn){ AIMoves(); }
		}
		else if (scene==2){
			if (s != null && s.getSource()==spacesArray[7].button){
				Replay();
			}
		}
	} 

	public int checkWin(){ // return 0 for no winner, 1 for player winner, 2 for ai winner
		// all possible winning combinations:
		// 012, 345, 678 horizontals
		// 048, 246 diagonals
		// 036, 147, 258 virtical

		availableSpaces = 0;
		for (int i=0;i<spacesArray.length;i++)
		{
			if (spacesArray[i].ownership==0)
			{ 
				availableSpaces++; 
			}
		}

		for(int i=0;i<8;i++)
		{
			if (
			ticTac.spacesArray[winConditions[i][0]].ownership == 2 &&
			ticTac.spacesArray[winConditions[i][1]].ownership == 2 &&
			ticTac.spacesArray[winConditions[i][2]].ownership == 2)
			{
				System.out.println("Player win");
				scene = 2;
				return 1;
			}
			else if (
			ticTac.spacesArray[winConditions[i][0]].ownership == 1 &&
			ticTac.spacesArray[winConditions[i][1]].ownership == 1 &&
			ticTac.spacesArray[winConditions[i][2]].ownership == 1)
			{
				System.out.println("AI win");
				scene = 2;
				return 2;
			}
		}
		if (availableSpaces == 0)
		{
			 return 3; 
		}
		return 0;
	}

	public void randomMove(){
		// AI that chooses a random space
		availableSpaces = 0;
		for (int i=0;i<spacesArray.length;i++){
			if (spacesArray[i].ownership==0){ availableSpaces++; }
		}

		System.out.println(availableSpaces);
		while (!playersTurn && availableSpaces>0){
			System.out.println("computer sees turn");
			int AITurnRand = (int)(spacesArray.length * Math.random());
			System.out.println("generated number: " + AITurnRand );
			if (spacesArray[AITurnRand].ownership == 0){
				spacesArray[AITurnRand].ownership = 2;
				playersTurn = true;
				Moves();
				finalScreen(checkWin());
				System.out.println("picked at random");
				return;
			}
			else { playersTurn = false; }
		}
		Moves();
		finalScreen(checkWin());
	}


	public void AIMoves()
	{
		availableSpaces = 0;
		for (int i=0;i<spacesArray.length;i++)
		{
			if (spacesArray[i].ownership==0)
			{
				availableSpaces++; 
			}
		}
		while (!playersTurn)
		{
			// center spot
			if (spacesArray[4].ownership == 0)
			{ 
				spacesArray[4].ownership=1;
				playersTurn = true;
				Moves();
				finalScreen(checkWin());
				System.out.println("option 10");
				return;
			}

			// prioritize blocking
			for(int i=0;i<8;i++){
				if (
				spacesArray[winConditions[i][0]].ownership == 2 &&
				spacesArray[winConditions[i][1]].ownership == 2
				){
					if (spacesArray[winConditions[i][2]].ownership == 0){
						spacesArray[winConditions[i][2]].ownership=1;
						playersTurn = true;
						Moves();
						finalScreen(checkWin());
						System.out.println("option 1");
						return;
					}
				}
				else if (
				spacesArray[winConditions[i][1]].ownership == 2 &&
				spacesArray[winConditions[i][2]].ownership == 2
				){
					if (spacesArray[winConditions[i][0]].ownership == 0){
						spacesArray[winConditions[i][0]].ownership=1;
						playersTurn = true;
						Moves();
						finalScreen(checkWin());
						return;
					}
				}
				else if (
				spacesArray[winConditions[i][0]].ownership == 2 &&
				spacesArray[winConditions[i][2]].ownership == 2
				){
					if (spacesArray[winConditions[i][1]].ownership == 0){
						spacesArray[winConditions[i][1]].ownership=1;
						playersTurn = true;
						Moves();
						finalScreen(checkWin());
						System.out.println("option 2");
						return;
					}
				}
			}

			// prioritize making a winning move
			for(int i=0;i<8;i++){
				if (spacesArray[winConditions[i][0]].ownership == 1 &&
					spacesArray[winConditions[i][1]].ownership == 1)
				{
					if (spacesArray[winConditions[i][2]].ownership == 0)
					{
						spacesArray[winConditions[i][2]].ownership=1;
						playersTurn = true;
						Moves();
						finalScreen(checkWin());
						System.out.println("option 3");
						return;
					}
				}
				else if (spacesArray[winConditions[i][1]].ownership == 1 &&
						spacesArray[winConditions[i][2]].ownership == 1)
				{
					if (spacesArray[winConditions[i][0]].ownership == 0)
					{
						spacesArray[winConditions[i][0]].ownership=1;
						playersTurn = true;
						Moves();
						finalScreen(checkWin());
						System.out.println("option 4");
						return;
					}
				}
				else if (spacesArray[winConditions[i][0]].ownership == 1 &&
						spacesArray[winConditions[i][2]].ownership == 1)
				{
					if (spacesArray[winConditions[i][1]].ownership == 0)
					{
						spacesArray[winConditions[i][1]].ownership=1;
						playersTurn = true;
						Moves();
						finalScreen(checkWin());
						System.out.println("option 5");
						return;
					}
				}
			}			

			// top and bottom center
			if (spacesArray[1].ownership == 0 ||
				spacesArray[7].ownership == 0)
			{
				if (spacesArray[1].ownership == 0)
				{
					spacesArray[1].ownership=1;
					playersTurn = true;
					Moves();
					finalScreen(checkWin());
					System.out.println("option 6");
					return;
				}
				else if (spacesArray[7].ownership == 0)
				{
					spacesArray[7].ownership=1;
					playersTurn = true;
					Moves();
					finalScreen(checkWin());
					System.out.println("option 7");
					return;
				}
			}
			else if (spacesArray[3].ownership == 0 ||
					spacesArray[5].ownership == 0)
			{
				if (spacesArray[3].ownership == 0)
				{
					spacesArray[3].ownership=1;
					playersTurn = true;
					Moves();
					finalScreen(checkWin());
					System.out.println("option 8");
					return;
				}
				else if (spacesArray[5].ownership == 0)
				{
					spacesArray[5].ownership=1;
					playersTurn = true;
					Moves();
					finalScreen(checkWin());
					System.out.println("option 9");
					return;
				}
			}

			System.out.println("Resorted to random");
			randomMove(); // resort to a random move
		}
	}

	// add the final screen
	public void finalScreen(int s){
		if (s==0)
		{ 
			return; 
		}
		scene = 2;
		if (s==1)
		{
			System.out.println("Victory!");
			try 
			{
				BufferedImage winimg = ImageIO.read(new File("src/victory.png"));
				ImageIcon winicon = new ImageIcon(winimg);
				JLabel winlabel = new JLabel(winicon);
				winlabel.setBounds(0, 0, 800, 600);
				container.add(winlabel, 10, 10);
			} 
			catch (IOException e)
			{
				e.printStackTrace();
			}
		}
		else if (s==2){
			try {
				BufferedImage loseimg = ImageIO.read(new File("src/loss.png"));
				ImageIcon loseicon = new ImageIcon(loseimg);
				JLabel loselabel = new JLabel(loseicon);
				loselabel.setBounds(0, 0, 800, 600);
				container.add(loselabel, 10, 10);
			} catch (IOException e) {
				e.printStackTrace();
			}
		}
		else if (s==3){
			try {
				BufferedImage tieimg = ImageIO.read(new File("src/tie.png"));
				ImageIcon tieicon = new ImageIcon(tieimg);
				JLabel tielabel = new JLabel(tieicon);
				tielabel.setBounds(0, 0, 800, 600);
				container.add(tielabel, 10, 10);
			} catch (IOException e) {
				e.printStackTrace();
			}
		}
	}

	public void Replay(){
		for(int i=0;i<spacesArray.length;i++){
			spacesArray[i].ownership = 0;
		}
		/*
		playerTurn = false;
		gameState = 0;
		chooseDrawn = false;
		*/
		dispose();
		Game TTT=new Game();
	}
	public static void main(String [] args)
	{
		Game TTT = new Game();
	}
}