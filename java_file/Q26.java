import java.sql.*;
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

class Q26 extends JFrame implements ActionListener
{
    JTextField tf1, tf2, tf3, tf4;
    Connection con = null;
    PreparedStatement st = null;
    ResultSet rs = null;

    public Q26()
    {
        tf1 = new JTextField(20);
        tf2 = new JTextField(20);
        tf3 = new JTextField(20);
        tf4 = new JTextField(20);
        JLabel l1 = new JLabel("Name");
        JLabel l2 = new JLabel("Code");
        JLabel l3 = new JLabel("Designation");
        JLabel l4 = new JLabel("Salary");
        JButton b1 = new JButton("Save");
        setLayout(new FlowLayout());
        add(l1);
        add(tf1);
        add(l2);
        add(tf2);
        add(l3);
        add(tf3);
        add(l4);
        add(tf4);
        add(b1);
        b1.addActionListener(this);

        try {
            // Update the connection string with your DB name, user, and password
            con = DriverManager.getConnection(
                    "jdbc:mysql://localhost:3306/ui", "root", "Apex_2407"
            );
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }
    }

    @Override
    public void actionPerformed(ActionEvent e)
    {
        try {
            // Use parameter placeholders for prepared statement
            st = con.prepareStatement("INSERT INTO employee(name, code, designation, salary) VALUES (?, ?, ?, ?)");
            st.setString(1, tf1.getText());
            st.setInt(2, Integer.parseInt(tf2.getText()));
            st.setString(3, tf3.getText());
            st.setInt(4, Integer.parseInt(tf4.getText()));
            st.executeUpdate();
        } catch (Exception ex) {
            JOptionPane.showMessageDialog(this, "Error: " + ex.getMessage());
        }
    }

    public static void main(String[] args) {
        Q26 db = new Q26();
        db.setSize(600, 800);
        db.setVisible(true);
        db.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }
}
