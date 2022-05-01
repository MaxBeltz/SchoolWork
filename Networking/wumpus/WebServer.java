import java.net.*;
import java.io.*;
import java.util.*; 
//Made by Max Beltz and Alex McGrath
 
public class WebServer{
	public static void main(String[] args) throws IOException{
		Socket theConnection;
		try{
			ServerSocket theServer = new ServerSocket(8042); //sets up the server
			try{
				while (true)
				{
					theConnection = theServer.accept(); //accepts connection
					//BufferedWriter output = new BufferedWriter(new OutputStreamWriter(theConnection.getOutputStream()));
					BufferedReader input = new BufferedReader(new InputStreamReader(theConnection.getInputStream()));
					DataOutputStream otpt = new DataOutputStream(theConnection.getOutputStream());
					StringBuffer sb = new StringBuffer();
					String str; //will take input
					str = input.readLine(); //reads first line
					while (!str.isEmpty()){ //checks to see when the message is done
						sb.append(str + "\r\n");
						str = input.readLine();
					}
					str = sb.toString(); //string version of input
					request req = new request(); //makes request
					req.setInfo(str); //applies request info
					System.out.println(req); //prints out request system side for testing
					responce res = new responce(); //makes a responce class
					res.setInfo(req); //aplies responce info
					otpt.write(res.toString().getBytes()); //prepairs responce print
					otpt.write(res.Data);
					otpt.flush(); //sends over responce 
				}
			}
			catch (IOException e) {
				theServer.close();
				System.err.println(e);
			}			
		}
		catch (IOException e) {
			System.err.println(e);	
		}
	}
}

class request{ //request class
String method; //must be GET
String path; //Where the request is sent to
String version; //what http
String host; //who is sending the request
HashMap<Integer, String> headers = new HashMap<Integer, String>(); //the headers
Integer headerPos = 0; //where in the hashmap the header will be added
	
	public request(){ //genaric constructor
		method = "";
		path = "";
		version = "";
	}
	
	public void setInfo(String info){ //applies specific info
		String [] splitInfo = info.split("\\r?\\n"); //splits the request by lines
		firstLine(splitInfo[0]); //sends to parse the first line
		host = splitInfo[1]; //the second line will always be the host
		for (int i = 2; i<splitInfo.length; i++){ //used to take in the headers
			addHeader(splitInfo[i]);
			headerPos++;
		}
	}
		
	public void firstLine (String info){ //settin the data in the request 
		int index = 0; //will be used as the end of the substring
		int oldIndex = 0; //will be used as the beginning of the substring
		index = info.indexOf(" "); //searches for the space between the request and path
		setMethod(info.substring(0, index)); //applies that method
		index++; //moves ahead for the path
		oldIndex = index; //sets the new beginnign of the substring
		index = info.indexOf(" ", oldIndex); //finds the end of the path
		if (info.charAt(oldIndex) == '/')
			oldIndex++;
		setPath(info.substring(oldIndex, index)); //sets the path ignoring the first /
		index++; //increases the index
		version = info.substring(index, info.length()); //declairs what HTML is being used
	}
	
	public void setMethod(String met){ 
		method = met;}
		
	public String getMethod(){
		return method;}
		
	public void setPath(String Pa){
		path = Pa;}
		
	public String getPath(){
		return path;}
		
	public void addHeader (String head){
		headers.put(headerPos,head);}
		
	public String getHeader(String head){
		return headers.get(head);}
	
	public String printHeader (){ //print all headers
		String head = headers.get(0);
		for(Integer i=1; i < headers.size(); i++)
			head = head + "\n" + headers.get(i);
		return head;
	}
	
	public String toString () { //print out request
		return (method + " " + path + " " + version + "\n" + host + "\n" + 
			printHeader() + "\n\n");
	}
}

class responce { //responce class
String version; //verson of http
int code; //message code
String message; //message
HashMap<Integer, String> headers = new HashMap<Integer, String>(); //storage for headers
byte[] Data; //storage for the data
public static String webRoot = System.getProperty("user.dir") + "/html";
public static String defaultIndex = "index.html";

	public responce(){ //genaric constructor with error values for testing
		version = "ERROR";
		code = -1;
		message = "ERROR";
	}
	
	public void setInfo(request req){ //Used to set the info of the responce
		version = req.version; //pulls info from the request
		if (req.path.equals("")) //sets path for generic request
			req.path = defaultIndex;
		req.path = webRoot + "/" + req.path;
		setCode(req); //sends to check validity of request
		if (code == 200) //if the request is valid
			setHeaders(req); //ad the headers
	}

	public void setCode (request req){
		try{
			if (req.method.equals("GET")){
				byte[] file = encodeFile(req.path); //retrieves file
				if (file == null){ //if the file does not exist
					code = 404;
					message = "Error, file does not exist";
				}
				else{ //on a successful file retrieval
					Data = file;
					code = 200;
					message = "OK";
				}
			}
			else{ //if they try anything put a get request
				code = 400;
				message = "Bad Request";
			}
		}
		catch(Exception e){ //catch for any error
			code = 500;
			message = "Unexpected Error";
		}
	}
	
	public void setHeaders(request req){ //used to set half the headers
		Date today = new Date();
		headers.put(0, "Date: " + today.toString()); //ads the date and time
		String ext = req.path.substring(req.path.indexOf(".")+1, req.path.length()); //finds content type
		String type = contentType(ext); //send to find header based on content type
		headers.put(2, "Content-Type: " + type); //adds content type
		headers.put(4, "Server: WebServer"); //adds the webserver
	}
	
	public byte[] encodeFile(String filePath) throws IOException{ //method for finding file and adding headers dealing with it
		try{
			File file = new File(filePath); //creates the file
			FileInputStream fileInputStreamReader = new FileInputStream(file);
			byte[] bytes = new byte[(int)file.length()];
			fileInputStreamReader.read(bytes); //reads the file
			long lastMod = file.lastModified(); //find when the file was last modified
			Date date = new Date(lastMod); //converts to date for purpose of toString
			headers.put(1, "Last-Modified: " + date.toString()); //adds last modified to header
			headers.put(3, "Content-Length: " + bytes.length); //adds length to header
			return bytes; //returns the file
		}
		catch (FileNotFoundException e) { //If the file does not exist
			e.printStackTrace();
			return null;
		}
		catch (IOException e){ //on another error
			e.printStackTrace();
			return null;
		}
	}
	
	public String contentType (String type) { //finds the header based on thecontenty type
		if(type.equals("html") || type.equals("htm")) 
			return "text/html";
		else if(type.equals("jpg"))
			return "application/json";
		else if(type.equals("png"))
			return "application/png";
		else if(type.equals("css"))
			return "text/css";
		else
			return "Error, improper file type"; //on an unrecognized file type
	}
	public String hashToString (HashMap <Integer, String> in){ //used for printing hashmaps
		String temp = in.get(0);
		for(Integer i=1; i < in.size(); i++)
			temp = temp + "\n" + in.get(i);
		return temp;
	}
		
	public String getHeader(String head){
		return headers.get(head);}
	
	public String toString(){
		return version + " " + code + " " + message + "\n" + hashToString(headers) + "\n\n";
		}
		
	/*public byte[] getBytes (){
		byte[] otpt = new byte[toString().length()];
		//otpt = otpt + Data;
		return Data;
	}*/
}