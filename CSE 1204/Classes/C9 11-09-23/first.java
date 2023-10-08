import java.util.Scanner;
public class first  
{  
public static void main(String args[])   
{  
    System.out.println("Welcome to CSE 1203");
    System.out.println("Welcome to Java");
    int x;

    String s;
    Scanner input = new Scanner(System.in);
    System.out.println("Enter your name: ");
    s=input.nextLine();
    x=(s).length();
    System.out.println("Your name is "+x+" characters long");
}  
}  

