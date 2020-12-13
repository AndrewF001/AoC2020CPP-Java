package com.company;

public class Main {

    public static void main(String[] args) {
        long Start = System.currentTimeMillis();

        FileReader.PrintFiles();
        DefaultClass program;
        program = new Day1();
        program = new Day2();
        program = new Day3();
        program = new Day4();
        program = new Day5();
        program = new Day6();
        //program = new Day7();
        program = new Day8();
        program = new Day9();
        program = new Day10();
        //program = new Day11();
        program = new Day12();
        program = new Day13();
        System.out.println("\nThe entire program took: " + (System.currentTimeMillis()-Start) + " Milliseconds");
    }


}
