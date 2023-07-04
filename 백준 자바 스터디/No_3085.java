import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class No_3085 {
    static char[][] arr;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int rMax, cMax;
        arr = new char[N][N];

        for (int i = 0; i < N; i++) {
            String S = br.readLine();
            for (int j = 0; j < N; j++)
                arr[i][j] = S.charAt(j);
        }

        rMax = rowSwap(N);
        cMax = columnSwap(N);
        if (rMax >= cMax)
            System.out.println(rMax);
        else
            System.out.println(cMax);
    }

    public static int rowSwap(int N) {
        char c;
        int max = 1, numR, numC;
        char[][] arr2 = new char[N][N];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N - 1; j++) {

                for (int k = 0; k < N; k++) {
                    arr2[k] = Arrays.copyOf(arr[k], N);
                }
                c = arr2[i][j];
                arr2[i][j] = arr2[i][j + 1];
                arr2[i][j + 1] = c;

                numR = rowCount(N, arr2);
                if (numR > max)
                    max = numR;
                numC = columnCount(N, arr2);
                if (numC > max)
                    max = numC;
            }
        }
        return max;
    }

    public static int columnSwap(int N) {
        char c;
        int max = 1, numR, numC;
        char[][] arr2 = new char[N][N];
        for (int i = 0; i < N - 1; i++) {
            for (int j = 0; j < N; j++) {

                for (int k = 0; k < N; k++) {
                    arr2[k] = Arrays.copyOf(arr[k], N);
                }

                c = arr2[i][j];
                arr2[i][j] = arr2[i + 1][j];
                arr2[i + 1][j] = c;

                numR = rowCount(N, arr2);
                if (numR > max)
                    max = numR;
                numC = columnCount(N, arr2);
                if (numC > max)
                    max = numC;
            }
        }
        return max;
    }

    public static int rowCount(int N, char[][] check) {
        int max = 1;
        for (int i = 0; i < N; i++) {
            int cnt = 1;
            for (int j = 0; j < N - 1; j++) {
                if (check[i][j] == check[i][j + 1]) {
                    cnt++;
                } else {
                    cnt = 1;
                }
                if (cnt > max) {
                    max = cnt;
                }
            }
        }
        return max;
    }

    public static int columnCount(int N, char[][] check) {
        int max = 1;
        for (int j = 0; j < N; j++) {
            int cnt = 1;
            for (int i = 0; i < N - 1; i++) {
                if (check[i][j] == check[i + 1][j]) {
                    cnt++;
                } else {
                    cnt = 1;
                }
                if (cnt > max) {
                    max = cnt;
                }
            }
        }
        return max;
    }
}