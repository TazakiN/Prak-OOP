import java.util.ArrayList;
import java.util.Collections;

public class Solver {
  private ArrayList<String> prompts;

  public Solver() {
    this.prompts = new ArrayList<String>();
  }

  public void addPiece(String prompt) {
    this.prompts.add(prompt);
  }

  public String scrapeAnswer() {
    ArrayList<Scraper> scrapers = new ArrayList<>();

    // Membuat instance Scraper untuk setiap prompt
    for (String prompt : prompts) {
      Scraper scraper = new Scraper(prompt);
      scrapers.add(scraper);
      scraper.start();
    }

    StringBuilder answer = new StringBuilder();
    ArrayList<Character> pieces = new ArrayList<>();

    // Mengumpulkan jawaban dari setiap scraper
    for (Scraper scraper : scrapers) {
      try {
        pieces.add(scraper.getAnswer());
      } catch (InterruptedException e) {
        e.printStackTrace();
      }
    }

    // Mengurutkan jawaban sesuai abjad
    Collections.sort(pieces);

    // Menggabungkan jawaban menjadi satu string
    for (char piece : pieces) {
      answer.append(piece);
    }

    return answer.toString();
  }
}
