public class Scraper extends Thread {
    private Gpt gpt;
    private Solver solver;
    private int index;

    public Scraper(Gpt gpt, Solver solver, int index) {
        this.gpt = gpt;
        this.solver = solver;
        this.index = index;
    }

    @Override
    public void run() {
        char answer = gpt.getPieceAnswer();
        solver.setPieceAnswer(index, answer);
    }
}