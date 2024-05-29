public class Scraper extends Thread {
    private String prompt;
    private char answer;
    private boolean done = false;

    public Scraper(String prompt) {
        this.prompt = prompt;
    }

    @Override
    public void run() {
        Gpt gpt = new Gpt(prompt);
        answer = gpt.getPieceAnswer();

        synchronized (this) {
            done = true;
            notify();
        }
    }

    public synchronized char getAnswer() throws InterruptedException {
        while (!done) {
            wait();
        }
        return answer;
    }
}
