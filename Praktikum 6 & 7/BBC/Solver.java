import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;

public class Solver {
  private ArrayList<String> prompts;
  private char[] answers;
  private int count = 0;

  public Solver() {
    this.prompts = new ArrayList<>();
  }

  public void addPiece(String prompt) {
    this.prompts.add(prompt);
  }

  public synchronized void setPieceAnswer(int index, char answer) {
    answers[index] = answer;
    count++;
    if (count == prompts.size()) {
      notify();
    }
  }

  public synchronized String scrapeAnswer() {
    int size = prompts.size();
    answers = new char[size];

    ArrayList<Scraper> scrapers = new ArrayList<>(size);

    for (int i = 0; i < size; i++) {
      Gpt gpt = new Gpt(prompts.get(i));
      Scraper scraper = new Scraper(gpt, this, i);
      scrapers.add(scraper);
      scraper.start();
    }

    while (count < size) {
      try {
        wait();
      } catch (InterruptedException e) {
        Thread.currentThread().interrupt();
      }
    }

    return new String(answers);
  }
}