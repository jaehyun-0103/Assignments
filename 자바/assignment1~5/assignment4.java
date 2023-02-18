package assignment;

import java.util.Scanner;

public class assignment4 {
    public static void main(String[] args) {
        int num[] = new int[10];
        String histo[] = {"", "", "", "", "", "", "", "", "", ""};
        int cnt = 0;
        System.out.println("숫자를 10개 입력하세요.");
        while (cnt != 10) {
            Scanner in = new Scanner(System.in);
            num[cnt] = in.nextInt();
            cnt++;
        }
        for (int i = 0; i < 10; i++) {
            if (num[i] >= 0 && num[i] < 10)
                histo[0] += "*";
            else if (num[i] >= 10 && num[i] < 20)
                histo[1] += "*";
            else if (num[i] >= 20 && num[i] < 30)
                histo[2] += "*";
            else if (num[i] >= 30 && num[i] < 40)
                histo[3] += "*";
            else if (num[i] >= 40 && num[i] < 50)
                histo[4] += "*";
            else if (num[i] >= 50 && num[i] < 60)
                histo[5] += "*";
            else if (num[i] >= 60 && num[i] < 70)
                histo[6] += "*";
            else if (num[i] >= 70 && num[i] < 80)
                histo[7] += "*";
            else if (num[i] >= 80 && num[i] < 90)
                histo[8] += "*";
            else if (num[i] >= 90 && num[i] < 100)
                histo[9] += "*";
        }
        for (int j = 0; j < 10; j++) {
            System.out.print((j * 10) + "~" + (j * 10 + 9) + ":");
            System.out.println(histo[j]);
        }
    }
}