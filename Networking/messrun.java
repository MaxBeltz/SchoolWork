import java.io.*;
import java.util.*;

public class messrun
{
	public static void main(String [] args) throws IOException
	{
		message mess = new message();
		System.out.println(mess);
	}
}

class message
{
	String text;
	Date today;
	String contenttype;
	
	public message() 
	{
		text = "Hello, it is currently ";
		today = new Date();
		contenttype = "This message was made using strings and the built in date format in java";
	}
	
	public String toString(){
		return text + today + "\n" + contenttype;
	}
}	
