package javaNewPackage;

import javax.swing.ImageIcon;
import javax.swing.JFrame;
import javax.swing.JLabel;
import java.awt.Color;
import java.awt.Container;
import java.awt.Font;
import java.awt.Graphics;

class MyFrameCSE extends JFrame {
    JLabel label1 = new JLabel();
    Container c;
    Font fn = new Font("Arial", Font.BOLD, 20);
    Color color = new Color(14, 233, 142);

    public MyFrameCSE() {
        c = this.getContentPane();
        c.setLayout(null);
        label1.setBounds(100, 50, 500, 30);
        label1.setText("Welcome to Java Label");
        label1.setFont(fn);
        label1.setForeground(color);
        c.add(label1);
    }

    public void paint(Graphics g) {
        // g.drawRect(100, 50, 200, 60);
        g.setColor(new Color(12, 12, 12));
        g.fillOval(180, 230, 80, 80);
    }
}

public class CSE21A extends JFrame {
    public static void main(String[] args) {
        System.out.println("Welcome to GUI in java");
        MyFrameCSE f = new MyFrameCSE();
        ImageIcon image = new ImageIcon("logo.png");
        f.setIconImage(image.getImage());
        f.setTitle("CSE 1203 Class");
        f.setVisible(true);
        f.setBounds(500, 100, 300, 450);
        // f.setBackground(new Color(12, 12, 12));
        // f.setSize(300, 400);
        f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }
}