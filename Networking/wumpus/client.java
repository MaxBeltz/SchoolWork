import java.io.BufferedInputStream;
import java.io.BufferedReader;
import java.io.DataOutputStream;
import java.io.InputStreamReader;
import java.io.IOException;
import java.net.Socket;
import java.net.SocketException;
import java.net.UnknownHostException;
import java.nio.charset.StandardCharsets;
import java.util.Scanner;


//Need to do
//Wait for responce
//Recieve responce
//Parse responce
//Continue to play the game
public class client {
    static String hostname = "localhost";
    static int port = 42069;

    public static void main(String[] args) throws IOException, SocketException, UnknownHostException {

        Socket theSocket = new Socket(hostname, port);
        DataOutputStream dos = new DataOutputStream(theSocket.getOutputStream());

		BufferedInputStream bis = new BufferedInputStream( theSocket.getInputStream() ) ;
        BufferedReader br = new BufferedReader( new InputStreamReader(bis, StandardCharsets.UTF_8));

        Scanner scanner = new Scanner(System.in);
        String message = "";
        do {
            System.out.println("Enter your command (JOIN/MOVE/SHOOT/HELP/QUIT)");
            String com = scanner.nextLine();
			String roo = "";
			if (com.equals("JOIN")){
				System.out.println("Enter Your Name");
				roo = scanner.nextLine();}
			else if (com.equals("MOVE") || com.equals("SHOOT")){
				System.out.println("Enter the appropriate room");
				roo = scanner.nextLine();}
			String comroo= com+roo;
			Integer ln = comroo.length();
			message = com + "|" + roo + "|" + 0;
			System.out.println(message);
            dos.writeBytes( message + "\n" );
			System.out.println(1);



            String response = br.readLine();
			System.out.println(2);
			System.out.println(responce);
			System.out.println(3);
            String [] parts = response.split("\\|");
			System.out.println(4);
			System.out.println(parts.length);
			System.out.println(5);
            /*Integer byteLength = (parts[2]);
            char[] cbuf = new char[byteLength];
			br.read(cbuf, 0, byteLength);
			String msg = new String(cbuf);
            System.out.println("[" + hostname + "]: " + msg);*/

        } while ( !message.equals("quit") );
		bis.close();
		br.close();
        theSocket.close();
    }

}