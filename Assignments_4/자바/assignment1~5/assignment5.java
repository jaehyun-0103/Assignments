package assignment;

import java.util.Scanner;

public class assignment5 {
    public static void main(String[] args) {
        int i, j, row, column, n, cnt = 0;

        Scanner in = new Scanner(System.in);
        int M = in.nextInt(), N = in.nextInt();
        double P = in.nextDouble();
        String[][] boardC = new String[M][N];

        for (i = 0; i < M; i++)
            for (j = 0; j < N; j++)
                boardC[i][j] = "-";
        while (cnt <= (int) (M * N * P)) {
            boardC[(int) (Math.random() * M)][(int) (Math.random() * N)] = "*";
            cnt++;
        }
        for (i = 0; i < M; i++) {
            for (j = 0; j < N; j++)
                System.out.print(boardC[i][j]);
            System.out.println();
        }

        System.out.println();

        for (i = 0; i < M; i++) {
            for (j = 0; j < N; j++)
                switch (boardC[i][j]) {
                    case "*":
                        System.out.print(boardC[i][j]);
                        break;
                    default:
                        for (n = 0, row = (i > 0) ? i - 1 : 0; row <= i + 1 && row <= M - 1; row++)
                            for (column = (j > 0) ? j - 1 : 0; column <= j + 1 && column <= N - 1; column++)
                                if (boardC[row][column].equals("*"))
                                    n++;
                        System.out.print(n);
                        break;
                }
            System.out.println();
        }
    }
}
