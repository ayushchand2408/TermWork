import javax.swing.*; 
import java.awt.*; 
public class practice { 
public static void main(String[] args) { 
JFrame frame = new JFrame("Simple JPanel Example"); 
JPanel panel = new JPanel();  // default layout = FlowLayout 
JLabel label = new JLabel("Welcome to JPanel!"); 
JButton button = new JButton("Click Me"); 
panel.add(label); 
panel.add(button); 
frame.add(panel); 
frame.setSize(300, 150); 
frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE); 
frame.setVisible(true); 
} 
}