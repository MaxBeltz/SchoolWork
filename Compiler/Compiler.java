import java.io.*;
import java.util.*;
import java.lang.Math;

class Compiler 
{
  public static double count = 16;
  public static ArrayList<String> access=new ArrayList<String>();
  public static ArrayList<Double> bionary=new ArrayList<Double>(); 
  
  public static void Conversion(String nextLine, String[][] compList, String[][] destList, String[][] jumpList, PrintWriter print)
  {
    int i = 0;
    String command = "";
    if(nextLine.equals(""))
       return;
    while(nextLine.charAt(i) == ' ')
      i++;
    if(nextLine.charAt(i) == '/' || nextLine.charAt(i) == '(')
         return;
    if(nextLine.charAt(i) == '@')
    {
      String location = "";
      int locint = -1;
      i++;
      while(i<nextLine.length())
       {
         location = location+nextLine.charAt(i);
         i++;
       }
      try
      {
        if (location.charAt(0) == 'R')
        {
          double test = (double)Integer.parseInt(location.substring(1,location.length()));
          print.print("0");
          Specificbion(test, print);
        }
        else
        {
          double test = (double)Integer.parseInt(location);
          print.print("0");
          Specificbion(test, print);
        }
      }      
      catch (NumberFormatException e){
        Protocal(location, print);}
      return;
    }
    else{
      while(nextLine.charAt(i) != '=' && nextLine.charAt(i) != ';'){
        command = command + nextLine.charAt(i);
        i++;}
      if(nextLine.charAt(i) == ';')
      {
        print.print("111");
        Comp(command, compList, print);
        Dest("null", destList, print);
        String jump = "";
        jump = (nextLine.charAt(i+1) + "" + nextLine.charAt(i+2) + nextLine.charAt(i+3));
        Jump(jump, jumpList, print);
      }
      else if(nextLine.charAt(i) == '=')
      {
        print.print("111");
        String comp = "";
        i++;
        while(i<nextLine.length() && nextLine.charAt(i) != ' ' && nextLine.charAt(i) != '/')
        {
          comp = comp+nextLine.charAt(i);
          i++;
        }
        Comp(comp, compList, print);
        Dest(command,destList, print);
        Jump("null", jumpList, print);
      }
    }
  }
  
  public static void Checkjump(String file, PrintWriter print) throws IOException
  {
    Scanner check = new Scanner(new FileReader(file));
    String store = "";
    int i = 0;
    double line = 0;
    while(check.hasNextLine())
    {
      line++;
      i = 0;
      store = "";
      String nextLine = check.nextLine();
       if(nextLine.equals(""))
          line--;
       else if (nextLine.charAt(0) == '/')
          line--;
       else
       {
         while(nextLine.charAt(i) == ' ')
           i++;
         if(nextLine.charAt(i) == '(')
         {
           line--;
           i++;
           while(nextLine.charAt(i) != ')')
           {
             store = (store + nextLine.charAt(i));
             i++;
           }
           access.add(store);
           bionary.add(line);
         }
       }
    }
  }
                               
  public static void Protocal(String location, PrintWriter print)
  {
    print.print("0");
    Double num = CheckA(location, print);
    Specificbion(num, print);
  }
  
  public static Double CheckA(String location, PrintWriter print)
  {
    for(int i = 0; i<access.size(); i++)
    {
      if(access.indexOf(location) != -1)
        return bionary.get(access.indexOf(location));
    }
     access.add(location);
     bionary.add(count);
     count++;
     return bionary.get(bionary.size()-1);
  }
  
  public static void Specificbion(Double num, PrintWriter print)
  {
    double working = (double)num;
    for(int i=14; i>=0; i--)
    {
      if(working >= Math.pow(2,i))
      {
        print.print("1");
        working = (working-Math.pow(2,i));
      }
      else
        print.print("0");
    }
    print.println("");
  }
  
  public static void Comp(String comp, String[][] list, PrintWriter print)
  {
    for (int i=0; i<28; i++){
      if (comp.equals(list[i][0]))
            print.print(list[i][1]);
          }
  }
  
  public static void Dest(String dest, String[][] list, PrintWriter print)
  {
     for (int i=0; i<8; i++){
      if (dest.equals(list[i][0]))
            print.print(list[i][1]);
          }
  }
  
   public static void Jump(String jump, String[][] list, PrintWriter print)
  {
     for (int i=0; i<7; i++){
      if (jump.equals(list[i][0]))
            print.println(list[i][1]);
          }
  }
   
   public static void StandardVar()
   {
    access.add("SCREEN");
    bionary.add(16384.0);
    access.add("SP");
    bionary.add(0.0);
   }
   
  
  public static void main(String [] args) throws IOException{
    StandardVar();
    PrintWriter print = new PrintWriter(new FileWriter("Bionary.txt"));
    Scanner scan = new Scanner(System.in);
    String [][] action = new String[28][2];
    Scanner actionFile = new Scanner(new FileReader("Action.txt"));
    for(int i=0; i<28; i++)
    {
      action[i][0] = actionFile.nextLine();
      action[i][1] = actionFile.nextLine();
    }
    String [][] dest = new String[8][2];
    Scanner destFile = new Scanner(new FileReader("Dest.txt"));
    for(int i=0; i<8; i++)
    {
      dest[i][0] = destFile.nextLine();
      dest[i][1] = destFile.nextLine();
    }
    String [][] jump = new String[7][2];
    Scanner jumpFile = new Scanner(new FileReader("Jump.txt"));
    for(int i=0; i<7; i++)
    {
      jump[i][0] = jumpFile.nextLine();
      jump[i][1] = jumpFile.nextLine();
    }
    System.out.println("What file are you reading");
    String file = scan.nextLine();
    Scanner read = new Scanner(new FileReader(file));
    Checkjump(file, print);
    while(read.hasNextLine())
    {
      String input = read.nextLine();
      Conversion(input, action, dest, jump, print);
    }
    print.close();
  }
}
  