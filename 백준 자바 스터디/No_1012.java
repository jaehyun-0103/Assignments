import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class No_1012 {
    static int M, N, K; // 가로, 세로, 배수의 수
    static int[][] cabbage; // 양배추가 있는 위치를 나타낸 2차원 배열
    static boolean[][] visit; // 방문한 위치를 나타낼 2차원 배열
    static int count;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());

        for (int i = 0; i < T; i++) {
            count = 0;
            StringTokenizer st = new StringTokenizer(br.readLine(), " ");
            M = Integer.parseInt(st.nextToken());
            N = Integer.parseInt(st.nextToken());
            K = Integer.parseInt(st.nextToken());
            cabbage = new int[M][N];
            visit = new boolean[M][N];

            for (int j = 0; j < K; j++) {
                st = new StringTokenizer(br.readLine(), " ");
                int p1 = Integer.parseInt(st.nextToken());
                int p2 = Integer.parseInt(st.nextToken());
                cabbage[p1][p2] = 1;
            }

            for (int m = 0; m < M; m++)
                for (int n = 0; n < N; n++)
                    if (cabbage[m][n] == 1 && !visit[m][n]) {
                        bfs(m, n);
                        count++;
                    }
            System.out.println(count);
        }
    }

    // bfs
    static void bfs(int x, int y) {
        Queue<int[]> que = new LinkedList<int[]>();

        que.add(new int[]{x, y});
        visit[x][y] = true;

        while (!que.isEmpty()) {
            x = que.peek()[0];
            y = que.peek()[1];
            que.poll();

            // 상하좌우 확인
            for (int i = 0; i < 4; i++) {
                int pointX = x, pointY = y;
                if (i == 0) pointX += 1;
                else if (i == 1) pointY += 1;
                else if (i == 2) pointX -= 1;
                else pointY -= 1;

                if (pointX >= 0 && pointY >= 0 && pointX < M && pointY < N)
                    if (!visit[pointX][pointY] && cabbage[pointX][pointY] == 1) {
                        que.add(new int[]{pointX, pointY});
                        visit[pointX][pointY] = true;
                    }
            }
        }
    }
}