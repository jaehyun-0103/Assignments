import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class No_2630 {
    static int white = 0;
    static int blue = 0;
    static int[][] arr;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        arr = new int[N][N];

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine(), " ");
            for (int j = 0; j < N; j++) {
                arr[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        partition(0, 0, N);
        System.out.println(white);
        System.out.println(blue);
    }

    static void partition(int row, int col, int size) {
        if (check(row, col, size) == 'o') {
            if (arr[row][col] == 0) {
                white++;
            } else {
                blue++;
            }
            return;
        }

        int half = size / 2;
        partition(row, col, half);
        partition(row, col + half, half);
        partition(row + half, col, half);
        partition(row + half, col + half, half);
    }

    static char check(int row, int col, int num) {
        int color = arr[row][col];
        for (int i = row; i < num + row; i++) {
            for (int j = col; j < col + num; j++) {
                if (arr[i][j] != color)
                    return 'x';
            }
        }
        return 'o';
    }
}