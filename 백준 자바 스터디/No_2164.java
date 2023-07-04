import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class No_2164 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int [] arr = new int[2*N+1];
        int top=1, rear=N;

        for(int i=0;i<=N;i++)
            arr[i]=i;

        for(int i=0;i<N-1;i++) {
            top++;
            arr[rear+1]=arr[top];
            top++;
            rear++;
            if(top==rear)
                break;
        }
        System.out.println(arr[top]);
    }
}