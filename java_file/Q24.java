import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

class Q24 extends JFrame implements ActionListener{
    JTextField tf1,tf2;
    int count=0;

    public Q24(){
        JLabel l1=new JLabel("Enter String: ");
        tf1=new JTextField(20);
        JButton jb1=new JButton("COUNT VOWEL");
        JButton jb2=new JButton("RESET");
        JButton jb3=new JButton("EXIT");
        JLabel l2=new JLabel("Result: ");
        tf2=new JTextField(20);
        setLayout(new FlowLayout(FlowLayout.CENTER,30,10));

        add(l1);
        add(tf1);
        add(jb1);
        add(jb2);
        add(jb3);
        add(l2);
        add(tf2);
        jb1.addActionListener(this);
        jb2.addActionListener(this);
        jb3.addActionListener(this);
    }

    public void actionPerformed(ActionEvent e){
        String s=e.getActionCommand();
        String str=tf1.getText();

        if(s.equals("EXIT")){
            System.exit(0);
        }

        else if (s.equals("RESET")) {
            count=0;
            tf1.setText("");
            tf2.setText("");
        }

        else{
            for(int i=0;i<str.length();i++){
                char ch=str.charAt(i);
                ch=Character.toLowerCase(ch);
                if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u'){
                    count++;
                }
            }

            tf2.setText(String.valueOf(count));
        }
    }

    public static void main(String args[]) {
        Q24 d = new Q24();
        d.setSize(400, 300);
        d.setVisible(true);
        
    }
}
