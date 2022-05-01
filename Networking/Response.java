import java.util.*;
import java.net.*;
import java.io.*;

public class Response{

    int code;
    String adjacent;
    int byteLength;
    String data;

    public Response(String r){
        String [] parts = r.split("\\|");
        code = Integer.parseInt(parts[0]);
        adjacent = parts[1];
        byteLength = Integer.parseInt(parts[2]);
    }

    void setData(String d){
        data = d;
    }

    Integer getLength(){
        return byteLength;
    }

    public String toString(){
        //String out = String.valueOf(code) +"|"+ adjacent +"|"+ String.valueOf(byteLength) + "\n";
        //out += data;
        //out += "\n";
		String out = data + "\n";

        return out;
    }

}