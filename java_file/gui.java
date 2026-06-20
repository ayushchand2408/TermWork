import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class gui extends JFrame implements ActionListener {
    JTextField tf1,tf2,tf3,tf4;
    JButton b1,b2 ,b3;
    public gui() {
        tf1 = new JTextField(20);
        tf2 = new JTextField(20);
        tf3 = new JTextField(20);

        JLabel l1 = new JLabel("First Number");
        JLabel l2 = new JLabel("Second Number");
        JLabel l3 = new JLabel("Result");
        
        b1 = new JButton("Sum");
        b2 = new JButton("Sub");
        b3 = new JButton("Concate");

        setLayout(new FlowLayout(FlowLayout.CENTER,20,10));
        add(l1);
        add(tf1);
        add(l2);
        add(tf2);
        add(l3);
        add(tf3);
        
        add(b1);
        add(b2);
        add(b3);
        b1.addActionListener(this);
        b2.addActionListener(this);
        b3.addActionListener(this);


        
    }

    public void actionPerformed(ActionEvent e){
        
        int a = Integer.parseInt(tf1.getText()); 
        int b = Integer.parseInt(tf2.getText());

        if (e.getSource() == b1) { 
            tf3.setText(String.valueOf(a + b)); 
        } else if (e.getSource() == b2) { 
            tf3.setText(String.valueOf(a - b)); 
        }
        else if(e.getSource() == b3){
            tf3.setText(tf1.getText()+tf2.getText());
        }
       

    }
    public static void main(String[] args) {
        gui d  =new gui(); 
        d.setSize(300, 400);
        d.setVisible(true);
    }
}