import java.math.BigInteger;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.util.Scanner;

class mymd5 {
    public static String getmd5(String input){
    try{
        MessageDigest md = MessageDigest.getInstance("MD5");

        byte[] arr = md.digest(input.getBytes());

        BigInteger num = new BigInteger(1,arr);

        String text = num.toString(16);
        while(text.length()<=32){
            text = "0"+text;
        }

        return text;
    }

    catch(NoSuchAlgorithmException e){
        throw new RuntimeException(e);
    }
}
    

    public static void main(String args[]) throws NoSuchAlgorithmException{
        Scanner sc = new Scanner(System.in);
        String mssg = sc.nextLine();
        // String mssg = "Hello";
        System.out.println("The hashed text is : " +getmd5(mssg));
    }
}
