import java.net.*;
import java.io.*;
import java.util.*;

public class SendingMessage {

    public static void main(String[] args) {
        Socket theSocket;
        String hostname;

        if (args.length > 0) {
            hostname = args[0];
        }
        else {
            hostname = "localhost";
        }

        try {
			message mess = new message();
            theSocket = new Socket(hostname, 43500);
            BufferedReader theTimeStream = new BufferedReader(new InputStreamReader(theSocket.getInputStream())); 
			OutputStream outputStream = theSocket.getOutputStream();
			PrintStream out = new PrintStream(outputStream);
			String sending = mess.toString();
			out.println(sending);
        }
        catch (UnknownHostException e) {
            System.err.println(e);
        }
        catch (IOException e) {
            System.err.println(e);
        }
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
