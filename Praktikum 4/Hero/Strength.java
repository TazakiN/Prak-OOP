public class Strength extends Hero{
    public Strength() {
        super();
    }

    public Strength(int level) {
        super(level);
    }

    @Override
    public Double value() {
        return this.getLevel() + 0.5;
    }

    @Override
    public void printInfo() {
        System.out.println("Strength Hero (Lvl "+ this.getLevel() + ")");
    }

}