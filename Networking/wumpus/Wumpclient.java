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
    static int port = 10101;

    public static void main(String[] args) throws IOException, SocketException, UnknownHostException {

        Socket theSocket = new Socket(hostname, port);
        DataOutputStream dos = new DataOutputStream(theSocket.getOutputStream());

	BufferedInputStream bis = new BufferedInputStream( theSocket.getInputStream() ) ;
        BufferedReader br = new BufferedReader( new InputStreamReader(bis, StandardCharsets.UTF_8));

        Scanner scanner = new Scanner(System.in);
        String message = "";
        do {
            System.out.print("Enter message: ");
            message = scanner.nextLine();
            dos.writeBytes( message + "\n" );

            String msg = br.readLine();

            System.out.println("[" + hostname + "]: " + msg);

        } while ( !message.equals("quit") );

        theSocket.close();
    }

}