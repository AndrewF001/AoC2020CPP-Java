package com.company;

public class Main {

    public static void main(String[] args) {
        long Start = System.nanoTime();

        FileReader.PrintFiles();
        DefaultClass program;
        program = new Day1();
        program = new Day2();
        program = new Day3();
        program = new Day4();
        program = new Day5();
        program = new Day6();

        System.out.println("The entire program took: " + (System.nanoTime()-Start) + " nanoseconds : " + ((double)(System.nanoTime()-Start)/100000) + " milliseconds");
    }


}
