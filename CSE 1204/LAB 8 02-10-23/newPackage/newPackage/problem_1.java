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

    void Display() {
        System.out.println("Inside A, x = " + x);
    }
}

class B extends A {
    int x = 20;

    public B() {
        super(200);
        System.out.println("Inside B constructor");
    }

    public int getX() {
        return (x + 10);
    }

    void Display() {
        super.Display();
        System.out.println("Inside B, x = " + x);
    }
}

public class problem_1 {
    public static void main(String[] args) {
        B b = new B();
        b.Display();
    }
}