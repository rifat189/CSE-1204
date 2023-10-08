package newPackage;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPasswordField;
import javax.swing.JTextField;

import java.awt.Color;
import java.awt.Container;
import java.awt.Font;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

class MyFrameX extends JFrame implements ActionListener {
    Container c;
    Font fn = new Font("Arial", Font.BOLD, 14);
    JLabel labelLogin = new JLabel("Login");
    JTextField textLogin = new JTextField();
    JLabel labelPassword = new JLabel("Password");
    JPasswordField textPassword = new JPasswordField();
    JButton btnSubmit = new JButton("Submit");
    JButton btnRefresh = new JButton("Refresh");
    JLabel labelDisplay = new JLabel("Display Board");
    String myLogin = "admin";
    String myPassword = "cse";

    public MyFrameX() {
        c = this.getContentPane();
        c.setLayout(null);
        c.setBackground(Color.lightGray);
        // adding properties to the objects
        labelLogin.setBounds(150, 50, 220, 35);
        labelLogin.setFont(fn);
        textLogin.setBounds(230, 50, 220, 35);
        textLogin.setFont(fn);
        labelPassword.setBounds(150, 100, 220, 35);
        labelPassword.setFont(fn);
        textPassword.setBounds(230, 100, 220, 35);
        textPassword.setFont(fn);
        btnSubmit.setBounds(230, 150, 100, 40);
        btnRefresh.setBounds(335, 150, 100, 40);
        labelDisplay.setBounds(230, 200, 400, 40);
        // btnSubmit.setForeground(Color.BLUE);
        // btnSubmit.setBackground(Color.YELLOW);
        // btnRefresh.setForeground(Color.BLACK);
        // btnRefresh.setBackground(Color.YELLOW);

        // adding objects to the container
        c.add(labelLogin);
        c.add(textLogin);
        c.add(labelPassword);
        c.add(textPassword);
        c.add(btnSubmit);
        c.add(btnRefresh);
        c.add(labelDisplay);

        btnSubmit.addActionListener(this);
        btnRefresh.addActionListener(this);

    }

    // @Override
    public void actionPerformed(ActionEvent e) {
        if (e.getSource() == btnRefresh) {
            textLogin.setText("");
            textPassword.setText("");
            labelDisplay.setText("Enter login and password");
        }
        if (e.getSource() == btnSubmit) {
            // labelDisplay.setText("myLogin");
            String inputLogin = textLogin.getText();
            String inputPassword = String.copyValueOf(textPassword.getPassword());
            if ((inputLogin.equals(myLogin)) && (inputPassword.equals(myPassword)))
                labelDisplay.setText("Login successful");
            else
                labelDisplay.setText("Not Successful");
        }
    }

}

public class CSELAB {
    public static void main(String[] args) {
        MyFrameX frame = new MyFrameX();
        frame.setTitle("Login Form");
        frame.setBounds(200, 200, 500, 350);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setVisible(true);
    }
}