package assignment;

import java.io.*;

public class assignment17 {
    public static void main(String[] args) {
        String input = "D:\\Temp\\double.txt";
        try (DataOutputStream dos = new DataOutputStream(new FileOutputStream(input));
             DataInputStream dis = new DataInputStream(new FileInputStream(input));) {

            dos.writeDouble(1.1);
            dos.writeDouble(2.2);
            dos.writeDouble(3.3);
            dos.writeDouble(4.4);
            dos.writeDouble(5.5);

            //dos.flush();

            for (int i = 0; i < 5; i++)
                System.out.println(dis.readDouble());
        } catch (IOException e) {
        }
    }
}
