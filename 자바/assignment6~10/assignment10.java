package assignment;

import java.util.NoSuchElementException;
import java.util.StringTokenizer;

public class assignment10 {
    public static void main(String[] args) {
        String s = "of the people, by the people, for the people";
        try {
            showTokens(s, ", ");
        } catch (NoSuchElementException e) {
            System.out.println("끝");
        }
    }

    // while(ture) {}을 사용하는 showTokens() 메서드 추가
    public static void showTokens(String s, String p) {
        StringTokenizer token = new StringTokenizer(s, p);
        while (true) {
            System.out.println(token.nextToken());
        }
    }
}
