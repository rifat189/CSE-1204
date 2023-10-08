package newPackage;
class A {
    int x;

    public A() {
        x = 0;
    }

    public A(int x) {
        this.x = x;
    }

    public int getX() {
        return (x + 10);
    }
}

class B extends A {
    int x = 20;

    public int getX() {
        return (super.x + 10); // i) Display x of class A in class B
    }
    
    public int callGetXInA() {
        return super.getX(); // ii) Statement to call getX() of class A in class B
    }
    
    public B(int x) {
        super(x); // iii) Call parameterized constructor of class A in class B
    }
}

public class topic2 {
    public static void main(String[] args) {
        B objB = new B(30); // Creating an instance of class B
        System.out.println("x in class B: " + objB.x); // Display x in class B
        System.out.println("Result of getX in class B: " + objB.getX());
        System.out.println("Result of calling getX in class A from class B: " + objB.callGetXInA());
    }
}