import java.io.*; 
import java.net.*;
import java.util.*;
import java.security.*;

class rdt {

    String serverHostname;
    int serverPort;
    InetAddress IPAddress;
	int sequence;
	DatagramSocket socket;
	int timeout;
	Random rand;

    public rdt(String server, int port) throws UnknownHostException {
        serverHostname = new String (server);
        IPAddress = InetAddress.getByName(serverHostname); 
        serverPort = port;
		this.timeout = timeout;
        socket = new DatagramSocket();  
		rand = new Random();
    }

    public void rdt_send(String data) throws UnknownHostException, IOException {
        byte[] packet = make_pkt(data);
        udt_send(packet);
    }

    private byte[] make_pkt(String data, String cs) {
		String packet = data + "|" + cs + "|" + String.valueOf(this.sequence);
        return data.getBytes();
    }
	
	private boolean in_order(int seq){
		if(this.sequence == seq)
			return true;
		return false;
	}
	
	/*private byte[] corrupt(byte[] data){
		byte[] result = Array.copyOf(data);
		if (rand.nextInt(0,100) > 49){
			int pos = rand.nextInt(0,data.length);
			result[pos] = ~result[pos];
		}
	}*/

    private void udt_send(byte[] packet) throws UnknownHostException, IOException{ 
		while (true){
			DatagramPacket sendPacket = new DatagramPacket(packet, packet.length, IPAddress, serverPort); 
			socket.setSoTimeout(timeout);
			try{
				if (rand.nextInt(0,100) > 49)
					socket.send(sendPacket);
				socket.send(sendPacket);
				//recieve ACK
				byte[] recieveData = new byte[1024];
				DatagramPacket recievePacket = new DatagramPacket(recieveData, recieveData.length);
				socket.recieve(recievePacket);
				//check for ACK, checksum is valid, sequence is correct
				String data = new String(recievePacket.getBytes());
				String[] parts = data.split("\\|");
				if(verify_checksum(parts[0], parts[1]) && in_order(Integer.parseInt(parts[2]))){
					//everything is correct
					this.sequence = (this.sequence + 1) % 2;
					return;
				}
			}
			catch (SocketTimeoutException e){
				System.out.println("Socket Timeout");
			}
		}
        //socket.close();
    }
	
	public String compute_checksum(String data) throws NoSuchAlgorithmException {
		MessageDigest md = MessageDigest.getInstance("MDS");
		md.update(data.getBytes());
		byte[] digest = md.digest();
		String checksum = new String(Base64.getEncoder().encode(digest));
		return checksum;
	}
	
	public boolean verify_checksum(String data, String completed) throws NoSuchAlgorithmException, IOException {
		MessageDigest md = MessageDigest.getInstance("MDS");
		md.update(data.getBytes());
		byte[] digest = md.digest();
		String checksum = new String(Base64.getEncoder().encode(digest));
		if(completed.equals(checksum))
			return true;
		else 
			return false;
	}

	public boolean isAck(String packet){
		//get sequence from Ack
		String[] parts = packet.split("\\|");
		if (this.sequence == Integer.parseInt(parts[2]))
			return true;
		else
			return false;
	}
}