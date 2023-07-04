import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class No_11725 {
    static int N;
    static ArrayList<Integer> graph[];
    static int[] parent;
    static int[] visit;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        graph = new ArrayList[N + 1];
        parent = new int[N + 1];
        visit = new int[N + 1];

        for (int i = 0; i < N + 1; i++) {
            graph[i] = new ArrayList<>();
        }

        for (int i = 0; i < N - 1; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            graph[a].add(b);
            graph[b].add(a);
        }
        dfs(1);
        for (int i = 2; i < parent.length; i++)
            System.out.println(parent[i]);
    }
    public static void dfs(int num) {
        visit[num] = 1;
        for (int i : graph[num]) {
            if (visit[i] == 0) {
                parent[i] = num;
                dfs(i);
            }
        }
    }
}