import java.util.regex.Pattern;

public class Term_5 {
    public static boolean isValidIPv4(String ip) {
        String ipv4Pattern = "^([0-9]{1,3})\\.([0-9]{1,3})\\.([0-9]{1,3})\\.([0-9]{1,3})$";
        

        if (!Pattern.matches(ipv4Pattern, ip)) 
            return false;

        String[] octets = ip.split("\\.");

        for (String octet : octets) {
            int num = Integer.parseInt(octet);
            if (num < 0 || num > 255) 
                return false;
        }

        return true;
    }

    public static void main(String[] args) {
        String[] testIPs = {"128.0.0.1", "125.16.100.1", "125.512.100.1", "125.512.100.abc"};

        for (String ip : testIPs) {
            if (isValidIPv4(ip))
                System.out.println(ip + " -> Valid");
            else
                System.out.println(ip + " -> Not Valid");
        }
    }
}