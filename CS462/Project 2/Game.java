import java.io.*;
import javax.swing.*;
import java.util.*;
import java.awt.event.*;
import java.awt.*;
import java.awt.image.BufferedImage;
import javax.imageio.ImageIO;

//javac Game.java
//java Game

class Terminator extends WindowAdapter
{
	public void windowClosing(WindowEvent e)
	{
		System.out.println("Game closing...");
		System.exit(0);
	}
}

class Graphics{ //class created to implement the graphics of tic tac toe
	Container container;
	
	public Graphics(Container cont){
		container = cont;
	} 
	
    public void Board(){ //creates the board Graphic
		String gameboard = ("TicTacToeBoard.png");
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
	
	public void title(){ //creates the title graphic
		try 
		{
			BufferedImage openimg = ImageIO.read(new File("title.png"));
			ImageIcon openicon = new ImageIcon(openimg);
			JLabel openlabel = new JLabel(openicon);
			openlabel.setBounds(0, 0, 800, 600);
			container.add(openlabel, 1, 1);
		} 
		catch (IOException e) 
		{
			e.printStackTrace();
		}
	}
	
	public void Moves(boardSpace[] spacesArray)// X's and O's  board
    {
		for (int i=0;i<spacesArray.length;i++)
		{
			if (spacesArray[i].ownership == 1) 
			{
				try 
				{
					BufferedImage oimg = ImageIO.read(new File("O.png"));
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
			else if (spacesArray[i].ownership == 2) 
			{
				try 
				{
					BufferedImage ximg = ImageIO.read(new File("X.png"));
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

	public void finalScreen(int s){ //board
		if (s==0)
		{ 
			return; 
		}
		if (s==1)
		{
			System.out.println("Victory!");
			try 
			{
				BufferedImage wining = ImageIO.read(new File("victory.png"));
				ImageIcon winicon = new ImageIcon(wining);
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
				BufferedImage loseimg = ImageIO.read(new File("loss.png"));
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
				BufferedImage tieimg = ImageIO.read(new File("tie.png"));
				ImageIcon tieicon = new ImageIcon(tieimg);
				JLabel tielabel = new JLabel(tieicon);
				tielabel.setBounds(0, 0, 800, 600);
				container.add(tielabel, 10, 10);
			} catch (IOException e) {
				e.printStackTrace();
			}
		}
	}
}


public class Game extends JFrame implements ActionListener
{
    boardSpace[] spacesArray = new boardSpace[9];
	JLabel boardlabel, xlabel;
	Container container;
	ImageIcon xicon, oicon;
	public Graphics TTTBoard; //created the graphics class above
	int[][] winConditions = { //game
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
	
	int availableSpaces;

    int scene = 0; // 0 = title, 1 = game, 2 = game over
	boolean playersTurn = false;
	
	public Game()
	{
		setTitle("Tic Tac Toe");
		Terminator kill=new Terminator();
		addWindowListener(kill);
		setSize(800,800);
		container = new JLayeredPane();
		TTTBoard = new Graphics(container);
		//the following are the dimensions of the buttons in the button array
		//dimensions are determined by the size pf the board image
		int basex = 186, basey = 61; //the base valuse of x and y
		int diffx = 155, diffy = 180; //the change of the value of x and y depending on position
		int x = 0, y = 0, wide = 120, high = 120; //the values that will be put into the consrtuctor 

		for(int i=0;i<spacesArray.length;i++)
		{
			spacesArray[i] = new boardSpace();
			x = basex + diffx *(i%3);
			y = basey + diffy *(i/3);
			spacesArray[i].setButtonBounds(x, y, wide, high);
			container.add(spacesArray[i].button, 0, 0);
			spacesArray[i].button.addActionListener(this);
			spacesArray[i].button.setVisible(true); //buttons don't work without this for some reason???
		}
		TTTBoard.title();
		add(container);
		setVisible(true);
		
		ActionEvent s = null;
		actionPerformed(s);
	}
	
	public void actionPerformed(ActionEvent s) //game
	{
		if (scene == 1){
			if (playersTurn){ // make player move based on button
				for(int i=0;i<spacesArray.length;i++){
					if(s != null && s.getSource()==spacesArray[i].button){
						if(spacesArray[i].ownership == 0){
							System.out.println("Player made move " + i);
							spacesArray[i].ownership = 2;
							TTTBoard.Moves(spacesArray);
							TTTBoard.finalScreen(checkWin());
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
				TTTBoard.Board();
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
	
	public void moveMade(int pos, int own){
		spacesArray[pos].ownership=own;
		playersTurn = (own==1);
		TTTBoard.Moves(spacesArray);
		TTTBoard.finalScreen(checkWin());
	}
	
	public int checkWin(){ // return 0 for no winner, 1 for player winner, 2 for ai winner 
		// all possible winning combinations:
		// 012, 345, 678 horizontals
		// 048, 246 diagonals
		// 036, 147, 258 virtical
		for(int i=0;i<8;i++)
		{
			if (
			spacesArray[winConditions[i][0]].ownership == 2 &&
			spacesArray[winConditions[i][1]].ownership == 2 &&
			spacesArray[winConditions[i][2]].ownership == 2)
			{
				System.out.println("Player win");
				scene = 2;
				return 1;
			}
			else if (
			spacesArray[winConditions[i][0]].ownership == 1 &&
			spacesArray[winConditions[i][1]].ownership == 1 &&
			spacesArray[winConditions[i][2]].ownership == 1)
			{
				System.out.println("AI win");
				scene = 2;
				return 2;
			}
		}
		
		availableSpaces = 0;
		for (int i=0;i<spacesArray.length;i++)
		{
			if (spacesArray[i].ownership==0)
			{ 
				availableSpaces++; 
			}
		}
		if (availableSpaces == 0)
		{
			 return 3; 
		}
		return 0;
	}
	
	public void AIMoves() //the AI moves
	{
		while (!playersTurn)
		{
			// center spot
			if (spacesArray[4].ownership == 0)
			{ 
				moveMade(4,1);
				System.out.println("option 4");
				return;
			}
			
			//prioritize winning
			//checks to see if any 2 out of 3 win spaces are held by self then claims the 3rd
			// prioritize blocking
			//checks to see if any 2 out of 3 win spaces are held by opponent then claims the 3rd
			for(int k=1; k<3; k++){
				for(int i=0;i<8;i++){
					for(int j=0; j<3; j++){
						if(spacesArray[winConditions[i][(j+1)%3]].ownership == k &&
						   spacesArray[winConditions[i][(j+2)%3]].ownership == k &&
						   spacesArray[winConditions[i][(j)]].ownership == 0){
							   System.out.println("option " + winConditions[i][j]);
							   moveMade(winConditions[i][j], 1);
							   return;
						   }
					}
				}
			}
			
			//prioritize the up right left down then the corners
			for(int i=1; i<18; i+=2){
				if(spacesArray[i%9].ownership == 0){
					moveMade(i%9,1);
					return;
				}
			}
		}
	}

	public void Replay(){ //game
		for(int i=0;i<spacesArray.length;i++){
			spacesArray[i].ownership = 0;
		}
		dispose();
		Game TTT=new Game();
	}
	public static void main(String [] args)
	{
		Game TTT = new Game();
	}
}