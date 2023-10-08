package newPackage;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;

import java.awt.Color;
import java.awt.Container;

class MyFrameX extends JFrame {
    Container c;
    JButton btnSubmit = new JButton("Submit");
    JButton btnCancel = new JButton("Cancl");
    JLabel label1 = new JLabel();

    public MyFrameX() {
        c = this.getContentPane();
        c.setLayout(null);
        c.setBackground(Color.lightGray);
        btnSubmit.setBounds(100, 250, 130, 40);
        btnCancel.setBounds(250, 250, 130, 40);
        label1.setBounds(250, 250, 130, 40);
        c.add(btnSubmit);
        c.add(btnCancel);

    }
}

public class CSE3 {
    public static void main(String[] args) {
        MyFrameX frame = new MyFrameX();
        frame.setTitle("Login Form");
        frame.setBounds(200, 200, 500, 350);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setVisible(true);
    }
}