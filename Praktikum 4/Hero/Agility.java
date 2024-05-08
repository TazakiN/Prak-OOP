public class Agility extends Hero {
    public Agility() {
        super();
    }

    public Agility(int level) {
        super(level);
    }
    
    @Override
    public Double value() {
        return this.getLevel() + 0.75;
    }

    @Override
    public void printInfo() {
        System.out.println("Agility Hero (Lvl "+ this.getLevel() + ")");
    }
}
