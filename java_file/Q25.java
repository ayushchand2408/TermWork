import javafx.application.Application;
import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.scene.Scene;
import javafx.scene.control.*;
import javafx.scene.layout.*;
import javafx.stage.Stage;

import java.util.HashMap;

public class Q25 extends Application {

    private ComboBox<String> movieComboBox;
    private ComboBox<String> showtimeComboBox;
    private Spinner<Integer> ticketSpinner;
    private Label totalCostLabel;

    private final HashMap<String, Integer> moviePrices = new HashMap<>();

    @Override
    public void start(Stage primaryStage) {
        // Movie and showtime prices
        moviePrices.put("Avengers: Endgame", 250);
        moviePrices.put("Inception", 200);
        moviePrices.put("Interstellar", 220);

        // UI Elements
        Label movieLabel = new Label("Select Movie:");
        movieComboBox = new ComboBox<>();
        movieComboBox.getItems().addAll(moviePrices.keySet());

        Label showtimeLabel = new Label("Select Showtime:");
        showtimeComboBox = new ComboBox<>();
        showtimeComboBox.getItems().addAll("10:00 AM", "1:00 PM", "4:00 PM", "7:00 PM");

        Label ticketLabel = new Label("Number of Tickets:");
        ticketSpinner = new Spinner<>(1, 10, 1);

        Button calculateButton = new Button("Calculate Total");
        totalCostLabel = new Label("Total: ₹0");

        Button confirmButton = new Button("Confirm Booking");
        Button resetButton = new Button("Reset");
        Button exitButton = new Button("Exit");

        // Layout
        GridPane grid = new GridPane();
        grid.setVgap(10);
        grid.setHgap(10);
        grid.setPadding(new Insets(20));
        grid.add(movieLabel, 0, 0);
        grid.add(movieComboBox, 1, 0);
        grid.add(showtimeLabel, 0, 1);
        grid.add(showtimeComboBox, 1, 1);
        grid.add(ticketLabel, 0, 2);
        grid.add(ticketSpinner, 1, 2);
        grid.add(calculateButton, 0, 3);
        grid.add(totalCostLabel, 1, 3);

        HBox buttonBox = new HBox(10, confirmButton, resetButton, exitButton);
        buttonBox.setAlignment(Pos.CENTER);

        VBox root = new VBox(15, grid, buttonBox);
        root.setAlignment(Pos.CENTER);
        root.setPadding(new Insets(20));

        // Logic
        calculateButton.setOnAction(e -> calculateTotal());
        confirmButton.setOnAction(e -> confirmBooking());
        resetButton.setOnAction(e -> resetFields());
        exitButton.setOnAction(e -> primaryStage.close());

        // Scene
        Scene scene = new Scene(root, 400, 300);
        primaryStage.setTitle("Movie Ticket Booking System");
        primaryStage.setScene(scene);
        primaryStage.show();
    }

    private void calculateTotal() {
        String selectedMovie = movieComboBox.getValue();
        Integer ticketCount = ticketSpinner.getValue();

        if (selectedMovie != null) {
            int price = moviePrices.get(selectedMovie);
            int total = price * ticketCount;
            totalCostLabel.setText("Total: ₹" + total);
        } else {
            showAlert(Alert.AlertType.WARNING, "Please select a movie.");
        }
    }

    private void confirmBooking() {
        String movie = movieComboBox.getValue();
        String showtime = showtimeComboBox.getValue();
        int tickets = ticketSpinner.getValue();

        if (movie != null && showtime != null) {
            showAlert(Alert.AlertType.INFORMATION, "Booking Confirmed!\nMovie: " + movie +
                    "\nShowtime: " + showtime + "\nTickets: " + tickets);
        } else {
            showAlert(Alert.AlertType.WARNING, "Please complete all selections.");
        }
    }

    private void resetFields() {
        movieComboBox.setValue(null);
        showtimeComboBox.setValue(null);
        ticketSpinner.getValueFactory().setValue(1);
        totalCostLabel.setText("Total: ₹0");
    }

    private void showAlert(Alert.AlertType type, String message) {
        Alert alert = new Alert(type);
        alert.setHeaderText(null);
        alert.setContentText(message);
        alert.showAndWait();
    }

    public static void main(String[] args) {
        launch(args);
    }
}
