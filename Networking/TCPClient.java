import java.net.*;
import java.io.*;

public class TCPClient {

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
			
            theSocket = new Socket(hostname, 43500);
            BufferedReader theTimeStream = new BufferedReader(new InputStreamReader(theSocket.getInputStream())); 
            //String theTime = theTimeStream.readLine();
			PrintWriter writer = new PrintWriter(theSocket.getOutputStream(), true);
			writer.println("This is a message sent to the server");
            System.out.println("It is " + 5 + " at " + hostname);
			writer.close();
        }
        catch (UnknownHostException e) {
            System.err.println(e);
        }
        catch (IOException e) {
            System.err.println(e);
        }
    }

}