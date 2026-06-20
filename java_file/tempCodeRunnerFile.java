import java.io.File;
import java.io.IOException;
import javax.imageio.ImageIO;
import java.awt.image.BufferedImage;
import java.awt.Graphics2D;

public class Assignment_3_Q1 {
    public static void main(String[] args) {
        try {
            File inputFile = new File("C:\\Users\\ayush\\OneDrive\\Documents\\Desktop\\java.file\\OIP.jpg");

            if (!inputFile.exists()) {
                System.out.println("File not found: " + inputFile.getAbsolutePath());
                return;
            }

            BufferedImage originalImage = ImageIO.read(inputFile);

            if (originalImage == null) {
                System.out.println("ImageIO could not read the image. It might be corrupted or in an unsupported format.");
                return;
            }

            System.out.println("Image read successfully: " + inputFile.getName());

            BufferedImage rgbImage = new BufferedImage(
                originalImage.getWidth(),
                originalImage.getHeight(),
                BufferedImage.TYPE_INT_RGB
            );

            Graphics2D g = rgbImage.createGraphics();
            g.drawImage(originalImage, 0, 0, null);
            g.dispose();

            File outputFile = new File("C:\\Users\\ayush\\OneDrive\\Documents\\Desktop\\java.file\\input.jpg");
            boolean success = ImageIO.write(rgbImage, "jpg", outputFile);

            if (success) {
                System.out.println("Image written successfully to: " + outputFile.getName());
            } else {
                System.out.println("Image writing failed. Format might not be supported.");
            }

        } catch (IOException e) {
            System.out.println("IOException: " + e.getMessage());
        }
    }
}
