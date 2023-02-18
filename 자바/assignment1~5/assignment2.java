package assignment;

public class assignment2 {
    public static void main(String[] args) {
        int a, b, c;
        for (a = 1; a < 10; a++)
            for (b = 1; b < 10; b++)
                for (c = 1; c < 10; c++) {
                    if ((a * a + b * b == c * c) && (a + b + c <= 20))
                        System.out.printf("(%d, %d, %d)\n", a, b, c);
                }
    }
}
