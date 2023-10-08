class Person {
    String name = "Person";

    public void Display() {
        System.out.println(name);
    }
}

class Employee extends Person {
    String name = "Employee";

    public void Display() {
        super.Display();
        System.out.println(name);
    }
}

public class test2 {
    public static void main(String[] args) {
        Employee emp = new Employee();
        emp.Display();
    }
}