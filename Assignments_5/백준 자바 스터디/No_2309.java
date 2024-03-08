import java.util.Scanner;

public class No_2309 {
    public static void main(String[] args) {
        int height = -1;
        int k = 1, i = 0, j = 0, sum = 0;
        int false1 = -1, false2 = -1, temp;
        int[] dwarf = new int[9];
        Scanner in = new Scanner(System.in);

        for (int a = 0; a < 9; a++) {
            height = in.nextInt();
            dwarf[a] = height;
            sum += height;
        }

        for (int b = 0; b < 9; b++)
            for (int c = 0; c < 9; c++) {
                if (dwarf[b] < dwarf[c]) {
                    temp = dwarf[b];
                    dwarf[b] = dwarf[c];
                    dwarf[c] = temp;
                }
            }

        for (i = 0; i < 8; i++) {
            for (j = k; j < 9; j++)
                if (dwarf[i] + dwarf[j] == (sum - 100)) {
                    false1 = i;
                    false2 = j;
                }
            k++;
        }

        for (int t = 0; t < 9; t++) {
            if (t == false1 || t == false2)
                continue;
            System.out.println(dwarf[t]);
        }
    }
}