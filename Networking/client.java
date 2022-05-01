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

public class client {
    static String hostname = "localhost";
    static int port = 42069;

    public static void main(String[] args) throws IOException, SocketException, UnknownHostException {

        Socket theSocket = new Socket(hostname, port);
        DataOutputStream dos = new DataOutputStream(theSocket.getOutputStream());

		BufferedInputStream bis = new BufferedInputStream( theSocket.getInputStream() ) ;
        BufferedReader br = new BufferedReader( new InputStreamReader(bis, StandardCharsets.UTF_8));

        Scanner scanner = new Scanner(System.in);
        String command = "";
        do {
            System.out.println("Enter your command (JOIN/MOVE/SHOOT/HELP/QUIT)");
            command = scanner.nextLine();
			String room = "";
			if (command.equals("JOIN")){
				System.out.println("Enter Your Name");
				room = scanner.nextLine();}
			else if (command.equals("MOVE") || command.equals("SHOOT")){
				System.out.println("Enter the appropriate room");
				room = scanner.nextLine();}

			Request req = new Request(command, room, 0);
            dos.writeBytes(req.toString());

            String response = br.readLine();
			Response res = new Response(response);
			Integer byteLength = res.getLength();
            char[] cbuf = new char[byteLength];
			br.read(cbuf, 0, byteLength);
			String data = new String(cbuf);
			res.setData(data);
			System.out.println("[" + hostname + "]: " + res.toString());

        } while ( !command.equals("QUIT") );
		bis.close();
		br.close();
		dos.close();
		theSocket.close();
		System.out.println("Disconnected. Thank you for playing!");
    }

}