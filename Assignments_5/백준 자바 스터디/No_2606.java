import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class No_2606 {
    static int M;
    static int N;
    static int[][] graph;
    static int[] visit;
    static int count = 0;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        M = Integer.parseInt(st.nextToken()); // 컴퓨터 수
        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken()); // 입력 횟수
        graph = new int[M + 1][M + 1];
        visit = new int[M + 1];

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            int a1 = Integer.parseInt(st.nextToken());
            int b1 = Integer.parseInt(st.nextToken());
            graph[a1][b1] = graph[b1][a1] = 1;
        }
        dfs(1);
        System.out.println(count - 1);
    }
    public static void dfs(int num) {
        count++;
        visit[num] = 1;
        for (int i = 1; i <= M; i++) {
            if (graph[num][i] == 1 && visit[i] == 0)
                dfs(i);
        }
    }
}