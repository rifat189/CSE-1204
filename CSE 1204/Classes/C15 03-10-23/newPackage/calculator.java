package newPackage;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;

import java.awt.Color;
import java.awt.Container;
import java.awt.Font;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.beans.IntrospectionException;

class MyFormCalculator extends JFrame implements ActionListener {

    Container c;
    Font fn1 = new Font("Courier", Font.BOLD, 18);
    JLabel labelDisplay = new JLabel("Display");
    JButton btn[] = new JButton[16];
    int row, col;
    String str1 = "", str2, op;

    MyFormCalculator() {
        c = this.getContentPane();
        c.setLayout(null);
        c.setBackground(Color.darkGray);
        // set the properties of the objects
        labelDisplay.setBounds(15, 7, 235, 50);
        labelDisplay.setForeground(Color.black);
        labelDisplay.setBackground(Color.lightGray);
        labelDisplay.setOpaque(true);
        labelDisplay.setHorizontalAlignment(JLabel.RIGHT);
        labelDisplay.setFont(fn1);
        // create buttons 1-9
        row = 1;
        col = 1;
        for (int i = 1; i <= 9; i++) {
            btn[i] = new JButton(Integer.toString(i));
            btn[i].setBounds(15 + (col - 1) * 60, 80 + (row - 1) * 60, 55, 55);
            c.add(btn[i]);
            btn[i].addActionListener(this);
            col++;
            if (col > 3) {
                row++;
                col = 1;
            }
        }
        // for 0 button
        row = 4;
        col = 1;
        int i = 0;
        btn[i] = new JButton(Integer.toString(i));
        btn[i].addActionListener(this);
        btn[i].setBounds(15 + (col - 1) * 60, 80 + (row - 1) * 60, 55, 55);
        c.add(btn[i]);

        // for = button
        row = 4;
        col = 2;
        i = 10;
        btn[i] = new JButton("=");
        btn[i].setBackground(Color.yellow);
        btn[i].addActionListener(this);
        btn[i].setBounds(15 + (col - 1) * 60, 80 + (row - 1) * 60, 55, 55);
        c.add(btn[i]);

        // for + button
        row = 4;
        col = 3;
        i = 11;
        btn[i] = new JButton("+");
        btn[i].setBackground(Color.green);
        btn[i].addActionListener(this);
        btn[i].setBounds(15 + (col - 1) * 60, 80 + (row - 1) * 60, 55, 55);
        c.add(btn[i]);

        // for - button
        row = 4;
        col = 4;
        i = 12;
        btn[i] = new JButton("-");
        btn[i].setBackground(Color.green);
        btn[i].addActionListener(this);
        btn[i].setBounds(15 + (col - 1) * 60, 80 + (row - 1) * 60, 55, 55);
        c.add(btn[i]);

        // for / button
        row = 3;
        col = 4;
        i = 13;
        btn[i] = new JButton("/");
        btn[i].setBackground(Color.green);
        btn[i].addActionListener(this);
        btn[i].setBounds(15 + (col - 1) * 60, 80 + (row - 1) * 60, 55, 55);
        c.add(btn[i]);

        // for * button
        row = 2;
        col = 4;
        i = 14;
        btn[i] = new JButton("*");
        btn[i].setBackground(Color.green);
        btn[i].addActionListener(this);
        btn[i].setBounds(15 + (col - 1) * 60, 80 + (row - 1) * 60, 55, 55);
        c.add(btn[i]);

        // for c button
        row = 1;
        col = 4;
        i = 15;
        btn[i] = new JButton("c");
        btn[i].setBackground(Color.red);
        btn[i].setBounds(15 + (col - 1) * 60, 80 + (row - 1) * 60, 55, 55);
        c.add(btn[i]);

        // add objects to the container
        c.add(labelDisplay);
    }

    public void actionPerformed(ActionEvent e) {
        // for equal btn
        if (e.getSource() == btn[10]) {
            int result = 0;
            int x = Interger.parseInt(str2);
            int y = Integer.parseInt(str1);
            switch (op) {
                case "+":
                    result = x + y;
                    break;
                case "-":
                    result = x - y;
                    break;
                case "/":
                    result = x / y;
                    break;
                case "*":
                    result = x * y;
                    break;
            }
            labelDisplay.setText(Integer.toString(result));
            str1="";
            str2="";
        }
        for (int i = 0; i <= 9; i++) {
            if (e.getSource() == btn[i]) {
                str1 = str1 + Integer.toString(i);
                labelDisplay.setText(str1);
            }
        } // end of digit loop

        // for operator buttons
        for (int i = 11; i <= 14; i++) {
            if (e.getSource() == btn[i]) {
                switch (i) {
                    case 11:
                        op = "+";
                        break;
                    case 12:
                        op = "-";
                        break;
                    case 13:
                        op = "/";
                        break;
                    case 14:
                        op = "*";
                        break;

                }
                str2 = str1;
                str1 = "";
                labelDisplay.setText(op);
            }
        }
    }

}

public class calculator {
    public static void main(String[] args) {
        MyFormCalculator frame = new MyFormCalculator();
        frame.setBounds(200, 100, 280, 400);
        frame.setVisible(true);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setTitle("My Calculator");
    }
}