import java.util.Arrays;

public class Term_9 {
    public static int findMinPlatforms(int[] arr, int[] dep) {
        Arrays.sort(arr);
        Arrays.sort(dep);

        int platformNeeded = 0, maxPlatforms = 0;
        int i = 0, j = 0, n = arr.length;

        while (i < n && j < n) {
            if (arr[i] <= dep[j]) {
                platformNeeded++;
                i++;
            } else {
                platformNeeded--;
                j++;
            }
            maxPlatforms = Math.max(maxPlatforms, platformNeeded);
        }

        return maxPlatforms;
    }

    public static void main(String[] args) {
        int[] arr1 = {900, 940, 950, 1100, 1500, 1800};
        int[] dep1 = {910, 1200, 1120, 1130, 1900, 2000};
        System.out.println("Minimum platforms needed: " + findMinPlatforms(arr1, dep1));

        int[] arr2 = {900, 940};
        int[] dep2 = {910, 1200};
        System.out.println("Minimum platforms needed: " + findMinPlatforms(arr2, dep2));
    }
}