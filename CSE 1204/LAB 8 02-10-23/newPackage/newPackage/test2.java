package newPackage;

import java.awt.Point;

public class test2 {
    public static void main(String[] args) {
        Point p = new Point();
        System.out.println(getPoint(p));
    }

    public static Point getPoint(Point p){
        p.translate(1, 1);
        return p;
        // return p.translate(1, 1);
    }
}
