package assignment;

import java.util.Arrays;
import java.util.List;
import java.util.stream.Stream;

public class assignment15 {
    public static void main(String[] args) {
        List<String> list = Arrays.asList("갈매기", "나비", "다람쥐", "라마");
        Stream<String> word = list.stream();

        for (String a : word.toList()) {
            if (a.length() == 2)
                System.out.println(a);
        }
    }
}
