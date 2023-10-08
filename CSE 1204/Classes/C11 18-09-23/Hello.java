import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;

class A {

}

class B extends A {

}

public class Hello extends B {
    public static void main(String[] args) {
        System.out.println("Welcome to cse 1203");
        int[] ax = { 10, 20, 9, 90, 50 };
        System.out.println("ax[] = " + Arrays.toString(ax));
        Arrays.sort(ax);
        System.out.println("ax[] = " + Arrays.toString(ax));
        ArrayList<String> fruit = new ArrayList<>();
        fruit.add("Apple");
        fruit.add("Orange");
        fruit.add("Jackfruit");
        fruit.add("Guava");

        System.out.println(fruit);
        System.out.println(fruit.get(0));
        fruit.set(0, "Banana");
        System.out.println(fruit);
        boolean i = fruit.contains("Orange");
        if (i) {
            System.out.println("Fruit found");
        } else {
            System.out.println("Not found");
        }
        fruit.remove("Orange");
        System.out.println(fruit);
        Collections.sort(fruit);
        System.out.println(fruit);
        fruit.clear();
        System.out.println(fruit);
    }
}