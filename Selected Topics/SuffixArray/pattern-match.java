import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;

public class SuffixArraySearch {

    public static void main(String[] args) {

        String text = "proiectarea algoritmilor de Cormen MIT";
        String pattern = "algo";

        ArrayList<Integer> SA = new ArrayList<>();

        // Construirea suffix array
        for (int i = 0; i < text.length(); ++i) {
            SA.add(i);
        }

        System.out.println("Text: " + text);
        System.out.println("Pattern: " + pattern);
        System.out.println();

        // Sortarea sufixelor
        Collections.sort(SA, new Comparator<Integer>() {
            @Override
            public int compare(Integer a, Integer b) {
                return text.substring(a).compareTo(text.substring(b));
            }
        });

        /*
        // Afisarea suffix array-ului
        for (int i = 0; i < SA.size(); ++i) {
            System.out.print(SA.get(i) + " ");
        }
        */

        int left = 0;
        int right = SA.size() - 1;

        boolean found = false;

        while (left <= right) {

            int middle = (left + right) >> 1;

            int pos = SA.get(middle);

            String suffix = text.substring(pos);

            String prefix;

            if (suffix.length() >= pattern.length()) {
                prefix = suffix.substring(0, pattern.length());
            } else {
                prefix = suffix;
            }

            if (pattern.equals(prefix)) {
                System.out.println("Found At index: " + pos);
                found = true;
                break;
            }

            if (prefix.compareTo(pattern) < 0) {
                left = middle + 1;
            } else {
                right = middle - 1;
            }
        }

        if (!found) {
            System.out.println("Not Found!");
        }
    }
}
