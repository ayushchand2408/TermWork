import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class SalaryCalculatorGUI extends JFrame {

    // Declare GUI components
    private JLabel nameLabel;
    private JTextField nameField;
    private JLabel codeLabel;
    private JTextField codeField;
    private JLabel designationLabel;
    private JTextField designationField;
    private JLabel salaryLabel;
    private JTextField salaryField;

    private JButton saveButton;
    private JButton resetButton;
    private JButton exitButton;

    public SalaryCalculatorGUI() {
        // Set the title of the JFrame
        super("Salary Calculator");

        // Set the default close operation (exit the application when closed)
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        // Set the size of the window
        setSize(400, 300);

        // Set the layout manager for the content pane.
        // Using GridBagLayout for more flexible component placement.
        setLayout(new GridBagLayout());
        GridBagConstraints gbc = new GridBagConstraints();
        gbc.insets = new Insets(5, 5, 5, 5); // Add padding around components

        // Initialize components
        nameLabel = new JLabel("NAME");
        nameField = new JTextField(20); // 20 columns wide

        codeLabel = new JLabel("CODE");
        codeField = new JTextField(20);

        designationLabel = new JLabel("DESIGNATION");
        designationField = new JTextField(20);

        salaryLabel = new JLabel("SALARY");
        salaryField = new JTextField(20);

        saveButton = new JButton("SAVE");
        resetButton = new JButton("RESET");
        exitButton = new JButton("EXIT");

        // Add components to the frame using GridBagLayout
        // Labels
        gbc.gridx = 0; // Column 0
        gbc.gridy = 0; // Row 0
        gbc.anchor = GridBagConstraints.WEST; // Align to the west (left)
        add(nameLabel, gbc);

        gbc.gridy = 1; // Row 1
        add(codeLabel, gbc);

        gbc.gridy = 2; // Row 2
        add(designationLabel, gbc);

        gbc.gridy = 3; // Row 3
        add(salaryLabel, gbc);

        // Text Fields
        gbc.gridx = 1; // Column 1
        gbc.gridy = 0; // Row 0
        gbc.fill = GridBagConstraints.HORIZONTAL; // Fill horizontally
        gbc.weightx = 1.0; // Give extra horizontal space to text fields
        add(nameField, gbc);

        gbc.gridy = 1; // Row 1
        add(codeField, gbc);

        gbc.gridy = 2; // Row 2
        add(designationField, gbc);

        gbc.gridy = 3; // Row 3
        add(salaryField, gbc);

        // Buttons
        // Reset constraints for buttons to be centered or grouped
        gbc.gridx = 0; // Start from column 0
        gbc.gridy = 4; // Row 4
        gbc.gridwidth = 2; // Span across two columns
        gbc.fill = GridBagConstraints.NONE; // Do not fill horizontally
        gbc.weightx = 0; // No extra horizontal space
        gbc.anchor = GridBagConstraints.CENTER; // Center the buttons group

        // Create a panel for buttons to group them
        JPanel buttonPanel = new JPanel(new FlowLayout(FlowLayout.CENTER, 10, 10)); // Center alignment, 10px gap
        buttonPanel.add(saveButton);
        buttonPanel.add(resetButton);
        buttonPanel.add(exitButton);
        add(buttonPanel, gbc);


        // Add Action Listeners to buttons
        saveButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                // Placeholder for SAVE action
                // In a real application, you would save the data from text fields
                String name = nameField.getText();
                String code = codeField.getText();
                String designation = designationField.getText();
                String salary = salaryField.getText();

                JOptionPane.showMessageDialog(SalaryCalculatorGUI.this,
                        "Saving Data:\n" +
                        "Name: " + name + "\n" +
                        "Code: " + code + "\n" +
                        "Designation: " + designation + "\n" +
                        "Salary: " + salary,
                        "Save Action",
                        JOptionPane.INFORMATION_MESSAGE);
            }
        });

        resetButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                // Placeholder for RESET action
                // Clears all text fields
                nameField.setText("");
                codeField.setText("");
                designationField.setText("");
                salaryField.setText("");
                JOptionPane.showMessageDialog(SalaryCalculatorGUI.this,
                        "All fields have been reset.",
                        "Reset Action",
                        JOptionPane.INFORMATION_MESSAGE);
            }
        });

        exitButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                // Placeholder for EXIT action
                // Exits the application
                System.exit(0);
            }
        });

        // Make the window visible
        setVisible(true);

        // Center the window on the screen
        setLocationRelativeTo(null);
    }

    public static void main(String[] args) {
        // Run the GUI creation on the Event Dispatch Thread (EDT)
        // This is crucial for Swing applications to ensure thread safety
        SwingUtilities.invokeLater(new Runnable() {
            @Override
            public void run() {
                new SalaryCalculatorGUI();
            }
        });
    }
}
