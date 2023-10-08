class Calculator{
int s;
public int add(int x,int y) {
s=x+y;
return s;
}
public int sub(int x,int y) {
s=x-y;
return s;
}
}
public class test extends Calculator {
public static void main(String[] args) {
test cal=new test();
System.out.println(cal.add(3, 5));
}
}