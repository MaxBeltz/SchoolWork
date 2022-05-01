import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.net.Socket;
import java.net.*;
import java.io.*;
import java.util.ArrayList; 
import java.util.Arrays; 
import java.util.HashMap;
import java.util.Map;
import java.util.Iterator;
import java.util.Set;
import java.util.Scanner; 



public class HttpClient { 

    public static void main(String[] args) throws IOException {
		request send = new request(); //creating the request
		//send.setInfo();
		send.requestEasy(); //used for testing
		String serverAddress = send.path;
		HashMap<Integer, String> answer = new HashMap<Integer, String>(); //HM for the responce
		try{
			System.out.println(send); //Show what the request looks like
			Socket s = new Socket(serverAddress, 80); //build socket
			BufferedWriter output = new BufferedWriter(new OutputStreamWriter(s.getOutputStream())); //build interactions
			output.write(send.toString());
			output.flush();
			BufferedReader input = new BufferedReader(new InputStreamReader(s.getInputStream()));
			int count = 0; //count ro read answer
			answer.put(count,input.readLine());
			while(answer.get(count) != null && count < 10){ //Janky reading
				count ++;
				answer.put(count,input.readLine());
			}
			s.close();
			responce recieve = new responce(); //Set up responce
			//recieve.parse(answer); //parse the answer into the responce
			System.out.println(recieve);//print out the respince
			//System.out.println(recieve.getHeader());
			//System.out.println(recieve.getData());
		}
		catch (UnknownHostException e) {
            System.err.println(e);
		}
        System.exit(0);
    }	
}

class request{ //request class
String method; //get or post
String path; //where the request is sent
String version; //what http
HashMap<Integer, String> headers = new HashMap<Integer, String>(); //the headers
String data; //data sent on the post
char add; //used to check if you want to add a header
int headerPos = 0; //where in the hashmap the header will be added
Scanner scan = new Scanner(System.in);
	
	public request(){ //genaric constructor
		method = "";
		path = "httpbin.org";
		version = "HTTP/1.1";
		headers.put(headerPos,"Accept: */*");
		headerPos++;
		headers.put(headerPos,"User-Agent: HttpClient");
		data = "";
	}
		
	public void setInfo (){ //settin the data in the request 
		System.out.println("GET or POST");
		String met = scan.nextLine();
		setMethod(met);
		data = setData(method);
		System.out.println("What is the server IP");
		String IP = scan.nextLine();
		setPath(IP);
		System.out.println("Add a header? (Y/N)");
		add = scan.nextLine().charAt(0);
		while(add == 'Y'){ //figure out why it is double printing
			headerPos++;
			System.out.println("What is the header?");
			String head = scan.nextLine();
			addHeader(head);
			System.out.println("Add a header? (Y/N)");
			add = scan.nextLine().charAt(0);
		}
	}
	
	public void setMethod(String met){ 
		method = met;}
		
	public void setPath(String IP){
		path = IP;}
		
	public String setData(String method){ //set data assuming a post request
		String data = "";
		if (method.equals("POST")){
			System.out.println("What is the content of your post");
			data = scan.nextLine();
			headers.put(headerPos, "Content-Length: " + data.length());
			headerPos++;
			headers.put(headerPos,"Content-Type: application/x-www-form-urlencoded");
			headerPos++;
		}
		return data;
	}
		
	public void addHeader (String head){
		headers.put(headerPos,head);}
	
	public String printHeader (){ //print all headers
		String head = headers.get(0);
		for(Integer i=1; i < headers.size(); i++)
			head = head + "\n" + headers.get(i);
		return head;
	}
	
	public void requestEasy(){ //easy generic request used for testing
		method = "GET";
		path = "www.butler.edu";
		version = "HTTP/1.1";
		data = "";
		addHeader("If-modified-since: Tue, 08 May 2018 17:02:01 GMT");
	}	
	
	public String toString () { //print out method 
		return (method + " /" + "cs435.html" + " " + version + "\nHost: " + path + "\n" + 
			printHeader() + "\n\n" + data);
	}
}

class responce{ //responce class
String version; //verson of http
String code; //message code
String message; //message
HashMap<Integer, String> headers = new HashMap<Integer, String>(); //storage for headers
HashMap<Integer, String> data = new HashMap<Integer, String>(); //storage for data
int headersCount = 1; //used for hashmap placement
int dataCount = 1; //used for hashmap placement

	public responce(){ //genaric constructor
		version = "ERROR";
		code = "ERROR";
		message = "ERROR";
	}

	public void parse (HashMap <Integer, String> inpt){ //used for getting information into specific responces
		String temp = inpt.get(0);
		int ver = temp.indexOf(" ");
		int co = temp.indexOf(" ", ver);
		version = temp.substring(0,ver);
		code = temp.substring(ver,co);
		message = temp.substring(co);
		while (inpt.get(headersCount).length() != 0){
			headers.put(headersCount,inpt.get(headersCount));
			headersCount++;
		}
		headersCount++;
		while (headersCount < inpt.size()){
			data.put(dataCount,inpt.get(headersCount));
			headersCount++;
			dataCount++;
		}
	}
	
	public String hashToString (HashMap <Integer, String> in){ //used fro printing hashmaps
		String temp = in.get(1);
		for(Integer i=2; i < in.size(); i++)
			temp = temp + "\n" + in.get(i);
		return temp;
	}
	
	public String getData(){
		return hashToString(data);}
		
	public String getHeader(String head){
		return headers.get(head);}
	
	public String toString(){
		return version + code + " " + message + "\n" + hashToString(headers) + "\n\n" + hashToString(data);}
}