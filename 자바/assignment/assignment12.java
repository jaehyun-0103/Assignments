package assignment;

import java.util.function.Consumer;

public class assignment12 {
    public static void main(String[] args) {
        Consumer<Integer> apple = t -> {
            if (t == 1)
                System.out.println(t + " apple.");
            else if (t > 1)
                System.out.println(t + " apples.");
        };
        apple.accept(3);
        apple.accept(1);
    }
}
