import java.io.*;
import java.util.*;

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

