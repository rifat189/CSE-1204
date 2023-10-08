package newPackage;
import java.util.Random;
import javax.swing.JFrame;
class testing extends JFrame {

}

public class test {
    public static void main(String[] args) {
        Random rand = new Random();
        int int_random1 = rand.nextInt(25);
        int int_random2 = rand.nextInt(100);
        System.out.println(int_random1 + "+" + int_random2 + " = " + (int_random1 + int_random2));
    }
}
