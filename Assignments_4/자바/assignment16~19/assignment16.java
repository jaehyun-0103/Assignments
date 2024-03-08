package assignment;

import java.util.stream.Collectors;
import java.util.stream.Stream;

public class assignment16 {
    public static void main(String[] args) {
        Stream<assignment.Nation> n1 = assignment.Nation.nations.stream();
        Stream<assignment.Nation> n2 = n1.filter(x -> x.getType() == assignment.Nation.Type.LAND);

        String land = n2.map(x -> x.getName()).collect(Collectors.joining(", "));

        System.out.println(land);
    }
}
