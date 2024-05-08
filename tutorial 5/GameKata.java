import java.util.*;

public class GameKata {
    public static void run(String[] tito, String[] wiwid) {
        Map<String, Integer> titoWords = new HashMap<>();
        Map<String, Integer> wiwidWords = new HashMap<>();

        for (String word : tito) {
            titoWords.put(word, titoWords.getOrDefault(word, 0) + 1);
        }

        for (String word : wiwid) {
            wiwidWords.put(word, wiwidWords.getOrDefault(word, 0) + 1);
        }

        for (String word : titoWords.keySet()) {
            if (wiwidWords.containsKey(word)) {
                System.out.println(word);
            }
        }
    }

}
