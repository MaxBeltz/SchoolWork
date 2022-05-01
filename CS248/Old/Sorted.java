import java.io.*;
import java.util.*;

class Sorted
{
	public static void main(String [] args)
	{
		Scanner scan = new Scanner(System.in);
		System.out.println("How large is the list");
		int num = scan.nextInt();
		Integer [] Selection = new Integer[num];
		Integer [] Bubble = new Integer[num];
		Integer [] Insertion = new Integer[num];
		Integer [] Shell = new Integer[num];
		Integer [] Merge = new Integer[num];
		Integer [] Quick = new Integer[num];
		for (int i = 0; i < num; i++)
		{
			Integer randnum;
			randnum = (Integer)((int)(Math.random()*num + 1));
			Selection[i] = randnum;
			Bubble[i] = randnum;
			Insertion[i] = randnum;
			Shell[i] = randnum;
			Merge[i] = randnum;
			Quick[i] = randnum;
			if (num <= 100)
				System.out.print(randnum + ", ");
		}
		System.out.println(" ");
		double time = System.currentTimeMillis();
		sorts.selection(Selection);
		time = (System.currentTimeMillis() - time);
		System.out.println("Selection Time: " + time);
		
		time = System.currentTimeMillis();
		sorts.bubble(Bubble);
		time = (System.currentTimeMillis() - time);
		System.out.println("Bubble Time: " + time);
		
		time = System.currentTimeMillis();
		sorts.insertion(Insertion);
		time = (System.currentTimeMillis() - time);
		System.out.println("Insertion Time: " + time);
		
		time = System.currentTimeMillis();
		sorts.shell(Shell);
		time = (System.currentTimeMillis() - time);
		System.out.println("Shell Time: " + time);
		
		time = System.currentTimeMillis();
		sorts.merge(Merge);
		time = (System.currentTimeMillis() - time);
		System.out.println("Merge Time: " + time);
		
		time = System.currentTimeMillis();
		sorts.quick(Quick);
		time = (System.currentTimeMillis() - time);
		System.out.println("Quick Time: " + time);
	}
}