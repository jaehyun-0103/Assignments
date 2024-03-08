package assignment;

import java.util.Scanner;

public class assignment1 {
    public static void main(String[] args) {
        int sum = 0;

        Scanner in = new Scanner(System.in);
        System.out.printf("0~999 사이의 숫자를 입력하세요 : ");
        int num = in.nextInt();

        while (num != 0) {
            sum += num % 10;
            num /= 10;
        }

        System.out.println("각 자릿수의 합 = " + sum);
    }
}