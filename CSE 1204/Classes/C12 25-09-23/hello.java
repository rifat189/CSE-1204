abstract class A {
    int x;

    // public A() {
    // System.out.println("Inside Constructor of class A");
    // }

    // public A(int x) {
    // System.out.println("Inside constructor of class A = " + x);
    // }

    // public void Show() {
    // System.out.println("Inside Show of class A");
    // }
    abstract public void Show();
}

interface C {
    public void Show();
    // interface means all methods and classes inside any class are abstract
}
class D implements C{

    public void Show() {
       
    }

}
class B extends A {
    // public B(int x) {
    // super(x); //to call parent class
    // }

    public void Show() {
        System.out.println("Inside Show of class B");
        // super.Show();
    }
}

public class hello {
    public static void main(String[] args) {
        System.out.println("Welcome to CSE 1203");
        // B b = new B();
        // b.Show();
        D d = ;
        d.Show();
    }
}