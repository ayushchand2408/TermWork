package p1;

public class class1 {
    // Instance method to convert Celsius to Fahrenheit
    public float celToFah(float celsius) {
        return (celsius * 9 / 5) + 32;
    }

    // Static method to convert Fahrenheit to Celsius
    public static float fahToCel(float fahrenheit) {
        return (fahrenheit - 32) * 5 / 9;
    }
}