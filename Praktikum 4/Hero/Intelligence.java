public class Intelligence extends Hero {
    public Intelligence() {
        super();
    }

    public Intelligence(int level) {
        super(level);
    }
    
    @Override
    public Double value() {
        return this.getLevel() + 0.25;
    }

    @Override
    public void printInfo() {
        System.out.println("Intelligence Hero (Lvl "+ this.getLevel() + ")");
    }
}
