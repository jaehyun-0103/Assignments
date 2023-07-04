import java.util.Scanner;

public class No_1789 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        long S = in.nextLong();
        long T = 0, res = 0;

        // 시그마 공식 활용
        while (S >= res) {
            T++;
            res = (T * (T + 1)) / 2;
        }
        System.out.println(--T); // 이전 결과를 토대로 while문의 조건이 충족되므로 -1
    }
}