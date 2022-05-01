import java.util.*;
import java.net.*;
import java.io.*;

public class Request{

    String command;
    String room;
    int length;

    public Request(String c, String r, int l){
        setCommand(c);
        setRoom(r);
        setLength(l);
    }

    void setCommand(String command){
        this.command = command;
        //set the Command to JOIN, MOVE, SHOOT, or QUIT
    }

    void setRoom(String room){
        this.room = room;
        //set the target room value
    }
    
    void setLength(int length){
        this.length = length;
        //sets data length to 0
    }

    public String toString() {
        String methodLine = command +"|"+ room +"|"+ String.valueOf(length) + "\n";
        return methodLine;
    }
}